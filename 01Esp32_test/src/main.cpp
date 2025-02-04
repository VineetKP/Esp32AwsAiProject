#include <Arduino.h>

// put function declarations here:
#define LED_BUILTIN 2

void setup() {
  // put your setup code here, to run once:
  // int result = myFunction(2, 3);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
}
