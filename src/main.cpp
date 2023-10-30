#include <Arduino.h>
#define PinInterrupcion0 2
#define PinInterrupcion1 3
volatile int contador0 = 0;
volatile int contador1 = 0;
int contadoranteror0 = 0;
int contadoranteror1 = 0;
int grados = 15;
int led = 7;

void interrupcion0(){
  contador0++;
}

void interrupcion1(){
  contador1++;
}

void setup()
{
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  Serial.print("contador0: ");
  Serial.print(contador0);
  Serial.print(" ; contador1: ");
  Serial.println(contador1);
  attachInterrupt(digitalPinToInterrupt(PinInterrupcion0), interrupcion0, RISING);
  attachInterrupt(digitalPinToInterrupt(PinInterrupcion1), interrupcion1, RISING);
}

void loop()
{
  digitalWrite(led, LOW);
  if (contador0 != contadoranteror0)
  {
    Serial.print("contador0: ");
    Serial.print(contador0);
    Serial.print(" ; contador1: ");
    Serial.println(contador1);
    contadoranteror0 = contador0;
  }
  if (contador1 != contadoranteror1)
  {
    Serial.print("contador0: ");
    Serial.print(contador0);
    Serial.print(" ; contador1: ");
    Serial.println(contador1);
    contadoranteror1 = contador1;
  }
  if (contador0 >= grados)
  {
    contador0 = 0;
    digitalWrite(led, HIGH);
    delay(1000);
  }
  if (contador1 >= grados)
  {
    contador1 = 0;
    digitalWrite(led, HIGH);
    delay(1000);
  }
}