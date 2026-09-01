#include "Structures.h"

dedoIndice indice;
dedoMayor mayor;
dedoAnular anular;
dedoMenique menique;
dedoPulgar pulgar;

void dedoIndice::calibrar()
{
    float lectura = analogRead(potePin);
    if(lectura > max)
    {
    max = lectura;
    }
    if(lectura < min)
    {
    min = lectura;
    }
}
void dedoIndice::flex()
{
    motor.write(map(analogRead(potePin), min, max, 0, 180));
}
void dedoIndice::ext()
{
    motor.write(0);
}
void dedoIndice::reset()
{
    indice.min = 1023;
    indice.max = 0;
}
void dedoMayor::calibrar()
{
    float lectura = analogRead(potePin);
    if(lectura > max)
    {
    max = lectura;
    }
    if(lectura < min)
    {
    min = lectura;
    }
}
void dedoMayor::flex()
{
    motor.write(map(analogRead(potePin), min, max, 0, 180));
}
void dedoMayor::ext()
{
    motor.write(0);
}
void dedoMayor::reset()
{
    mayor.min = 1023;
    mayor.max = 0;
}
void dedoAnular::calibrar()
{
    float lectura = analogRead(potePin);
    if(lectura > max)
    {
    max = lectura;
    }
    if(lectura < min)
    {
    min = lectura;
    }
}
void dedoAnular::flex()
{
    motor.write(map(analogRead(potePin), min, max, 0, 180));
}
void dedoAnular::ext()
{
    motor.write(0);
}
void dedoAnular::reset()
{
    anular.min = 1023;
    anular.max = 0;
}
void dedoMenique::calibrar()
{
    float lectura = analogRead(potePin);
    if(lectura > max)
    {
    max = lectura;
    }
    if(lectura < min)
    {
    min = lectura;
    }
}

void dedoMenique::flex()
{
    motor.write(map(analogRead(potePin), min, max, 0, 180));
}
void dedoMenique::ext()
{
    motor.write(0);
}
void dedoMenique::reset()
{
    menique.min = 1023;
    menique.max = 0;
}

void dedoPulgar::calibrar()
{
    float lectura = analogRead(potePin);
    if(lectura > max)
    {
    max = lectura;
    }
    if(lectura < min)
    {
    min = lectura;
    }
}

void dedoPulgar::flex()
{
    motor.write(map(analogRead(potePin), min, max, 0, 180));
}
void dedoPulgar::ext()
{
    motor.write(0);
}
void dedoPulgar::reset()
{
    pulgar.min = 1023;
    pulgar.max = 0;
}