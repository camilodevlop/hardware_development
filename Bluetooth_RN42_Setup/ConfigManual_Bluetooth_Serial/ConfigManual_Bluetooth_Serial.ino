#define SerialPort Serial

void setup() {
  SerialPort.begin(115200);
  Serial1.begin(115200);   // Arduino - Bluetooth


}

void loop() {
  if (SerialPort.available()) {
    Serial1.write(Serial.read());
  }

  if (Serial1.available()) {
    SerialPort.write(Serial1.read());
  }
}
