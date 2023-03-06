#ifndef SDMODULE_H
#define SDMODULE_H
#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include <SPI.h>
#include <SD.h>
#include <Elegoo_GFX.h>    // Core graphics library
#include <Elegoo_TFTLCD.h> // Hardware-specific library
#include "Results.h"


void displayTest(struct Results, File cableFile);
void writeTest(struct Results, File cableFile);

#endif