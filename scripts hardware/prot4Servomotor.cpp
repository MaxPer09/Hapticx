#include <Servo.h>
#include "Structures4.h"
//¡Este es parte de un sketch de prueba! al menos por ahora, la versión oficial es el prototipo 3
dedos* objetos[5];
void resetServos() {
    for(int i = 0; i <=4; i++){objetos[i]->ext();}
}
void setup() {
    Serial.begin(9600);
    //Este es el experimento en cuestión, un array de objetos:
    objetos[0] = &pulgar;
    objetos[1] = &indice;
    objetos[2] = &mayor;
    objetos[3] = &anular;
    objetos[4] = &menique;
    for (int i = 0; i <= 4; i++){objetos[i]->motor.attach(objetos[i]->servoPin);}
    resetServos();
}
void loop() {
    if(Serial.available()>0)
    {
        String comando = Serial.readStringUntil('\n'); //Es FUNDAMENTAL que el que envie los comados los termine siempre con un \n, sino se coje toda la lógica.
        comando.trim();
        for(int i = 0; i <= 4; i++)
        {
            if(comando == objetos[i]->comandoExt){objetos[i]->ext();}
            if(comando == objetos[i]->comandoFlex){objetos[i]->flex();}         
        }
    }
}