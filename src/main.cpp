#include <Arduino.h>

#define LED1_PIN 2   
#define LED2_PIN 4   

bool ledState1 = false;
bool ledState2 = false;
bool blinking1 = false;
bool blinking2 = false;

void toggleLed1() {
  if (!blinking1) {
    ledState1 = !ledState1;
    digitalWrite(LED1_PIN, ledState1 ? HIGH : LOW);
    Serial.println(ledState1 ? "LED1 bật" : "LED1 tắt");
  }
}

void blinkLed1() {
  blinking1 = !blinking1;
  if (!blinking1) digitalWrite(LED1_PIN, LOW);
  Serial.println(blinking1 ? "LED1 nhấp nháy" : "LED1 dừng nháy");
}

void toggleLed2() {
  if (!blinking2) {
    ledState2 = !ledState2;
    digitalWrite(LED2_PIN, ledState2 ? HIGH : LOW);
    Serial.println(ledState2 ? "LED2 bật" : "LED2 tắt");
  }
}

void blinkLed2() {
  blinking2 = !blinking2;
  if (!blinking2) digitalWrite(LED2_PIN, LOW);
  Serial.println(blinking2 ? "LED2 nhấp nháy" : "LED2 dừng nháy");
}

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  Serial.begin(115200);

  Serial.println("===== Hướng dẫn =====");
  Serial.println("Serial Monitor:");
  Serial.println(" - '1' : LED1 bật/tắt");
  Serial.println(" - '2' : LED1 nhấp nháy/dừng nháy");
  Serial.println(" - 'a' : LED2 bật/tắt");
  Serial.println(" - 'b' : LED2 nhấp nháy/dừng nháy");
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    if (cmd == '1') toggleLed1();
    else if (cmd == '2') blinkLed1();
    else if (cmd == 'a') toggleLed2();
    else if (cmd == 'b') blinkLed2();
  }

  if (blinking1) {
    digitalWrite(LED1_PIN, HIGH);
    delay(200);
    digitalWrite(LED1_PIN, LOW);
    delay(200);
  }

  if (blinking2) {
    digitalWrite(LED2_PIN, HIGH);
    delay(200);
    digitalWrite(LED2_PIN, LOW);
    delay(200);
  }
}
