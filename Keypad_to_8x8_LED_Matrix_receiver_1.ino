//We must include these libraries

#include <Wire.h>

#include <LiquidCrystal.h>

#include <LedControl.h>

#include "Matrix.h"

/*
 Now we need Pin Numbers to work with.
 *** These pin numbers may not work with your hardware ***
 pin 4 is connected to the DataIn 
 pin 3 is connected to LOAD(CS)
 pin 2 is connected to the CLK 
 I am using only a single MAX7219.

 This code is intended for use with the other code in the zip you downloaded running on another Arduino
 
 Now connect the SCL pins on both of the Arduinos together and do the same for the SDA pins as well

 */
LedControl lc=LedControl(4,2,3,1);
/* set this variable from 1 to 15 for changing the screen brightness */
int ScreenIntensity=0;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,ScreenIntensity);
  /* and clear the display */
  lc.clearDisplay(0);
  
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  delay(300);
  Serial.print("Starting");
  delay(200);
  Serial.print(".");
  delay(200);
  Serial.print(".");
  delay(200);
  Serial.print(".");
  delay(200);
  Serial.print(".");
  delay(200);
  Serial.print(".");
  delay(200);
  Serial.print(".");
  delay(200);
  Serial.println(".");
  delay(200);
  Serial.println("Ready");
}

void n0() {
  lc.setRow(0,0,B01111110);
  lc.setRow(0,1,B11100111);
  lc.setRow(0,2,B11000011);
  lc.setRow(0,3,B11000011);
  lc.setRow(0,4,B11000011);
  lc.setRow(0,5,B11000011);
  lc.setRow(0,6,B11100111);
  lc.setRow(0,7,B01111110);
  
  delay(25);
}

void n1() {
  lc.setRow(0,0,B00011000);
  lc.setRow(0,1,B00111000);
  lc.setRow(0,2,B01111000);
  lc.setRow(0,3,B00011000);
  lc.setRow(0,4,B00011000);
  lc.setRow(0,5,B00011000);
  lc.setRow(0,6,B00011000);
  lc.setRow(0,7,B01111110);
  
  delay(25);
}

void n2() {
  lc.setRow(0,0,B00111100);
  lc.setRow(0,1,B01100110);
  lc.setRow(0,2,B11000011);
  lc.setRow(0,3,B00000111);
  lc.setRow(0,4,B01111100);
  lc.setRow(0,5,B11100000);
  lc.setRow(0,6,B11000000);
  lc.setRow(0,7,B11111111);
  
  delay(25);
}

void n3() {
  lc.setRow(0,0,B01111110);
  lc.setRow(0,1,B11100111);
  lc.setRow(0,2,B00000011);
  lc.setRow(0,3,B01111110);
  lc.setRow(0,4,B01111110);
  lc.setRow(0,5,B00000011);
  lc.setRow(0,6,B11100111);
  lc.setRow(0,7,B01111110);
  
  delay(25);
}

void n4() {
  lc.setRow(0,0,B00011110);
  lc.setRow(0,1,B00110110);
  lc.setRow(0,2,B01100110);
  lc.setRow(0,3,B11111111);
  lc.setRow(0,4,B11111111);
  lc.setRow(0,5,B00000110);
  lc.setRow(0,6,B00000110);
  lc.setRow(0,7,B00000110);
  
  delay(25);
}

void n5() {
  lc.setRow(0,0,B01111111);
  lc.setRow(0,1,B11100000);
  lc.setRow(0,2,B11000000);
  lc.setRow(0,3,B11100000);
  lc.setRow(0,4,B01111110);
  lc.setRow(0,5,B00000111);
  lc.setRow(0,6,B00000111);
  lc.setRow(0,7,B11111110);
  
  delay(25);
}

void n6() {
  lc.setRow(0,0,B01111110);
  lc.setRow(0,1,B11100011);
  lc.setRow(0,2,B11000000);
  lc.setRow(0,3,B11100000);
  lc.setRow(0,4,B11111110);
  lc.setRow(0,5,B11100111);
  lc.setRow(0,6,B11100111);
  lc.setRow(0,7,B01111110);
  
  delay(25);
}

void n7() {
  lc.setRow(0,0,B01111111);
  lc.setRow(0,1,B11000111);
  lc.setRow(0,2,B00000110);
  lc.setRow(0,3,B00001100);
  lc.setRow(0,4,B00011000);
  lc.setRow(0,5,B00110000);
  lc.setRow(0,6,B01100000);
  lc.setRow(0,7,B11000000);
  
  delay(25);
}

void n8() {
  lc.setRow(0,0,B01111110);
  lc.setRow(0,1,B11100111);
  lc.setRow(0,2,B11000011);
  lc.setRow(0,3,B01111110);
  lc.setRow(0,4,B01111110);
  lc.setRow(0,5,B11000011);
  lc.setRow(0,6,B11100111);
  lc.setRow(0,7,B01111110);
  
  delay(25);
}

void n9() {
  lc.setRow(0,0,B01111110);
  lc.setRow(0,1,B11100111);
  lc.setRow(0,2,B11000011);
  lc.setRow(0,3,B11111111);
  lc.setRow(0,4,B01111111);
  lc.setRow(0,5,B00000111);
  lc.setRow(0,6,B10000111);
  lc.setRow(0,7,B11111110);
  
  delay(25);
}

void A() {
  lc.setRow(0,0,B00111100);
  lc.setRow(0,1,B01100110);
  lc.setRow(0,2,B11000011);
  lc.setRow(0,3,B11100111);
  lc.setRow(0,4,B11111111);
  lc.setRow(0,5,B11100111);
  lc.setRow(0,6,B11000011);
  lc.setRow(0,7,B11000011);
  
  delay(25);
}

void B() {
  lc.setRow(0,0,B11111100);
  lc.setRow(0,1,B11100111);
  lc.setRow(0,2,B11000011);
  lc.setRow(0,3,B11111110);
  lc.setRow(0,4,B11111110);
  lc.setRow(0,5,B11000011);
  lc.setRow(0,6,B11100111);
  lc.setRow(0,7,B11111100);
  
  delay(25);
}

void C() {
  lc.setRow(0,0,B01111110);
  lc.setRow(0,1,B11100011);
  lc.setRow(0,2,B11000001);
  lc.setRow(0,3,B11000000);
  lc.setRow(0,4,B11000000);
  lc.setRow(0,5,B11000001);
  lc.setRow(0,6,B11100011);
  lc.setRow(0,7,B01111110);
  
  delay(25);
}

void D() {
  lc.setRow(0,0,B11111100);
  lc.setRow(0,1,B11101110);
  lc.setRow(0,2,B11000111);
  lc.setRow(0,3,B11000011);
  lc.setRow(0,4,B11000011);
  lc.setRow(0,5,B11000111);
  lc.setRow(0,6,B11101110);
  lc.setRow(0,7,B11111100);
  
  delay(25);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  //Serial.println(x);         // print the integer
  
  if(ScreenIntensity>15) {
    ScreenIntensity=15;
  }
  if(ScreenIntensity<0) {
    ScreenIntensity=0;
  }
  lc.setIntensity(0,ScreenIntensity);
  
  if(x!=0) {
    
    if(x==48) {
      n0();
      Serial.println("0");
    } else if(x==49) {
      n1();
      Serial.println("1");
    } else if(x==50) {
      n2();
      Serial.println("2");
    } else if(x==51) {
      n3();
      Serial.println("3");
    } else if(x==52) {
      n4();
      Serial.println("4");
    } else if(x==53) {
      n5();
      Serial.println("5");
    } else if(x==54) {
      n6();
      Serial.println("6");
    } else if(x==55) {
      n7();
      Serial.println("7");
    } else if(x==56) {
      n8();
      Serial.println("8");
    } else if(x==57) {
      n9();
      Serial.println("9");
    } else if(x==65) {
      A();
      Serial.println("A");
    } else if(x==66) {
      B();
      Serial.println("B");
    } else if(x==67) {
      C();
      Serial.println("C");
    } else if(x==68) {
      D();
      Serial.println("D");
    } else if(x==42) {
      ScreenIntensity--;
      Serial.print("Screen Brightness ");
      Serial.println(ScreenIntensity);
    } else if(x==35) {
      ScreenIntensity++;
      Serial.print("Screen Brightness ");
      Serial.println(ScreenIntensity);
    }
  }
}

void loop() {
  delay(100);
}
