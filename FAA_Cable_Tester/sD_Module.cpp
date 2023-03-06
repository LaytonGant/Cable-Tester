
//This is the basic sD card test I have that uses the LCD, MEGA, and sD module all together
//I need to integrate this into the rest of our GUI 
#include "sD_Module.h" 

File cableFile;
String var;
int firstPin;

void setup() {

  Serial.print("Initializing SD card...");

  if (!SD.begin(53)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

}

void displayTest(struct Results, File cableFile) {
  
  unsigned long start = micros();

  // re-open the file for reading:
  cableFile = SD.open(Results.testname);
  if (cableFile) {
    Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (cableFile.available()) { // <><><><><>This needs to be integrated with the GUI to the History <><><><><>
      var = char(cableFile.read());
      Serial.println(var);
    }
    // close the file:
    Serial.println("End of File");
    Serial.println();
    cableFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  delay(1000);delay(1000);delay(1000);delay(1000);delay(1000);
 
}

void writeTest(struct Results, File cableFile){
  
  cableFile = SD.open(Results.testname, FILE_WRITE);
  firstPin = 1;

  // if the file opened okay, write to it:
  if (cableFile) {
    Serial.print("Writing to test.txt...");
    cableFile.println(Results.cablename);
    cableFile.println("Continuity:", Results.Continuity);
    cableFile.println("Presense of Shielding:", Results.Shielding);
    cableFile.println("Pin-to-pin Correct?:", Results.PinToPin);
    while(Results.pins){
      cableFile.println(firstPin);
      cableFile.print(Results.pins[firstPin-1]);
      firstPin++;
    }
    // close the file:
    cableFile.close();
    Serial.println("Done writing to file.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("Error opening test.txt");
  }
}
