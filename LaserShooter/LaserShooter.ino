#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <List.hpp>
#include "Utilities.cpp"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// General settings
int sensitivity = 20;
int sensitivityDiff = 20;
int winningScore = 20;
long finitDurationdMs = 2500;
int game_idx = 0;

// Button board
const int keyboardPin = A10;

// Group A
const int buzzerPinA = 4;

const int ldrPinA1 = A1;
const int ledPinA1a = 22;
const int ledPinA1b = 23;

const int ldrPinA2 = A2;
const int ledPinA2a = 24;
const int ledPinA2b = 25;

const int ldrPinA3 = A3;
const int ledPinA3a = 26;
const int ledPinA3b = 27;

const int ldrPinA4 = A4;
const int ledPinA4a = 28;
const int ledPinA4b = 29;

// Group B
const int buzzerPinB = 7;

const int ldrPinB1 = A11;
const int ledPinB1a = 32;
const int ledPinB1b = 33;

const int ldrPinB2 = A12;
const int ledPinB2a = 34;
const int ledPinB2b = 35;

const int ldrPinB3 = A13;
const int ledPinB3a = 36;
const int ledPinB3b = 37;

const int ldrPinB4 = A9;
const int ledPinB4a = 38;
const int ledPinB4b = 39;


class Light
{
	int pin;		// the number of the LED pin
	boolean active; // active or not
	int ledState;	// ledState used to set the LED

public:
	Light()
	{
	}

public:
	Light(int pin_)
	{
		pin = pin_;
		ledState = LOW;
		active = false;
		pinMode(pin, OUTPUT);
	}

	void toggleActive()
	{
		active = !active;
	}
	void activate()
	{
		active = true;
	}

	void deactivate()
	{
		active = false;
	}

	void update()
	{
		ledState = active ? HIGH : LOW;
		digitalWrite(pin, ledState);
	}
};

class Flasher
{
	// Class Member Variables
	// These are initialized at startup
	int pin;		// the number of the LED pin
	long onMs;		// milliseconds of on-time
	long offMs;		// milliseconds of off-time
	boolean active; // active or not

	// These maintain the current state
	int ledState;			  // ledState used to set the LED
	unsigned long previousMs; // will store last time LED was updated

public:
	Flasher()
	{
	}
	// Constructor - creates a Flasher
	// and initializes the member variables and state
public:
	Flasher(int pin_, long onMs_, long offMs_)
	{
		pin = pin_;
		onMs = onMs_;
		offMs = offMs_;
		ledState = LOW;
		previousMs = 0;
		active = false;
		pinMode(pin, OUTPUT);
	}

	void toggleActive()
	{
		active = !active;
	}
	void activate()
	{
		active = true;
	}

	void deactivate()
	{
		active = false;
	}

	void update()
	{
		// check to see if it's time to change the state of the LED
		unsigned long currentMs = millis();
		if (active)
		{
			if ((ledState == HIGH) && (currentMs - previousMs >= onMs))
			{
				ledState = LOW;				 // Turn it off
				previousMs = currentMs;		 // Remember the time
				digitalWrite(pin, ledState); // Update the actual LED
			}
			else if ((ledState == LOW) && (currentMs - previousMs >= offMs))
			{
				ledState = HIGH;			 // turn it on
				previousMs = currentMs;		 // Remember the time
				digitalWrite(pin, ledState); // Update the actual LED
			}
		}
		else
		{
			previousMs = currentMs;
			digitalWrite(pin, LOW);
		}
	}
};

class Buzzer
{
	// These are initialized at startup
	int pin;		// the number of the Buzzer pin
	long soundMs;	// milliseconds sound buzzer for give frequency
	boolean active; // active or not
	long frequency;
	unsigned long activatedMillis; // will store last time Buzzer was updated

public:
	Buzzer()
	{
	}

public:
	Buzzer(int pin_, long soundMs_, int frequency_)
	{
		pin = pin_;
		pinMode(pin, OUTPUT);
		active = false;
		frequency = frequency_;
		soundMs = soundMs_;
		activatedMillis = 0;
	}

	void activate()
	{
		active = true;
		activatedMillis = millis();
	}

	void deactivate()
	{
		active = false;
		activatedMillis = 0;
	}

	void update()
	{
		// check to see if it's time to change the state of the LED
		// Serial.println((String)"buzzer active?: " + active);
		unsigned long currentMillis = millis();
		if (active)
		{
			// exceeded sound ms
			if (((currentMillis - activatedMillis) >= soundMs))
			{
				noTone(pin);
				deactivate();
			}
			else
			{
				tone(pin, frequency);
			}
		}
	}
};

class Target
{
	int ldrPin;
	int sensitivityPin;

public:
	String id;
	int hitCount;
	Light light;
	Flasher flasher;
	Buzzer buzzer;
	long durationMs; // milliseconds of on-time
	boolean isHit;	 // isHit or not
	boolean isArmed; // is target selected or not

	// These maintain the current state
	unsigned long previousMs; // will store last time Target was updated

public:
	Target()
	{
	}

public:
	Target(String id_, int pin_, int &sensitivity_, Light light_, Flasher flash_,
		   Buzzer buzzer_, long durationMs_)
	{
		id = id_;
		ldrPin = pin_;
		sensitivity = sensitivity_;
		buzzer = buzzer_;
		flasher = flash_;
		light = light_;
		durationMs = durationMs_;
		isHit = false;
		isArmed = false;
		hitCount = 0;
		previousMs = 0;
		pinMode(ldrPin, INPUT);
	}

	void arm()
	{
		isArmed = true;
		light.activate();
		flasher.deactivate();
		Serial.print("Target: ");
		Serial.print((String)id);
		Serial.println(" armed!!!");
	}

	void unarm()
	{
		isArmed = false;
		isHit = false;
		light.deactivate();
		light.update();
		flasher.deactivate();
		flasher.update();
		Serial.print("Target: ");
		Serial.print((String)id);
		Serial.println(" unarmed!!!");
	}

	boolean isIdle()
	{
		return !isHit && !isArmed;
	}

	void reset()
	{
		//Serial.println("Reset Target: " + (String)id);
		hitCount = 0;
		unarm();
	}

	void setSensitity(int sensitivity_)
	{
		sensitivity = sensitivity_;
		Serial.println( "Target: " + (String)id + " setting sensitivity to " + (String)sensitivity);

	}

	void Update()
	{

		unsigned long currentMs = millis();
		// Serial.print("Update Target: ");
		// 							Serial.print((String)id);
		// 							Serial.println(" armed: " +  isArmed);

		if (isArmed)
		{
			if (isHit)
			{
				// Serial.println((String)"timing: " + (currentMs - previousMs) + " " + durationMs);
				if ((currentMs - previousMs) >= durationMs)
				{
					Serial.print("Target: ");
					Serial.print((String)id);
					Serial.println(" deactivated");
					// Serial.println(" deactivated");
					flasher.deactivate();
					light.deactivate();
					// buzzer.Deactivate();
					isHit = false;
					isArmed = false;
					previousMs = 0; // Reset time
				}
			}
			else
			{
				//				int sensitivity = 20;//analogRead(sensitivityPin);
				int ldrStatus = analogRead(ldrPin);
				
				// if(ldrStatus < 100) {
				// Serial.println((String) "" + id + ": Sensitity: " + (String)sensitivity + " ldr: " + ldrStatus);
				// }

				// low ldr = hit
				if (ldrStatus < sensitivity)
				{
					hitCount++;
					light.deactivate();
					flasher.activate();
					buzzer.activate();
					isHit = true;
					Serial.print("Target: ");
					Serial.print((String)id);
					Serial.print(" Hit: ");
					Serial.println((String)hitCount);
					previousMs = currentMs; // Remember the time
				}
			}
			light.update();
			buzzer.update();
		}
		flasher.update();
	}
};

// Games
// random target selection selected till hit
const String game_random_infinite = "rn";
// random target selection selected for limited amount of time
const String game_random_finite = "rn_lmt";
// incremental target selection selected till hit
const String game_incremental_infinite = "inc";
// incremental target selection selected for limited amount of time
const String game_incremental_finite = "inc_lmt";
// select all targets at once, reselect all when all hit
const String game_all_together = "all";

const String gameModes[5] = { game_incremental_infinite, game_incremental_finite, game_random_infinite, game_random_finite, game_all_together};
/**
 * Represents a group of targets, which participate in a game
 */

class TargetGroup
{

public:
	List<Target *> targets;
	int lastTargetIdx = -1;
	String groupId;
	int gameId;
	long durationMs;		  // milliseconds of on-time
	unsigned long previousMs; // will store last time Target was updated
	boolean isEnded;
	boolean hasWon;
	boolean stopped;

public:
	TargetGroup(String groupId_, const List<Target *> &targets_, int &gameId_, long &duartionMs_)
	{
		//		for (int i = 0; i <= sizeof(targets_); i++) {
		//			targets.add(targets_[i]);
		//		}
		targets = targets_;
		gameId = gameId_;
		groupId = groupId_;
		durationMs = duartionMs_;
		previousMs = 0;
		isEnded = false;
		hasWon = false;
		stopped = false;
	}

private:
	boolean allIdle()
	{
		//		Serial.println("Group " + groupId + " allIdle: count " + (String)targets.getSize());
		for (int i = 0; i < targets.getSize(); i++)
		{
			if (!targets.getValue(i)->isIdle())
			{
				// Serial.println("Target " + (String)i + " still armed");
				return false;
			}
		}
		return true;
	}

private:
	int randomTargetIdx()
	{
		int newRandomTargetIdx = random(0L, targets.getSize());
		return lastTargetIdx != newRandomTargetIdx ? newRandomTargetIdx : randomTargetIdx();
	}

private:
	void armTarget(int idx)
	{
		Serial.println("Arming target: " + (String)idx + " ...");
		for (int i = 0; i < targets.getSize(); i++)
		{
			auto t = targets.getValue(i);
			if (idx == i)
			{
				t->arm();
				lastTargetIdx = idx;
				Serial.println("Group " + (String)groupId + " Armed target: " + (String)i);
			}
			else
			{
				t->unarm();
			}
		}
	}

private:
	void armTargetIncremental()
	{
		// Serial.println("Group " + (String)groupId + " Armed targets incremental");
		// Serial.println("============================================");
		int newTargetIdx = lastTargetIdx == (targets.getSize() - 1) ? 0 : lastTargetIdx + 1;
		armTarget(newTargetIdx);
//		Serial.println("============================================");
	}

private:
	void armTargetRandom()
	{
		// Serial.println("Group " + (String)groupId + " Armed targets random");
		// Serial.println("============================================");
		int newRandomTarget = randomTargetIdx();
		armTarget(newRandomTarget);
		// Serial.println("============================================");
	}

private:
	void armAll()
	{
		// Serial.println("Group " + (String)groupId + " Armed targets");
		// Serial.println("============================================");
		for (int i = 0; i < targets.getSize(); i++)
		{
			Serial.println("Group " + (String)groupId + " Armed target: " + (String)i);
			targets.getValue(i)->arm();
		}
		// Serial.println("============================================");

	}

private:
	void flashAll()
	{
		for (int i = 0; i < targets.getSize(); i++)
		{
			targets.getValue(i)->flasher.activate();
		}
	}


private:
	void unarmAll()
	{
		// Serial.println("Group " + (String)groupId + " Unarm targets");
		// Serial.println("============================================");
		for (int i = 0; i < targets.getSize(); i++)
		{
			Serial.println("Group " + (String)groupId + " Unarmed target: " + (String)i);
			targets.getValue(i)->unarm();
		}
		// Serial.println("============================================");

	}

private:
	void updateAll()
	{
		for (int i = 0; i < targets.getSize(); i++)
		{

			auto t = targets.getValue(i);
			if (t->id != "")
			{
				// Serial.println("Group " + (String)groupId + " updating target : " + (String)t->id);
				t->Update();
			}
			else
			{
				Serial.println("Group " + (String)groupId + " INVALID index for target : " + (String)i);
			}
		}
	}

public:
	int score()
	{
		int score = 0;
		for (int i = 0; i < targets.getSize(); i++)
		{
			score += targets.getValue(i)->hitCount;
		}
		return score;
	}

public:
	void resetAll()
	{
		// Serial.println("Group " + (String)groupId + " Reset targets");
		// Serial.println("============================================");		
		isEnded = false;
		hasWon = false;
		stopped = false;
		for (int i = 0; i < targets.getSize(); i++)
		{
			auto t = targets.getValue(i);
			Serial.println("Group: " + (String)groupId + " resetting: " + (String)t->id);
			t->reset();
		
		}
		//Serial.println("============================================");

	}

public:
	void setGameId(int &gameId_)
	{
		gameId = gameId_;
	}

public:
	void setDuartionMs(long &durationMs_)
	{
		durationMs = durationMs_;
	}

public:
	void setSensitivity(int sensitivity_)
	{
		for (int i = 0; i < targets.getSize(); i++)
		{
			auto t = targets.getValue(i);
			t->setSensitity(sensitivity_);
		}
	}

public:
	void endGame(boolean isEnded_, boolean &hasWon_) {
		isEnded = isEnded_;
		hasWon = hasWon_;
	}

public:
	void update()
	{
		unsigned long currentMs = millis();
		if(isEnded) {
			if(!stopped) {
				unarmAll();
				if(hasWon) {
					flashAll();
				}
				stopped = true;
			}
		} else {

		if (allIdle())
		{
			//Serial.println("All idle: Game Mode " + gameModes[gameId]);
			previousMs = 0;
		}

		if (gameModes[gameId] == game_random_infinite)
		{
			if (allIdle())
			{
				armTargetRandom();
			}
		}
		else if (gameModes[gameId] == game_incremental_infinite)
		{
			if (allIdle())
			{
				armTargetIncremental();
			}
		}
		else if (gameModes[gameId] == game_random_finite)
		{
			if ((currentMs - previousMs) >= durationMs)
			{
				armTargetRandom();
				previousMs = currentMs;
			}
		}
		else if (gameModes[gameId] == game_incremental_finite)
		{
			if ((currentMs - previousMs) >= durationMs)
			{
				armTargetIncremental();
				previousMs = currentMs;
			}
		}
		else
		{
			if (allIdle())
			{
				armAll();
			}
		}
		}
		updateAll();
	}

	void print()
	{
		Serial.println("Game Group: " + groupId);
		for (int i = 0; i < targets.getSize(); i++)
		{
			auto t = targets.getValue(i);
			Serial.println("Target: " + (t->id) + " Armed: " + (String)(t->isIdle()));
		}
	}
};

class Game
{
	TargetGroup *targetGroupA;
	TargetGroup *targetGroupB;
	int &winningScore;
	
	public: Game(TargetGroup *targetGroupA_, TargetGroup *targetGroupB_, int &winningScore_)
	{
		targetGroupA = targetGroupA_;
		targetGroupB = targetGroupB_;
		winningScore = winningScore_;
	}

	public:
	void update() {
		
		//when winning score is 0,the game is infiniate
		if(winningScore != 0) {
			auto winA = targetGroupA->score() >= winningScore;
			auto winB = targetGroupB->score() >= winningScore;
			if(winA || winB) {
				Serial.println("Game Ended!!!: A win: " + (String)winA + " B win: " + (String)winB);
				targetGroupA->endGame(true, winA);
				targetGroupB->endGame(true, winB);
			}
		}
		targetGroupA->update();
		targetGroupB->update();
	}

	public:
	void setWinningScore(int &winningScore_) {
		winningScore = winningScore_;

	}

	public:
	void setGameId(int &game_idx) {
				targetGroupA->setGameId(game_idx);
				targetGroupB->setGameId(game_idx);
	}

public:
	void setSensitivityA(int &sensitivity) {
				targetGroupA->setSensitivity(sensitivity);
	}

	void setSensitivityB(int &sensitivity) {
				targetGroupB->setSensitivity(sensitivity);
	}

	public:
	void setDuartionMs(long &duarationMs) {
				targetGroupA->setDuartionMs(duarationMs);
				targetGroupB->setDuartionMs(duarationMs);
	}

public:
	void reset() {
				targetGroupA->resetAll();
				targetGroupB->resetAll();
	}
};

// Group A config
Buzzer buzzerA(buzzerPinA, 300, 1400);

Flasher flasherA1(ledPinA1a, 100, 100);
Light lightA1(ledPinA1b);
Target *targetA1 = new Target("target-A-1", ldrPinA1, sensitivity, lightA1, flasherA1, buzzerA, 1000);

Flasher flasherA2(ledPinA2a, 100, 100);
Light lightA2(ledPinA2b);
Target *targetA2 = new Target("target-A-2", ldrPinA2, sensitivity, lightA2, flasherA2, buzzerA, 1000);

Flasher flasherA3(ledPinA3a, 100, 100);
Light lightA3(ledPinA3b);
Target *targetA3 = new Target("target-A-3", ldrPinA3, sensitivity, lightA3, flasherA3, buzzerA, 1000);

Flasher flasherA4(ledPinA4a, 100, 100);
Light lightA4(ledPinA4b);
Target *targetA4 = new Target("target-A-4", ldrPinA4, sensitivity, lightA4, flasherA4, buzzerA, 1000);


TargetGroup *targetGroupA;

// Group B config
Buzzer buzzerB(buzzerPinB, 300, 1700);

Flasher flasherB1(ledPinB1a, 100, 100);
Light lightB1(ledPinB1b);
Target *targetB1 = new Target("target-B-1", ldrPinB1, sensitivity, lightB1, flasherB1, buzzerB, 1000);

Flasher flasherB2(ledPinB2a, 100, 100);
Light lightB2(ledPinB2b);
Target *targetB2 = new Target("target-B-2", ldrPinB2, sensitivity, lightB2, flasherB2, buzzerB, 1000);

Flasher flasherB3(ledPinB3a, 100, 100);
Light lightB3(ledPinB3b);
Target *targetB3 = new Target("target-B-3", ldrPinB3, sensitivity, lightB3, flasherB3, buzzerB, 1000);

Flasher flasherB4(ledPinB4a, 100, 100);
Light lightB4(ledPinB4b);
Target *targetB4 = new Target("target-B-4", ldrPinB4, sensitivity, lightB4, flasherB4, buzzerB, 1000);

TargetGroup *targetGroupB;

// Config
ButtonBoard *board;

enum Mode
{
	gameMode,
	sensitivityMode,
	sensitivityDiffMode,
	winningScoreMode,
	finitDurationdMsMode
};
String ModesDesc[5] = {"game", "sens", "sensDiff", "winScore", "duration"};

class Configurer
{

	boolean selectMode = false;
	int modeId = 0;
	Game * game;

public:
	Mode mode = gameMode;
	int sensitivity;
	int sensitivityDiff;
	int winningScore;
	long finitDurationdMs;
	int game_idx;

	Configurer(int &game_idx_, int &sensitivity_, int &sensitivityDiff_, int &winningScore_, long &finitDurationdMs_, Game * &game_)
	{
		game_idx = game_idx_;
		sensitivity = sensitivity_;
		sensitivityDiff = sensitivityDiff_;
		winningScore = winningScore_;
		finitDurationdMs = finitDurationdMs_;
		game = game_;
	}

	Mode nextMode()
	{
		modeId++;
		if (modeId == (sizeof(Mode) + 2))
		{
			modeId = 0;
		}
		return static_cast<Mode>(modeId);
	}


public:
	String modeValue() {
		String value = "";
		if(mode == gameMode) {
			value = "" + (String)gameModes[game_idx];
		} else if(mode == sensitivityMode) {
			value = "" + (String)sensitivity;
		} else if(mode == sensitivityDiffMode) {
			value = "" + (String)sensitivityDiff;
		} else if(mode == winningScoreMode) {
			value = "" + (String)winningScore;
		} else if(mode == finitDurationdMsMode) {
			value = "" + (String)finitDurationdMs;
		} 
		return ModesDesc[mode] + " " + value + "";
	}

public:
	void configure(Key &key)
	{
		if (key == select)
		{
			game->reset();
		}
		else if (key == right || key == left) {
			mode = nextMode();
			Serial.println("New Mode Id is" + (String)modeId + " New Mode is" + (String)mode + " Mode Desc " + (String)ModesDesc[mode]);

		}
		else if (mode == gameMode)
		{
			int currentGameIdx = game_idx;
			if (key == up)
			{
				if (sizeof(gameModes) - 1 == game_idx)
				{
					game_idx = 0;
				}
				else
				{
					game_idx++;
				}
			}
			else if (key == down)
			{
				if (game_idx == 0)
				{
					game_idx = sizeof(gameModes) - 1;
				}
				else
				{
					game_idx--;
				}
			}
			if(currentGameIdx != game_idx) {

				Serial.println("Change GameMode to " + (String)gameModes[game_idx]);
				game->setGameId(game_idx);
				game->reset();
			}
		}
		else if (mode == sensitivityMode)
		{
			int currentSensitivity = sensitivity;
			if (key == up)
			{
				sensitivity += 2;
			}
			else if (key == down)
			{
				sensitivity -= 2;
			}
			if(currentSensitivity != sensitivity) {
				int sensitivityB = sensitivity + sensitivityDiff;
				Serial.println("Change Senstivity A to " + (String)sensitivity);
				Serial.println("Change Senstivity B to " + (String)sensitivityB);
				
				game->setSensitivityA(sensitivity);
				game->setSensitivityB(sensitivityB);
			}
		}

		else if (mode == sensitivityDiffMode)
		{
			int currentSensitivityDiff = sensitivityDiff;
			if (key == up)
			{
				sensitivityDiff += 2;
			}
			else if (key == down)
			{
				sensitivityDiff -= 2;
			}
			if(currentSensitivityDiff != sensitivityDiff) {
				int sensitivityB = sensitivity + sensitivityDiff;
				Serial.println("Change Senstivity A to " + (String)sensitivity);
				Serial.println("Change Senstivity B to " + (String)sensitivityB);
				game->setSensitivityA(sensitivity);
				game->setSensitivityB(sensitivityB);
			}
		}
		else if (mode == winningScoreMode)
		{
			int currentWinningScore = winningScore;
			if (key == up)
			{
				winningScore += 1;
			}
			else if (key == down)
			{
				if(winningScore <= 0) {
					winningScore = 0;
				} else {
				 	winningScore -= 1;
				}
			}
			if(currentWinningScore != winningScore) {
				Serial.println("Change winning Socreto " + (String)winningScore);
				game->setWinningScore(winningScore);
			}
		}
		else if (mode == finitDurationdMsMode)
		{
			long currentFinitDurationdMsMode = finitDurationdMs;
			if (key == up)
			{
				finitDurationdMs += 100;
			}
			else if (key == down)
			{
				finitDurationdMs -= 100;
			}
			if(currentFinitDurationdMsMode != finitDurationdMs) {
				Serial.println("Change finitDurationdM to " + (String)finitDurationdMs);
				game->setDuartionMs(finitDurationdMs);
			}
		}
	}
};

List<Target *> targetsA;
List<Target *> targetsB;
Configurer *configurer;
Game *game;

void setup()
{
	Serial.begin(9600);
	Serial.println("LaserGame " + gameModes[game_idx] + " initialization.");

	if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
	{ // Address 0x3D for 128x64
		Serial.println(F("SSD1306 allocation failed"));
		for (;;)
			;
	}
	delay(2000);
	display.clearDisplay();
	display.display();

	targetsA.add(targetA1);
	targetsA.add(targetA3);
	targetsA.add(targetA4);
	targetsA.add(targetA2);
	targetGroupA = new TargetGroup("Group-A", targetsA, game_idx, finitDurationdMs);
	targetGroupA->print();

	targetsB.add(targetB1);
	targetsB.add(targetB2);
	targetsB.add(targetB3);
	targetsB.add(targetB4);
	targetGroupB = new TargetGroup("Group-B", targetsB, game_idx, finitDurationdMs);
	targetGroupB->print();

	game = new Game(targetGroupA, targetGroupB, winningScore);

	// Configurer
	configurer = new Configurer(game_idx, sensitivity, sensitivityDiff, winningScore, finitDurationdMs, game);
	board = new ButtonBoard(keyboardPin, [](Key k) -> void
							{ configurer->configure(k); });

	Serial.println("Game initialized");

	//	targetA1->arm();
	//	targetA2->arm();

	// lightA1.activate();
	// flasherA1.activate();
}

void loop()
{

	// for (int i = 0; i < targets1.getSize(); i++)
	// {
	// 	if (targets1.getValue(i)->isIdle())
	// 	{
	// 		Serial.println("Armed target: " + (String)i);
	// 		targets1.getValue(i)->arm();
	// 	}
	// 	targets1.getValue(i)->Update();
	// }

	// targets1.getValue(0)->Update();
	// if(targets1.getValue(0)->isIdle()) {
	// 	Serial.println("Target idle, re-arm");
	// 	targets1.getValue(0)->arm();
	// }
	// lightA1.update();
	// flasherA1.update();
	// targetA1->Update();
	// targetA2->Update();

	game->update();
	board->update();

	//Display
	display.clearDisplay();
	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0, 5);
	display.println("Game: " + gameModes[configurer->game_idx]);
	display.setCursor(0, 15);
	display.println((String) "Score A: " + targetGroupA->score() + " B: " + targetGroupB->score());
	display.setCursor(0, 25);
	display.println("Mode: " + configurer->modeValue());
	display.display();

}
