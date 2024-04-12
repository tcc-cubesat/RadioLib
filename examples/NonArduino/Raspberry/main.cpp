#include <RadioLib.h>
#include "PiHal.h"
#include <string>
#include <stdio.h>

PiHal *hal = new PiHal(1);

SX1276 radio = new Module(hal, 8, 17, 4, 13);

LoRaWANNode node(&radio, &AU915, 2);

uint32_t devAddr = 0x20010443;
// uint64_t devEUI  = 0x2000704320010443;
// uint8_t devAddr[] = { 0x20, 0x01, 0x04, 0x43 };
uint8_t devEui[] = {0x20, 0x00, 0x70, 0x43, 0x20, 0x01, 0x04, 0x43};
uint8_t nwkKey[] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};
uint8_t appKey[] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

int main(int argc, char **argv)
{
  int state = 0;

  state = radio.begin();
  if (state == RADIOLIB_ERR_NONE)
  {
    printf("[Radio Begin]...ok!\n");
  }
  else
  {
    printf("[Radio Begin]...error: %i\n", state);
  }

  state = node.beginABP(devAddr, nwkKey, appKey);
  node.setDwellTime(false);
  if (state == RADIOLIB_ERR_NONE)
  {
    printf("[Radio ABP]...ok!\n");
  }
  else
  {
    printf("[Radio ABP]...error: %i\n", state);
  }

  uint64_t devaddr = node.getDevAddr();
  printf("[LoRaWAN] DevAddr: %llu", devaddr);

  printf("Sending LoRa packet ...");
  state = node.uplink("hello", 100);
  if (state == RADIOLIB_ERR_NONE)
  {
    printf("send!\n");
    node.saveSession();
    radio.reset();
  }
  else
  {
    printf("failed, code %i\n", state);
    return (1);
  }

  hal->delay(100);
}

// int16_t sendReceive(const char* strUp, uint8_t port, uint8_t* dataDown, size_t* lenDown, bool isConfirmed = false, LoRaWANEvent_t* eventUp = NULL, LoRaWANEvent_t* eventDown = NULL);
