
#include "pitches.h"

const int redLED1 = 7;
const int redLED2 = 6;
const int greenLED1 = 5;
const int greenLED2 = 4;
const int blueLED1 = 3;
const int blueLED2 = 2;

const int speakerPin = 8;
const int buttonPin = 9;
int buttonState;
int randNumber;
int hold;
int sensorPin = A5;
int sensorValue;

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;

int ledState = LOW;
unsigned long previousMillis = 0;
const long interval = 2;
unsigned long currentMillis = 0;

int ledState2 = LOW;
unsigned long previousMillis2 = 0;
const long interval2 = 0;
unsigned long currentMillis2 = 0;

int ledState3 = LOW;
unsigned long previousMillis3 = 0;
const long interval3 = 0;
unsigned long currentMillis3 = 0;

int ledState4 = LOW;
unsigned long previousMillis4 = 0;
const long interval4 = 0;
unsigned long currentMillis4 = 0;

int ledState5 = LOW;
unsigned long previousMillis5 = 0;
const long interval5 = 0;
unsigned long currentMillis5 = 0;

int ledState6 = LOW;
unsigned long previousMillis6 = 0;
const long interval6 = 0;
unsigned long currentMillis6 = 0;

int i = 0;
int add = 1;
int j = 0;
int l = 0;
int m = 3;
int n = 0;
int p = 3;

int LEDs[] = {
  redLED1, redLED2, blueLED1, blueLED2, greenLED1, greenLED2
};

// Despacito
int melody1[] = {
  NOTE_B4, NOTE_FS4, NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_G4,
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_A4, NOTE_D5, NOTE_A4, NOTE_D5, NOTE_A4, NOTE_D5, NOTE_E5,
  NOTE_CS5
};

int noteDurations1[] = {
  2, 8, 8, 8, 8, 6, 6, 6, 6, 6, 4, 1, 1, 8, 8, 8, 8, 4, 4, 6, 6, 1
};

//Havana
int melody2[] = {
  NOTE_D4, NOTE_D4, NOTE_AS3, NOTE_AS3, NOTE_G3, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_C4,
  NOTE_AS3, NOTE_D4, NOTE_D4, NOTE_AS3, NOTE_AS3, NOTE_G3, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_D4, NOTE_D4, NOTE_AS3, NOTE_AS3, NOTE_G3,
  NOTE_D4, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_D4, NOTE_AS3, NOTE_D4, NOTE_C4, NOTE_D4,
  NOTE_C4, NOTE_AS3, NOTE_D4, NOTE_A3, NOTE_AS3, NOTE_A3, NOTE_AS3, NOTE_A3, NOTE_AS3, NOTE_A3
};


int noteDurations2[] = {
  4, 4, 4, 4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4 , 4, 4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4 , 4, 4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4
};

//shape of you - ed sheeran
int melody3[] = {
  NOTE_E5, NOTE_FS5, NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_FS5, NOTE_CS5,
  NOTE_E5, NOTE_FS5, NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_CS5, NOTE_CS5,
  NOTE_E5, NOTE_FS5, NOTE_GS5, NOTE_CS5, NOTE_E5, NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_FS5,
  NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_CS5
};
//length - 33

int noteDurations3[] = {
  8, 8, 4, 8, 8, 4, 4, 2, 8, 8, 8, 4, 8, 8, 4, 4, 2, 8, 8, 8, 4, 4, 4, 4, 2, 8, 8, 4, 8, 8,
  4, 4, 2, 2
};

//fire - adele
int melody4[] = {
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_E4,
  NOTE_D4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_D4,
  NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_E4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_E4,
  NOTE_F4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_C5,
  NOTE_F4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_C5, NOTE_C5, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_D4,
  NOTE_F4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_D4,
  NOTE_D4, NOTE_F4, NOTE_D4
};

int noteDurations4[] = {
  4, 4, 4, 2, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  2, 4, 2, 4, 4, 4, 4, 4, 4, 4, 2, 4, 2, 2, 2, 2, 2, 4, 4, 1, 4, 4, 2, 4, 2, 4, 4, 2, 2,
  4, 4, 2, 4, 4, 2, 4, 4, 2, 2, 2, 4, 4, 4, 1
};

int melody5[] = {
  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4,
  NOTE_B4, NOTE_D5, NOTE_C5, NOTE_E5, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_E5, NOTE_A4, NOTE_A4,
  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_C5, NOTE_B4,
  NOTE_A4, NOTE_B4, NOTE_D5, NOTE_E5
};

int noteDurations5[] = {
  4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 2, 1, 4, 4, 4, 2, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4,
  4, 2, 2
};

//roar by Katy Perry
int melody6[] = {
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_AS4, NOTE_AS4, NOTE_G4, NOTE_F4, NOTE_AS4,
  NOTE_G4, NOTE_AS4, NOTE_AS4, NOTE_G4, NOTE_F4, NOTE_AS4, NOTE_G4, NOTE_F4, NOTE_AS4,
  NOTE_G4, NOTE_F4, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G4, NOTE_F4, NOTE_AS4

};

int noteDurations6[] = {
  4, 4, 4, 4, 4, 4, 2, 4, 4, 2, 2, 3, 8, 4, 4, 2, 4, 4, 2, 4, 4, 2, 2, 4, 4, 4, 2, 4, 2, 1

};

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(redLED1, OUTPUT);
  pinMode(redLED2, OUTPUT);
  pinMode(greenLED1, OUTPUT);
  pinMode(greenLED2, OUTPUT);
  pinMode(blueLED1, OUTPUT);
  pinMode(blueLED2, OUTPUT);
  randomSeed(analogRead(A0));
  Serial.begin(9600);

}

void loop() {
  sensorValue = analogRead(sensorPin);
  //buttonState = digitalRead(buttonPin);
  if (sensorValue < 500) {

    hold = randNumber;
    randNumber = random(1, 7);
    while (randNumber == hold) {
      randNumber = random(1, 7);
    }

    if (randNumber == 6) {
      for (int k = 0; k < 2; k++) {
        digitalWrite(redLED1, HIGH);
        digitalWrite(redLED2, HIGH);
        digitalWrite(blueLED1, HIGH);
        digitalWrite(blueLED2, HIGH);
        digitalWrite(greenLED1, HIGH);
        digitalWrite(greenLED2, HIGH);
        delay(500);
        digitalWrite(redLED1, LOW);
        digitalWrite(redLED2, LOW);
        digitalWrite(blueLED1, LOW);
        digitalWrite(blueLED2, LOW);
        digitalWrite(greenLED1, LOW);
        digitalWrite(greenLED2, LOW);
        delay(500);

      }



      for (int thisNote = 0; thisNote < 52; thisNote++) {//havana

        if (i < 0) {
          add = 1;
          i = 0;
        }

        else if (i >= 5) {
          add = -1;
        }


        currentMillis = millis();

        if (currentMillis - previousMillis >= interval) {
          // save the last time you blinked the LED
          previousMillis = currentMillis;

          // if the LED is off turn it on and vice-versa:
          if (ledState == LOW) {
            ledState = HIGH;
          } else {
            ledState = LOW;
          }

          // set the LED with the ledState of the variable:
          digitalWrite(LEDs[i], ledState);
          i = i + add;
        }





        int noteDuration2 = 1000 / noteDurations2[thisNote];
        tone(8, melody2[thisNote], noteDuration2);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration2 * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
        if (thisNote == 51) {
          for (int a = 0; a < 6; a++) {
            digitalWrite(LEDs[a], LOW);
          }
        }

      }
    }

    else if (randNumber == 5) {
      for (int k = 0; k < 2; k++) {
        digitalWrite(redLED1, HIGH);
        digitalWrite(redLED2, HIGH);
        digitalWrite(blueLED1, HIGH);
        digitalWrite(blueLED2, HIGH);
        digitalWrite(greenLED1, HIGH);
        delay(500);
        digitalWrite(redLED1, LOW);
        digitalWrite(redLED2, LOW);
        digitalWrite(blueLED1, LOW);
        digitalWrite(blueLED2, LOW);
        digitalWrite(greenLED1, LOW);
        delay(500);

      }
      for (int thisNote = 0; thisNote < 34  ; thisNote++) {//new rules

        if (j >= 5) {
          j = 0;
        }


        currentMillis2 = millis();

        if (currentMillis2 - previousMillis2 >= interval2) {
          // save the last time you blinked the LED
          previousMillis2 = currentMillis2;

          // if the LED is off turn it on and vice-versa:
          if (ledState2 == LOW) {
            ledState2 = HIGH;
          } else {
            ledState2 = LOW;
          }

          // set the LED with the ledState of the variable:
          digitalWrite(LEDs[j], ledState2);
          j = j + 2;
        }


        int noteDuration5 = 1000 / noteDurations5[thisNote];
        tone(speakerPin, melody5[thisNote], noteDuration5);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration5 * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
        if (thisNote == 33) {
          for (int a = 0; a < 6; a++) {
            digitalWrite(LEDs[a], LOW);
          }
        }
      }
    }

    else if (randNumber == 4) {
      for (int k = 0; k < 2; k++) {
        digitalWrite(redLED1, HIGH);
        digitalWrite(redLED2, HIGH);
        digitalWrite(blueLED1, HIGH);
        digitalWrite(blueLED2, HIGH);
        delay(500);
        digitalWrite(redLED1, LOW);
        digitalWrite(redLED2, LOW);
        digitalWrite(blueLED1, LOW);
        digitalWrite(blueLED2, LOW);
        delay(500);

      }



      for (int thisNote = 0; thisNote < 73  ; thisNote++) {//fire - adele
        if (l >= 5) {
          l = 0;
        }


        currentMillis3 = millis();

        if (currentMillis3 - previousMillis3 >= interval3) {
          // save the last time you blinked the LED
          previousMillis3 = currentMillis3;

          // if the LED is off turn it on and vice-versa:
          if (ledState3 == LOW) {
            ledState3 = HIGH;
          } else {
            ledState3 = LOW;
          }

          Serial.println(ledState3);
          digitalWrite(LEDs[l], ledState3);
          digitalWrite(LEDs[l + 1], ledState3);

          l = l + 2;
        }
        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration4 = 1000 / noteDurations4[thisNote];
        tone(speakerPin, melody4[thisNote], noteDuration4);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration4 * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
        if (thisNote == 72) {
          for (int a = 0; a < 6; a++) {
            digitalWrite(LEDs[a], LOW);
          }
        }
      }
    }

    else if (randNumber == 3) {//shape of you - ed sheeran




      for (int k = 0; k < 2; k++) {
        digitalWrite(redLED1, HIGH);
        digitalWrite(redLED2, HIGH);
        digitalWrite(blueLED1, HIGH);
        delay(500);
        digitalWrite(redLED1, LOW);
        digitalWrite(redLED2, LOW);
        digitalWrite(blueLED1, LOW);
        delay(500);

      }
      for (int thisNote = 0; thisNote < 33  ; thisNote++) {
        currentMillis4 = millis();

        if (currentMillis4 - previousMillis4 >= interval4) {
          // save the last time you blinked the LED
          previousMillis4 = currentMillis4;

          // if the LED is off turn it on and vice-versa:
          if (ledState4 == LOW) {
            ledState4 = HIGH;
          } else {
            ledState4 = LOW;
          }


          Serial.println(m);
          digitalWrite(LEDs[m], ledState4);
          digitalWrite(LEDs[m + 1], ledState4);
          digitalWrite(LEDs[m + 2], ledState4);

        }

        int noteDuration3 = 1000 / noteDurations3[thisNote];
        tone(speakerPin, melody3[thisNote], noteDuration3);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration3 * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
        if (thisNote == 32) {
          for (int a = 0; a < 6; a++) {
            digitalWrite(LEDs[a], LOW);
          }
        }
      }

    }

    else if (randNumber == 2) {
      for (int k = 0; k < 2; k++) {
        digitalWrite(redLED1, HIGH);
        digitalWrite(redLED2, HIGH);
        delay(500);
        digitalWrite(redLED1, LOW);
        digitalWrite(redLED2, LOW);
        delay(500);

      }

      for (int thisNote = 0; thisNote < 28  ; thisNote++) {//roar - katy perry

        currentMillis5 = millis();

        if (currentMillis5 - previousMillis5 >= interval5) {
          // save the last time you blinked the LED
          previousMillis5 = currentMillis5;

          // if the LED is off turn it on and vice-versa:
          if (ledState5 == LOW) {
            ledState5 = HIGH;
          } else {
            ledState5 = LOW;
          }



          digitalWrite(LEDs[n], ledState5);
          digitalWrite(LEDs[n + 5], ledState5);


        }
        int noteDuration6 = 1000 / noteDurations6[thisNote];
        tone(speakerPin, melody6[thisNote], noteDuration6);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration6 * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
        if (thisNote == 27) {
          for (int a = 0; a < 6; a++) {
            digitalWrite(LEDs[a], LOW);
          }
        }
      }

    }

    else if (randNumber == 1) {
      for (int k = 0; k < 2; k++) {
        digitalWrite(redLED1, HIGH);
        delay(500);
        digitalWrite(redLED1, LOW);
        delay(500);

      }
      for (int thisNote = 0; thisNote < 22; thisNote++) {//despacito

        currentMillis6 = millis();

        if (currentMillis6 - previousMillis6 >= interval6) {
          // save the last time you blinked the LED
          previousMillis6 = currentMillis6;

          // if the LED is off turn it on and vice-versa:
          if (ledState6 == LOW) {
            ledState6 = HIGH;
          } else {
            ledState6 = LOW;
          }
        }



        digitalWrite(LEDs[p], ledState6);

        int noteDuration1 = 1000 / noteDurations1[thisNote];
        tone(8, melody1[thisNote], noteDuration1);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration1 * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
        if (thisNote == 21) {

          digitalWrite(LEDs[p], LOW);

        }

      }
    }
  }
}
