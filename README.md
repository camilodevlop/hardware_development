# hardware_development

Adaptation of interaction devices for people with physical disabilities in the upper limbs

Universidad Nacional de Colombia

Jan 2016 - Dec 2019

Three types of devices were developed to validate the adaptation model proposed in my doctoral thesis. The first one was called IMU-Mouse and its operation was based on head movements. The second type of device was a Joystick. Both prototypes could be programmed to perform the interaction actions of a pointing device. The last type was the keyboard. Particularly, two keyboards were developed -one with six keys and one with 18 keys-. The Keys could be programmed to perform any interaction action. The versatility of the previous prototypes to change both the form and the functionalities was used to adapt devices according to the interaction needs of the users.  All the adaptation processes were assisted by a group of engineers.

**

Tech stack: C++ -the language of the Arduino IDE is based on it-, Teensy 3.2 and Arduino Micro development boards, Bluetooth HCI RN-42, IMU MPU-9250 and Joystick Gravity V2.

Tools: Arduino IDE 1.8.1 and Teensyduino 1.49.

**

Engineering team: most of their responsibilities were aimed at building the structure of the devices using Computer Aided Design (CAD), printed circuit board design, 3D printing, and some programming tasks.

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

The source code is available in the Head_Mouse and Bluetooth_RN42_Setup directories.

Figures 1 and 2 illustrate the interaction actions that were implemented in the device: pointer movement and click. For the movement action, it is desired that the user intuitively relates the head movements with the movements of the pointer (Fig. 1). The horizontal displacement is carried out through the angular displacement on the transverse axis of the head. The vertical movement of the pointer is performed by means of the angular displacement of the head on its longitudinal axis. Finally, a movement that consists of generating a marked change of acceleration by nodding the head executes the click (Fig. 2).

Figure 1

![desplazamiento](https://user-images.githubusercontent.com/116608938/231599644-7c55861f-ead5-49a9-aebc-a1195f6963ee.png)

Figure 2

![clic](https://user-images.githubusercontent.com/116608938/231599828-8b40e5cc-463f-452c-afd0-b5610722e95a.png)

The GY-85 IMU that has an ADXL-345 digital accelerometer, an ITG-3205 gyroscope and a HMC-5853L magnetometer is used as the mouse measurement system. The systems are placed on a headband so that the device remains stable on the user's head (Fig. 3). In the ADXL-345 the acceleration variations are measured along the x, y and z axes. When the change of acceleration occurs in the same direction of the axes, it is taken as positive, otherwise it is taken as negative. For acceleration, the g-force is used as the unit of measurement, where 1 g is equivalent to Earth's gravity (9.806 m/s2). The speed is measured in degrees per second (°/s) and in this case it is considered as positive when the movements are clockwise.

Figure 3

![imumousediseno](https://user-images.githubusercontent.com/116608938/231600101-6333fb48-069d-4283-bb89-2a4ec42cfc54.png)

Figure 4 shows the physical implementation of the device: the integration of the IMU and the Arduino on a printed circuit, the box containing the circuit with a hole that allows the micro USB connection, and the device that is located on the head of a user without arms.

Figure 4

![imumouse_implementacion](https://user-images.githubusercontent.com/116608938/231600456-c530d5b1-6c58-4558-b901-6ee37cef1846.png)

The wireless version of the IMU-Mouse is presented in figure 5. In this version, the RN-42 Bluetooth –embedded in the SparkFun Bluetooth Mate Silver board– and a Lipo battery with 3.7V output and 1100 mAh capacity are added.

Figure 5

![Imu_mouse_ini](https://user-images.githubusercontent.com/116608938/231603412-df2153b6-3046-49c4-bc24-03e9fcce8abe.png)

The final version of the IMU-Mouse is presented in figure 6. In this case, the IMU GY-85 is replaced by the SparkFun Breakout IMU MPU-9250. The Arduino Pro Micro electronic development board is replaced by the Teensy 3.2. The prototype was mounted on the NeuroSky MindWave Mobile 2 device's headband which is lighter and has a better fit.

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

Example 2: adaptación de un dispositivo apuntador usando el joystick (Figs. 20-24). Este dispositivo atiende las  necesidades de interacción de una mano metacarpiana con trasplante de dedos del pie.

Figure 20

![IMG_20200129_115946](https://user-images.githubusercontent.com/116608938/231889770-e200fcde-3b26-4596-9c2c-7a21178792b6.jpg)

Figure 21

![fit2_7](https://user-images.githubusercontent.com/116608938/231890106-7df38d9b-5516-4a16-82b1-208f1b730250.png)

Figure 22

![Joystick_based_pointing](https://user-images.githubusercontent.com/116608938/231890928-682383dc-bf2e-4d6c-bc4e-a6f864036ecc.png)

Figure 23

![IMG_222](https://user-images.githubusercontent.com/116608938/231891081-810ab185-00e1-4a64-a41d-e8cb1557e7c1.jpg)

Figure 24

![fit2_17](https://user-images.githubusercontent.com/116608938/231891217-b498d5ff-0175-474d-80b6-67be07747bc6.png)

Example 3: combinación del IMU-Mouse y el teclado de 6 botones (Fig. 25). Esta combinación atiende las  necesidades de interacción de una mano metacarpiana con trasplante de dedos del pie. Por medio del IMU-Mouse se mueve el puntero en la pantalla. Por medio del teclado se ejecutan las acciones restantes de un dispositivo apuntador.

Figure 25

![part1_it1](https://user-images.githubusercontent.com/116608938/231892701-bbaaf89c-193f-4222-83c5-fc785f7a7307.png)

Example 4: combinación del joystick y el teclado de 6 botones. Esta combinación atiende las  necesidades de interacción de un usuario con parálisis parcial en las extremidades superiores. El usuario utiliza férulas porque no puede mover las manos. Por medio del joystick se mueve el puntero en la pantalla. Se construye un soporte para el brazo en el cual se incluye el joystick (Figs. 26 and 27). También se adapta una nueva palanca al joystick para facilitar la interacción (Fig. 28). Por medio del teclado se ejecutan el click, left click, scroll up, scroll down and Ctrl+Alt+Supr.

Figure 26

![part2_joystick_sop3](https://user-images.githubusercontent.com/116608938/231895327-42241166-cd0a-446c-b678-1c0757acc3d1.png)

Figure 27

![part2_joystick_sop4](https://user-images.githubusercontent.com/116608938/231895377-c35c6d54-7c2f-41cd-96b8-769ded1f43a8.png)

Figure 28

![part2_joystick_sop2](https://user-images.githubusercontent.com/116608938/231895560-dea21801-285b-4aac-8b6c-f33e072faf04.png)
