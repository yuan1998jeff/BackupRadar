#include <SoftwareSerial.h>

// To run on Arduino UNO
SoftwareSerial BTSerial(0, 1); // RX | TX
char c ='Z';
void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Arduino UNO with HC-06 is ready");

    BTSerial.begin(9600);   
    Serial.println("BTSerial started at 9600");

}
//
void loop() {
    BTSerial.write(c);
    delay(1000);
    
    
}
