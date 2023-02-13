#ifndef BUTTONS_H
#define BUTTONS_H
#include <Arduino.h>
#include <stdio.h>
#include <Elegoo_GFX.h>    // Core graphics library
#include <Elegoo_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>
#include "GUI_Functions.h"

/******************* UI details */
#define BUTTON_X 40 //This adjusts the x direction of the buttons
#define BUTTON_Y 25 //This adjusts the y direction of the buttons
#define BUTTON_W 57 //This adjusts the button width
#define BUTTON_H 20 //This adjusts the button height
#define BUTTON_SPACING_X 20 //Button spacing in the x direction
#define BUTTON_SPACING_Y 20 //Button spacing in the y direction
#define BUTTON_TEXTSIZE 1

#define CABLEBUTTON_X 40 //This adjusts the x direction of the buttons
#define CABLEBUTTON_Y 25 //This adjusts the y direction of the buttons
#define CABLEBUTTON_W 240 //This adjusts the button width
#define CABLEBUTTON_H 23 //This adjusts the button height
#define CABLEBUTTON_SPACING_X 20 //Button spacing in the x direction
#define CABLEBUTTON_SPACING_Y 10 //Button spacing in the y direction
//---------------------------------------------------------------------------------------------------------------//
void createHomeButtons(Elegoo_GFX_Button buttons[], Elegoo_TFTLCD tft, uint16_t buttoncolors[], char buttonlabels[][20]);
void createCableButtons(Elegoo_GFX_Button cables[], Elegoo_TFTLCD tft, uint16_t cablecolors[], char cablelabels[][20]);
//---------------------------------------------------------------------------------------------------------------//
#endif