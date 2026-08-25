#ifndef PRUEBA_STRUCTURE_H
#define PRUEBA_STRUCTURE_H

/*
Esto de acá son *Estructuras* y es lo más parecido a los "objetos" de  Javascript. Se guardan atributos (o métodos) pertenecientes
a un grupo específico (ese grupo es el motor de la estructura) y después se puede acceder a cada uno de esos muy
facilmente con motorEstructura.motorAtributo . Como verás, también pueden guardarse funciones como atributos y varios
tipos distintos de variables, lo cual es la razón por la que elegí esta manera de programar.
 Aca se guardan los datos de todos los dedos, tanto de sus servomotores como de sus potenciometros. 
PD:Las variables min y max son para calibrar los potenciometros. Al enviar el comando "calibrar" deberían de resetearse
a sus valores por defecto
*/

#include <Arduino.h>
#include <Servo.h>

struct dedoIndice {
    Servo motor;
    String comandoFlex = "indice";
    String comandoExt = "extIndice";
    int servoPin = 3;
    int potePin = A0;
    int max = 0;
    int min = 1023;
    void flex();
    void ext();
    void reset();
    void calibrar ();
    int obtenerFlexion ();
};
struct dedoMayor {
    Servo motor;
    String comandoFlex = "mayor";
    String comandoExt = "extMayor";
    int servoPin = 5;
    int potePin = A1;
    int max = 0;
    int min = 1023;
    void flex();
    void ext();
    void reset();
    // se llama repetidamente mientras el usuario abre y cierra la mano
    void calibrar ();
    int obtenerFlexion ();

};
struct dedoAnular {
    Servo motor;
    String comandoFlex = "anular";
    String comandoExt = "extAnular";
    int servoPin = 6;
    int potePin = A2;
    int max = 0;
    int min = 1023;
    void flex();
    void ext();
    void reset();
    void calibrar ();
    int obtenerFlexion ();

};
struct dedoMenique {
    Servo motor;
    String comandoFlex = "menique";
    String comandoExt = "extMenique";
    int servoPin = 9;
    int potePin = A3;
    int max = 0;
    int min = 1023;
    void flex();
    void ext();
    void reset();
    void calibrar ();
    int obtenerFlexion ();

};
struct dedoPulgar {
    Servo motor;
    String comandoFlex = "pulgar";
    String comandoExt = "extPulgar";
    int servoPin = 10;
    int potePin = A4;
    int max = 0;
    int min = 1023;
    void flex();
    void ext();
    void reset();
    void calibrar ();
    int obtenerFlexion ();

};

extern dedoIndice indice;
extern dedoMayor mayor;
extern dedoAnular anular;
extern dedoMenique menique;
extern dedoPulgar pulgar;

#endif