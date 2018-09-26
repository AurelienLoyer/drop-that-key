#include <TrinketKeyboard.h>

void setup() {
  TrinketKeyboard.begin();
  TrinketKeyboard.print(" https://slides.com/aurelienloyer/attention-hacker-fort ");

  delay(200);

  TrinketKeyboard.pressKey(0, 0x28);
  delay(10);

  TrinketKeyboard.pressKey(0, 0);
  delay(300);
}

void loop() {
}
