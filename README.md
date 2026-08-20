# Hapticx
Repositorio para el proyecto Haptixc. Guante háptico para VR. Acá encontrarás todos los archivos necesarios relacionados al control del hardware


## Pasos para cargar el código en la computadora local y arduino
Los siguientes pasos solo se tendrán que hacer una vez en la computadora que se va a usar durante todo el proyecto y presentación (obviamente esa computadora no tiene que estar frezzada). Al menos por ahora estamos usando la n23 del carro azul.

- Creá un sketch nuevo en arduino IDE y pegá en el el script de c++ principal (al menos por ahora, es prot3Servomotor.cpp).
- en ese mismo sketch de arduino, andá a los tres puntos (...) de arriba a la derecha y presioná "new tab" o "nueva pestaña"
- Nombrá esa pestaña "Structures.h"
- En esa nueva pestaña que creaste, pegá todo el código que está en el archivo Structures.h de este repositorio, dentro de la carpeta "scripts hardware"
- De la misma manera, creá otra pestaña que se llame Structures.cpp y pegá todo el código del archivo con el mismo nombre de este repositorio
- Guardá el sketch *CLAVE*:
    Tras guardar se debería de haber creado una carpeta con:
    - prot3Servomotor.ino (o el sketch prinicpal que estemos usando).
    - Structures.h
    -Structures.cpp
    Y estos tres archivos deberían tener el mismo código que en el repositorio

    Una vez hecho esto, cada vez que se quiera iniciar el código en arduino IDE, sea por lo que sea, se tiene que:
    - Ir a "file" arriba a la izquierda
    - Seleccionar "open"
    - Abrir el archivo .ino que está en la carpeta del sketch
    No hay que crear un sketch nuevo cada vez, porque se pierden las estructuras que dicen como guardar los datos

## Pasos para la conexión bluetooth
si el arduino está energizado (no es necesario que sea por el puerto USB) y se quiere vincular la computadora con el módulo bluetooth (llamado HC-06), hacer lo siguiente:
- Asegurarse que el arduino está prendido
- Ir a configuración de windows 
- Ir a bluetooth y dispositivos
- Apretar en "agregar dispositivo" y elegir la opción bluetooth de la ventana emergente
- La computadora empezará a mostrar un listado de los dispositivos cercanos, hay que buscar la opción llamada HC-06 y vincularse con la contraseña 1234
- La comunicación debería abrirse en el puerto COM5, usar ese puerto en arduino IDE para la comunicación

Si no encontrás la opción de HC-06 en el listado, verificá que la luz del módulo bluetooth del guante está parpadeando rápido. Si está apagada significa que el módulo no está energizado. Si parpadea muy lento, entre 5 y 10 segundos, significa que el módulo ya está conectado a una computadora,