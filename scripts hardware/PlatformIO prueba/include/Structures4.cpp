#include "Structures4.h"

dedoIndice indice;
dedoMayor mayor;
dedoAnular anular;
dedoMenique menique;
dedoPulgar pulgar;

void dedos :: flex() 
{
    float grados = map(analogRead(potePin), 0, 1023, 0, 180)*2; //multiplicamos el ángulo *2 porque sino el servomotor solo se mueve la mitad de lo que debería, ni idea pq
    motor.write(grados);
    Serial.print("Comando de flexionar dedo "); Serial.println(comandoFlex);
}
void dedos :: ext() 
{
    motor.write(0);
    Serial.print("Comando de extender dedo "); Serial.println(comandoExt);
}