#ifndef ACTIONS_H
#define ACTIONS_H
#include <Arduino.h>

enum lengthSound { shortSound, longSound};

#define ledRED 8
#define ledGREEN 9
#define ledBLUE 10
#define ledYELLOW 11

#define buzzer 6

void soundRED(lengthSound type);
void soundGREEN(lengthSound type);
void soundBLUE(lengthSound type);
void soundYELLOW(lengthSound type);

#endif