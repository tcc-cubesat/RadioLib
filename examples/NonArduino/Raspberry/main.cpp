
// include the library
#include <RadioLib.h>

// include the hardware abstraction layer
#include "PiHal.h"

#include <string>
// #include <SSTV.h>

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
// DIO2 pin: RASP(12)

SX1272 radio = new Module(hal, 8, 17, 4, 13);

LoRaWANNode node(&radio, &US915, 2);

int main(int argc, char** argv) 
{
  
  int state = radio.begin();
  
  uint32_t devAddr = 0x20010443;
  uint64_t devEUI = 0x2000704320010443;
  uint8_t nwkKey[] = { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6,0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C };

  uint8_t appKey[] = { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6,0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C };
  // int state = radio.begin(915.0, 500.0, 6, 5, 0x14, 2, 20, 1);
  state = node.beginABP(devAddr, nwkKey, appKey);

  if (state == RADIOLIB_ERR_NONE){

    printf("success!\n");
  } else 
  {  
    printf("failed, code %i\n", state);
  }
  // string message = "Hello!";
  int count = 0;
  
    while(true)
    {
    int state = RADIOLIB_ERR_NONE;
    printf("Sending LoRa packet ...");
    // radio.transmit("Hello!");
    state = node.uplink("hello", 10, true);
    if (state == RADIOLIB_ERR_NONE){
    printf("send!\n");
  } 
  else 
    {
     
    printf("failed, code %i\n", state);
  }
    hal->delay(1000);
    

    printf("Done!");
    
  }
  return(0);
}
