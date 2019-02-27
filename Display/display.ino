#include <UTFT.h> // Open source TFT library
#include <memorysaver.h>

#include <stdio.h>  // asprintf

#define DISPLAY_MODEL   CTE32HR 
#define SDA             38
#define SCL             39
#define CS              40
#define RST             41



extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

// Construct a TFT instance
UTFT tft = UTFT(DISPLAY_MODEL, SDA, SCL, CS, RST);


void setup() {
  // put your setup code here, to run once:
  tft.InitLCD();

  // Set screen to have a black background
  tft.clrScr();

  // Set the font size
  tft.setFont(BigFont);

  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

  // TODO: Read from sensors, and then read data from Bluetooth
  float d1 = 7.0;
  float d2 = 9.0;
  float d3 = 11.0;

  displayDigits(d1, d2, d3);
  
  delay(100);

}

void displayDigits(float d1, float d2, float d3) {
  d1 = 7.0;
  d2 = 8.0;
  d3 = 9.0;


  int width = tft.getDisplayXSize();
  int height = tft.getDisplayYSize();

  int h_spacing = 10;
  
  int x1 = h_spacing;
  int x2 = width / 3 + h_spacing;
  int x3 = 2*width / 3 + h_spacing;

  tft.setFont(BigFont);
  
  tft.print("D1: ", x1, 100);
  tft.print("D2: ", x2, 100);
  tft.print("D3: ", x3, 100);

  
  tft.setFont(SevenSegNumFont);

  tft.drawRect(x1-5, 80, x2-2*h_spacing,  240);
  tft.drawRect(x2-5, 80, x3-2*h_spacing,  240);
  tft.drawRect(x3-5, 80, width-h_spacing, 240);
  
  // Display digits to screen
  tft.printNumF(d1, 2, 2*h_spacing,  180);
  tft.printNumF(d2, 2, x2+h_spacing, 180);
  tft.printNumF(d3, 2, x3+h_spacing, 180);
}
