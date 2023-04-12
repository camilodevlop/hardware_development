# hardware_development

Adaptation of interaction devices for people with physical disabilities in the upper limbs
Universidad Nacional de Colombia
Jan 2016 - Dec 2019

Three types of devices were developed to validate the adaptation model proposed in my doctoral thesis. The first one was called IMU-Mouse and its operation was based on head movements. The second type of device was a Joystick. Both prototypes could be programmed to perform the interaction actions of a pointing device. The last type was the keyboard. Particularly, two keyboards were developed -one with six keys and one with 18 keys-. The Keys could be programmed to perform any interaction action. The versatility of the previous prototypes to change both the form and the functionalities was used to adapt devices according to the interaction needs of the users.  All the adaptation processes were assisted by a group of engineers.

**

Tech stack: C++ -the language of the Arduino IDE is based on it-, Teensy 3.2 and Arduino Micro development boards, Bluetooth HCI RN-42, IMU MPU-9250 and Joystick Gravity V2.

Tools: Arduino IDE 1.8.5 and Teensyduino 1.58.

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






This repository contains the code of different electronic interaction devices. In some cases the photographic record is included. The devices were developed for people with physical disabilities in the upper extremities. For the development, the Arduino micro, the Teensy 3.2, the Bluetooth HCI RN-42, an inertial measurement unit, a joystick, and a set of electrodes were used. Computer-Aided Design (CAD) and 3D printing were also used for the construction of the devices.
