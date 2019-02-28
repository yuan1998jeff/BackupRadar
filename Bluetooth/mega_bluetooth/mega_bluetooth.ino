#include <SoftwareSerial.h>

// To run on Arduino UNO
SoftwareSerial BTSerial(0, 1); // RX | TX
char c =' ';
void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Arduino UNO with HC-06 is ready");

    BTSerial.begin(9600);   
    Serial.println("BTSerial started at 9600");

}
//
void loop() {
    // Keep reading from HC-05 and send to Arduino Serial Monitor
    if (BTSerial.available())
    {  
        c = BTSerial.read();
        Serial.write(c);
    }
 
    // Keep reading from Arduino Serial Monitor and send to HC-05
    if (Serial.available())
    {
        c =  Serial.read();
 
        // mirror the commands back to the serial monitor
        // makes it easy to follow the commands
        Serial.write(c);   
        BTSerial.write(c);  
    }
}
