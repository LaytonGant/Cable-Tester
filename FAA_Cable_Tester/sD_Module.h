#ifndef SDMODULE_H
#define SDMODULE_H
#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include <SPI.h>
#include <SD.h>
#include <Elegoo_GFX.h>    // Core graphics library
#include <Elegoo_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>
#include "GUI_Functions.h"
#include "Results.h"
#include "Cable_Definition.h"

void readCableInfo(struct CableDef cablelist[50]);
void displayTest(struct Results, Elegoo_TFTLCD tft, File cableFile);
void writeTest(struct Results, File cableFile);

#endif