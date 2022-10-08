#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <List.hpp>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//Group A
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



//Group B
const int buzzerPinB = 7;

const int ldrPinB1 = A3;
const int ledPinB1a = 32;
const int ledPinB1b = 33;



const int potPin = A0;

//const int laserPin = 7;


class Light {
	int pin;      // the number of the LED pin
	boolean active; //active or not
	int ledState;  // ledState used to set the LED

public:
	Light() {
	}
	public:Light(int pin_) {
		pin = pin_;
		ledState = LOW;
		active = false;
		pinMode(pin, OUTPUT);
	}

	void toggleActive() {
		active = !active;
	}
	void activate() {
		active = true;
	}

	void deactivate() {
		active = false;
	}

	void update() {
		ledState = active ? HIGH : LOW;
		digitalWrite(pin, ledState);
	}
};

class Flasher {
	// Class Member Variables
	// These are initialized at startup
	int pin;      // the number of the LED pin
	long onMs;     // milliseconds of on-time
	long offMs;    // milliseconds of off-time
	boolean active; //active or not

	// These maintain the current state
	int ledState;                 // ledState used to set the LED
	unsigned long previousMs;   // will store last time LED was updated

public:
	Flasher() {
	}
	// Constructor - creates a Flasher
	// and initializes the member variables and state
public:
	Flasher(int pin_, long onMs_, long offMs_) {
		pin = pin_;
		onMs = onMs_;
		offMs = offMs_;
		ledState = LOW;
		previousMs = 0;
		active = false;
		pinMode(pin, OUTPUT);
	}

	void toggleActive() {
		active = !active;
	}
	void activate() {
		active = true;
	}

	void deactivate() {
		active = false;
	}


	void update() {
		// check to see if it's time to change the state of the LED
		unsigned long currentMs = millis();
		if (active) {
			if ((ledState == HIGH)
					&& (currentMs - previousMs >= onMs)) {
				ledState = LOW;  // Turn it off
				previousMs = currentMs;  // Remember the time
				digitalWrite(pin, ledState);  // Update the actual LED
			} else if ((ledState == LOW)
					&& (currentMs - previousMs >= offMs)) {
				ledState = HIGH;  // turn it on
				previousMs = currentMs;   // Remember the time
				digitalWrite(pin, ledState);   // Update the actual LED
			}
		} else {
			previousMs = currentMs;
			digitalWrite(pin, LOW);
		}
	}
};

class Buzzer {
	// These are initialized at startup
	int pin;      // the number of the Buzzer pin
	long soundMs;     // milliseconds sound buzzer for give frequency
	boolean active; //active or not
	long frequency;
	unsigned long activatedMillis;   // will store last time Buzzer was updated

public:
	Buzzer() {
	}

public:
	Buzzer(int pin_, long soundMs_, int frequency_) {
		pin = pin_;
		pinMode(pin, OUTPUT);
		active = false;
		frequency = frequency_;
		soundMs = soundMs_;
		activatedMillis = 0;
	}

	void activate() {
		active = true;
		activatedMillis = millis();
	}

	void deactivate() {
		active = false;
		activatedMillis = 0;
	}

	void update() {
		// check to see if it's time to change the state of the LED
		//Serial.println((String)"buzzer active?: " + active);
		unsigned long currentMillis = millis();
		if (active) {
			//exceeded sound ms
			if (((currentMillis - activatedMillis) >= soundMs)) {
				noTone(pin);
				deactivate();
			} else {
				tone(pin, frequency);
			}
		}
	}
};

class Target {
	int ldrPin;
	int sensitivityPin;
public:
	String id;
	int hitCount;
	Light light;
	Flasher flasher;
	Buzzer buzzer;
	long durationMs;     // milliseconds of on-time
	boolean isHit; //isHit or not
	boolean isArmed; //is target selected or not

	// These maintain the current state
	unsigned long previousMs;   // will store last time Target was updated

public:
	Target() {
	}
public:
	Target(String id_, int pin_, int sensitivityPin_, Light light_, Flasher flash_,
			Buzzer buzzer_, long durationMs_) {
		id = id_;
		ldrPin = pin_;
		sensitivityPin = sensitivityPin_;
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

	void arm() {
		isArmed = true;
		light.activate();
		flasher.deactivate();
		Serial.print("Target: ");
		Serial.print((String)id);
		Serial.println(" armed!!!");

	}

	void unarm() {
		isArmed = false;
		light.deactivate();
		flasher.deactivate();
	}

	boolean isIdle() {
		return !isHit && !isArmed;
	}


	void Update() {

		unsigned long currentMs = millis();
		//Serial.print("Update Target: ");
//							Serial.print((String)id);
//							Serial.println( isArmed);

		if (isArmed && id != "") {
			if (isHit) {
				//Serial.println((String)"timing: " + (currentMs - previousMs) + " " + durationMs);
				if ((currentMs - previousMs) >= durationMs) {
					Serial.print("Target: ");
					Serial.print((String)id);
					Serial.println( " deactivated");
					//Serial.println(" deactivated");
					flasher.deactivate();
					light.deactivate();
					//buzzer.Deactivate();
					isHit = false;
					isArmed = false;
					previousMs = 0;  //Reset time
				}
			} else {
				int sensitivity = 20;//analogRead(sensitivityPin);
				int ldrStatus = analogRead(ldrPin);
				//Serial.println((String) "" + id + ": Sensitity: " + (sensitivity)				+ " ldr: " + ldrStatus);

				//low ldr = hit
				if (ldrStatus < sensitivity) {
					hitCount++;
					light.deactivate();
					flasher.activate();
					buzzer.activate();
					isHit = true;
					Serial.print("Target: ");
					Serial.print((String)id);
					Serial.print( " Hit: ");
					Serial.println((String)hitCount);
					previousMs = currentMs;  // Remember the time
				}

			}
			light.update();
			flasher.update();
			buzzer.update();
		}

	}
};

//Games
//random target selection selected till hit
const String game_random_infinite = "random_infinite";
//random target selection selected for limited amount of time
const String game_random_finite = "random_finite";
//incremental target selection selected till hit
const String game_incremental_infinite = "incremental_infinite";
//incremental target selection selected for limited amount of time
const String game_incremental_finite = "incremental_finite";
//select all targets at once, reselect all when all hit
const String game_all_together = "all_together";

/**
 * Represents a group of targets, which participate in a game
 */

class TargetGroup {

public:
	List<Target *> targets;
	int lastTargetIdx = -1;
	String groupId;
	String gameId;
	long durationMs;     // milliseconds of on-time
	unsigned long previousMs;   // will store last time Target was updated

public:
	TargetGroup(String groupId_, const List<Target *> &targets_, String &gameId_, long duartionMs_) {
//		for (int i = 0; i <= sizeof(targets_); i++) {
//			targets.add(targets_[i]);
//		}
		targets = targets_;
		gameId = gameId_;
		groupId = groupId_;
		durationMs = duartionMs_;
		previousMs = 0;
	}

private:
	boolean allIdle() {
		for (int i = 0; i < targets.getSize(); i++) {
			if (!targets.getValue(i)->isIdle()) {
				//Serial.println("Target " + (String)i + " still armed");
				return false;
			}
		}
		return true;
	}

private:
	int randomTargetIdx() {
		int newRandomTargetIdx = random(0L, targets.getSize());
		return lastTargetIdx != newRandomTargetIdx ?
				newRandomTargetIdx : randomTargetIdx();

	}

private:
	void armTarget(int idx) {
		for (int i = 0; i < targets.getSize(); i++) {
			targets.getValue(i)->unarm();
			if (idx == i) {
				targets.getValue(i)->arm();
				lastTargetIdx = idx;
				Serial.println("Armed target: " + (String)i);
			}
		}
	}

private:
	void armTargetIncremental() {
		int newTargetIdx = lastTargetIdx == targets.getSize() ? 0 : lastTargetIdx + 1;
		armTarget(newTargetIdx);
	}

private:
	void armTargetRandom() {
		int newRandomTarget = randomTargetIdx();
		armTarget(newRandomTarget);
	}

private:
	void armAll() {
		for (int i = 0; i < targets.getSize(); i++) {
			Serial.println("Armed target: " + (String)i);
			targets.getValue(i)->arm();
		}
	}

private: void updateAll() {
			for (int i = 0; i < targets.getSize(); i++) {
				targets.getValue(i)->Update();
			}
		}

public: int score() {
		int score = 0;
		for (int i = 0; i < targets.getSize(); i++) {
			score += targets.getValue(i)->hitCount;
		}
		return score;
	}

public: void update() {
		unsigned long currentMs = millis();

		if (allIdle()) {
			Serial.println("All idle");
		}

		if (gameId == game_random_infinite) {
			if (allIdle()) {
				armTargetRandom();
			}
		} else if (gameId == game_incremental_infinite) {
			if (allIdle()) {
				armTargetIncremental();
			}
		} else if (gameId == game_random_finite) {
			if ((currentMs - previousMs) >= durationMs) {
				armTargetIncremental();
				previousMs = currentMs;
			}
		} else if (gameId == game_incremental_finite) {
			if ((currentMs - previousMs) >= durationMs) {
				armTargetIncremental();
				previousMs = currentMs;
			}
		} else {
			if (allIdle()) {
				armAll();
			}
		}
		updateAll();

	}

	void print() {
		Serial.println("Game Group: " + groupId);
		for (int i = 0; i < targets.getSize(); i++) {
			auto t = targets.getValue(i);
			Serial.println("Target: " + (t->id) + " Armed: " + (String)(t->isIdle()));
		}
	}
};

//Group A config
Buzzer buzzerA(buzzerPinA, 300, 1400);

Flasher flasherA1(ledPinA1a, 100, 100);
Light lightA1(ledPinA1b);
Target *targetA1 = new Target("target-A-1", ldrPinA1, potPin, lightA1, flasherA1, buzzerA, 1000);

Flasher flasherA2(ledPinA2a, 100, 100);
Light lightA2(ledPinA2b);
Target *targetA2 = new Target("target-B-1", ldrPinA2, potPin, lightA2, flasherA2, buzzerA, 1000);


//Group B config
// Buzzer buzzerB(buzzerPinB, 300, 1700);

// Flasher flasherB1(ledPinB1a, 100, 100);
// Light lightB1(ledPinB1b);
// Target * targetB1("target-B-1", ldrPinB1, potPin, lightB1, flasherB1, buzzerB, 1000);

//General settings
String game_idx = game_random_infinite;
int finitDurationdMsIn = 5000l;

List<Target *> targetsA;




TargetGroup * targetGroupA;



void setup() {
	Serial.begin(9600);
	Serial.println("LaserGame " + game_idx + " initialization.");

	//Serial.begin(115200);

	if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
		Serial.println(F("SSD1306 allocation failed"));
		for (;;)
			;
	}
	delay(2000);
	display.clearDisplay();
	display.display();
	targetsA.add(targetA1);
	targetsA.add(targetA2);
	targetGroupA = new TargetGroup("Group-A", targetsA, game_idx, finitDurationdMsIn);
	targetGroupA->print();
	// targetGroup1 = new TargetGroup(targets1, game_idx, finitDurationdMsIn);
	//targetsv1.

//	targetGroup1.targets.add(targetA1);
//	targetGroup2.targets.add(target2);

	Serial.println("Initialized targets");
	//targetGroup1.print();
	//targets1.get(0.arm();
//	targetA1->arm();
//	targetA2->arm();


	//lightA1.activate();
	//flasherA1.activate();
	//pinMode(ledPin, OUTPUT);
	//pinMode(buzzerPin, OUTPUT);
	//pinMode(ldrPin, INPUT);
//  pinMode( laserPin , OUTPUT);
//  digitalWrite( laserPin , HIGH);
}

void loop() {

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
	//lightA1.update();
	//flasherA1.update();
	//targetA1->Update();
	//targetA2->Update();
	
	targetGroupA->update();
	
	//targetGroup2.update();
	display.clearDisplay();

	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0, 5);
	// Display static text
	int sensitivity = 20;//analogRead(potPin);
	display.println((String) "Sensitivity: " + sensitivity);
	display.setCursor(0, 15);
	display.println("Game: " + game_idx);
	display.setCursor(0, 30);
	// display.println(
	// 		(String) "A: " + targetGroupA->score() + " B: "
	// 				+ targetGroupB->score());
	display.display();
//
//	//TODO: reset
//	if (sensitivity == 0) {
//		targetA1.hitCount = 0;
//		target2.hitCount = 0;
//	}

}
