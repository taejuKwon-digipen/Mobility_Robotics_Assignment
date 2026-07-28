const int LED_PIN[4] = {13, 12, 11, 10};  // LED 핀 번호 배열 (index 0 = LED1)
const int BUTTON_PIN = 2;

int state = 0;                // 4비트로 표현되는 LED 상태값 (0~15)
bool inputMode = false;       // 지금 시리얼 입력을 받는 중인지
int lastButtonState = HIGH;   // 풀업이라 평소엔 HIGH

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(LED_PIN[i], OUTPUT);
  }
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // 내부 풀업 사용
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  // 버튼이 방금 눌린 순간만 감지
  if (buttonState == LOW && lastButtonState == HIGH) {
    delay(20); // 디바운싱
    if (digitalRead(BUTTON_PIN) == LOW) { // 딜레이 후 다시 확인해서 진짜 눌림인지 검증
      inputMode = true;
      Serial.println("0~15까지의 정수를 입력해주세요");
    }
  }
  lastButtonState = digitalRead(BUTTON_PIN); // 딜레이 이후의 최신 상태로 갱신

  if (inputMode && Serial.available() > 0) {
    int input = Serial.parseInt();

    while (Serial.available() > 0) {
      Serial.read(); // 남은 버퍼 비우기 (엔터 때문에)
    }

    if (input >= 0 && input <= 15) {
      state = input;//int
      applyState(state);
      inputMode = false; // 처리 끝, 다음 버튼 누르기 전까진 입력 안 받음
    } else {
      Serial.println("0~15 사이 숫자만 입력해주세요.");
    }
  }
}

// state 값(0~15)을 받아서 4비트로 해석하고, 각 비트에 맞게 LED on off
void applyState(int value) {
  // 입력값을 "13 (0b1101)" 형태로 로그 출력
  Serial.print("Input: " + String(value) );
  Serial.print(" (0b");
  for (int i = 3; i >= 0; i--) //(MSB -> LSB)
  {
    Serial.print((value >> i) & 1);
  }
  Serial.println(")");

  // 비트 0번(LSB)부터 3번(MSB)까지 순서대로 각 LED에 반영
  for (int i = 0; i < 4; i++) {
    int bitValue = (value >> i) & 1; // i번째 비트만 추출 (0 또는 1)

    digitalWrite(LED_PIN[i], bitValue == 1 ? HIGH : LOW); // 비트가 1이면 ON, 0이면 OFF

    Serial.print("LED ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(bitValue == 1 ? "ON" : "OFF");
  }
}
