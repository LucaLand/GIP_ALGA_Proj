/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2, tempoPrint = 2000;
#define powerVDD A3
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
bool lux = true;



void setupLCD() {
  //pinMode(A0, OUTPUT);
  //digitalWrite(A0, HIGH);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(powerVDD, OUTPUT);
  digitalWrite(powerVDD, HIGH);
  // Print a message to the LCD.
  //lcd.print("Stiamo Pariando!!");
  lcd.setCursor(0,0);
  lcd.print("Progetto A.L.G.A.");
  delay(tempoPrint);
  lcd.setCursor(0,0);
  lcd.print("A.L.G.A.        ");
  delay(tempoPrint);
}

void LCDPrintInfo(int temp, int luxTimeHours, int luxTimeMinutes, int luxTimeSeconds) {
  lcd.setCursor(8,0);
  lcd.print("Temp:");
  lcd.print(temp);
  lcd.print("C ");
  lcd.setCursor(0,1);
  lcd.print("Light:");
  lcd.print(luxTimeHours);
  lcd.print("h");
  lcd.print(luxTimeMinutes);
  lcd.print("m");
  lcd.print(luxTimeSeconds);
  lcd.print("s");
  lcd.print(" Ph:0");
}

void LCDPrintReset(){
   for(int i=0; i<3; i++){
    lcd.clear();
    lcd.print("RESET!");
    delay(300);
    lcd.clear();
    delay(200);
   }
}
