#include <EEPROM.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "SONGS.h"
#include "ACTIONS.h"

#define maintenanceLED 12

#define switchPIN 13

LiquidCrystal_I2C lcd(0x27,16,2);

int level = 0;
int current_index = 0; // current level

bool can_read = false; // disable / enable input
int last_switch;

void lightRED(){
   if (difficulty == 2) soundRED(shortSound);
      else if (difficulty == 1) soundRED(mediumSound);
      else soundRED(longSound);
}

void lightBLUE(){
   if (difficulty == 2) soundBLUE(shortSound);
      else if (difficulty == 1) soundBLUE(mediumSound);
      else soundBLUE(longSound);
}

void lightGREEN(){
   if (difficulty == 2) soundGREEN(shortSound);
      else if (difficulty == 1) soundGREEN(mediumSound);
      else soundGREEN(longSound);
}

void lightYELLOW(){
   if (difficulty == 2) soundYELLOW(shortSound);
      else if (difficulty == 1) soundYELLOW(mediumSound);
      else soundYELLOW(longSound);
}

void show_Patern(){ // repeats the pattern that was buit until current level

    current_index = 1;

    while (current_index <= level)
    {
        if (EEPROM.read(current_index) == 0) lightRED();
        if (EEPROM.read(current_index) == 1) lightGREEN();
        if (EEPROM.read(current_index) == 2) lightBLUE();
        if (EEPROM.read(current_index) == 3) lightYELLOW();

        delay(250);

        current_index++;
    }

    current_index = 0;
}

void choose_Next_Number(){

    can_read = false;

    digitalWrite(maintenanceLED, HIGH);

    int next = random(4);
    level++;
    EEPROM.write(level, next);

    current_index = 0;

    show_Patern();

    delay(500);

    updateDisplay();
    digitalWrite(maintenanceLED, LOW);
    can_read = true;
}

void end_Game(){
    digitalWrite(maintenanceLED, HIGH);
    delay(1000);

    level = 0;
    current_index = 0;

    choose_Next_Number();
}

void reset(){
    level = 0;
    current_index = 0;
}

void changeDif(){
  if (difficulty == 2)
    difficulty = 0;
  else difficulty++;

  updateDisplay();
}

void check_buttons(){
    int readingRED = 0, readingGREEN = 0, readingBLUE = 0, readingYELLOW = 0;

    int value = analogRead(A0);
    if (value <= 100) { changeDif(); }
    else if (value > 100 && value < 600) { readingRED = 1; } 
    else if (value >= 600 && value < 700) { readingGREEN = 1; } 
    else if (value >= 700 && value < 800) { readingBLUE = 1; }
    else if (value >= 800 && value < 1000) { readingYELLOW = 1; }

    Serial.println(value);

    if (readingRED == 1){ 
        lightRED();

        current_index++;

        if (EEPROM.read(current_index) != 0) end_Game();
        if (current_index == level) choose_Next_Number();

        delay(150);

        return;
    }

    if (readingGREEN == 1){
        lightGREEN();

        current_index++;

        if (EEPROM.read(current_index) != 1) end_Game();
        if (current_index == level) choose_Next_Number();

        delay(150);

        return;
    }

    if (readingBLUE == 1){
        lightBLUE();
      
        current_index++;

        if (EEPROM.read(current_index) != 2) end_Game();
        if (current_index == level) choose_Next_Number();

        delay(150);

        return;
    }

    if (readingYELLOW == 1){
        lightYELLOW();

        current_index++;

        if (EEPROM.read(current_index) != 3) end_Game();
        if (current_index == level) choose_Next_Number();

        delay(150);

        return;
    }
}

void updateDisplay(){
    lcd.init();
    
    lcd.setCursor(0,0);
    lcd.print("Score:");
    lcd.setCursor(10,0);
    lcd.print("Mode:");

    lcd.setCursor(6,0);
    lcd.print(level);
    lcd.setCursor(15,0);
    lcd.print(digitalRead(switchPIN)); 

    lcd.setCursor(2,1);
    lcd.print("Difficulty:");
    lcd.setCursor(13,1);

    if (difficulty == 0) lcd.print("E");
    else if (difficulty == 1) lcd.print("M");
    else if (difficulty == 2) lcd.print("H");
}

void setup() {
    Serial.begin(9600);

    pinMode(ledRED, OUTPUT);
    pinMode(ledGREEN, OUTPUT);
    pinMode(ledBLUE, OUTPUT);
    pinMode(ledYELLOW, OUTPUT);

    pinMode(maintenanceLED, OUTPUT);

    last_switch = 1;
    
    lcd.init();// initialize the lcd 
    lcd.init();
    // Print a message to the LCD.
    lcd.backlight();
    
    updateDisplay();
}

void loop() {
    int switchValue = digitalRead(switchPIN);

    if (last_switch != switchValue){
        if (last_switch == 0)
            choose_Next_Number();
        else if (last_switch == 1) reset();
        
        last_switch = switchValue;
        updateDisplay();
    }

    if (switchValue == 1){
        if (can_read)
            check_buttons();
    } else {
      int readingRED = 0, readingGREEN = 0, readingBLUE = 0, readingYELLOW = 0;

      int value = analogRead(A0);
      if (value < 400) { readingRED = 1; } 
      else if (value >= 400 && value < 600) { readingGREEN = 1; } 
      else if (value >= 600 && value < 700) { readingBLUE = 1; }
      else if (value >= 700 && value < 1000) { readingYELLOW = 1; }

      if (readingRED == 1) song1();
      if (readingGREEN == 1) song2();
      if (readingBLUE == 1) song3();
      if (readingYELLOW == 1) song4();
    }
}