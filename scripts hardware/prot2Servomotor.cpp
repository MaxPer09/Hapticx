#include <Servo.h>
#include <ArduinoSTL.h>
#include <map>
std::map<String, int> mapOrders; //Aca estoy creando un "mapa" (es parecido a los objetos de JS, pero más choto) lo voy a usar para guardar dedo = pin

/*
Estos tres arrays manejan la lógica interna del script. Cada index representa los datos de un dedo.
el índice tiene el index 0, el mayor tiene el 1...
el array nombre almacena los nombres de los dedos, y se usa para los comandos que se reciben. El array
de pines tiene la información de los pines a los que se une cada nombre. Y el array dedos es el que
hace toda la magia, ya que en él se guardan las variables de tipo Servo asociadas a un nombre y a un pin
(los dos arrays anteriores) y se usa para mover los servos en sí.
*/
const char* comandos[5] = {"indice","mayor","anular","menique","pulgar"}; 
const  int pines[5] = {3,5,6,9,10}; 
const Servo dedos[5] = {indice,mayor,anular,menique,pulgar};

void moverMotor(int i, int angulo) //el se proporciona el index del dedo que se quiere mover y el ángulo
{
    dedos[i].write(angulo);
}

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
    for(int i=0; i<5; i++)
    {
        dedos[i].attatch(pines[i]); 
        mapOrders[nombres[i]] = i;
    }

    resetServos(); //Se ponen todos llos servomotores en "descanso"
}

void loop()
{
    if(Serial.available()>0)
    {
        String comando = Serial.readStringUntil('\n'); //Es FUNDAMENTAL que el que envie los comados los termine siempre con un \n, sino se coje toda la lógica.
        for(int i=0;i<=5;i++)
        {
            if(comando == comandos[i]){
                moverMotor(i, 140);
            }
            
            if(i == 5){
                Serial.println("Comando no encontrado, revisar sintaxis");
            }
        }
    }
}