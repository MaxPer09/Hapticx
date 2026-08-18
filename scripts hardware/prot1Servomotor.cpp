#include <Servo.h>
#include <ArduinoSTL.h>
#include <map>

Servo indice;
Servo mayor;
Servo anular;
Servo menique;
Servo pulgar;

void flexIndex()
{
   indice.write(140); //los 140° son de ejemplo, no sé bien a cuantos grados deberíamos moverlo para trabar el dedo
}
void flexMayor()
{
    mayor.write(140);
}
void flexAnular()
{
    anular.write(140);
}
void flexMenique()
{
    menique.write(140);
}
void flexPulgar()
{
    pulgar.write(140);
}
void extIndice()
{
    indice.write(0);
}
void extMayor()
{
    mayor.write(0);
}
void extAnular()
{
    anular.write(0);
}
void extMenique()
{
    menique.write(0);
}
void extMayor()
{
    pulgar.write(0);
}

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
    Serial.begin(9600);
    indice.attach(3);
    mayor.attach(5);
    anular.attach(6);
    menique.attach(9);
    pulgar.attach(10);

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
//Este código es feo, pero ser perfeccionista no es rentable.