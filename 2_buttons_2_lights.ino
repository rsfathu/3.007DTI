#include <FastLED.h>
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int  buttonPin2 = 4;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to
const int ledPin2 = 12;       // the pin that the LED is attached to

#define NUM_LEDS 3
#define NUM_LEDS2 3
CRGB leds[NUM_LEDS];
CRGB leds2[NUM_LEDS2];


// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

int buttonPushCounter2 = 0;   // counter for the number of button presses
int buttonState2 = 0;         // current state of the button
int lastButtonState2 = 0;     // previous state of the button

void setup() {
  FastLED.addLeds<WS2812, ledPin, GRB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812, ledPin2, GRB>(leds2, NUM_LEDS2);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 250);
  FastLED.clear();
  FastLED.show();

  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the button pin as a input:
  pinMode(buttonPin2, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the LED as an output:
  pinMode(ledPin2, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);

}


void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;

  if (buttonState2 != lastButtonState2) {
    // if the state has changed, increment the counter
    if (buttonState2 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter2++;
      Serial.println("on");
      Serial.print("number of button2 pushes: ");
      Serial.println(buttonPushCounter2);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState2 = buttonState2;

  // turns on the LED every four button pushes by checking the modulo of the
  // button push counter. the modulo function gives you the remainder of the
  // division of two numbers:
  if (buttonPushCounter + buttonPushCounter2 == 0) {
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin, LOW);
    
    for (int i=1; i<NUM_LEDS; i++){
      leds[i] = CRGB(128,128,0);
      FastLED.setBrightness(5*i);  //if so, change the state of the LED.  Uses a neat trick to change the state
      FastLED.show();
    }  
    for (int i=1; i<NUM_LEDS2; i++){
      leds2[i] = CRGB(0,0,0);
      FastLED.setBrightness(0);  //if so, change the state of the LED.  Uses a neat trick to change the state
      FastLED.show();
    }
  }  
  else {
    if (buttonPushCounter + buttonPushCounter2 == 1) {
      digitalWrite(ledPin, HIGH);
      for (int i=1; i<NUM_LEDS; i++){
        leds[i] = CRGB(255 - 128*i, 128, 128*i );
        FastLED.setBrightness(0.5*i);  //if so, change the state of the LED.  Uses a neat trick to change the state
        FastLED.show();
      }
      
      digitalWrite(ledPin2, HIGH);
      for (int i=1; i<NUM_LEDS2; i++){
        leds2[i] = CRGB(255 - 128*i, 128, 128*i );
        FastLED.setBrightness(0.5*i);  //if so, change the state of the LED.  Uses a neat trick to change the state
        FastLED.show();
      }
    } 
    else {
      digitalWrite(ledPin, HIGH);    
      for (int i=1; i<NUM_LEDS; i++){
        leds[i] = CRGB(255 - 128*i, 128, 128*i );
        FastLED.setBrightness(5*i);  //if so, change the state of the LED.  Uses a neat trick to change the state
        FastLED.show();
      }
      
      digitalWrite(ledPin2, HIGH);    
      for (int i=1; i<NUM_LEDS2; i++){
        leds2[i] = CRGB(255 - 128*i, 128, 128*i );
        FastLED.setBrightness(5*i);  //if so, change the state of the LED.  Uses a neat trick to change the state
        FastLED.show();
      }
    }
  }

}
