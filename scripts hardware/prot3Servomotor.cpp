#include <Arduino.h>
#include <Servo.h>
#include "Structures.h"

void resetServos() {
    indice.ext();
    mayor.ext();
    anular.ext();
    menique.ext();
    pulgar.ext();
}

void ejecutarCalibracion() {
    indice.reset();
    mayor.reset();
    anular.reset();
    menique.reset();
    pulgar.reset();

    unsigned long tiempoInicio = millis();
    while (millis() - tiempoInicio < 5000) {
        indice.calibrar();
        mayor.calibrar();
        anular.calibrar();
        menique.calibrar();
        pulgar.calibrar();
        delay(10);
    }
}

void procesarComando(String comando) {
    if (comando == "indice")         indice.flex();
    else if (comando == "extIndice")  indice.ext();
    else if (comando == "mayor")      mayor.flex();
    else if (comando == "extMayor")   mayor.ext();
    else if (comando == "anular")     anular.flex();
    else if (comando == "extAnular")  anular.ext();
    else if (comando == "menique")    menique.flex();
    else if (comando == "extMenique") menique.ext();
    else if (comando == "pulgar")     pulgar.flex();
    else if (comando == "extPulgar")  pulgar.ext();
    else if (comando == "calibrar")   ejecutarCalibracion();
    else {
        Serial.print("Comando ");
        Serial.print(comando);
        Serial.println(" no encontrado.");
    }
}

void setup() {
    Serial.begin(115200);

    indice.motor.attach(indice.servoPin);
    mayor.motor.attach(mayor.servoPin);
    anular.motor.attach(anular.servoPin);
    menique.motor.attach(menique.servoPin);
    pulgar.motor.attach(pulgar.servoPin);

    resetServos();
    ejecutarCalibracion();
}

void loop() {
    // 1. Si llega una orden, mueve el servo correspondiente según el potenciómetro
    if (Serial.available() > 0) {
        String comando = Serial.readStringUntil('\n');
        comando.trim();
        procesarComando(comando);
    }

    // 2. Envía constantemente la posición actual de flexión (0 a 180) calculada tras la calibración
    Serial.print(pulgar.obtenerFlexion());  Serial.print(",");
    Serial.print(indice.obtenerFlexion());  Serial.print(",");
    Serial.print(mayor.obtenerFlexion());   Serial.print(",");
    Serial.print(anular.obtenerFlexion());  Serial.print(",");
    Serial.println(menique.obtenerFlexion());

    delay(20);
}