#include "ACTIONS.h"

void soundRED(lengthSound type){
    digitalWrite(ledRED, HIGH);
    tone(buzzer, 44); // note C in Hz 261
    
    if (type == shortSound) delay(50); 
      else if (type == mediumSound)delay(300);
      else delay(500);

    noTone(buzzer);
    digitalWrite(ledRED, LOW);
}

void soundGREEN(lengthSound type){
    digitalWrite(ledGREEN, HIGH);
    tone(buzzer, 330); // note D in Hz  
  
    if (type == shortSound) delay(50);
      else if (type == mediumSound)delay(300);
      else delay(500);

    noTone(buzzer);
    digitalWrite(ledGREEN, LOW);
}

void soundBLUE(lengthSound type){
    digitalWrite(ledBLUE, HIGH);
    tone(buzzer, 784); // note E in Hz  
  
    if (type == shortSound) delay(50); 
      else if (type == mediumSound) delay(300);
      else delay(500);

    noTone(buzzer);
    digitalWrite(ledBLUE, LOW);
}

void soundYELLOW(lengthSound type){
    digitalWrite(ledYELLOW, HIGH);
    tone(buzzer, 1397); // note F in Hz
    
    if (type == shortSound) delay(50);
      else if (type == mediumSound) delay(300); 
      else delay(500);
    
    noTone(buzzer);
    digitalWrite(ledYELLOW, LOW);
}