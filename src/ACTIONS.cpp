#include "ACTIONS.h"

void soundRED(lengthSound type){
    
    if (type == shortSound) {
        digitalWrite(ledRED, HIGH);
        tone(buzzer, 44); // note C in Hz 261

        delay(150);

        noTone(buzzer);

        digitalWrite(ledRED, LOW);
    } else {
        digitalWrite(ledRED, HIGH);
        tone(buzzer, 44); // note C in Hz 261

        delay(500);

        noTone(buzzer);
            
        digitalWrite(ledRED, LOW);
    }
}

void soundGREEN(lengthSound type){
    if (type == shortSound) {
        digitalWrite(ledGREEN, HIGH);
        tone(buzzer, 330); // note D in Hz  

        delay(150);

        noTone(buzzer);

        digitalWrite(ledGREEN, LOW);
    } else {
        digitalWrite(ledGREEN, HIGH);
        tone(buzzer, 330); // note D in Hz  

        delay(500);

        noTone(buzzer);
            
        digitalWrite(ledGREEN, LOW);
    }  
}

void soundBLUE(lengthSound type){
    if (type == shortSound) {
        digitalWrite(ledBLUE, HIGH);
        tone(buzzer, 784); // note E in Hz  

        delay(150);

        noTone(buzzer);

        digitalWrite(ledBLUE, LOW);
    } else {
        digitalWrite(ledBLUE, HIGH);
        tone(buzzer, 784); // note E in Hz  

        delay(500);

        noTone(buzzer);
            
        digitalWrite(ledBLUE, LOW);
    }
}

void soundYELLOW(lengthSound type){
    if (type == shortSound) {
        digitalWrite(ledYELLOW, HIGH);
        tone(buzzer, 1397); // note F in Hz

        delay(150);

        noTone(buzzer);

        digitalWrite(ledYELLOW, LOW);
    } else {
        digitalWrite(ledYELLOW, HIGH);
        tone(buzzer, 1397); // note F in Hz

        delay(500);

        noTone(buzzer);
            
        digitalWrite(ledYELLOW, LOW);
    }

}