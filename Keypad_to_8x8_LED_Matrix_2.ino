#include <Keypad.h>

#include <Wire.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
/*

 This code is intended for use with the other code in the zip you downloaded running on another Arduino

 Now connect the SCL pins on both of the Arduinos together and do the same for the SDA pins as well

 */

//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  Wire.beginTransmission(8);    // transmit to device #8
  //Wire.write("x is ");       // sends five bytes
  Wire.write(customKey);      // sends one byte
  Wire.endTransmission();    // stop transmitting

  if (customKey){
    Serial.println(customKey);
  }
  delay(50);
}
