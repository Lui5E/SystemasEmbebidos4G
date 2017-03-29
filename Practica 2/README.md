Objetivo general:

Diseñar, programar e implementar sistema embebido para una calculadora binaria de ocho bits

con las cuatro operaciones aritméticas básicas.

Objetivos específicos:

1. Identificar cada uno de los cinco puertos de entrada y salida en el microcontrolador.

2. Reconocer características y funciones asociadas a cada una de las terminales de los cinco puertos.

3. Implementar arquitectura hardware/software para la solución de la práctica.

4. Generar proyecto para la aplicación en lenguaje C.

5. Reconocer directivas de preprocesamiento necesarias para que el compilador reconozca la

configuración general del microcontrolador objetivo.

6. Practicar funciones específicas para la configuración, entrada y salida de puertos digitales.

7. Practicar operadores aritméticos y lógicos para la transformación de información digital.

8. Comprobar resultado de la implementación física de la práctica.

9. Documentar resultado de la implementación física de la práctica.


Requerimientos de la práctica:

1. Datos enteros de ocho bits sin signo para las cuatro operaciones aritméticas, serán ingresados por

dos DIP switches de ocho posiciones en configuración Pull-Down conectados a los puertos C y D.

2. Cada operación aritmética será activadas al presionar uno de los cuatro interruptores de presión

(push button) normalmente abiertos (NA) en Pull-Down conectados a las terminales RB7:RB4 del

puerto B.

3. El rebote producido por los interruptores de presión para la selección de operación deberá ser

eliminado con un arreglo electrónico anti rebote.

4. El resultado de las operaciones se mostrará inmediatamente después de la selección en 13 LEDs,

con resistencias limitadoras en serie, conectados a las terminales RA5:RA0, RB3:RB0 y RE2:RE0,

como se indica en la figura 3.1.

5. El suministro de corriente de cada terminal de salida para mostrar resultado, no debe exceder 8.0

mA de corriente para alimentar cada LED.

6. Considerar posiciones más y menos significativas del resultado en el formateo para cada puerto

de salida.

7. En la suma y multiplicación no hay orden de ingreso de los datos de entrada. El producto será

truncado a 13 bits en todos los casos.

8. En la resta y división el puerto C será minuendo y dividendo respectivamente. En caso de inversión

de operandos: la diferencia deberá ser mostrada en C-2 con n=13 bits y rutina de error escogida

en caso de error.

9. Velocidad de procesamiento a 16 Mhz.

10. Voltaje de alimentación a 5.0 Voltios, suministrado por módulo reductor y convertidor de Ac a DC

en el rango de 6.5 a 12.0 Voltios con al menos 250 mA de corriente.
