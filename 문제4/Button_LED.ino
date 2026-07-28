const int LED_PIN[3] = {13, 12, 11};
const int BUTTON_PIN = 2;

void setup() {
  for(int i= 0; i<3; i++)
  {
    pinMode(LED_PIN[i], OUTPUT);
  }
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // 내부 풀업 사용
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {   // 풀업이라 눌렸을 때 LOW
    for(int i = 0; i <3; i++)
    {
      digitalWrite(LED_PIN[i], HIGH);
      Serial.println("Button Pressed -> LED"+ String(i) + "ON");
      delay(100);
    }
  } else {
    for(int i = 3; i >0; i--)
    {
      digitalWrite(LED_PIN[i], LOW);
      Serial.println("Button Pressed -> LED"+ String(i) + "OFF");
      delay(100);
    }
  }

  delay(20); // 시리얼 로그 너무 빨리 찍히는 것 방지용
}