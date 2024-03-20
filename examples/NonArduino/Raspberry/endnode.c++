
// include the library
#include <RadioLib.h>
#inclde <string>
// include the hardware abstraction layer
#include "PiHal.h"
#define loRaPort = 2000;
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

LoRaWANNode node(&radio, &US915, 2);
// the entry point for the program
int main(int argc, char** argv) {

  printf("[SX1272 - LoRa] Initializing ... ");
  int state = radio.begin();
  if (state != RADIOLIB_ERR_NONE) {
    printf("failed, code %d\n", state);
    return(1);
  }else {
    printf("success!\n");
  }


  uint64_t joinEUI = 0x1111111111111111;
  uint64_t devEUI = 0x20007043200100443;
  uint8_t nwkKey[] = { 0x74, 0x6F, 0x70, 0x53, 0x65, 0x63, 0x72, 0x65,
                       0x74, 0x4B, 0x65, 0x79, 0x31, 0x33, 0x33, 0x34 };

  uint8_t appKey[] = { 0x61, 0x44, 0x69, 0x66, 0x66, 0x65, 0x72, 0x65,
                       0x6E, 0x74, 0x4B, 0x65, 0x79, 0x41, 0x42, 0x43 };
  printf("[LoRaWAN] Attempting over the air activation ...");
  state = node.beginOTAA(joinEUI, devEUI, nwkKey, appKey);

  if (state != RADIOLIB_ERR_NONE){
    printf("failed, code %d\n", state);
    return(1);
  } else {
    printf("success!\n");
    hal->dela(2000)
  }
  int count = 0;
  
  for(;;) {
    // send a packet
    printf("[LoRaWAN] Sending uplink packet ... ");
    string strUp = "Hello!" + std::to_string(loRaPort);
    string strDown;
    int state = node.sendReceive(strUp, loRaPort, strDown);
    if(state == RADIOLIB_ERR_NONE) {
      // the packet was successfully transmitted
      printf("Received a downlink!\n");

      // wait for a second before transmitting again
      hal->delay(100);

    } else {
      printf("failed, code %d\n", state);

    }

  }

  return(0);
}
