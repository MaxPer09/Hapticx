//Recordatorio: ahora que creamos las estructuras de Structures.h, hay que rehacer este código basandose en ellas. Es por tu bien, lo prometo

#include "Structures.h"
#include <Servo.h>

#define pot0 A0
#define pot1 A1
#define pot2 A2
#define pot3 A3
#define pot4 A4

std::map<String, void(*)()> mapOrders; //Aca estoy creando un "mapa" (es parecido a los objetos de JS, pero más choto) lo voy a usar para guardar funciones :)
Servo dedos[5] = {indice,mayor,anular,menique,pulgar}; //Este es un array con todas las variables que representan a los servomotores. Lo voy a usar para algunas boludeces

void resetServos()
{
    

    //La función resetServos() pone a todos los servomotores a 0, porque sino se quedarían en la última posición que
    //se les pidió, trabando el dedo cuando no es necesario
    for (int i = 0; i < 5; i++)
    {
        dedos[i].write(0);
    }
}
void setup()
{

    resetServos(); //Se ponen todos los servomotores en "descanso"

    mapOrders["indice"] = flexIndex;
    mapOrders["mayor"] = flexMayor;
    mapOrders["anular"] = flexAnular;
    mapOrders["menique"] = flexMenique;
    mapOrders["pulgar"] = flexPulgar;
    mapOrders["extIndice"] = extIndice;
    mapOrders["extMayor"] = extMayor;
    mapOrders["extAnular"] = extAnular;
    mapOrders["extMenique"] = extMenique;
    mapOrders["extPulgar"] = extPulgar;


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
//Este código es feo, repetitivo, redundante, pero ser perfeccionista no es rentable.