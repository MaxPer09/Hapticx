#include "Structures4.h"

dedoIndice indice;
dedoMayor mayor;
dedoAnular anular;
dedoMenique menique;
dedoPulgar pulgar;

void dedos :: flex() 
{
    float grados = map(analogRead(potePin), 0, 1023, 0, 180)*2;
    motor.write(grados);
    Serial.print("Comando de flexionar dedo "); Serial.println(comandoFlex);
}
void dedos :: ext() 
{
    motor.write(0);
    Serial.print("Comando de extender dedo "); Serial.println(comandoExt);
}