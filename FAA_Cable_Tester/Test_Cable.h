#ifndef TEST_CABLE_H
#define TEST_CABLE_H
#include <Arduino.h>

// Function Prototypes
void TestCable_Unit(void);
void srClearPulse(void);
void srClockPulse(void);
void bcClearPulse(void);
void bcClockPulse(void);
void waitForStart(void);
void TestCable();
int findPin(int pin);

#endif