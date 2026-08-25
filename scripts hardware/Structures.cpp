#include "Structures.h"

dedoIndice indice;
dedoMayor mayor;
dedoAnular anular;
dedoMenique menique;
dedoPulgar pulgar;

void dedoIndice::calibrar()
{
    int lectura = analogRead(potePin);
        if (lectura < min) min = lectura;
        if (lectura > max) max = lectura;
}

int dedoIndice::obtenerFlexion()
{
    // no sé si es necesario pero para evitar errores si no se calibró
    if (max <= min) return 0;
    int lecturaActual = analogRead (potePin);
    int mapeado = map (lecturaActual, min, max, 0, 180);
//Esta línea de abajo es para mantener el valor estrictamente entre 0 y 180
    return constrain (mapeado, 0, 180);
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
    int lectura = analogRead(potePin);
        if (lectura < min) min = lectura;
        if (lectura > max) max = lectura;
}

int dedoMayor::obtenerFlexion()
{
    // no sé si es necesario pero para evitar errores si no se calibró
    if (max <= min) return 0;
    int lecturaActual = analogRead (potePin);
    int mapeado = map (lecturaActual, min, max, 0, 180);
//Esta línea de abajo es para mantener el valor estrictamente entre 0 y 180
    return constrain (mapeado, 0, 180);
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
    int lectura = analogRead(potePin);
        if (lectura < min) min = lectura;
        if (lectura > max) max = lectura;
}

int dedoAnular::obtenerFlexion()
{
    // no sé si es necesario pero para evitar errores si no se calibró
    if (max <= min) return 0;
    int lecturaActual = analogRead (potePin);
    int mapeado = map (lecturaActual, min, max, 0, 180);
//Esta línea de abajo es para mantener el valor estrictamente entre 0 y 180
    return constrain (mapeado, 0, 180);
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
    int lectura = analogRead(potePin);
        if (lectura < min) min = lectura;
        if (lectura > max) max = lectura;
}

int dedoMenique::obtenerFlexion()
{
    // no sé si es necesario pero para evitar errores si no se calibró
    if (max <= min) return 0;
    int lecturaActual = analogRead (potePin);
    int mapeado = map (lecturaActual, min, max, 0, 180);
//Esta línea de abajo es para mantener el valor estrictamente entre 0 y 180
    return constrain (mapeado, 0, 180);
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
    int lectura = analogRead(potePin);
        if (lectura < min) min = lectura;
        if (lectura > max) max = lectura;
}

int dedoPulgar::obtenerFlexion()
{
    // no sé si es necesario pero para evitar errores si no se calibró
    if (max <= min) return 0;
    int lecturaActual = analogRead (potePin);
    int mapeado = map (lecturaActual, min, max, 0, 180);
//Esta línea de abajo es para mantener el valor estrictamente entre 0 y 180
    return constrain (mapeado, 0, 180);
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