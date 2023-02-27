// Grace Bost && Layton Gant 
#include <Elegoo_GFX.h>    // Core graphics library
#include <Elegoo_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>
#include <stdio.h>
#include <string.h>
#include "GUI_Functions.h"
#include "Buttons.h"
#include "Test_Cable.h"
#include "Results.h"
#include "Cable_Definition.h"
// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

uint8_t textfield_i=0;
char textfield[TEXT_LEN+1] = "";

//Elegoo set up
extern Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
//Button Definitions
Elegoo_GFX_Button  buttons[10];
Elegoo_GFX_Button  cables[14];

/* Button Creation */
char buttonlabels[4][20] = {"Main", "Results", "History",
                            "Go Test"};
uint16_t buttoncolors[5] = {ILI9341_DARKGREY, ILI9341_DARKGREY, ILI9341_DARKGREY, 
                             ILI9341_DARKGREY, ILI9341_BLUE};

char cablelabels[14][20] = {"RJ45", "RJ45", "RJ45","RJ45","RJ45","RJ45","RJ45","RJ45","RJ45","RJ45","RJ45","RJ45","RJ45","RJ45"};
uint16_t cablecolors[14] = {ILI9341_DARKGREY, ILI9341_LIGHTGREY, ILI9341_DARKGREY, ILI9341_LIGHTGREY, ILI9341_DARKGREY, ILI9341_LIGHTGREY,ILI9341_DARKGREY, 
ILI9341_LIGHTGREY,ILI9341_DARKGREY, ILI9341_LIGHTGREY,ILI9341_DARKGREY, ILI9341_LIGHTGREY,ILI9341_DARKGREY, ILI9341_LIGHTGREY};
                             
void setup(void) {
  Serial.begin(9600);
  TestCable_Unit();
  Serial.println(F("TFT LCD test"));

#ifdef USE_Elegoo_SHIELD_PINOUT
  Serial.println(F("Using Elegoo 2.8\" TFT Arduino Shield Pinout"));
#else
  Serial.println(F("Using Elegoo 2.8\" TFT Breakout Board Pinout"));
#endif

  Serial.print("TFT size is "); Serial.print(tft.width()); Serial.print("x"); Serial.println(tft.height());

  tft.reset();
// <><><><><><> SETUP <><><><><><>
  uint16_t identifier = tft.readID();
  if(identifier == 0x9325) {
    Serial.println(F("Found ILI9325 LCD driver"));
  } else if(identifier == 0x9328) {
    Serial.println(F("Found ILI9328 LCD driver"));
  } else if(identifier == 0x4535) {
    Serial.println(F("Found LGDP4535 LCD driver"));
  }else if(identifier == 0x7575) {
    Serial.println(F("Found HX8347G LCD driver"));
  } else if(identifier == 0x9341) {
    Serial.println(F("Found ILI9341 LCD driver"));
  } else if(identifier == 0x8357) {
    Serial.println(F("Found HX8357D LCD driver"));
  } else if(identifier==0x0101)
  {     
      identifier=0x9341;
       Serial.println(F("Found 0x9341 LCD driver"));
  }else {
    Serial.print(F("Unknown LCD driver chip: "));
    Serial.println(identifier, HEX);
    Serial.println(F("If using the Elegoo 2.8\" TFT Arduino shield, the line:"));
    Serial.println(F("  #define USE_Elegoo_SHIELD_PINOUT"));
    Serial.println(F("should appear in the library header (Elegoo_TFT.h)."));
    Serial.println(F("If using the breakout board, it should NOT be #defined!"));
    Serial.println(F("Also if using the breakout, double-check that all wiring"));
    Serial.println(F("matches the tutorial."));
    identifier=0x9341;
  }
// <><><><><><> SETUP <><><><><><>

/******************* Begin tft */
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(BLACK);

  //create buttons
  drawplate(buttons, tft, buttoncolors, buttonlabels);
  createHomeButtons(buttons, tft, buttoncolors, buttonlabels);
  createCableButtons(cables, tft, cablecolors, cablelabels);
}

void loop(void) {
    digitalWrite(13, HIGH);
    TSPoint p = ts.getPoint();
    digitalWrite(13, LOW);

      GUI_Run(p, tft, buttons, buttoncolors, buttonlabels, cables, cablecolors, cablelabels);
 
}