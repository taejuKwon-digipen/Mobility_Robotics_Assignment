const int LED_PIN = 13;
const int BUTTON_PIN = 2;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // 내부 풀업 사용
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {   // 풀업이라 눌렸을 때 LOW
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Button Pressed -> LED ON");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Button Released -> LED OFF");
  }

  delay(20); // 시리얼 로그 너무 빨리 찍히는 것 방지용
}