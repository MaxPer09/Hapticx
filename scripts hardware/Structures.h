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

Nota del máxi del futuro: tuvimos que crear la clase "dedos" con un "constructor" en cada una porque al hacer indice.metodo
el compilador daba error. En resumen, para usar los valores dentro de una estructura esta tiene que pertenecer a una "clase",
que es un molde que dice que cosas van a tener adentro todos sus hijos (dice que variables y funciones van a tener adentro)
e hice que todas las estructuras sean "hijas" de esa clase. El constructor es un poco confuso, pero sirve para que las variables
dentro de cada estructura individual tengan valores por defecto, sino tendrían que estar definidos en el .ino y eso... queda feo.
*/

#include <Arduino.h>
#include <Servo.h>

class dedos 
{
    public:
    //Nos llegó la hora... hay que pasar todo a objetos y clases porque c++ es un lenguaje orientado a objetos
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
    int obtenerFlexion();
};

struct dedoIndice : public dedos {
    dedoIndice() {
        //Esto de aca son los famosos constructores. Las variables en sí ya existen, porque se heredan de la clase "dedos"
        //Pero, el constructor sirve para darle un valor por defecto dentro de la propia estructura, sin hacerlo en el
        //script principal.
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
    int obtenerFlexion ();
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
    // se llama repetidamente mientras el usuario abre y cierra la mano
    void calibrar ();
    int obtenerFlexion ();
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
    int obtenerFlexion ();
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
    int obtenerFlexion ();
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
    int obtenerFlexion ();
};

extern dedoIndice indice;
extern dedoMayor mayor;
extern dedoAnular anular;
extern dedoMenique menique;
extern dedoPulgar pulgar;
#endif