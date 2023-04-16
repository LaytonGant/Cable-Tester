#include "Buttons.h"

void createHomeButtons(Elegoo_GFX_Button buttons[], Elegoo_TFTLCD tft, uint16_t buttoncolors[], char buttonlabels[][20]){
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

void createCableButtons(Elegoo_GFX_Button cablePageChange[], Elegoo_GFX_Button cables[], Elegoo_TFTLCD tft, uint16_t cablecolors[], char cablelabels[][20]){
  for (uint8_t row=0; row<5; row++) {
    for (uint8_t col=0; col<1; col++) {
      cables[col + row*3].initButton(&tft, 130+col*(CABLEBUTTON_W+CABLEBUTTON_SPACING_X), 
                 85+row*(CABLEBUTTON_H+CABLEBUTTON_SPACING_Y),    // x, y, w, h, outline, fill, text
                  CABLEBUTTON_W, CABLEBUTTON_H, ILI9341_WHITE, cablecolors[col+row*3], ILI9341_WHITE,
                  cablelabels[col*3 + row], BUTTON_TEXTSIZE); 
      cables[col + row*3].drawButton();
    }
  }

  cablePageChange[0].initButton(&tft, 285, 125, 50, CABLEBUTTON_H, 
                  ILI9341_WHITE, ILI9341_LIGHTGREY, ILI9341_WHITE,
                  "Next", BUTTON_TEXTSIZE); 
      cablePageChange[0].drawButton();
  
  cablePageChange[1].initButton(&tft, 285, 175, 50, CABLEBUTTON_H, 
                  ILI9341_WHITE, ILI9341_LIGHTGREY, ILI9341_WHITE,
                  "Back", BUTTON_TEXTSIZE); 
      cablePageChange[1].drawButton();

}

