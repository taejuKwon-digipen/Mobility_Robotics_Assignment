const int LED_PIN = 13;
const int BUTTON_PIN = 2;

int lastButtonState = HIGH;   // 풀업이라 평소 상태가 HIGH
bool ledState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // 내부 풀업 사용
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  // 풀업이라 눌렸을 때 LOW. 이전엔 HIGH, 지금 LOW인 순간만 반응
  if (buttonState == LOW && lastButtonState == HIGH) {
    delay(20);
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    Serial.println(ledState ? "Button Pressed -> LED ON" : "Button Pressed -> LED OFF");
  }

  lastButtonState = buttonState;
  delay(20);
}
