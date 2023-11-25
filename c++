#include <DHT.h>

// Define os pinos para os LEDs do semáforo 1
const int redLED1 = 8;
const int yellowLED1 = 9;
const int greenLED1 = 10;

// Define os pinos para o sensor DHT11 do semáforo 1
const int dhtPin1 = 2;

// Define os pinos para os LEDs do semáforo 2
const int redLED2 = 11;
const int yellowLED2 = 12;
const int greenLED2 = 13;

// Define os pinos para o sensor DHT11 do semáforo 2
const int dhtPin2 = 3;

// Crie objetos DHT para ler a temperatura e a umidade para cada semáforo
DHT dht1(dhtPin1, DHT11);
DHT dht2(dhtPin2, DHT11);

void setup() {
  // Inicializa os pinos dos LEDs como saída
  pinMode(redLED1, OUTPUT);
  pinMode(yellowLED1, OUTPUT);
  pinMode(greenLED1, OUTPUT);
  pinMode(redLED2, OUTPUT);
  pinMode(yellowLED2, OUTPUT);
  pinMode(greenLED2, OUTPUT);

  // Inicializa os sensores DHT
  dht1.begin();
  dht2.begin();
}

void loop() {
  // Lê a temperatura do semáforo 1
  float temperature1 = dht1.readTemperature();

  // Lê a temperatura do semáforo 2
  float temperature2 = dht2.readTemperature();

  Serial.begin(4800);

  // Verifica se as leituras de temperatura são válidas
  if (!isnan(temperature1) && !isnan(temperature2)) {
    Serial.print("Temperatura Semáforo 1: ");
    Serial.print(temperature1);
    Serial.println("°C");
    Serial.print("Temperatura Semáforo 2: ");
    Serial.print(temperature2);
    Serial.println("°C");

    // Ajusta os tempos dos semáforos com base nas temperaturas de cada semáforo
    int redTime1, yellowTime1, greenTime1;
    int redTime2, yellowTime2, greenTime2;

    if (temperature1 >= 30.0) { // Temperatura alta, semáforo 1 mais rápido
      redTime1 = 3000;
      yellowTime1 = 1000;
      greenTime1 = 2000;
    } else { // Temperatura normal, tempos padrão para semáforo 1
      redTime1 = 4000;
      yellowTime1 = 2000;
      greenTime1 = 4000;
    }

    if (temperature2 >= 30.0) { // Temperatura alta, semáforo 2 mais rápido
      redTime2 = 3000;
      yellowTime2 = 1000;
      greenTime2 = 2000;
    } else { // Temperatura normal, tempos padrão para semáforo 2
      redTime2 = 4000;
      yellowTime2 = 2000;
      greenTime2 = 4000;
    }

    // Sincroniza os semáforos para alternarem
    trafficLight(redLED1, yellowLED1, greenLED1, redLED2, yellowLED2, greenLED2, redTime1, yellowTime1, greenTime1, redTime2, yellowTime2, greenTime2);
  }
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
