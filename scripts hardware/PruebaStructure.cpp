/*
Esto de acá son *Estructuras* y es lo más parecido a los "objetos" de  Javascript. Se guardan atributos pertenecientes
a un grupo específico (ese grupo es el nombre de la estructura) y después se puede acceder a cada uno de esos muy
facilmente con nombreEstructura.nombreAtributo . Como verás, también pueden guardarse funciones como atributos y varios
tipos distintos de variables, lo cual es la razón por la que elegí esta manera de programar.
 Aca se guardan los datos de todos los dedos, tanto de sus servomotores como de sus potenciometros. 
PD:Las variables min y max son para calibrar los potenciometros. Al enviar el comando "calibrar" deberían de resetearse
a sus valores por defecto
*/
struct dedoIndice {

    Servo nombre = indice;
    std::string comandoFlex = "indice";
    std::string comandoExt = "extIndice";
    int servoPin = 3;
    int potePin = A0;
    int max = 0;
    int min = 1023;
    void flex()
    {
        nombre.write(map(analogRead(potePin), 0, 1023, min, max));
    }
    void ext()
    {
        nombre.write(0);
    }
};
struct dedoMayor {

    Servo nombre = mayor;
    std::string comandoFlex = "mayor";
    std::string comandoExt = "extMayor";
    int servoPin = 5;
    int potePin = A1;
    int max;
    int min;
    void flex()
    {
        nombre.write(map(analogRead(potePin), 0, 1023, min, max));
    }
    void ext()
    {
        nombre.write(0);
    }
};
struct dedoAnular {

    Servo nombre = anular;
    std::string comandoFlex = "anular";
    std::string comandoExt = "extAnular";
    int servoPin = 6;
    int potePin = A2;
    int max = 0;
    int min = 1023;
    void flex()
    {
        nombre.write(map(analogRead(potePin), 0, 1023, min, max));
    }
    void ext()
    {
        nombre.write(0);
    }
};
struct dedoMenique {

    Servo nombre;
    std::string comandoFlex = "menique";
    std::string comandoExt = "extMenique";
    int servoPin = 9;
    int potePin = A3;
    int max = 0;
    int min = 1023;
    void flex()
    {
        nombre.write(map(analogRead(potePin), 0, 1023, min, max));
    }
    void ext()
    {
        nombre.write(0);
    }
};
struct dedoPulgar {

    Servo nombre;
    std::string comandoFlex = "pulgar";
    std::string comandoExt = "extPulgar";
    int servoPin = 10;
    int potePin = A4;
    int max = 0;
    int min = 1023;
    void flex()
    {
        nombre.write(map(analogRead(potePin), 0, 1023, min, max));
    }
    void ext()
    {
        nombre.write(0);
    }
};

dedoIndice indice;
dedoMayor mayor;
dedoAnular anular;
dedoMenique menique;
dedoPulgar pulgar;

