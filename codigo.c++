#include <LiquidCrystal.h>
#include <Servo.h>

// LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Servo
Servo servo;

// Pinos
#define trigEcho 9
#define servoPin 6

#define ledVerde 7
#define ledAmarelo 8
#define ledVermelho 13

#define potPin A0
#define tempPin A1

// Controle de tempo
unsigned long tempoAnterior = 0;
const long intervalo = 1000;

// Variáveis
float temperatura = 0;
int bateria = 0;
long distancia = 0;

// -------------------- SETUP --------------------
void setup() {
  lcd.begin(16, 2);

  servo.attach(servoPin);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

// -------------------- LOOP --------------------
void loop() {
  unsigned long agora = millis();

  if (agora - tempoAnterior >= intervalo) {
    tempoAnterior = agora;

    lerSensores();
    processarSistema();
    atualizarDisplay();
  }
}

// -------------------- SENSOR ULTRASSÔNICO (1 PINO) --------------------
long medirDistancia() {
  long duracao;
  long dist;

  pinMode(trigEcho, OUTPUT);
  digitalWrite(trigEcho, LOW);
  delayMicroseconds(2);

  digitalWrite(trigEcho, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigEcho, LOW);

  pinMode(trigEcho, INPUT);
  duracao = pulseIn(trigEcho, HIGH, 30000);

  dist = duracao * 0.034 / 2;

  if (dist <= 0 || dist > 400) {
    return -1;
  }

  return dist;
}

// -------------------- LEITURA --------------------
void lerSensores() {
  // Temperatura (TMP36)
  int leituraTemp = analogRead(tempPin);
  temperatura = (leituraTemp * 5.0 / 1023.0 - 0.5) * 100;

  // Tratamento de erro simples
  if (temperatura < -40 || temperatura > 125) {
    temperatura = 0;
  }

  // Bateria
  bateria = analogRead(potPin);

  // Distância
  distancia = medirDistancia();
}

// -------------------- LÓGICA --------------------
void processarSistema() {

  // RESET LEDs
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);

  // TEMPERATURA CRÍTICA
  if (temperatura > 35) {
    digitalWrite(ledVermelho, HIGH);
  }

  // BATERIA
  if (bateria < 300) {
    digitalWrite(ledAmarelo, HIGH);
  } else {
    digitalWrite(ledVerde, HIGH);
  }

  // DESVIO AUTOMÁTICO
  if (distancia != -1 && distancia < 20) {
    servo.write(90); // desvio
  } else {
    servo.write(0); // normal
  }
}

// -------------------- DISPLAY --------------------
void atualizarDisplay() {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperatura, 1);

  lcd.setCursor(9, 0);
  lcd.print("B:");
  lcd.print(bateria);

  lcd.setCursor(0, 1);

  if (distancia == -1) {
    lcd.print("D:ERRO");
  } else {
    lcd.print("D:");
    lcd.print(distancia);
    lcd.print("cm");
  }
}