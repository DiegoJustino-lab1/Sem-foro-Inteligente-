#include <DHT.h> 

const int redLED1 = 8;
const int yellowLED1 = 9;
const int greenLED1 = 10;

const int redLED2 = 11;
const int yellowLED2 = 12;
const int greenLED2 = 13;

const int proximityPin1 = 2;
const int proximityPin2 = 3;

void setup() {
  pinMode(redLED1, OUTPUT);
  pinMode(yellowLED1, OUTPUT);
  pinMode(greenLED1, OUTPUT);
  pinMode(redLED2, OUTPUT);
  pinMode(yellowLED2, OUTPUT);
  pinMode(greenLED2, OUTPUT);
  
  pinMode(proximityPin1, INPUT);
  pinMode(proximityPin2, INPUT);
}

void loop() {
  int proximity1 = digitalRead(proximityPin1);
  int proximity2 = digitalRead(proximityPin2);

  Serial.begin(4800);

  int redTime1, yellowTime1, greenTime1;
  int redTime2, yellowTime2, greenTime2;

  if (proximity1 == HIGH) {
    redTime1 = 3000;
    yellowTime1 = 1000;
    greenTime1 = 2000;
  } else {
    redTime1 = 4000;
    yellowTime1 = 2000;
    greenTime1 = 4000;
  }

  if (proximity2 == HIGH) {
    redTime2 = 3000;
    yellowTime2 = 1000;
    greenTime2 = 2000;
  } else {
    redTime2 = 4000;
    yellowTime2 = 2000;
    greenTime2 = 4000;
  }

  trafficLight(redLED1, yellowLED1, greenLED1, redLED2, yellowLED2, greenLED2, redTime1, yellowTime1, greenTime1, redTime2, yellowTime2, greenTime2);
}

void trafficLight(int redPin1, int yellowPin1, int greenPin1, int redPin2, int yellowPin2, int greenPin2, int redTime1, int yellowTime1, int greenTime1, int redTime2, int yellowTime2, int greenTime2) {
  digitalWrite(redPin1, HIGH);
  digitalWrite(greenPin2, HIGH);
  delay(redTime1);
  digitalWrite(greenPin2, LOW);
  digitalWrite(yellowPin2, HIGH);
  delay(yellowTime2);
  digitalWrite(yellowPin2, LOW);
  digitalWrite(redPin1, LOW);

  digitalWrite(redPin2, HIGH);
  digitalWrite(greenPin1, HIGH);
  delay(greenTime1);
  digitalWrite(greenPin1, LOW);

  digitalWrite(yellowPin1, HIGH);
  delay(yellowTime1);
  digitalWrite(yellowPin1, LOW);

  digitalWrite(redPin2, LOW);
}
