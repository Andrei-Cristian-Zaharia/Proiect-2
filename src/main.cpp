#include "ACTIONS.h"
#include "SONGS.h"
#include <EEPROM.h>

#define buttonRED 2
#define buttonGREEN 3
#define buttonBLUE 4
#define buttonYELLOW 5

#define maintenanceLED 12

#define switchPIN 13

int level = 0;
int current_index = 0; // current level

bool can_read = false; // disable / enable input

void show_Patern(){ // repeats the pattern that was buit until current level

    current_index = 1;

    while (current_index <= level)
    {
        if (EEPROM.read(current_index) == 0) soundRED(longSound);

        if (EEPROM.read(current_index) == 1) soundGREEN(longSound);

        if (EEPROM.read(current_index) == 2) soundBLUE(longSound);

        if (EEPROM.read(current_index) == 3) soundYELLOW(longSound);

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

void check_buttons(){
    int readingRED = 0, readingGREEN = 0, readingBLUE = 0, readingYELLOW = 0;

    int value = analogRead(A0);
    if (value < 400) {
        Serial.println("Button1");
        readingRED = 1;
    } else if (value >= 400 && value < 600) {
        Serial.println("Button2");
        readingGREEN = 1;
    } else if (value >= 600 && value < 700) {
        Serial.println("Button3");
        readingBLUE = 1;
    } else if (value >= 700 && value < 1000) {
        Serial.println("Button4");
        readingYELLOW = 1;
    }

    if (readingRED == 1){
        soundRED(shortSound);

        current_index++;

        if (EEPROM.read(current_index) != 0) end_Game();
        if (current_index == level) choose_Next_Number();

        delay(250);

        return;
    }

    if (readingGREEN == 1){
        soundGREEN(shortSound);

        current_index++;

        if (EEPROM.read(current_index) != 1) end_Game();
        if (current_index == level) choose_Next_Number();

        delay(250);

        return;
    }

    if (readingBLUE == 1){
        soundBLUE(shortSound);

        current_index++;

        if (EEPROM.read(current_index) != 2) end_Game();
        if (current_index == level) choose_Next_Number();

        delay(250);

        return;
    }

    if (readingYELLOW == 1){
        soundYELLOW(shortSound);

        current_index++;

        if (EEPROM.read(current_index) != 3) end_Game();
        if (current_index == level) choose_Next_Number();

        delay(250);

        return;
    }
}

void setup() {
    Serial.begin(9600);

    pinMode(buttonRED, INPUT);
    pinMode(buttonGREEN, INPUT);
    pinMode(buttonBLUE, INPUT);
    pinMode(buttonYELLOW, INPUT);

    pinMode(ledRED, OUTPUT);
    pinMode(ledGREEN, OUTPUT);
    pinMode(ledBLUE, OUTPUT);
    pinMode(ledYELLOW, OUTPUT);

    pinMode(maintenanceLED, OUTPUT);

    choose_Next_Number();
}

void loop() {
    int switchValue = digitalRead(switchPIN);

    if (switchValue == 1){
        if (can_read)
            check_buttons();
    } else {
        int readingRED = 0, readingGREEN = 0, readingBLUE = 0, readingYELLOW = 0;

        int value = analogRead(A0);
    if (value < 400) {
        Serial.println("Button1");
        readingRED = 1;
    } else if (value >= 400 && value < 600) {
        Serial.println("Button2");
        readingGREEN = 1;
    } else if (value >= 600 && value < 700) {
        Serial.println("Button3");
        readingBLUE = 1;
    } else if (value >= 700 && value < 1000) {
        Serial.println("Button4");
        readingYELLOW = 1;
    }

        if (readingRED == 1) song1();
    }
}