# Bitacora de hardware
## Cambiós hechos, ordenados por fecha

### 10 de agosto
- Se comenzó con la investigación del módulo UHC-06 para comunicación bluetooh.
- Se creó un prototipo básico para probar el concepto.

### 11 de agosto
- Finalmente, conseguimos hacer que funcione la conexión bluetooth entre arduino y computadora, eso ya está terminado.

### 12 de agosto
- Creamos el primer prototipo de código para controlar los servomotores usando punteros de función.

### 13 de agosto
- Abandonamos el primer prototipo porque era un poco aparatoso.
- Empezamos el prototipo 2 intentando reescribir todo para hacerlo más sencillo de leer.

### 18 de agosto
- Abandonamos el prototipo 2, no se adaptaba realmente a lo que necesitabamos.
- Decidimos que también vamos a incluir potenciometros ademas de los servomotores.
- planeamos y empezamos el prototipo 3, el cual usa estructuras en vez de arrays. Es útil para los potenciometros.
- Terminamos todo el archivo con las estructuras y lo transformamos en header para incluirlo como "librería" en IDE, falta la lógica.
- Escribí instrucciones de uso en el README.

#### 24 de agosto
- El prototipo 3 ya es completamente funcional, solo queda la construcción física del hardware para  hacer las pruebas.

### 25 de agosto
- Las estructuras daban un error al compilarlas porque no pertenecían a una clase, ya creamos la clase y las hicimos hijas de la estructura "dedos".

### 7 de septiembre
- En las ultimas clases estuvimos haciendo tests, encontrando bugs y modificando parte de la lógica para solucionarlos. Ya funciona bien, por suerte.
- Ahora la función calibrar() toma por sí misma el valor de su potenciometro y ajusta min y max en función de su lectura, todo de una.
- Eliminamos la función obtenerFlexion() puesto que ya no era necesaria.
- Adicionalmente, ya añadimos todos los modelos 3d que vamos a imprimir (por ahora, solo como prototipos) pero aún no los enviamos. 
- Nota: Necesitamos obtener, de alguna manera, los resortes para tensar el potenciometro.
- Nota 2: Aún no tenemos decidido como vamos a energizar el guante en sí, puesto que las baterías suelen ser muy grandes y pesadas.
- Sin miedo al éxito.
