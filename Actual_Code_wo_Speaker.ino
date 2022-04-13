#include <FastLED.h>
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int  buttonPin2 = 3;    // the pin that the pushbutton is attached to
const int  buttonPin3 = 4;    // the pin that the pushbutton is attached to

const int speaker = 7;       // the pin that the LED is attached to

const int ledPin = 13;       // the pin that the LED is attached to
const int ledPin2 = 12;       // the pin that the LED is attached to
const int ledPin3 = 11;       // the pin that the LED is attached to

const int dimintensity = 1;
const int brightintensity = 200;

unsigned long previousMS = 0;
unsigned long currentMS = 0;
unsigned long lastMS = 0;
const int off_switch = 5000;

#define NUM_LEDS 48
#define NUM_LEDS2 80
#define NUM_LEDS3 48
CRGB leds[NUM_LEDS];
CRGB leds2[NUM_LEDS2];
CRGB leds3[NUM_LEDS3];

const int tstrip1 = 625/NUM_LEDS;
const int tstrip2 = 625/NUM_LEDS2;
const int tstrip3 = 625/NUM_LEDS3;

const int rstrip1 = 255/NUM_LEDS;
const int rstrip2 = 255/NUM_LEDS2;
const int rstrip3 = 255/NUM_LEDS3;

// Variables will change:
int b1 = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

int b2 = 0;   // counter for the number of button presses
int buttonState2 = 0;         // current state of the button
int lastButtonState2 = 0;     // previous state of the button

int b3 = 0;   // counter for the number of button presses
int buttonState3 = 0;         // current state of the button
int lastButtonState3 = 0;     // previous state of the button

void setup() {
  FastLED.addLeds<WS2812, ledPin, GRB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812, ledPin2, GRB>(leds2, NUM_LEDS2);
  FastLED.addLeds<WS2812, ledPin3, GRB>(leds2, NUM_LEDS3);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 250);
  FastLED.clear();
  FastLED.show();

  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the button pin as a input:
  pinMode(buttonPin2, INPUT);
  // initialize the button pin as a input:
  pinMode(buttonPin3, INPUT);

  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the LED as an output:
  pinMode(ledPin2, OUTPUT);
  // initialize the LED as an output:
  pinMode(ledPin3, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  unsigned long currentMS = millis();
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  // compare the buttonState to its previous state

  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      previousMS = currentMS;
      b1++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(b1);
    } 
    else {
      Serial.println("off");  // if the current state is LOW then the button went from on to off:    
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
      previousMS = currentMS;
      b2++;
      Serial.println("on");
      Serial.print("number of button2 pushes: ");
      Serial.println(b2);
    } 
    else {
      Serial.println("off");  // if the current state is LOW then the button went from on to off:
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState2 = buttonState2;

  if (buttonState3 != lastButtonState3) {
    // if the state has changed, increment the counter
    if (buttonState3 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      previousMS = currentMS;
      b3++;
      Serial.println("on");
      Serial.print("number of button3 pushes: ");
      Serial.println(b3);
    } 
    else {
      Serial.println("off");  // if the current state is LOW then the button went from on to off: 
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState3 = buttonState3;

  if (currentMS - previousMS > off_switch) {
    b1 = 0;
    b2 = 0;
    b3 = 0;
  }

  Serial.println(String(b1) + " " + String(b2) + " " + String(b3));

  if (b1 > 0 and b2 > 0){
    brightrainbow1();    
    brightrainbow2();
    brightrainbow3();
  }        
  else {
    if (b3 != 0 and b2 == 0 and b1 == 0) {
      dimrainbow2();
      dimrainbow3();      
      yellow1(); 
    }
    else {
      if ((b1 > 0 or b2 > 0) and (b1 == 0 or b2 == 0)){
        dimrainbow1();
        dimrainbow2();
        dimrainbow3();
      }
      else {
        nthg2();
        nthg3();
        yellow1();
        }
      } 
    }
  }

void btn1(){
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      previousMS = currentMS;
      b1++;
      Serial.println("on");
      Serial.print("number of b1 pushes: ");
      Serial.println(b1);
    } 
    else {
        Serial.println("off");  // if the current state is LOW then the button went from on to off:
       
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;  
}
void btn2(){
  if (buttonState2 != lastButtonState2) {
    // if the state has changed, increment the counter
    if (buttonState2 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      previousMS = currentMS;
      b2++;
      Serial.println("on");
      Serial.print("number of b2 pushes: ");
      Serial.println(b2);
    } 
    else {
        Serial.println("off");  // if the current state is LOW then the button went from on to off:
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState2 = buttonState2;
}
void btn3(){
  if (buttonState3 != lastButtonState3) {
    // if the state has changed, increment the counter
    if (buttonState3 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      previousMS = currentMS;
      b3++;
      Serial.println("on");
      Serial.print("number of b3 pushes: ");
      Serial.println(b3);
    } 
    else {
        Serial.println("off");  // if the current state is LOW then the button went from on to off: 
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState3 = buttonState3;
}

void nthg2(){
  digitalWrite(ledPin2, LOW);
  for (int i=0; i<NUM_LEDS2; i++){
    leds2[i] = CRGB(0, 0, 0);
    FastLED.setBrightness(1);
    FastLED.show();
    }
}
void nthg3(){
  digitalWrite(ledPin3, LOW);    
  for (int i=0; i<NUM_LEDS3; i++){
    leds3[i] = CRGB(0, 0, 0);
    FastLED.setBrightness(1);
    FastLED.show();
  }  
}
void yellow1(){
  digitalWrite(ledPin, HIGH);
  for (int i=1; i<NUM_LEDS; i++){
    leds[i] = CRGB(255,255,0);
    FastLED.setBrightness(4);  //if so, change the state of the LED.  Uses a neat trick to change the state
    FastLED.show();
  }
}
void dimrainbow1(){
  digitalWrite(ledPin, HIGH);
  for (int i=1; i<NUM_LEDS; i++){
    btn1();
    btn2();
    btn3();
    leds[i] = CRGB(0, 255 - rstrip1*i, rstrip1*i );
    FastLED.setBrightness(dimintensity);
    FastLED.show();
    delay(tstrip1);
    }
  // Turn lights from blue to magenta from right to left 
  for (int i=1; i<NUM_LEDS; i++){
    btn1();
    btn2();
    btn3();
    leds[i] = CRGB(5*rstrip1,0 , 255-5*rstrip1);
    FastLED.setBrightness(dimintensity);
    FastLED.show();
    delay(tstrip1);
    }
    
}
void dimrainbow2(){
  digitalWrite(ledPin2, HIGH);
  for (int i=1; i<NUM_LEDS2; i++){
    btn1();
    btn2();
    btn3();
    leds2[i] = CRGB(0, 255 - rstrip2*i, rstrip2*i );
    FastLED.setBrightness(dimintensity);
    FastLED.show();
    delay(tstrip2);
    }
  // Turn lights from blue to magenta from right to left 
  for (int i=1; i<NUM_LEDS2; i++){
    btn1();
    btn2();
    btn3();
    leds2[i] = CRGB(rstrip2*i,0 , 255-rstrip2*i);
    FastLED.setBrightness(dimintensity);
    FastLED.show();
    delay(tstrip2);
    }
}
void dimrainbow3(){
  digitalWrite(ledPin3, HIGH);
  for (int i=0; i<NUM_LEDS3; i++){
    btn1();
    btn2();
    btn3();
    leds3[i] = CRGB(0, 255 - rstrip3*i, rstrip3*i );
    FastLED.setBrightness(dimintensity);
    FastLED.show();
    delay(tstrip3);
    }
  // Turn lights from blue to magenta from i=0 to i=NUM_LEDS3 
  for (int i=0; i<NUM_LEDS3; i++){
    btn1();
    btn2();
    btn3();
    leds3[i] = CRGB(rstrip3*i,0 , 255-rstrip3*i);
    FastLED.setBrightness(dimintensity);
    FastLED.show();
    delay(tstrip3);
    }
}
void brightrainbow1(){
  digitalWrite(ledPin, HIGH);    
  for (int i=1; i<NUM_LEDS; i++){
    btn1();
    btn2();
    btn3();
    leds[i] = CRGB(0, 255 - rstrip1*i, rstrip1*i );
    FastLED.setBrightness(brightintensity);
    FastLED.show();
    delay(tstrip1);
    }
  // Turn lights from blue to magenta from right to left 
  for (int i=1; i<NUM_LEDS; i++){
    btn1();
    btn2();
    btn3();
    leds[i] = CRGB(rstrip1*i,0 , 255-rstrip1*i);
    FastLED.setBrightness(brightintensity);
    FastLED.show();
    delay(tstrip1);
    }
}
void brightrainbow2(){
  digitalWrite(ledPin2, HIGH);    
  for (int i=1; i<NUM_LEDS2; i++){
    btn1();
    btn2();
    btn3();
    leds2[i] = CRGB(0, 255 - rstrip2*i, rstrip2*i );
    FastLED.setBrightness(brightintensity);
    FastLED.show();
    delay(tstrip2);
    }
  // Turn lights from blue to magenta from right to left 
  for (int i=1; i<NUM_LEDS2; i++){
    btn1();
    btn2();
    btn3();
    leds2[i] = CRGB(rstrip2*i,0 , 255-rstrip2*i);
    FastLED.setBrightness(brightintensity);
    FastLED.show();
    delay(tstrip2);
    }
}
void brightrainbow3(){  
  digitalWrite(ledPin3, HIGH);    
  for (int i=1; i<NUM_LEDS3; i++){
    btn1();
    btn2();
    btn3();
    leds3[i] = CRGB(0, 255 - rstrip3*i, rstrip3*i );
    FastLED.setBrightness(brightintensity);
    FastLED.show();
    delay(tstrip3);
    }
  // Turn lights from blue to magenta from right to left 
  for (int i=1; i<NUM_LEDS3; i++){
    leds3[i] = CRGB(rstrip3*i,0 , 255-rstrip3*i);
    FastLED.setBrightness(brightintensity);
    FastLED.show();
    delay(tstrip3);
    }
}