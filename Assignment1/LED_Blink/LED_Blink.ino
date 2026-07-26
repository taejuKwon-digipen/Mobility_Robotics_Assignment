const int LED_PIN = 13;
const int BLINK_INTERVAL_MS = 1000;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED ON");
  delay(BLINK_INTERVAL_MS);

  digitalWrite(LED_PIN, LOW);
  Serial.println("LED OFF");
  delay(BLINK_INTERVAL_MS);
}
