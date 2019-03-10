//For left LED
int redpinL = 2; 
int bluepinL = 3; 
int greenpinL = 4 ;
//For middle LED
int redpinM = 5; 
int bluepinM = 6; 
int greenpinM = 7;
//For right LED
int redpinR = 8; 
int bluepinR = 9; 
int greenpinR = 10;
int buzzer = 11; 

int cmL,cmM, cmR; // distacnes received from bluetooth

void setup(){
  pinMode(buzzer, OUTPUT);
  
  pinMode (redpinL, OUTPUT);
  pinMode (bluepinL, OUTPUT);
  pinMode (greenpinL, OUTPUT);
  pinMode (redpinM, OUTPUT);
  pinMode (bluepinM, OUTPUT);
  pinMode (greenpinM, OUTPUT);
  pinMode (redpinR, OUTPUT);
  pinMode (bluepinR, OUTPUT);
  pinMode (greenpinR, OUTPUT);
}

void loop(){
  //For buzzer
  if (cmL < 20 || cmM < 20 || cmR < 20) {
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(200);      
  noTone(buzzer);     // Stop sound...
  delay(200);      
  }
  else if ( ((cmL > 20) && (cmL < 40)) || ((cmM > 20) && (cmM < 40)) || ((cmM > 20) && (cmM < 40)) ) {
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(200);      
  noTone(buzzer);     // Stop sound...
  delay(600);      
  }
  else {
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(200);      
  noTone(buzzer);     // Stop sound...
  delay(1000);      
  }

  // Left lED
  if (cmL < 20) {
  analogWrite (redpinL, 255);
  analogWrite (bluepinL, 0);
  analogWrite (greenpinL, 0);
  }
  else if ((cmL > 20) && (cmL < 40)) {
  analogWrite (redPinL, 150);
  analogWrite (bluepinL, 50);
  analogWrite (greenpinL, 0);
  }
  else if (cmL > 40) {
  analogWrite (redpinL, 0);
  analogWrite (bluepinL, 255);
  analogWrite (greenpinL, 0);
  } 

  //Middle LED
  if (cmM < 20) {
  analogWrite (redpinM, 255);
  analogWrite (bluepinM, 0);
  analogWrite (greenpinM, 0);
  }
  else if ((cmM > 20) && (cmM < 40)) {
  analogWrite (redPinM, 150);
  analogWrite (bluepinM, 50);
  analogWrite (greenpinM, 0);
  }
  else if (cmM > 40) {
  analogWrite (redpinM, 0);
  analogWrite (bluepinM, 255);
  analogWrite (greenpinM, 0);
  } 

  //Right LED
  if (cmR < 20) {
  analogWrite (redpinR, 255);
  analogWrite (bluepinR, 0);
  analogWrite (greenpinR, 0);
  }
  else if ((cmR > 20) && (cmR < 40)) {
  analogWrite (redPinR, 150);
  analogWrite (bluepinR, 50);
  analogWrite (greenpinR, 0);
  }
  else if (cmR > 40) {
  analogWrite (redpinR, 0);
  analogWrite (bluepinR, 255);
  analogWrite (greenpinR, 0);
  } 
  
}
