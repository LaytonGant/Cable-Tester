#ifndef RESULTS_H
#define RESULTS_H
#include <Arduino.h>
#include <stdio.h>
#include <string.h>

struct Results {
       int pin[60];
       bool Continuity, Shielding, PinToPin;
       String cablename, testname;
};

#endif