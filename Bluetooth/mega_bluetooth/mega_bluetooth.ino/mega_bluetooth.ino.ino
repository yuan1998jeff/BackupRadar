#include <SoftwareSerial.h>

// To run on Arduino Mega
SoftwareSerial BTSerial(12, 13); // RX | TX

int distances[3];

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
      Serial.println("Received a message!");
      
      int dist1 = (int) BTSerial.read();
      int dist2 = (int) BTSerial.read();
      int dist3 = (int) BTSerial.read();
      
      Serial.println(dist1);
      Serial.println(dist2);
      Serial.println(dist3);      
    }
    
    delay(10);
}
