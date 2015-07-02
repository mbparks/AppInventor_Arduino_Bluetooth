#include <SoftwareSerial.h>

#define _pin_RX 10
#define _pin_TX 11
#define _pin_LED 13
#define _cmd_LED_OFF 0
#define _cmd_LED_ON 1

SoftwareSerial HC(_pin_RX, _pin_TX);
int BluetoothData; 

void setup() {
  HC.begin(9600);
  HC.println("Bluetooth Enabled! Press 1 to turn LED13 ON, 0 to turn OFF.");
  pinMode(_pin_LED,OUTPUT);
  digitalWrite(_pin_LED, _cmd_LED_OFF);
}

void loop() {
  if (HC.available()){
    BluetoothData=HC.read();
    if(BluetoothData=='1'){
      digitalWrite(_pin_LED, _cmd_LED_ON);
      HC.println("LED is ON");
    }
    if (BluetoothData=='2'){
      digitalWrite(_pin_LED, _cmd_LED_OFF);
      HC.println("LED is OFF");
    }
  }
  delay(100);
}

