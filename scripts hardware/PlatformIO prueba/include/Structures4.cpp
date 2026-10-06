#include "Structures4.h"
//¡Este es parte de un sketch de prueba! al menos por ahora, la versión oficial es el prototipo 3

dedoIndice indice;
dedoMayor mayor;
dedoAnular anular;
dedoMenique menique;
dedoPulgar pulgar;

void dedos :: flex() 
{
    motor.write(map(analogRead(potePin), 0, 1023, 0, 180));
    Serial.print("Comando de flexionar dedo "); Serial.println(nombre);
}
void dedos :: ext() {motor.write(0);}