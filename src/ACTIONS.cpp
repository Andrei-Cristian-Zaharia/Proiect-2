#include "ACTIONS.h"

void soundRED(lengthSound type){
    
    if (type == shortSound) {
        digitalWrite(ledRED, HIGH);
        delay(150);

        digitalWrite(ledRED, LOW);
    } else {
        digitalWrite(ledRED, HIGH);
        delay(500);
            
        digitalWrite(ledRED, LOW);
    }

    tone(buzzer, 261); // note C in Hz
}

void soundGREEN(lengthSound type){
    if (type == shortSound) {
        digitalWrite(ledGREEN, HIGH);
        delay(150);

        digitalWrite(ledGREEN, LOW);
    } else {
        digitalWrite(ledGREEN, HIGH);
        delay(500);
            
        digitalWrite(ledGREEN, LOW);
    }

    tone(buzzer, 293); // note D in Hz    
}

void soundBLUE(lengthSound type){
    if (type == shortSound) {
        digitalWrite(ledBLUE, HIGH);
        delay(150);

        digitalWrite(ledBLUE, LOW);
    } else {
        digitalWrite(ledBLUE, HIGH);
        delay(500);
            
        digitalWrite(ledBLUE, LOW);
    }

    tone(buzzer, 329); // note E in Hz  
}

void soundYELLOW(lengthSound type){
    if (type == shortSound) {
        digitalWrite(ledYELLOW, HIGH);
        delay(150);

        digitalWrite(ledYELLOW, LOW);
    } else {
        digitalWrite(ledYELLOW, HIGH);
        delay(500);
            
        digitalWrite(ledYELLOW, LOW);
    }

    tone(buzzer, 349); // note F in Hz
}