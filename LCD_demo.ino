/*===================================================================================================
                                            LCD DEMO
=====================================================================================================
Description:
  This program demonstrates various functions and methods available in the LiquidCrystal_I2C library, 
  including displaying text, toggling the backlight, and scrolling the display left and right.


Programmer:
  Felicity M. De Asis
  Shanna Dale R. Dela Torre
  Rhile L. Galpo

Date:
  10 Nov 2026
----------------------------------------------------------------------------------------------------*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// GPIOs
const uint8_t SDA_PIN = 21;
const uint8_t SCL_PIN = 22;

// LCD Configurations
const uint8_t LCD_ADDR = 0x27;   // try 0x3F if this doesn't work
const uint8_t LCD_COLS = 16;
const uint8_t LCD_ROWS = 2;

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

void setup() {
  Wire.begin(SDA_PIN, SCL_PIN);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // Diplay message
  lcd.clear();
  lcd.setCursor(0, 0);   // column 0, row 0
  lcd.print("Hello");
  lcd.setCursor(0, 1);   // column 0, row 1
  lcd.print("Felicity!");
  delay(2000);

  // Backlight Test
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Backlight OFF");
  delay(1000);
  lcd.noBacklight();
  delay(2000);

  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Backlight ON");
  lcd.backlight();
  delay(2000);


  // scroll-right
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("scroll");

  for(int i=0; i<6; i++){
    lcd.scrollDisplayRight();
    delay(500);
  }
  
  // scroll-left
  lcd.clear();
  lcd.setCursor(0,0);
  
  String msg = " 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16";
  lcd.print(msg);
  delay(2000);

  for(int i=0; i < msg.length()-16; i++){
    lcd.scrollDisplayLeft();
    delay(500);
  }
}