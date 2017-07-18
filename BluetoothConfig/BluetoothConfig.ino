#include <SoftwareSerial.h>
SoftwareSerial MyBluetoothModule(10, 11);

void setup() {
  MyBluetoothModule.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if (MyBluetoothModule.available()) {
    Serial.write(MyBluetoothModule);
  }
  if (Serial.available()) {
    MyBluetoothModule.write(Serial.read());
  }
}
