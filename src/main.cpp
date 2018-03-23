#include <Arduino.h>
/*
R2 eqn:
Vout = Vin*R2/(R1+R2)
...
R2 = R1*(Vin/Vout - 1)

Steinhart - Hart Thermistor Eqn:
1/T = A  + B logR2 + C logR2^3;
*/
const int readIn = A2;

void setup() {
Serial.begin(9600);
pinMode(readIn, INPUT);
}

int R1 = 10000; //USER SET
int ADCIN;
float R2, Vout;
float T;

//LOOK THESE UP FOR YOUR THERMISTOR'S RESISTANCE RATING
double A = 0.001125308852122;
double B = 0.000234711863267;
double C = 0.000000085663516;
float soundSpeed;

void loop() {
ADCIN = analogRead(readIn);
Vout = ADCIN/1023.;
R2 = R1 * (1/Vout - 1.0);
R2 = log(R2);
T = (float)A + B*R2 + C*R2*R2*R2;
T = 1/T;
T -= 273.15;
soundSpeed = 331 + 0.6 * T;
Serial.print("Speed of Sound: "); Serial.print(soundSpeed); Serial.print("\n");
delay(100);
}
