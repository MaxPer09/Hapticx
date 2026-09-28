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
    String comandoFlex;
    String comandoExt;
};

struct dedoIndice : public dedos {
    dedoIndice() {
        servoPin = 3;
        potePin = A0;
        comandoFlex = "indice";
        comandoExt = "extIndice";
    }
};

struct dedoMayor : public dedos {
    dedoMayor() {
        servoPin = 5;
        potePin = A1;
        comandoFlex = "mayor";
        comandoExt = "extMayor";
    }
};

struct dedoAnular : public dedos {
    dedoAnular() {
        servoPin = 6;
        potePin = A2;
        comandoFlex = "anular";
        comandoExt = "extAnular";
    }
};

struct dedoMenique : public dedos {
    dedoMenique() {
        servoPin = 9;
        potePin = A3;
        comandoFlex = "menique";
        comandoExt = "extMenique";
    }
};

struct dedoPulgar : public dedos {
    dedoPulgar() {
        servoPin = 10;
        potePin = A4;
        comandoFlex = "pulgar";
        comandoExt = "extPulgar";
    }
};

extern dedoIndice indice;
extern dedoMayor mayor;
extern dedoAnular anular;
extern dedoMenique menique;
extern dedoPulgar pulgar;

#endif