#include "max518.h"

const int dac_1_val = 200;     // Value written to DAC 1
const int dac_2_val = 100;     // Value written to DAC 2

Max518 max518_dac;

void setup() {
  // Initialize the serial interface
   Serial.begin(9600); 
   // Reset the DAC output
   if(!max518_dac.reset()) Serial.println("Error talking to DAC. Check wiring.");

   // Print out the values
   Serial.print("DAC 1 Output: ");
   Serial.print(dac_1_val);

   Serial.print(", DAC 2 Output: ");
   Serial.println(dac_2_val);

   // Update the DAC with a new value
//   if (!max518_dac.set_output_1(dac_1_val)) Serial.println("Error talking to DAC. Check wiring.");
//   if (!max518_dac.set_output_2(dac_2_val)) Serial.println("Error talking to DAC. Check wiring.");
  if (!max518_dac.set_output_1_2(dac_1_val, dac_2_val)) Serial.println("Error talking to DAC. Check wiring.");

}

void loop() {
  // put your main code here, to run repeatedly:

}
