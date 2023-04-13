# hardware_development

Adaptation of interaction devices for people with physical disabilities in the upper limbs
Universidad Nacional de Colombia
Jan 2016 - Dec 2019

Three types of devices were developed to validate the adaptation model proposed in my doctoral thesis. The first one was called IMU-Mouse and its operation was based on head movements. The second type of device was a Joystick. Both prototypes could be programmed to perform the interaction actions of a pointing device. The last type was the keyboard. Particularly, two keyboards were developed -one with six keys and one with 18 keys-. The Keys could be programmed to perform any interaction action. The versatility of the previous prototypes to change both the form and the functionalities was used to adapt devices according to the interaction needs of the users.  All the adaptation processes were assisted by a group of engineers.

**

Tech stack: C++ -the language of the Arduino IDE is based on it-, Teensy 3.2 and Arduino Micro development boards, Bluetooth HCI RN-42, IMU MPU-9250 and Joystick Gravity V2.

Tools: Arduino IDE 1.8.1 and Teensyduino 1.49.

**

Engineering team:

David Buriticá Ortegon
email: dburiticao@unal.edu.co

Manuel Alejandro Pérez
email: mperezt@unal.edu.co

Luis Felipe García
email: lufgarciaar@unal.edu.co

Aldemir Vargas Eudor
email: avargase@unal.edu.co

**

Device details and some adaptation examples are available below.

 .
 
 .
 
*** IMU-Mouse ***

CÓDIGO FUENTE EN: XXXXXXXXX
CÓDIGO FUENTE del Bluetooth en: XXXXXXX

En las figuras 1 y 2  se ilustran las acciones de interacción que se implementaron en el dispositivo: desplazamiento del cursor y clic. Para la acción de desplazamiento se desea que el usuario relacione de manera intuitiva los movimientos de la cabeza con los movimientos del cursor (Fig. 1). El desplazamiento horizontal se obtiene a través del desplazamiento angular sobre el eje transversal de la cabeza. El movimiento vertical del cursor a partir del desplazamiento angular de la cabeza sobre su eje longitudinal. Para la acción de clic se seleccionó un movimiento que consiste en generar un cambio marcado de aceleración asintiendo con la cabeza (Fig. 2).

Figure 1

![desplazamiento](https://user-images.githubusercontent.com/116608938/231599644-7c55861f-ead5-49a9-aebc-a1195f6963ee.png)

Figure 2

![clic](https://user-images.githubusercontent.com/116608938/231599828-8b40e5cc-463f-452c-afd0-b5610722e95a.png)

Como sistema de medida del mouse se utiliza la tarjeta IMU GY-85 que posee un acelerómetro digital ADXL-345, un giroscopio ITG-3205 y un magnetómetro HMC5853L. Los sistemas se ubican sobre una diadema para que el dispositivo permanezca estable en la cabeza del usuario (Fig. 3). En el ADXL-345 las variaciones de aceleración son medidas a lo largo de los ejes x, y e z. Cuando el cambio de aceleración se produce en la dirección de los ejes se toma como positiva, en caso contrario se toma como negativa. Para la aceleración se usa como unidad de medida la fuerza g, en donde 1 g equivale a la gravedad terrestre (9,806 m/ s2 ). El ITG-3205 entrega tres medidas de la velocidad con la cual cada uno de los ejes x, y e z rotan sobre sí mismos. La velocidad se mide en grados sobre segundo (°/s) y para este caso se toman como positiva cuando los movimientos están a favor de las manecillas del reloj.

Figure 3

![imumousediseno](https://user-images.githubusercontent.com/116608938/231600101-6333fb48-069d-4283-bb89-2a4ec42cfc54.png)

En la figura 4 se presenta la implementación física del dispositivo: la integración de la IMU y el Arduino sobre un circuito impreso, la caja contenedora del circuito con un orificio que permite la conexión micro USB, y el dispositivo que se ubica sobre la cabeza de un usuario sin brazos.

Figure 4

![imumouse_implementacion](https://user-images.githubusercontent.com/116608938/231600456-c530d5b1-6c58-4558-b901-6ee37cef1846.png)

La versión inalámbrica del IMU-Mouse es presentada en la figura 5. En esta versión son adicionados el Bluetooth RN-42 –embebido en la placa SparkFun Bluetooth Mate Silver– y una batería Lipo con salida de 3.7V y capacidad de 1100 mAh.

Figure 5

![Imu_mouse_ini](https://user-images.githubusercontent.com/116608938/231603412-df2153b6-3046-49c4-bc24-03e9fcce8abe.png)

La versión final del IMU-Mouse es presentada en la figura 6. En este caso la IMU GY-85 es sustituida por la SparkFun Breakout IMU MPU-9250. La tarjeta de desarrollo electrónica Arduino Pro Micro se sustituyó por la Teensy 3.2. El prototipo se montó sobre la diadema del dispositivo NeuroSky MindWave Mobile 2 la cual es más liviana y tiene un mejor ajuste.

Figure 6

![imu_mouse_pro2](https://user-images.githubusercontent.com/116608938/231605984-8642cc7b-680e-4f9d-adfd-8718ceee878d.png)

 .
 
 .
 
*** Keyboard ***

CÓDIGO FUENTE EN: XXXXXXXXX
CÓDIGO FUENTE del Bluetooth en: XXXXXXX

El teclado debe facilitar su operación a las personas con dificultades en las articulaciones o en los huesos. Esta facilidad se debe extender a las singularidades de los músculos que varían en fuerza, tono, o resistencia. El dispositivo también debe atender las necesidades a nivel de las estructuras corporales, por ejemplo, la ausencia total de extremidades superiores. La asistencia del aparato debe prestarse en al interacción con las aplicaciones de software que el usuario requiera. Además, el teclado debe adecuarse a las características físicas del entorno en donde se usa el computador.

Para atender los requerimientos expuestos en el párrafo anterior se utilizaron las ventajas tecnológicas disponibles. La estrategia que se emplea para activar las teclas requiere de poco esfuerzo físico. El tamaño y la forma de las teclas se puede variar así como el material de su construcción. El tamaño del teclado se puede personalizar para adecuarse a cualquier espacio de trabajo y se conecta al computador vía Bluetooth. La robustez física y la comunicación inalámbrica permiten que el dispositivo se opere con los pies. Las teclas son programables con cualquier función que realice un teclado incluidos los comandos abreviados del sistema Windows (p. ej., \textit{CTRL + C} que ejecuta la acción de copiar).

Para el caso en los que se requiere registrar la fuerza por la presión plantar, los transductores capacitivos y resistivos son los dos tipos de uso frecuente para llevar a cabo estas  medidas. El transductor que se utiliza en el teclado es una hoja conductiva sensible a la fuerza llamada Velostat que varía su resistencia. El Velostat es un resistor sensible a la fuerza (FSR) cuyo valor de resistencia disminuye cuando se aplica una presión sobre él. El diseño del teclado consiste en un arreglo de dos capas; una capa conductora que se implementa como un circuito impreso rígido (PCB rígida) y la capa del FSR (Velostat). El arreglo PCB-Velostat facilita la interacción a las personas con discapacidad porque no se requiere de un esfuerzo elevado para activar las teclas. En las figuras 7 y 8 se presentan respectivamente el diseño y la implementación de la PCB rígida que contiene una matriz de muestreo de tipo Shunt.

Figure 7

![PCB1_teclado](https://user-images.githubusercontent.com/116608938/231616049-05ebc34a-cd44-4bcb-8897-7bc7a3f204de.png)

Figure 8

![PCB_teclado](https://user-images.githubusercontent.com/116608938/231616264-3ed3fc03-dffc-4b18-931e-946c5730b6c9.png)

Con el objetivo de variar el tamaño del teclado, el contorno de las PCB se perfora con una terminación que se denomina ``Castellated''. Esta estrategia permite conectar en fila o columna varias PCB con el fin de agregar nuevas teclas (Fig. 9).

Figure 9

![castellated_teclado](https://user-images.githubusercontent.com/116608938/231617340-18d414c1-6aa1-4d10-8234-5daabf2c512d.png)

El contacto directo de la PCB con el Velostat se evita por medio de un separador adhesivo (Fig. 10). Para la fabricación de las bases de los teclados se utilizó una máquina CNC para cortar el acrílico (Fig. 11). El botón se eligió mediante pruebas de ensayo y error a partir de un conjunto de 7 botones que varían en diseño y rigidez (Fig. 12).

Figure 10. Partes del teclado: 1. Tuercas, 2. Sujetadores, 3. Botones, 4. Separador adhesivo, 5. PCB auxiliar, 6. PCB, 7. Soporte, 8. Tornillos.

![explosion](https://user-images.githubusercontent.com/116608938/231619691-afb4bac8-a3d0-4fdd-99ea-f1b5ee2bb563.png)

Figure 11

![fab_baseteclados](https://user-images.githubusercontent.com/116608938/231619713-b6e4c24c-8e63-475f-8c5d-28ba67829e20.png)

Figure 12

![siete_botones](https://user-images.githubusercontent.com/116608938/231619726-962b9a68-2c8a-4a3b-8ce2-df8523c0d943.png)

El pulsador de la figura 13 se seleccionó porque tanto la superficie plana como la forma de la base reducen la fuerza que se requiere para teclear. Al mismo tiempo, el diseño previene la activación accidental que causa la sensibilidad de los sensores. El tamaño del botón es adecuado para que se pueda operar con la mano, el pie o muñón. La fabricación se hizo con una impresora 3D y el material que se utilizó fue el poliuretano termoplástico (TPU, por su sigla en inglés).

Figure 13

![boton_selecionado](https://user-images.githubusercontent.com/116608938/231620648-2a489d21-1a7e-49a8-8b8a-a3e284bf34ff.png)

Una PCB adicional se desarrolló para integrar el teclado, la tarjeta de desarrollo Arduino Micro, el módulo SparkFun Bluetooth Mate Silver RN-42, y una batería de tipo Lipo (Fig. 14). Las partes del teclado se ensamblan y se conectan a esta PCB mediante un cable jumper flexible plano de 30 pines FFC/FPC (Fig. 15). La matriz de muestreo de las PCB que se combinan con el Velostat tienen un tamaño de 2x3. Una membrana de TPU une 6 botones de tal manera que coinciden con la disposición de cada matriz de muestreo (Fig. 16). La estructura ``Castelleted'' permite conectar en fila 3 PCB para formar el teclado de 18 botones. Finalmente se programan rutinas para asignar funciones a cada una de las teclas.

Figure 14

![PCB_teclado21](https://user-images.githubusercontent.com/116608938/231626563-3a1c3a35-f40a-461c-b035-f7fb07aad340.png)

Figure 15


![ensamblaje_teclado](https://user-images.githubusercontent.com/116608938/231627031-4a07b2fd-a28d-448b-808d-9beb59eff489.png)

Figure 16

![botones_matriz](https://user-images.githubusercontent.com/116608938/231627059-dba55b8f-4f90-42dc-959e-deaf91ea5665.png)

 .
 
 .
 
*** Joystick ***

CÓDIGO FUENTE EN: XXXXXXXXX
CÓDIGO FUENTE del Bluetooth en: XXXXXXX

Este dispositivo se puede configurar para ejecutar las funciones de un dispositivo apuntador (función de desplazamiento del puntero, clic, doble clic, o scroll). Una de las propiedades de este aparato consiste en que la forma de la palanca de mando puede variar según las características del usuario. Esta propiedad es relevante porque con ella se podrían atender las necesidades de personas con dificultades en las estructuras o funciones de los dedos, o en los músculos (debido a la fuerza, al tono, o la resistencia).

El módulo seleccionado es el joystick Gravity V2. Este módulo tiene tres ejes -X, Y, y Z.  El eje Z incluye un botón digital que se activa si la palanca se presiona desde arriba. El joystick se conecta a la Teensy 3.2 que envía las acciones de interacción mediante el módulo Bluetooth RN-45 (Fig. 17).

Figure 17

![esquema_joystick](https://user-images.githubusercontent.com/116608938/231632577-e62dce79-23a8-4ed7-9ada-3eb6f2f12d63.png)

 .
 
 .
 
*** Ejemplos de soluciones de interacción construidos a partir de los prototipos mencionados anteriormente ***

Example 1: combinación del joystick y el teclado de 6 botones (Figs. 18 and 19). Esta combinación atiende las  necesidades de interacción de una mano metacarpiana con trasplante de dedos del pie. Por medio del joystick se mueve el puntero en la pantalla. Por medio del teclado se ejecutan el click, left click, scroll up, scroll down and Ctrl+Alt+Supr.

Figure 18

![it2_teclado](https://user-images.githubusercontent.com/116608938/231831944-6e1afa19-af80-434c-b2ae-6f37d542ea7b.png)

Figure 19

![part1_it2](https://user-images.githubusercontent.com/116608938/231831990-e2647e88-026d-4ea1-b3f9-f46dd8d25a95.png)

Example 2: combinación del IMU-Mouse y el teclado de 6 botones (Fig. 20). Esta combinación atiende las  necesidades de interacción de una mano metacarpiana con trasplante de dedos del pie. Por medio del IMU-Mouse se mueve el puntero en la pantalla. Por medio del teclado se ejecutan las acciones restantes de un dispositivo apuntador.

Fig. 


This repository contains the code of different electronic interaction devices. In some cases the photographic record is included. The devices were developed for people with physical disabilities in the upper extremities. For the development, the Arduino micro, the Teensy 3.2, the Bluetooth HCI RN-42, an inertial measurement unit, a joystick, and a set of electrodes were used. Computer-Aided Design (CAD) and 3D printing were also used for the construction of the devices.
