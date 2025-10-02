#include <Arduino.h>

#define LED1_PIN 2  
#define LED2_PIN 4   

bool ledState1 = false;
bool ledState2 = false;
bool blinking = false;
int currentLed = 1;   

void toggleLed() {
  blinking = false;
  if (currentLed == 1) {
    ledState1 = !ledState1;
    digitalWrite(LED1_PIN, ledState1 ? HIGH : LOW);
  } else {
    ledState2 = !ledState2;
    digitalWrite(LED2_PIN, ledState2 ? HIGH : LOW);
  }
  Serial.print("Toggled LED ");
  Serial.println(currentLed);
}

void switchLed() {
  blinking = false;
  currentLed = (currentLed == 1) ? 2 : 1;
  Serial.print("Chuyển sang điều khiển LED ");
  Serial.println(currentLed);
}

void startBlinking() {
  blinking = true;
  Serial.print("Bắt đầu nhấp nháy LED ");
  Serial.println(currentLed);
}

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  Serial.begin(115200);

  Serial.println("===== Hướng dẫn =====");
  Serial.println("Gõ số và Enter trong Serial Monitor:");
  Serial.println("1: Bật/tắt LED");
  Serial.println("2: Chuyển LED1 <-> LED2");
  Serial.println("3: Nhấp nháy LED");
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    if (cmd == '1') toggleLed();
    else if (cmd == '2') switchLed();
    else if (cmd == '3') startBlinking();
  }


  if (blinking) {
    if (currentLed == 1) {
      digitalWrite(LED1_PIN, HIGH);
      delay(200);
      digitalWrite(LED1_PIN, LOW);
      delay(200);
    } else {
      digitalWrite(LED2_PIN, HIGH);
      delay(200);
      digitalWrite(LED2_PIN, LOW);
      delay(200);
    }
  }
}
