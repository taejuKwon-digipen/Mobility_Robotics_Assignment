const int LED_PIN = 13;
const int BUTTON_PIN = 2;
const unsigned long DEBOUNCE_DELAY = 50; // ms

int lastReading = HIGH;       // 직전 루프에서 읽은 원시(raw) 값, 풀업이라 평소엔 HIGH
int buttonState = HIGH;       // 디바운싱을 거쳐 확정된 버튼 상태
bool ledState = false;
unsigned long lastDebounceTime = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // 내부 풀업 사용
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  // 원시 값이 바뀔 때마다(채터링 포함) 안정 시점을 다시 기록
  if (reading != lastReading) {
    lastDebounceTime = millis();
  }

  // 마지막 변화 시점으로부터 DEBOUNCE_DELAY(ms) 동안 값이 안정적으로 유지됐을 때만 진짜 상태로 확정
  if (millis() - lastDebounceTime > DEBOUNCE_DELAY) {
    if (reading != buttonState) {
      buttonState = reading;

      // 확정된 상태가 눌림(LOW)으로 바뀐 순간에만 토글 (뗄 때는 반응하지 않음)
      if (buttonState == LOW) {
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState ? HIGH : LOW);
        Serial.println(ledState ? "Button pressed -> LED ON" : "Button pressed -> LED OFF");
      }
    }
  }

  lastReading = reading;
}
