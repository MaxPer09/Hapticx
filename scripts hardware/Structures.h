#ifndef PRUEBA_STRUCTURE_H
#define PRUEBA_STRUCTURE_H

#include <Arduino.h>
#include <Servo.h>

class dedos {
public:
    Servo motor;
    String comandoFlex;
    String comandoExt;
    int servoPin;
    int potePin;
    int max;
    int min;

    void flex();
    void ext();
    void reset();
    void calibrar();
};

struct dedoIndice : public dedos {
    dedoIndice() {
        comandoFlex = "indice";
        comandoExt = "extIndice";
        servoPin = 3;
        potePin = A0;
        max = 0;
        min = 1023;
    }
    //Técnicamente, no sería necesario poner aca las funciones, pero como somos imbéciles e hicimos primero las estructuras
    //y despues la clase, Structures.cpp hace referencia a cada estructura individual, asi que hay que dejarlos aca >:(
    void flex();
    void ext();
    void reset();
    void calibrar ();
};

struct dedoMayor : public dedos {
    dedoMayor() {
        comandoFlex = "mayor";
        comandoExt = "extMayor";
        servoPin = 5;
        potePin = A1;
        max = 0;
        min = 1023;
    }
    void flex();
    void ext();
    void reset();
    void calibrar ();
};

struct dedoAnular : public dedos {
    dedoAnular() {
        comandoFlex = "anular";
        comandoExt = "extAnular";
        servoPin = 6;
        potePin = A2;
        max = 0;
        min = 1023;
    }
    void flex();
    void ext();
    void reset();
    void calibrar ();
};

struct dedoMenique : public dedos {
    dedoMenique() {
        comandoFlex = "menique";
        comandoExt = "extMenique";
        servoPin = 9;
        potePin = A3;
        max = 0;
        min = 1023;
    }
    void flex();
    void ext();
    void reset();
    void calibrar ();
};

struct dedoPulgar : public dedos {
    dedoPulgar() {
        comandoFlex = "pulgar";
        comandoExt = "extPulgar";
        servoPin = 10;
        potePin = A4;
        max = 0;
        min = 1023;
    }
    void flex();
    void ext();
    void reset();
    void calibrar ();
};

extern dedoIndice indice;
extern dedoMayor mayor;
extern dedoAnular anular;
extern dedoMenique menique;
extern dedoPulgar pulgar;

#endif