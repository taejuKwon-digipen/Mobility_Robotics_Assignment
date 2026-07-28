// [목표1: 하드웨어-소프트웨어 연결] 13 = 보드의 실제 13번 디지털 핀 번호. 이 숫자가 코드와 회로를 잇는 연결고리.
const int LED_PIN = 13;
const int BLINK_INTERVAL_MS = 1000;

void setup() {
  // pinMode(pin, mode)
  // [목표2: GPIO 출력 설정] 13번 핀을 "신호를 내보내는 용도(OUTPUT)"로 지정
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600); // [목표4: 시리얼 디버깅] PC와 9600bps로 시리얼 통신 시작
}

void loop() {
  // digitalWrite(pin, HIGH/LOW)  -신호 on/off
  // [목표2: 주기적 신호 출력] 13번 핀에 전압을 걸어 LED ON
  digitalWrite(LED_PIN, HIGH);

  // println쓰는구나 진짜 c++기반이네
  Serial.println("LED ON"); // [목표4: 시리얼 디버깅] 현재 상태를 로그로 확인
  delay(BLINK_INTERVAL_MS); // [목표3: 지연 함수로 흐름 제어] 1초간 대기 후 다음 동작으로

  digitalWrite(LED_PIN, LOW); 
  Serial.println("LED OFF"); 
  delay(BLINK_INTERVAL_MS); 
