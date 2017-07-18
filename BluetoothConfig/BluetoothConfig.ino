#include <SoftwareSerial.h>

const byte rxPin = 10;
const byte txPin = 11;

SoftwareSerial MyBluetoothModule(rxPin, txPin);

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  
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
