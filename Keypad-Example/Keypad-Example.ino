#include "Keypad.h"

const byte rows = 3;
const byte cols = 4;
char keys[rows][cols] = {
  { '0', '8', '5', '2' },
  { '#', '9', '6', '3' },
  { '*', '7', '4', '1' }
};
byte row_pins[rows] = { 7, 8, 6 };
byte col_pins[cols] = { 5, 4, 3, 2 };

Keypad keypad = Keypad(makeKeymap(keys), row_pins, col_pins, rows, cols);

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  char key = keypad.getKey();
  if (key != NO_KEY)
    Serial.println(key);
}