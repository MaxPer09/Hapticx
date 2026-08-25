#include "Structures.h"
#include <Servo.h>
#include <ArduinoSTL.h>
#include <Map>

std::map<String, void(*)()> mapOrders; //Aca estoy creando un "mapa" (es parecido a los objetos de JS, pero más choto) lo voy a usar para guardar funciones.
// mensaje del mismo progrmador pero del futuro: cambié e tipo de mapa para que pueda guardar las funciones que están dentro de una estructura, porque antes solo podía guardar funciones globales
void resetServos()
{
    indice.ext();
    mayor.ext();
    anular.ext();
    menique.ext();
    pulgar.ext();
}

//Lo que hay aca abajo son funciones puente globales. Como me hice el pija y guarde funciones dentro de estructuras, ahora el mapa no puede llamarlas porque no son globales, asi que hay que hacer estas funciones puente
indiceflex(){indice.flex();}
mayorflex(){mayor.flex();}
anularflex(){anular.flex();}
meniqueflex(){menique.flex();}
pulgarflex(){pulgar.flex();}
indiceext(){indice.ext();}
mayorext(){mayor.ext();}
anularext(){anular.ext();}
meniqueext(){menique.ext();}
pulgarext(){pulgar.ext();}

void ejecutarCalibracion() {
    indice.reset();
    mayor.reset();
    anular.reset();
    menique.reset();
    pulgar.reset();
    unsigned long tiempoInicio = millis();
    while (millis()-tiempoInicio < 5000){
        indice.calibrar();
        mayor.calibrar();
        anular.calibrar();
        menique.calibrar();
        pulgar.calibrar();
        indice.obtenerFlexion();
        mayor.obtenerFlexion();
        anular.obtenerFlexion();
        menique.obtenerFlexion();
        pulgar.obtenerFlexion();
        delay(10);
    }
}

void setup()
{
    indice.motor.attach(indice.servoPin);
    mayor.motor.attach(mayor.servoPin);
    anular.motor.attach(anular.servoPin);
    menique.motor.attach(menique.servoPin);
    pulgar.motor.attach(pulgar.servoPin);
    resetServos(); //Se ponen todos los servomotores en "descanso"

    mapOrders["indice"] = indiceflex(); 
    mapOrders["mayor"] = mayorflex();
    mapOrders["anular"] = anularflex();
    mapOrders["menique"] = meniqueflex();
    mapOrders["pulgar"] = pulgarflex();
    mapOrders["extIndice"] = indiceext();
    mapOrders["extMayor"] = mayorext();
    mapOrders["extAnular"] = anularext();
    mapOrders["extMenique"] = meniqueext();
    mapOrders["extPulgar"] = pulgarext();
    /*
    ¿Qué es esto de aca arriba? Si sos un lector curioso y no entendés un carajo te paso un resumen:
    esto es un *Puntero de función*, ¿recordás los addEventListener() de back-end en 3ro? Sirve
    para más o menos lo mismo. Se asocia una función a una clave y esa clave es el comando que se recibe
    por el puerto serial. En resumen, cuando llega una orden se busca en el fichero (que es esta lista con
    clave = función) qué función le corresponde, que en este caso va a ser activar un servomotor distinto 
    por cada dedo. Lo bueno de esto es que es escalable, solo con añadir un puntero de función más 
    se puede hacer funcionar un comando nuevo.
    PD: Esto podría haberse hecho con una cadena de if(orden == dedo), pero soy masoquista y está
    bueno hacer cosas nuevas.
    */
    ejecutarCalibracion();
    mapOrders ["calibrar"] = ejecutarCalibracion;

}
void loop()
{
    if(Serial.available()>0)
    {
        String comando = Serial.readStringUntil('\n'); //Es FUNDAMENTAL que el que envie los comados los termine siempre con un \n, sino se coje toda la lógica.
        comando.trim();
        if (mapOrders.count(comando) > 0) {
            mapOrders[comando](); //<------------
          } else {
            Serial.print("Comando ");
            Serial.print(comando);
            Serial.println(" no encontrado. Revisar sintaxis");
            /*
            Esto es lo que dije antes. se indica que se va a usar una función que está dentro del mapa 
            "mapOrders", se pone el comando que llegó desde el puerto serial y se agregan unos () al final
            para indicar que es una función que se debe ejecutar.
            */
          }
    }
}