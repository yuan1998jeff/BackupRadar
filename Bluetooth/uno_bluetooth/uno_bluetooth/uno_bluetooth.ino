#include <SoftwareSerial.h>

// To run on Arduino Uno (Master)
SoftwareSerial BTSerial(2, 3); // RX | TX

int dist1 = 10;
int dist2 = 20;
int dist3 = 30;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Arduino UNO with HC-06 is ready");

    BTSerial.begin(9600);   
    Serial.println("BTSerial started at 9600");
}

void loop() {
    /*
    for(int i=0; i < 3; i++) {
      Serial.write(distances[i]);
      BTSerial.write(distances[i]);  
    }
    */
    Serial.println("Sending distance data.");
    Serial.println(dist1);
    Serial.println(dist2);
    Serial.println(dist3);
    
    BTSerial.write(dist1);
    BTSerial.write(dist2);
    BTSerial.write(dist3);
    delay(1000);
}
