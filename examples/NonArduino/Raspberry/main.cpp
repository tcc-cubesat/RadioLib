
// // include the library
// #include <RadioLib.h>

// // include the hardware abstraction layer
// #include "PiHal.h"

// #include <string>
// // #include <SSTV.h>

// // create a new instance of the HAL class
// // use SPI channel 1, because on Waveshare LoRaWAN Hat,
// // the SX1261 CS is connected to CE1
// PiHal* hal = new PiHal(1);

// // now we can create the radio module
// // pinout corresponds to the Waveshare LoRaWAN Hat
// // NSS pin:   8 RASP(8)
// // DIO0 pin:  17 RASP(17)
// // DIO1 pin:  13 RASP(13)
// // RST pin:  12 RASP(4)
// // DIO2 pin: RASP(12)

// SX1272 radio = new Module(hal, 8, 17, 4, 13);

// LoRaWANNode node(&radio, &US915, 2);

// int main(int argc, char** argv)
// {

//   int state = radio.begin();

//   uint32_t devAddr = 0x20010443;
//   uint64_t devEUI = 0x2000704320010443;
//   uint8_t nwkKey[] = { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6,0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C };
//   uint8_t appKey[] = { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6,0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C };
//   state = node.beginABP(devAddr, nwkKey, appKey);

//   if (state >= RADIOLIB_ERR_NONE){

//     printf("success!\n");
//     hal->delay(2000);
//   } else
//   {
//     printf("failed, code %i\n", state);
//   }
//   // string message = "Hello!";
//   int count = 0;

//   // printf("[LoRaWAN] DevAddr:");
//   // printf(node.getDevAddr());

//   // node.setADR(false);

//   // node.setDatarate(5);

//   // node.setCSMA(6,2, true);

//   // node.setDutyCycle(true, 1250);

//   // node.setDwellTime(true,400);

//     while(true)
//     {
//       printf("Sending LoRa packet ...");
//       int state = RADIOLIB_ERR_NONE;
//       // radio.transmit("Hello!");
//       state = node.uplink("hello",10);
//       // state = node.sendReceive('A', 10, strDown);

//       if (state == RADIOLIB_ERR_NONE){
//       printf("send!\n");
//   }
//   else
//     {
//     printf("failed, code %i\n", state);
//   }
//     printf("[LoRaWAN] Waiting for downlink ... ");
//     std::string strDown;
//     LoRaWANEvent_t event;
//     state = node.downlink(strDown, &event);
//     if(state == RADIOLIB_ERR_NONE) {
//     printf("success!");

//     // print data of the packet (if there are any)
//     printf("[LoRaWAN] Data:\t\t");
//     if(strDown.length() > 0) {
//       printf(strDown);
//     } else {
//       printf("<MAC commands only>");
//     }
//     printf("[LoRaWAN] RSSI:\t\t");
//     printf(radio.getRSSI());
//     printf(" dBm");

//     // print SNR (Signal-to-Noise Ratio)
//     printf("[LoRaWAN] SNR:\t\t");
//     printf(radio.getSNR());
//     printf(" dB");

//     // print frequency error
//     printf("[LoRaWAN] Frequency error:\t");
//     printf(radio.getFrequencyError());
//     printf(" Hz");

//     // print extra information about the event
//     printf("[LoRaWAN] Event information:");
//     printf("[LoRaWAN] Direction:\t");
//     if(event.dir == RADIOLIB_LORAWAN_CHANNEL_DIR_UPLINK) {
//       printf("uplink");
//     } else {
//       printf("downlink");
//     }
//     printf("[LoRaWAN] Confirmed:\t");
//     printf(event.confirmed);
//     printf("[LoRaWAN] Confirming:\t");
//     printf(event.confirming);
//     printf("[LoRaWAN] Datarate:\t");
//     printf(event.datarate);
//     printf("[LoRaWAN] Frequency:\t");
//     printf(event.freq, 3);
//     printf(" MHz");
//     printf("[LoRaWAN] Output power:\t");
//     printf(event.power);
//     printf(" dBm");
//     printf("[LoRaWAN] Frame count:\t");
//     printf(event.fcnt);
//     printf("[LoRaWAN] Port:\t\t");
//     printf(event.port);
    
//     printf(radio.getFrequencyError());

//     uint8_t margin = 0;
//     uint8_t gwCnt = 0;
//     if(node.getMacLinkCheckAns(&margin, &gwCnt) == RADIOLIB_ERR_NONE) {
//       printf("[LoRaWAN] LinkCheck margin:\t");
//       printf(margin);
//       printf("[LoRaWAN] LinkCheck count:\t");
//       printf(gwCnt);
//     }

//     uint32_t networkTime = 0;
//     uint8_t fracSecond = 0;
//     if(node.getMacDeviceTimeAns(&networkTime, &fracSecond, true) == RADIOLIB_ERR_NONE) {
//       printf("[LoRaWAN] DeviceTime Unix:\t");
//       printf(networkTime);
//       printf("[LoRaWAN] DeviceTime second:\t1/");
//       printf(fracSecond);
//     }
  
//   } else if(state == RADIOLIB_ERR_RX_TIMEOUT) {
//     printf("timeout!");
  
//   } else {
//     printf("failed, code ");
//     printf(state);
//   }
//   uint32_t minimunDelay = 60000;
//   uint32_t interval = node.timeUntilUplink();
//   uint32_t delayMs = std::max(interval,minimunDelay);
//   hal->delay(delayMs);


//   printf("Done!");

//   }
//   return(0);
// }

//   uint64_t devEUI = 0x2000704320010443;
//   uint8_t nwkKey[] = { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6,0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C };
//   uint8_t appKey[] = { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6,0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C };
// NSS pin:   8 RASP(8)
// DIO0 pin:  17 RASP(17)
// DIO1 pin:  13 RASP(13)
// RST pin:  12 RASP(4)
// DIO2 pin: RASP(12)

#include <RadioLib.h>
#include "PiHal.h"
#include <string>
#include <stdio.h>


PiHal* hal = new PiHal(1);

SX1272 radio = new Module(hal, 8, 17, 4, 13);

LoRaWANNode node(&radio, &US915, 2);

uint32_t devAddr = 0x20010443;

uint64_t devEUI = 0x2000704320010443;

uint8_t nwkKey[] = { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6,0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C };

uint8_t appKey[] = { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6,0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C };

int beginRadio(SX1272 radio){
  int state = radio.begin();
  if(state == RADIOLIB_ERR_NONE){
    printf("[Radio Begin]...ok!\n");
    return (state);
  } else {
    printf("[Radio Begin]...error: %i\n",state);
    return (-1);
  }
}


int beginABPLora(){
  int state = node.beginABP(devAddr, nwkKey, appKey);
  if(state >= RADIOLIB_ERR_NONE){
    printf("[LoRa ABP Begin]...ok!\n");
    return(state);
  } else{
    printf("[LoRa ABP Begin]...error: %i\n",state);
    return (-1);
  }
}
int main(){
  printf("[Radio]...ok!\n");
  printf("[LoRa Node]...ok!\n");

  int state = beginRadio(radio);
  state = beginABPLora();

  // node.setADR(true);
  // node.setDutyCycle(true, 1250);
  // node.setDwellTime(true, 1000);
  
  uint8_t count = 0;
  while(true){
    const char *strUp = "hello!";
    uint8_t strDown[256];
    size_t lenDown = 0;
    uint8_t port = 10;
    int16_t state = node.sendReceive(strUp, port, strDown, &lenDown);
    // int16_t state = node.uplink(strUp, port);
    if(state == RADIOLIB_ERR_NONE){
      printf("[LoRa sendReceive]...ok!\n");
      printf("[LoRaWAN] Data:\t\t");
      size_t dataDownLength = sizeof(strDown) / sizeof(strDown[0]);

      if(dataDownLength > 0){
        printf("%s",strDown);
      } else {
        printf("<MAC commands only>");
      }
    } else{
      printf("[LoRa sendReceive]...error: %i\n",state);
      return (-1);
    }

    uint32_t minimunDelay = 60000;
    uint32_t interval = node.timeUntilUplink();
    uint32_t delayMs = std::max(interval,minimunDelay);
    hal->delay(delayMs);
  }
  return(0);
}

// int16_t sendReceive(const char* strUp, uint8_t port, uint8_t* dataDown, size_t* lenDown, bool isConfirmed = false, LoRaWANEvent_t* eventUp = NULL, LoRaWANEvent_t* eventDown = NULL);