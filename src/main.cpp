#include <Arduino.h>
#include <OneButton.h>

#define LED1_PIN 2
#define LED2_PIN 4
#define BUTTON_PIN 0

OneButton button(BUTTON_PIN, true);

bool led1State = false;
bool led2State = false;
bool blinkMode = false;
int currentLed = 1; // 1 = LED1, 2 = LED2

void handleClick() {
  blinkMode = false; 
  if (currentLed == 1) {
    led1State = !led1State;
    digitalWrite(LED1_PIN, led1State ? HIGH : LOW);
  } else {
    led2State = !led2State;
    digitalWrite(LED2_PIN, led2State ? HIGH : LOW);
  }
}

void handleDoubleClick() {
  blinkMode = false;
  currentLed = (currentLed == 1) ? 2 : 1; // Chuyển đổi LED điều khiển
}

void handleLongPressStart() {
  blinkMode = true;
}

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);

  button.attachClick(handleClick);
  button.attachDoubleClick(handleDoubleClick);
  button.attachLongPressStart(handleLongPressStart);
}

void loop() {
  button.tick();

  if (blinkMode) {
    int pin = (currentLed == 1) ? LED1_PIN : LED2_PIN;
    digitalWrite(pin, HIGH);
    delay(200);
    digitalWrite(pin, LOW);
    delay(200);
  }
}
