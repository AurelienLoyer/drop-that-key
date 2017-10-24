#include "azertykeyboard.h"

void setup(){
  
  // ACTIVE OR NOT HACK
  pinMode(14, INPUT);
    
  if(digitalRead(14) == HIGH && 0){
    delay(500);
  }else {
     
    // Begining the Keyboard stream
    Keyboard.begin();
  
    // Wait 500ms
    delay(1000);
  
    delay(1000);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(' ');
    Keyboard.releaseAll();

    delay(1000);
    Keyboard.print(F("terminal"));
  
    delay(500);
    typeKey(KEY_RETURN);
  
    delay(1000);
    Keyboard.print(F("osascript "));
    typeKey('0x23|SHIFT');
    Keyboard.print(F("e 'set volume 7'"));
  
    delay(500);
    typeKey(KEY_RETURN);
  
    delay(500);
    Keyboard.print(F("open https://rickrolled.fr/"));
  
    delay(500);
    typeKey(KEY_RETURN);
  
    // Ending stream
    Keyboard.end();
  }
}


void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}


/* Unused endless loop */
void loop() {}
