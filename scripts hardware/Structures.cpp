#include "Structures.h"

dedoIndice indice;
dedoMayor mayor;
dedoAnular anular;
dedoMenique menique;
dedoPulgar pulgar;

void dedoIndice::flex()
{
    nombre.write(map(analogRead(potePin), 0, 1023, min, max));
}
void dedoIndice::ext()
{
    nombre.write(0);
}
void dedoIndice::reset()
{
    dedoIndice.min = 1023;
    dedoIndice.max = 0
}

void dedoMayor::flex()
{
    nombre.write(map(analogRead(potePin), 0, 1023, min, max));
}
void dedoMayor::ext()
{
    nombre.write(0);
}
void dedoIndice::reset()
{
    dedoIndice.min = 1023;
    dedoIndice.max = 0
}

void dedoAnular::flex()
{
    nombre.write(map(analogRead(potePin), 0, 1023, min, max));
}
void dedoAnular::ext()
{
    nombre.write(0);
}

void dedoMenique::flex()
{
    nombre.write(map(analogRead(potePin), 0, 1023, min, max));
}
void dedoMenique::ext()
{
    nombre.write(0);
}

void dedoPulgar::flex()
{
    nombre.write(map(analogRead(potePin), 0, 1023, min, max));
}
void dedoPulgar::ext()
{
    nombre.write(0);
}
