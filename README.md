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

The source code is available in the Keyboard and Bluetooth_RN42_Setup directories.

The keyboard must be easy to operate for people with joint or bone difficulties. This facility must be extended to the peculiarities of muscles that vary in strength, tone, or resistance. The device must also meet the needs at the level of body structures, for example, the total absence of upper extremities. In addition, the device must be adapted to the required software applications and the physical environment in which the computer is used.

To meet the requirements set forth in the previous paragraph, the available technological advantages are used. The strategy adopted to activate the keys requires little physical effort. The size and shape of the keys can be varied as well as the material of their construction. The keyboard's size can be customized to fit any workspace, and it connects to your computer via Bluetooth. The physical robustness and wireless communication allow the device to be operated by the feet. The keys are programmable with any function a keyboard performs, including Windows system shortcuts (e.g., CTRL + C).

If the force by plantar pressure is required, both the capacitive and resistive transducers are two of the most common to measure it. The transducer used in the keyboard is a force-sensitive conductive sheet called Velostat. The Velostat is a Force Sensitive Resistor (FSR) whose electrical resistance value decreases when pressure is applied to it. For the keyboard, a design consisting of two layers was proposed; one of the layers is implemented by means of a rigid printed circuit board (rigid PCB), and the remaining layer is the FSR Velostat. The PCB-Velostat arrangement facilitates interaction for people with disabilities because the keys do not require a great physical effort to be activated. Figures 7 and 8 respectively present the design and implementation of the rigid PCB that contains a Shunt-type sampling matrix.

Figure 7

![PCB1_teclado](https://user-images.githubusercontent.com/116608938/231616049-05ebc34a-cd44-4bcb-8897-7bc7a3f204de.png)

Figure 8

![PCB_teclado](https://user-images.githubusercontent.com/116608938/231616264-3ed3fc03-dffc-4b18-931e-946c5730b6c9.png)

In order to vary the size of the keyboard, the outline of the PCBs is perforated with a finish called ``Castellated''. This strategy allows connecting several PCBs in a row or column in order to add new keys (Fig. 9).

Figure 9

![castellated_teclado](https://user-images.githubusercontent.com/116608938/231617340-18d414c1-6aa1-4d10-8234-5daabf2c512d.png)

Direct contact of the PCB with the Velostat is prevented by means of an adhesive spacer (Fig. 10). For the manufacture of the keyboard bases, a CNC machine was used to cut the acrylic (Fig. 11). The button was chosen by trial and error from a set of 7 buttons that vary in design and stiffness (Fig. 12).

Figure 10. Keyboard parts: 1. Nuts, 2. Fasteners, 3. Buttons, 4. Adhesive spacer, 5. Auxiliary PCB, 6. PCB, 7. Base, 8. Screws.

![explosion](https://user-images.githubusercontent.com/116608938/231619691-afb4bac8-a3d0-4fdd-99ea-f1b5ee2bb563.png)

Figure 11

![fab_baseteclados](https://user-images.githubusercontent.com/116608938/231619713-b6e4c24c-8e63-475f-8c5d-28ba67829e20.png)

Figure 12

![siete_botones](https://user-images.githubusercontent.com/116608938/231619726-962b9a68-2c8a-4a3b-8ce2-df8523c0d943.png)

The switch in figure 13 was selected because both the flat surface and the shape of the base reduce the force required to type. At the same time, the design prevents accidental activation that causes sensitivity of the sensors. The button size is suitable for hand, foot or stump operation. The manufacturing was done with a 3D printer, and the material used was Thermoplastic Polyurethane (TPU).

Figure 13

![boton_selecionado](https://user-images.githubusercontent.com/116608938/231620648-2a489d21-1a7e-49a8-8b8a-a3e284bf34ff.png)

An additional PCB was developed to integrate the keyboard, the Arduino Micro development board, the SparkFun Bluetooth Mate Silver RN-42 module, and a Lipo type battery (Fig. 14). The keyboard parts are assembled and connected to this PCB via a 30-pin FFC/FPC flat flexible jumper cable (Fig. 15). The sampling matrix of the PCBs that are combined with the Velostat are 2x3 in size. A TPU membrane joins 6 buttons in such a way that they match the layout of each sampling array (Fig. 16). The ``Castellated'' structure allows 3 PCBs to be connected in a row to form the 18-button keyboard. Finally, routines are programmed to assign functions to each of the keys.

Figure 14

![PCB_teclado21](https://user-images.githubusercontent.com/116608938/231626563-3a1c3a35-f40a-461c-b035-f7fb07aad340.png)

Figure 15


![ensamblaje_teclado](https://user-images.githubusercontent.com/116608938/231627031-4a07b2fd-a28d-448b-808d-9beb59eff489.png)

Figure 16

![botones_matriz](https://user-images.githubusercontent.com/116608938/231627059-dba55b8f-4f90-42dc-959e-deaf91ea5665.png)

 .
 
 .
 
*** Joystick ***

The source code is available in the Mouse_Joystick_Buttons and Bluetooth_RN42_Setup directories.

This device can be configured to perform the functions of a pointing device (pointer movement function, click, double click, or scroll). One of the properties of this device is that the shape of the joystick can vary according to the characteristics of the user. This property is relevant to meet the needs of people with difficulties in the fingers or muscles due to strength, tone, or resistance. 

The selected module is the Gravity V2 joystick. This module has three axes -X, Y, and Z. The Z axis includes a digital button that is activated if the stick is pressed from above. The joystick is connected to the Teensy 3.2 which sends the interaction actions through the RN-45 Bluetooth module (Fig. 17).

Figure 17

![esquema_joystick](https://user-images.githubusercontent.com/116608938/231632577-e62dce79-23a8-4ed7-9ada-3eb6f2f12d63.png)

 .
 
 .
 
*** Examples of interaction solutions built from the prototypes mentioned above ***

Example 1: joystick and 6-button keyboard combination (Figs. 18 and 19). This combination addresses the interaction needs of a metacarpal hand with toes transplant. By means of the joystick, the pointer is moved on the screen. Using the keyboard, click, left click, scroll up, scroll down and Ctrl + Alt + Del are executed.

Figure 18

![it2_teclado](https://user-images.githubusercontent.com/116608938/231831944-6e1afa19-af80-434c-b2ae-6f37d542ea7b.png)

Figure 19

![part1_it2](https://user-images.githubusercontent.com/116608938/231831990-e2647e88-026d-4ea1-b3f9-f46dd8d25a95.png)

Example 2: adaptation of a pointing device using the joystick (Figs. 20-24). This device addresses the interaction needs of a metacarpal hand with toes transplant.

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

Example 3: IMU-Mouse and 6-button keyboard combination (Figs. 18 and 19). This combination addresses the interaction needs of a metacarpal hand with toes transplant. By means of the IMU-Mouse, the pointer is moved on the screen. The remaining actions of a pointing device are executed by means of the keyboard.

Figure 25

![part1_it1](https://user-images.githubusercontent.com/116608938/231892701-bbaaf89c-193f-4222-83c5-fc785f7a7307.png)

Example 4: joystick and 6-button keyboard combination. This combination addresses the interaction needs of a user with partial paralysis in the upper extremities. The wearer wears splints because he cannot move his hands. By means of the joystick, the pointer is moved on the screen. A support for the arm is built in which the joystick is included (Figs. 26 and 27). A new lever is also adapted to the joystick to facilitate interaction (Fig. 28). Using the keyboard, click, left click, scroll up, scroll down and Ctrl + Alt + Del are executed.

Figure 26

![part2_joystick_sop3](https://user-images.githubusercontent.com/116608938/231895327-42241166-cd0a-446c-b678-1c0757acc3d1.png)

Figure 27

![part2_joystick_sop4](https://user-images.githubusercontent.com/116608938/231895377-c35c6d54-7c2f-41cd-96b8-769ded1f43a8.png)

Figure 28

![part2_joystick_sop2](https://user-images.githubusercontent.com/116608938/231895560-dea21801-285b-4aac-8b6c-f33e072faf04.png)
