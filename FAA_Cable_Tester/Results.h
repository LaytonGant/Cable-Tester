#ifndef RESULTS_H
#define RESULTS_H
#include <Arduino.h>
#include <stdio.h>

struct Results {
       int pi[51][51];
       bool Co, Sh, PtP;
       char cn[50], tn[60];
};

extern const struct ResultsClass {
        struct Results (*new)(int pin[51][51], bool Continuity, bool Shielding
                              bool PinToPin, char cablename[50], char testname[60]);
} Results;

#endif