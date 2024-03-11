
// include the library
#include <RadioLib.h>

// include the hardware abstraction layer
#include "PiHal.h"

// create a new instance of the HAL class
// use SPI channel 1, because on Waveshare LoRaWAN Hat,
// the SX1261 CS is connected to CE1
PiHal* hal = new PiHal(1);

// now we can create the radio module
// pinout corresponds to the Waveshare LoRaWAN Hat
// NSS pin:   8 RASP(8)
// DIO0 pin:  17 RASP(17)
// DIO1 pin:  13 RASP(13)
// RST pin:  12 RASP(4)
SX1272 radio = new Module(hal, 8, 17, 4, 13);

// the entry point for the program
int main(int argc, char** argv) {
  // initialize just like with Arduino
  printf("[SX1278] Initializing ... ");
  int state = radio.begin();
  if (state != RADIOLIB_ERR_NONE) {
    printf("failed, code %d\n", state);
    return(1);
  }
  printf("success!\n");

  // loop forever
  for(;;) {
    // send a packet
    printf("[SX1278] Transmitting packet ... ");
    state = radio.transmit("Hello World!");
    if(state == RADIOLIB_ERR_NONE) {
      // the packet was successfully transmitted
      printf("success!\n");

      // wait for a second before transmitting again
      hal->delay(100);

    } else {
      printf("failed, code %d\n", state);

    }

  }

  return(0);
}
