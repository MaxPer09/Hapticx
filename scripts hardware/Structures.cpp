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

    virtual void flex() = 0;
    virtual void ext() = 0;
    virtual void reset() = 0;
    virtual void calibrar() = 0;
    virtual int obtenerFlexion() = 0;
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
    void flex() override;
    void ext() override;
    void reset() override;
    void calibrar() override;
    int obtenerFlexion() override;
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
    void flex() override;
    void ext() override;
    void reset() override;
    void calibrar() override;
    int obtenerFlexion() override;
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
    void flex() override;
    void ext() override;
    void reset() override;
    void calibrar() override;
    int obtenerFlexion() override;
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
    void flex() override;
    void ext() override;
    void reset() override;
    void calibrar() override;
    int obtenerFlexion() override;
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
    void flex() override;
    void ext() override;
    void reset() override;
    void calibrar() override;
    int obtenerFlexion() override;
};

extern dedoIndice indice;
extern dedoMayor mayor;
extern dedoAnular anular;
extern dedoMenique menique;
extern dedoPulgar pulgar;

#endif