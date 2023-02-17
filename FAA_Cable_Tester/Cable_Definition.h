#ifndef CABLE_DEFINITION_H
#define CABLE_DEFINITION_H
#include <Arduino.h>
#include <stdio.h>
#include <string.h>

struct CableDef {
       int pin[60];
       bool shielding;
};// RJ45A, RJ45B, RJ11, RJ12UTP, RJ21, D_sub9, D_sub15, D_sub25, HD_sub15,
 // USBA, USBB, USBMini, Amphenol;

#endif