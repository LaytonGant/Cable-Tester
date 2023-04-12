// Grace Bost
#include "sD_Module.h" 
#include "GUI_Functions.h"


void readCableInfo(struct CableDef cablelist[15]){
  File cableFile;
  char var;
  char buf[20];
  String cable;
  String shielding;
  int corPin, cablecount;
  char pins[60];
  
  // setup
  //Serial.println("Initializing SD card...");

  //if (!SD.begin(53)) {
   //Serial.println("initialization failed!");
 // while (1);
  //}
  //Serial.println("initialization done.");
  //

  cableFile = SD.open("cables.txt");
  if (cableFile) {
    Serial.println("cables.txt:");
    cablecount = 0;


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
    
      cable.toCharArray(buf,cable.length()+1);
      strcpy(cablelist[cablecount].name, buf);
     // _______________________________________
      var = char(cableFile.read());
      while(var != ',')
      {
        shielding += var;
        var = char(cableFile.read());
      }
      cablelist[cablecount].shielding = shielding;
      var = cableFile.read();
      while(var != '\n')
      {
        pins[corPin] = var;
        //Serial.println(corPin);
        //Serial.print(" = = ");
        //Serial.print(pins[corPin]);
        var = cableFile.read();
        cablelist[cablecount].pin[corPin]=pins[corPin];
        //Serial.print(cablelist[cablecount].pin[corPin]);
        corPin = corPin + 1;
      }
      //Serial.println();
      //Serial.println("IN THE STRUCT");
      //Serial.println(cablelist[cablecount].name);
      //Serial.println(cablelist[cablecount].shielding);
      cablecount = cablecount + 1;
    }
    cableFile.close();

  }
  else{
    Serial.println("File not found.");
  }
}

void displayTest(struct Results testResult, Elegoo_TFTLCD tft, File testFile) {
  
  char dvar;
  unsigned long start = micros();
  tft.setCursor(20, 60);
  tft.setTextColor(SUBPLATE_TCOLOR);
  tft.setTextSize(SUBPLATE_TSIZE);
  

  // re-open the file for reading:
  testFile = SD.open(testResult.testname);
  if (testFile) {
    Serial.println("results file opened");

    // read from the file until there's nothing else in it:
    while (testFile.available()) { // <><><><><>This needs to be integrated with the GUI to the History <><><><><>
      dvar = char(testFile.read());
      tft.println(dvar);
    }
    // close the file:
    Serial.println("End of File");
    Serial.println();
    testFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  } 
}


void writeTest(struct Results cableResult){
  int firstPin;
  Serial.println(cableResult.testname);
  File resultsFile = SD.open(cableResult.testname, FILE_WRITE);
  //File resultsFile = SD.open("test.txt", FILE_WRITE);
  firstPin = 1;


  // if the file opened okay, write to it:
  if (resultsFile) {
    Serial.print("Writing to test.txt...");
    resultsFile.println(cableResult.cablename);

    if(cableResult.Continuity == true){
    resultsFile.println("Continuity: True");
    } 
    else{
    resultsFile.println("Continuity: False");      
    }

    if(cableResult.Shielding == true){
      resultsFile.println("Presense of Shielding: True");
    }
    else{
      resultsFile.println("Presense of Shielding: False");
    }

    if(cableResult.PinToPin == true){
      resultsFile.println("Pin-to-Pin Connections Correct?: True");
    }
    else{
      resultsFile.println("Pin-to-Pin Connections Correct?: False");
    }

    while(cableResult.pin[firstPin-1] != 0){
     resultsFile.println(firstPin);
     resultsFile.print(cableResult.pin[firstPin-1]);
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

