#include "ACTIONS.h"
#include <EEPROM.h>

#define buttonRED 2
#define buttonGREEN 3
#define buttonBLUE 4
#define buttonYELLOW 5

#define maintenanceLED 12

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

    int next = random(2);
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
    int readingRED = digitalRead(buttonRED);
    int readingGREEN = digitalRead(buttonGREEN);
    int readingBLUE =  digitalRead(buttonBLUE);
    int readingYELLOW = digitalRead(buttonYELLOW);

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
}

void loop() {
    if (can_read)
        check_buttons();
}