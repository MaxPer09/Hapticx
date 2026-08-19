#ifndef PRUEBA_STRUCTURE_H
#define PRUEBA_STRUCTURE_H

/*
Esto de acá son *Estructuras* y es lo más parecido a los "objetos" de  Javascript. Se guardan atributos pertenecientes
a un grupo específico (ese grupo es el nombre de la estructura) y después se puede acceder a cada uno de esos muy
facilmente con nombreEstructura.nombreAtributo . Como verás, también pueden guardarse funciones como atributos y varios
tipos distintos de variables, lo cual es la razón por la que elegí esta manera de programar.
 Aca se guardan los datos de todos los dedos, tanto de sus servomotores como de sus potenciometros. 
PD:Las variables min y max son para calibrar los potenciometros. Al enviar el comando "calibrar" deberían de resetearse
a sus valores por defecto
*/

#include <Arduino.h>
#include <Servo.h>

struct dedoIndice {

    Servo nombre;
    String comandoFlex = "indice";
    String comandoExt = "extIndice";
    int servoPin = 3;
    int potePin = A0;
    int max = 0;
    int min = 1023;
    void flex();
    void ext();
};
struct dedoMayor {

    Servo nombre;
    String comandoFlex = "mayor";
    String comandoExt = "extMayor";
    int servoPin = 5;
    int potePin = A1;
    int max = 0;
    int min = 1023;
    void flex();
    void ext();
};
struct dedoAnular {

    Servo nombre;
    String comandoFlex = "anular";
    String comandoExt = "extAnular";
    int servoPin = 6;
    int potePin = A2;
    int max = 0;
    int min = 1023;
    void flex();
    void ext();
};
struct dedoMenique {

    Servo nombre;
    String comandoFlex = "menique";
    String comandoExt = "extMenique";
    int servoPin = 9;
    int potePin = A3;
    int max = 0;
    int min = 1023;
    void flex();
    void ext();
};
struct dedoPulgar {

    Servo nombre;
    String comandoFlex = "pulgar";
    String comandoExt = "extPulgar";
    int servoPin = 10;
    int potePin = A4;
    int max = 0;
    int min = 1023;
    void flex();
    void ext();
};

extern dedoIndice indice;
extern dedoMayor mayor;
extern dedoAnular anular;
extern dedoMenique menique;
extern dedoPulgar pulgar;

#endif