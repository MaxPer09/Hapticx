#include "Structures.h"

dedoIndice indice;
dedoMayor mayor;
dedoAnular anular;
dedoMenique menique;
dedoPulgar pulgar;

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
    dedoIndice.min = 1023;
    dedoIndice.max = 0
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
    dedoMayor.min = 1023;
    dedoMayor.max = 0
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
    dedoAnular.min = 1023;
    dedoAnular.max = 0
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
    dedoMenique.min = 1023;
    dedoMenique.max = 0
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
    dedoPulgar.min = 1023;
    dedoPulgar.max = 0
}