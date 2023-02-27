#include "GUI_Functions.h"

uint8_t pages = 0;
bool Change = false;
char textfield_subplate[TEXT_LEN+1] = "Select Cable:";

void GUI_Run(TSPoint p, Elegoo_TFTLCD tft, Elegoo_GFX_Button buttons[], uint16_t buttoncolors[], char buttonlabels[][20],
             Elegoo_GFX_Button cables[], uint16_t cablecolors[], char cablelabels[][20]){
  // if sharing pins, you'll need to fix the directions of the touchscreen pins
  //pinMode(XP, OUTPUT);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
    // scale from 0->1023 to tft.width
     p.x = map(p.x, TS_MAXX, TS_MINX, 0, tft.width());
     p.y = map(p.y, TS_MAXY, TS_MINY, 0, tft.width());
   }
   
  // go thru all the buttons, checking if they were pressed
  for (uint8_t b=0; b<4; b++) {
    if (buttons[b].contains(p.y, p.x)) {
      //Serial.print("Pressing: "); Serial.println(b);
      buttons[b].press(true);  // tell the button it is pressed
    } else {
      buttons[b].press(false);  // tell the button it is NOT pressed
    }
  }

for (uint8_t b=0; b<4; b++) {
    if (cables[b].contains(p.y, p.x)) {
      //Serial.print("Pressing: "); Serial.println(b);
      cables[b].press(true);  // tell the button it is pressed
    } else {
      cables[b].press(false);  // tell the button it is NOT pressed
    }
  }

  // now we can ask the buttons if their state has changed
  for (uint8_t b=0; b<4; b++) {
    if (buttons[b].justReleased()) {
      // Serial.print("Released: "); Serial.println(b);
      if (buttons[b].justReleased()==buttons[0].justReleased()){
          if (pages == 0){
            Change = false;
            buttons[b].drawButton();
          }
          else {
            Change = true;
            pages = 0;
            UpdateScreen(buttons, tft, buttoncolors, buttonlabels, cables, cablecolors, cablelabels);
          }
        }
      else if(buttons[b].justReleased()==buttons[1].justReleased()){
          if (pages == 1){
            Change = false;
            buttons[b].drawButton();
          }
          else{
            Change = true;
            pages = 1;
            UpdateScreen(buttons, tft, buttoncolors, buttonlabels, cables, cablecolors, cablelabels);
          }
      }
      else if(buttons[b].justReleased()==buttons[2].justReleased()){
          if (pages == 2){
            Change = false;
            buttons[b].drawButton();
          }
          else{
            Change = true;
            pages = 2;
            UpdateScreen(buttons, tft, buttoncolors, buttonlabels, cables, cablecolors, cablelabels);
          }
      }
      else if(buttons[b].justReleased()==buttons[3].justReleased()){
          Change = true;
          pages = 1;
          TestCable();
          UpdateScreen(buttons, tft, buttoncolors, buttonlabels, cables, cablecolors, cablelabels);
      }
    }
    
    if (buttons[b].justPressed()) {
        buttons[b].drawButton(true);  // draw invert!
        // if a numberpad button, append the relevant # to the textfield

      delay(100); // UI debouncing
    }
  }
  
}

void UpdateScreen(Elegoo_GFX_Button buttons[], Elegoo_TFTLCD tft, uint16_t buttoncolors[],
                 char buttonlabels[][20], Elegoo_GFX_Button cables[], uint16_t cablecolors[], char cablelabels[][20]){
// Blacks the screen before it checks the conditions to change the page
tft.fillScreen(BLACK);
delay(1000);

if(Change == true && pages == 0)
{
  drawplate(buttons, tft, buttoncolors, buttonlabels);

  for (uint8_t row=0; row<1; row++) {
    for (uint8_t col=0; col<4; col++) {
      buttons[col + row*4].initButton(&tft, BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X), 
                 BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y),    // x, y, w, h, outline, fill, text
                  BUTTON_W, BUTTON_H, ILI9341_WHITE, buttoncolors[col+row*3], ILI9341_WHITE,
                  buttonlabels[col + row*4], BUTTON_TEXTSIZE); 
      buttons[col + row*4].drawButton();
    }
  }
}

if(Change == true && pages == 1)
{
  drawplate(buttons, tft, buttoncolors, buttonlabels);
  for (uint8_t row=0; row<1; row++) {
    for (uint8_t col=0; col<4; col++) {
      buttons[col + row*4].initButton(&tft, BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X), 
                 BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y),    // x, y, w, h, outline, fill, text
                  BUTTON_W, BUTTON_H, ILI9341_WHITE, buttoncolors[5], ILI9341_WHITE,
                  buttonlabels[col + row*4], BUTTON_TEXTSIZE); 
      buttons[col + row*4].drawButton();
      Change == false;
    }
  }
}
if(Change == true && pages == 2)
{
  drawplate(buttons, tft, buttoncolors, buttonlabels);
  for (uint8_t row=0; row<1; row++) {
    for (uint8_t col=0; col<4; col++) {
      buttons[col + row*4].initButton(&tft, BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X), 
                 BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y),    // x, y, w, h, outline, fill, text
                  BUTTON_W, BUTTON_H, ILI9341_WHITE, buttoncolors[5], ILI9341_WHITE,
                  buttonlabels[col + row*4], BUTTON_TEXTSIZE); 
      buttons[col + row*4].drawButton();
      Change == false;
    }
  }
}
}

void drawplate(Elegoo_GFX_Button buttons[], Elegoo_TFTLCD tft, uint16_t buttoncolors[], char buttonlabels[][20]){
  //HomePlate
  tft.drawRect(HOMEPLATE_X, HOMEPLATE_Y, HOMEPLATE_W+1, HOMEPLATE_H+1, ILI9341_WHITE);
  tft.fillRect(HOMEPLATE_X+1, HOMEPLATE_Y+1, HOMEPLATE_W-1, HOMEPLATE_H-1, ILI9341_LIGHTGREY);
  //SubPlate
  tft.setCursor(SUBPLATE_X, SUBPLATE_Y);
  tft.setTextColor(SUBPLATE_TCOLOR);
  tft.setTextSize(SUBPLATE_TSIZE);
  if (pages == 0){
  tft.println(F("Select Cable:"));
  }
  else if (pages == 1){
  tft.println(F("Cable XX-XX:"));
  }
  else if (pages == 2){
  tft.println(F("Cable History:"));
  }
  //DisplayPlate
  tft.drawRect(DISPLAYPLATE_X, DISPLAYPLATE_Y, DISPLAYPLATE_W+1, DISPLAYPLATE_H+1, ILI9341_WHITE);
  tft.fillRect(DISPLAYPLATE_X+1, DISPLAYPLATE_Y+1, DISPLAYPLATE_W-1, DISPLAYPLATE_H-1, ILI9341_LIGHTGREY);
}

