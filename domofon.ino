#include <Keypad.h>
int buzzPin= 7; // I/O-pin from buzzer connects here digital
const int wpm = 20; // Morse speed in WPM
const int dotL = 1200/wpm; // Calculated dot-length
const int dashL = 3*dotL; // Dash = 3 x dot
const int sPause = dotL; // Symbol pause = 1 dot
const int lPause = dashL; // Letter pause = 3 dots
const int wPause = 7*dotL; // Word pause = 7 dots
const byte ROWS = 4; 
const byte COLS = 4; 
//Change the following pins your yours keypad pinout!
byte rowPins[ROWS] = {22, 23, 24, 25};
byte colPins[COLS] = {26, 27 ,28 ,29};
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
int ledPinR = 8;
int ledPinG = 9; 
int ledPinB = 10;

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup()
{
pinMode(buzzPin,OUTPUT); // Set buzzer-pin as output
//Serial.begin(9600);
}
void loop()
{
  char pass = 'D';
 char key = keypad.getKey();
 if(!!key){
  dot();
  stop();
//  Serial.println(key); 
 }
 if(key == pass){
  dash();
  for (int i = 0 ; i <= 255; i++) {
      analogWrite(ledPinR, i);
      analogWrite(ledPinG, i);
      analogWrite(ledPinB, i);
      delay(1);
    }
  for(int i = 255; i>=0; i--){
   analogWrite(ledPinR, i);
   analogWrite(ledPinG, i);
   analogWrite(ledPinB, i);
   delay(1);
  }
  for (int i = 0 ; i <= 255; i++) {
      analogWrite(ledPinR, i);
      analogWrite(ledPinG, i);
      analogWrite(ledPinB, i);
      delay(1);
    }
  for(int i = 255; i>=0; i--){
   analogWrite(ledPinR, i);
   analogWrite(ledPinG, i);
   analogWrite(ledPinB, i);
   delay(1);
  }
  for (int i = 0 ; i <= 255; i++) {
      analogWrite(ledPinR, i);
      analogWrite(ledPinG, i);
      analogWrite(ledPinB, i);
      delay(1);
    }
  for(int i = 255; i>=0; i--){
   analogWrite(ledPinR, i);
   analogWrite(ledPinG, i);
   analogWrite(ledPinB, i);
   delay(1);
  }
  for (int i = 0 ; i <= 255; i++) {
      analogWrite(ledPinR, i);
      analogWrite(ledPinG, i);
      analogWrite(ledPinB, i);
      delay(1);
    }
  for(int i = 255; i>=0; i--){
   analogWrite(ledPinR, i);
   analogWrite(ledPinG, i);
   analogWrite(ledPinB, i);
   delay(1);
  }
  delay(1500);
  stop();
 }
}

void dot(){ 
digitalWrite(buzzPin, LOW); // Tone ON
delay(dotL); // Tone length
digitalWrite(buzzPin, HIGH); // Tone OFF
delay(sPause); // Symbol pause
return;
}

void dash(){
digitalWrite(buzzPin, LOW); // Tone ON
delay(dashL); // Tone length
digitalWrite(buzzPin, HIGH); // Tone OFF
delay(sPause); // Symbol pause
return;
}
void stop(){
digitalWrite(buzzPin, HIGH); // Tone OFF
delay(sPause); // Symbol pause
digitalWrite(buzzPin, LOW); // Tone ON
delay(dashL); // Tone length
return;
}
