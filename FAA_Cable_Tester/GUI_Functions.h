#ifndef GUI_FUNCIONS_H
#define GUI_FUNCIONS_H
#include <Arduino.h>
#include <stdio.h>
#include <Elegoo_GFX.h>    // Core graphics library
#include <Elegoo_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>
#include "Buttons.h"
#include "Test_Cable.h"
#include "Results.h"
//---------------------------------------------------------------------------------------------------------------//
// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

// Color definitions
#define ILI9341_BLACK       0x0000      /*   0,   0,   0 */
#define ILI9341_NAVY        0x000F      /*   0,   0, 128 */
#define ILI9341_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define ILI9341_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define ILI9341_MAROON      0x7800      /* 128,   0,   0 */
#define ILI9341_PURPLE      0x780F      /* 128,   0, 128 */
#define ILI9341_OLIVE       0x7BE0      /* 128, 128,   0 */
#define ILI9341_LIGHTGREY   0xC618      /* 192, 192, 192 */
#define ILI9341_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define ILI9341_BLUE        0x001F      /*   0,   0, 255 */
#define ILI9341_GREEN       0x07E0      /*   0, 255,   0 */
#define ILI9341_CYAN        0x07FF      /*   0, 255, 255 */
#define ILI9341_RED         0xF800      /* 255,   0,   0 */
#define ILI9341_MAGENTA     0xF81F      /* 255,   0, 255 */
#define ILI9341_YELLOW      0xFFE0      /* 255, 255,   0 */
#define ILI9341_WHITE       0xFFFF      /* 255, 255, 255 */
#define ILI9341_ORANGE      0xFD20      /* 255, 165,   0 */
#define ILI9341_GREENYELLOW 0xAFE5      /* 173, 255,  47 */
#define ILI9341_PINK        0xF81F

// text box where numbers go
#define HOMEPLATE_X 10 //Text in the x direction
#define HOMEPLATE_Y 10 //Text in the y direction
#define HOMEPLATE_W 295 //Text box width
#define HOMEPLATE_H 30 //Text box height
#define HOMEPLATE_TSIZE 2
#define HOMEPLATE_TCOLOR ILI9341_BLACK
// the data (phone #) we store in the textfield
#define TEXT_LEN 40

// Pins to activate touch screen
#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin

//Touch For New ILI9341 TP
#define TS_MINX 120
#define TS_MAXX 900

#define TS_MAXY 920
#define TS_MINY 70
// We have a status line for like, is FONA working
#define STATUS_X 10
#define STATUS_Y 65

#define SUBPLATE_X 10//This is for the text under the homeplate
#define SUBPLATE_Y 50

#define SUBPLATE_TSIZE 2
#define SUBPLATE_TCOLOR ILI9341_WHITE

#define DISPLAYPLATE_X 10
#define DISPLAYPLATE_Y 70
#define DISPLAYPLATE_W 240 //Text box width
#define DISPLAYPLATE_H 160 //Text box height

#define MINPRESSURE 10
#define MAXPRESSURE 1000

void GUI_Run(TSPoint p, Elegoo_TFTLCD tft, Elegoo_GFX_Button buttons[], uint16_t b[], char bl[][20],
                   Elegoo_GFX_Button cables[], uint16_t c[], char cl[][20]);
void drawplate(Elegoo_GFX_Button buttons[], Elegoo_TFTLCD tft, uint16_t buttoncolors[], char buttonlabels[][20]);
void UpdateScreen(Elegoo_GFX_Button buttons[], Elegoo_TFTLCD tft, uint16_t b[], char bl[][20],
                   Elegoo_GFX_Button cables[], uint16_t c[], char cl[][20]);

//---------------------------------------------------------------------------------------------------------------//
#endif