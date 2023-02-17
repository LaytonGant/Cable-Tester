#include "Test_Cable.h"
// Creation of Classes
struct Results testresults;
struct CableDef RJ45A;
RJ45A.pin[] = {1; 2; 3; 4; 5; 6; 7; 8};
RJ45A.shielding = true;
/*struct CableDef RJ45B;
struct CableDef RJ11;
struct CableDef RJ12UTP;
struct CableDef RJ21;
struct CableDef D_sub9;
struct CableDef D_sub15;
struct CableDef D_sub25;
struct CableDef HD_sub15;
struct CableDef USBA;
struct CableDef USBB;
struct CableDef USBMini;
struct CableDef Amphenol;
*/
// Set Number of Pins to Test
const int numPins = 50;
// Define the "run test" button
const int runTestBtn = 2;
// Define Shift Register Control Pins
const int srInput = 3;  // Input to the Shift Register
const int srClear = 4;  // Clear pin for Shift Register
const int srClock = 5;  // Clock Pulse for Shift Register

// Define Binary Counter Control Pins
const int bcClear = 6;
const int bcClock = 7;

// Define MUX Read Pins
const int MUXReadA = 8;  // 2-pin MUX
const int MUXReadB = 9;  // 16-pin MUX 1
const int MUXReadC = 10; // 16-pin MUX 2
const int MUXReadD = 11; // 16-pin MUX 3

// Define Relay On/Off Pin
const int relay = 37;

// Set delay value (in ms)
unsigned long delayVal = 1;

void TestCable_Unit() {

  // initialize Shift Register Pins, initially write them, and Clear the Shift Registers:
  pinMode(srInput, OUTPUT); digitalWrite(srInput, LOW);
  pinMode(srClock, OUTPUT); digitalWrite(srClock, LOW);
  pinMode(srClear, OUTPUT); digitalWrite(srClear, HIGH); // Set to LOW to Clear Shift Register
  srClearPulse();

  // initialize Binary Counter pins and clear the count
  pinMode(bcClock, OUTPUT); digitalWrite(bcClock, LOW);
  pinMode(bcClear, OUTPUT); digitalWrite(bcClear, HIGH); // Set to LOW to Clear Binary Counter
  bcClearPulse();

  // initialize MUX pins and Initialize them LOW:
  pinMode(MUXReadA, INPUT);
  pinMode(MUXReadB, INPUT);
  pinMode(MUXReadC, INPUT);
  pinMode(MUXReadD, INPUT);

  // initialize output relay pin LOW
  pinMode(relay, OUTPUT); digitalWrite(relay, LOW);

  // initialize buttons
  pinMode(runTestBtn, INPUT);
}

void TestCable(){

  digitalWrite(relay, HIGH); delay(10);
  srClearPulse();
  bcClearPulse();
  Serial.print("|-------------------------------------------------------------------------------|\n");
  Serial.print("Beginning Pin to Pin Connectivity Test...\n\n");
  bool pinFound = LOW;
  int foundPin;

  // Set First SR Pin HIGH (1st pin of cable)
  digitalWrite(srInput, HIGH); delay(delayVal);
  srClockPulse();
  digitalWrite(srInput, LOW);

  Serial.write("Pin to Pin Connections:\n");
  for (int pin = 1; pin <= numPins; pin++)
  {
    foundPin = findPin(pin);
    if (foundPin == 0)
    {
      Serial.print(pin); Serial.print("-"); Serial.print("nothing :(\n");
      srClockPulse();
    } else
      {
        Serial.print(pin); Serial.print("-"); Serial.print(foundPin); Serial.print("\n");
        testresults.pin[pin-1] = foundPin;
        srClockPulse();
      }
    }

  srClearPulse();
  bcClearPulse();
  Serial.print("\n\nPin to Pin Connectivity Test Complete! Press the reset button to test again!\n");
  Serial.print("|-------------------------------------------------------------------------------|\n\n");
  digitalWrite(relay, LOW);

  // Wait for user to press the button to begin the test!
  waitForStart();
}

void waitForStart()
{
  bool runTestBtnPressed = LOW;
  while (runTestBtnPressed == LOW)
  {
    runTestBtnPressed = digitalRead(runTestBtn);
  }
}

// Function where we find the active pin on the receiving end
int findPin(int pin)
{
  int foundPin = 0;
  bool pinStateA;
  bool pinStateB;
  bool pinStateC;
  bool pinStateD;

  bcClearPulse();
  for (int j = 1; (j <= 16)&&(foundPin == 0); j++)
  {
    if ((pin >=1) && (pin <= 2))
    {
      pinStateA = digitalRead(MUXReadA);
      if (pinStateA == HIGH)
      {
        foundPin = j;
      }
    }

    if ((pin >= 3) && (pin <= 18))
    {
      pinStateB = digitalRead(MUXReadB);
      if (pinStateB == LOW)
      {
        foundPin = j+2;
      }
    }

    if ((pin >= 19) && (pin <= 34))
    {
      pinStateC = digitalRead(MUXReadC);
      if (pinStateC == LOW)
      {
        foundPin = j+18;
      }
    }

    if ((pin >= 35) && (pin <= 50))
    {
      pinStateD = digitalRead(MUXReadD);
      if (pinStateD == LOW)
      {
        foundPin = j+34;
      }
    }
    
    bcClockPulse();
  }
  
  return foundPin;
}

// Clock or Clear Pulse Functions

void srClearPulse()
{
  digitalWrite(srClear, LOW); 
  delay(delayVal); 
  digitalWrite(srClear, HIGH);
}

void srClockPulse()
{
  digitalWrite(srClock, HIGH);
  delay(delayVal);
  digitalWrite(srClock, LOW);
}

void bcClearPulse()
{
  digitalWrite(bcClear, LOW);
  delay(delayVal);
  digitalWrite(bcClear, HIGH);
}

void bcClockPulse()
{
  digitalWrite(bcClock, HIGH);
  delay(delayVal);
  digitalWrite(bcClock, LOW);
}



