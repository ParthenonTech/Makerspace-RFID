// Code by chad elish
// www.makerchad.com
// Created for the maker community and HackPGH.
// Thank you to Steve Owens and Geno Soroka for the help.
// Also thank you to MonkeyBoard.
// P.S. You will need the Wiegand library for this to run properly. https://github.com/monkeyboard/Wiegand-Protocol-Library-for-Arduino

#include <Wiegand.h>
String buttontotal; // Total values of buttons pressed
char typew; // Defines if a button was pressed or a card was scanned
int button = 100; // Last Button Pressed... set to a high number so last else if statment doesn't run
WIEGAND wg;

void setup() {
  Serial.begin(9600);

  // default Wiegand Pin 2 and Pin 3 see image on README.md
  // for non UNO board, use wg.begin(pinD0, pinD1) where pinD0 and pinD1
  // are the pins connected to D0 and D1 of wiegand reader respectively.
  wg.begin();
  
}

void loop()
{
  
  if (wg.available())
  {
    // Serial.print(wg.getWiegandType());
    typew = (wg.getWiegandType());
  }
  if (typew == 26) // Type 26 is a card scan
  {
    Serial.write(2); //STX
    //Serial.print("Card = ");
    Serial.print("R");
    Serial.print(wg.getCode());
    Serial.write(3); //ETX
    buttontotal = ""; // clears out keypad presses
    typew = "";
  }
  else if (typew == 4) // Type 4 is a button press
  {
    button = wg.getCode();
  }
  if (button == 27) // ESC Button
  {
    buttontotal = ""; // clears out keypad presses
    //Serial.println("Keypad Cleared");
  }
  else if (button == 13) // Type 4 is ENT
  {
    //Serial.print("Final Code = ");
    Serial.write(2); //STX
    Serial.print("K");
    Serial.print(buttontotal);
    Serial.write(3); //ETX
    buttontotal = ""; // clears out keypad presses
    //Serial.println("Keypad Cleared");
  }
  else if (button <= 9) // Check
  {
  //Serial.print("Number = ");
  //Serial.println(button);
  buttontotal += button;
  //Serial.print("Button Total = ");
  //Serial.println(buttontotal);
  }
}
