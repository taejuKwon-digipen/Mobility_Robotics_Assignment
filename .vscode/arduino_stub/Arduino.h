#pragma once

typedef unsigned char byte;
typedef bool boolean;

#define HIGH 0x1
#define LOW 0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

void pinMode(int pin, int mode);
void digitalWrite(int pin, int value);
int digitalRead(int pin);
int analogRead(int pin);
void analogWrite(int pin, int value);

unsigned long millis();
unsigned long micros();
void delay(unsigned long ms);
void delayMicroseconds(unsigned int us);

class SerialClass {
public:
  void begin(unsigned long baud);
  void print(const char* s);
  void print(int n);
  void println(const char* s);
  void println(int n);
  void println();
};

extern SerialClass Serial;

void setup();
void loop();
