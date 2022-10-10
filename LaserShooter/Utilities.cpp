#include <Arduino.h>
enum Key
{
  up,
  down,
  left,
  right,
  select,
  none
};

class ButtonBoard
{

  int keyboardPin;
  Key lastKey = none;
  int Key_read = 0;
  int Prev_Key_read = 1023;
  void (*buttonClicked)(Key);
  long durationMs;
  unsigned long previousMs; // will store last time Target was updated

public:
  ButtonBoard(int keyboardPin_, void (*buttonClicked_)(Key))
  {
    keyboardPin = keyboardPin_;
    buttonClicked = buttonClicked_;
    durationMs = 100;
    previousMs = 0;
  }

  void update()
  {
    // needed because too many reads causes wrong values
    unsigned long currentMs = millis();
    if ((currentMs - previousMs) >= durationMs)
    {
      buttonPressed();
      previousMs = currentMs;
    }
  }

  void buttonPressed()
  {
    Key_read = analogRead(keyboardPin);
    if (Prev_Key_read > 1000 and Prev_Key_read != Key_read and Key_read < 1000)
    {
      if (Key_read > 160 and Key_read < 180)
      {
        Serial.println("RIGHT (" + (String)Key_read + ")");
        buttonClicked(right);
      }
      else if (Key_read > 25 and Key_read < 60)
      {
        Serial.println("UP (" + (String)Key_read + ")");
        buttonClicked(up);
      }
      else if (Key_read > 80 and Key_read < 120)
      {
        Serial.println("DOWN (" + (String)Key_read + ")");
        buttonClicked(down);
      }
      else if (Key_read > 340 and Key_read < 370)
      {
        Serial.println("SELECT (" + (String)Key_read + ")");
        buttonClicked(select);
      }
      else if (Key_read < 15)
      {
        Serial.println("LEFT (" + (String)Key_read + ")");
        buttonClicked(left);
      }
      else
      {
        Serial.println("UNKNOWN Key " + (String)Key_read);
      }
    }
    Prev_Key_read = Key_read;
  }
};
