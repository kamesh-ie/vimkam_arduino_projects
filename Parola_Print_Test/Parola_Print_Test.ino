// Program to demonstrate the MD_Parola library
//
// Uses the Arduino Print Class extension with various output types
//
// NOTE: MD_MAX72xx library must be installed and configured for the LED
// matrix type being used. Refer documentation included in the MD_MAX72xx
// library or see this link:
// https://majicdesigns.github.io/MD_MAX72XX/page_hardware.html
//

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

const uint16_t WAIT_TIME = 1000;

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define MAX_DEVICES 4

#define CLK_PIN   5
#define DATA_PIN  7
#define CS_PIN    6
#define V_IN      9

// Hardware SPI connection
//MD_Parola P = MD_Parola(CS_PIN, MAX_DEVICES);
// Arbitrary output pins
 MD_Parola P = MD_Parola(DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup(void)
{
  P.begin();
  pinMode(V_IN,OUTPUT);
  pinMode(8,INPUT);

}

void loop(void)
{
  digitalWrite(V_IN,HIGH);
  P.print("Hello");
//  delay(WAIT_TIME);
//  P.print(1234, DEC);
//  delay(WAIT_TIME);
//  P.print(1234, HEX);
//  delay(WAIT_TIME);
//  P.print(12.5);      // float not supported by Arduino Print class
//  delay(WAIT_TIME);
//  P.print(9876l);
//  delay(WAIT_TIME);
//  P.println("end");   // only get the /r/n characters - avoid using println
//  delay(WAIT_TIME);
//  P.write('A');
//  delay(WAIT_TIME);
//  P.write('B');
//  delay(WAIT_TIME);
//  P.write('C');
//  delay(WAIT_TIME);
}
