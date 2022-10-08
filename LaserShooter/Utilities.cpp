#include <Arduino.h>
enum Key { up, down, left, right, select, none };


class ButtonBoard {

    int keyboardPin;
    Key lastKey = none;
    int Key_read = 0;
    int Prev_Key_read = 1023;
    void (*buttonClicked)(Key);
    long durationMs;
    unsigned long previousMs;   // will store last time Target was updated

  public:
    ButtonBoard(int keyboardPin_, void (*buttonClicked_)(Key)) {
      keyboardPin = keyboardPin_;
      buttonClicked = buttonClicked_;
      durationMs = 100;
      previousMs = 0;
    }


    void update() {
      //needed because too many reads causes wrong values
      unsigned long currentMs = millis();
      if ((currentMs - previousMs) >= durationMs) {
        buttonPressed();
        previousMs = currentMs;
     }
    }

    void buttonPressed() {
      Key_read = analogRead(keyboardPin);
      if (Prev_Key_read > 1000 and Prev_Key_read != Key_read and Key_read < 1000) {
        Serial.println(Key_read);
        if (Key_read > 160 and Key_read < 170 ) buttonClicked(right);
        else if (Key_read > 25 and Key_read < 40) buttonClicked(up);
        else if (Key_read > 80 and Key_read < 95) buttonClicked(down);
        else if (Key_read > 350 and Key_read < 360)  buttonClicked(select);
        else if (Key_read < 10 ) buttonClicked(left);
      }
      Prev_Key_read = Key_read;

    }
};



