#ifndef PRUEBA_STRUCTURE_H
#define PRUEBA_STRUCTURE_H

#include <Arduino.h>
#include <Servo.h>
//¡Esto es parte de un sketch de prueba! Al menos por ahora, la versión oficial es el prototipo 3
class dedos {
public:
    Servo motor;
    int servoPin;
    int potePin;

    void flex();
    void ext();
};

struct dedoIndice : public dedos {
    dedoIndice() {
        servoPin = 3;
        potePin = A0;
    }
};

struct dedoMayor : public dedos {
    dedoMayor() {
        servoPin = 5;
        potePin = A1;
    }
};

struct dedoAnular : public dedos {
    dedoAnular() {
        servoPin = 6;
        potePin = A2;
    }
};

struct dedoMenique : public dedos {
    dedoMenique() {
        servoPin = 9;
        potePin = A3;
    }
};

struct dedoPulgar : public dedos {
    dedoPulgar() {
        servoPin = 10;
        potePin = A4;
    }
};

extern dedoIndice indice;
extern dedoMayor mayor;
extern dedoAnular anular;
extern dedoMenique menique;
extern dedoPulgar pulgar;

#endif