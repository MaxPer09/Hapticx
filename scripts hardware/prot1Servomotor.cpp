#include <servo.h>
#include <Unordermap.h>
#include <ArduinoSTL.h>
#include <map>

servo indice;
Servo mayor;
Servo anular;
Servo menique;
Servo pulgar;
void flexIndex()
{
   indice.write(140); //los 140° son de ejemplo, no se bien a cuantos grados deberíamos moverlo para trabar el dedo
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

std::map<String, void(*)()> mapOrders;

void setup()
{
    Serial.begin(9600);
    indice.attach(3);
    mayor.attach(5);
    anular.attach(6);
    menique.attach(9);
    pulgar.attach(10);

    mapOrders["indice"] = flexIndex;
    mapOrders["mayor"] = flexMayor;
    mapOrders["anular"] = flexAnular;
    mapOrders["menique"] = flexMenique;
    mapOrders["pulgar"] = flexPulgar;
    /*
    ¿Qué es esto de aca arriba? Si sos un lector curioso y no entendés un carajo te paso un resumen:
    esto es un *Puntero de función*, ¿recordás los addEventListener() de back end en 3ro? Sirve
    para más o menos lo mismo. Se asocia una función a una clave y esa clave va a ser la orden que 
    se envíe por el puerto serial. En resumen, cuando llega una orden y se busca en el fichero que
    función le corresponde.
    PD: Esto podría haberse hecho con una cadena de if(orden == dedo), pero soy mazoquista y está
    bueno hacer cosas nuevas
    */
}

void loop()
{
    if(Serial.available()>1)
    {
        if (mapOrders.count(comando) > 0) {
            mapOrders[comando]();
          } else {
            Serial.println("Comando no encontrado.");
          }
    }
}