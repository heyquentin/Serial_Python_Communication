#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h> // F Malpartida's NewLiquidCrystal library
#define I2C_ADDR 0x3F // Define I2C Address for controller
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7
#define BACKLIGHT 3

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup() {

// Switch on the backlight
lcd.setBacklightPin(BACKLIGHT,POSITIVE);
lcd.setBacklight(HIGH);

// Reset the display
lcd.begin(16, 2);
lcd.clear();
lcd.home();

Serial.begin(9600);

}
 
void loop() {
  while (Serial.available()) {
    lcd.begin(16,2);
    lcd.clear();
    lcd.home();
    //Serial.println("");
    //Serial.println("TL1");
    //Serial.println("TL2");
    while (Serial.available() > 0) {
      char c = Serial.read();
      lcd.write(c);
      Serial.print(c);
    }
  }
}
