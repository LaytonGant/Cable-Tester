
//This is the basic sD card test I have that uses the LCD, MEGA, and sD module all together
//I need to integrate this into the rest of our GUI 
#include "sD_Module.h" 

File resultsFile, cableFile;
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

void readCableInfo(struct Cables, File cableFile){

  CableDef cablelist[10];

  cableFile = SD.open("cables.txt");
  if (cableFile) {
    Serial.println("cables.txt:");
    cablecount = 1;

    // read from the file until there's nothing else in it:
    while (cableFile.available()) {
      cable = ' ';
      shielding = ' ';
      var = char(cableFile.read());
      corPin = 0;
      while(var != ','){
        //Serial.print(var);
        cable += var;
        var = char(cableFile.read());
      }
      cablelist[cablecount].name = cable;
      var = char(cableFile.read());
      while(var != ',')
      {
        shielding += var;
        var = char(cableFile.read());
      }
      cablelist[cablecount].shielding = shielding;
      var = myFile.read();
      while(var != '\n')
      {
        pins[corPin] = var;
        //Serial.println(corPin);
        //Serial.print(" = = ");
        //Serial.print(pins[corPin]);
        var = cableFile.read();
        cablelist[cablecount].pin[corPin]=pins[corPin];
        Serial.print(cablelist[cablecount].pin[corPin]);
        corPin = corPin + 1;
      }
      Serial.println();
      Serial.println("IN THE STRUCT");
      Serial.println(cablelist[cablecount].name);
      Serial.println(cablelist[cablecount].shielding);
      cablecount = cablecount + 1;
    }
    cableFile.close();

}

void displayTest(struct Results, File resultsFile) {
  
  unsigned long start = micros();

  // re-open the file for reading:
  resultsFile = SD.open(Results.testname);
  if (resultsFile) {
    Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (resultsFile.available()) { // <><><><><>This needs to be integrated with the GUI to the History <><><><><>
      var = char(resultsFile.read());
      Serial.println(var);
    }
    // close the file:
    Serial.println("End of File");
    Serial.println();
    resultsFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  delay(1000);delay(1000);delay(1000);delay(1000);delay(1000);
 
}

void writeTest(struct Results, File resultsFile){
  
  resultsFile = SD.open(Results.testname, FILE_WRITE);
  firstPin = 1;

  // if the file opened okay, write to it:
  if (resultsFile) {
    Serial.print("Writing to test.txt...");
    resultsFile.println(Results.cablename);
    resultsFile.println("Continuity:", Results.Continuity);
    resultsFile.println("Presense of Shielding:", Results.Shielding);
    resultsFile.println("Pin-to-pin Correct?:", Results.PinToPin);
    while(Results.pins){
      resultsFile.println(firstPin);
      resultsFile.print(Results.pins[firstPin-1]);
      firstPin++;
    }
    // close the file:
    resultsFile.close();
    Serial.println("Done writing to file.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("Error opening test.txt");
  }
}
