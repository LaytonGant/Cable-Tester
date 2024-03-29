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

void readCableInfo(struct CableDef cablelist[15]);
void displayTest(struct Results testResult, Elegoo_TFTLCD tft, File testFile);
void writeTest(struct Results cableResult);

#endif