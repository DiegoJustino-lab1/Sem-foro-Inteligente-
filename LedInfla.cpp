#include <IRremote.h>
//definir a biblioteca especifica
int redLed = 5;
int yellowLed = 4;
int greenLed = 3;
int blueLed = 2;
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);
decode_results results;


void setup()
{
  
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  
  //iniciar monitor serial
  Serial.begin(9600);
  Serial.println("Habilitando IRin");
  irrecv.enableIRIn(); 
  Serial.println("Habilitando IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value; 
    Serial.println(value);
    switch (value) {
      case 2295: 
      	digitalWrite(redLed, HIGH);
      	delay(500);
      	digitalWrite(redLed, LOW);
      	break;
      
      case 34935:
      	digitalWrite(yellowLed, HIGH);
      	delay(500);
      	digitalWrite(yellowLed, LOW);
      	break;
      
      case 18615:
      	digitalWrite(greenLed, HIGH);
      	delay(500);
      	digitalWrite(greenLed, LOW);
      	break;
      
      case 10455:
      	digitalWrite(blueLed, HIGH);
      	delay(500);
      	digitalWrite(blueLed, LOW);
    }
    
    
    irrecv.resume(); // Receber o proximo valor
  }
   Serial.print(results.value, HEX);
}