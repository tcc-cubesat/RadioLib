#include "PiHal.h"
#include <iostream>
#include <RadioLib.h>
#include <csignal> // Biblioteca para lidar com sinais
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdint>

bool keepRunning = true;

void sigHandler(int sig)
{
  if (sig == SIGINT)
  {
    std::cout << "Received SIGINT, stopping..." << std::endl;
    keepRunning = false;
  }
}

PiHal *hal = new PiHal(1);

// now we can create the radio module
// pinout corresponds to the Waveshare LoRaWAN Hat
// NSS pin:   8 RASP(8)
// DIO0 pin:  17 RASP(17)
// DIO1 pin:  13 RASP(13)
// RST pin:  12 RASP(4)
// DIO2 pin: RASP(12)
SX1276 radio = new Module(hal, 8, 17, 4, 13);
AFSKClient audio(&radio, 12);
SSTVClient sstv(&radio);

int main(int argc, char **argv)
{
  std::vector<std::vector<uint32_t>> image;
  std::ifstream file("/home/tccsat/RadioLib/examples/NonArduino/Raspberry/cat.txt");
  if (file.is_open())
  {
    for (int i = 0; i < 256; i++)
    {
      std::string line;
      std::getline(file, line);
      std::vector<uint32_t> lista;
      std::istringstream iss(line);
      std::string token;
      while (std::getline(iss, token, ','))
      {
        uint32_t value = std::stoi(token, nullptr, 16);
        lista.push_back(value);
      }
      if (lista.size() != 320)
      {
        std::cerr << "O arquivo não contém 320 valores na linha " << (i + 1) << std::endl;
        return 1;
      }
      image.push_back(lista);
      std::cout << "Tamanho da linha " << (i + 1) << ": " << lista.size() << std::endl;
    }
  }
  else
  {
    std::cerr << "Não foi possível abrir o arquivo." << std::endl;
    return 1;
  }
  std::cout << "Tamanho da imagem: " << image.size() << std::endl;

  if (!image.empty())
  {
    std::cout << "Primeira linha da imagem:" << std::endl;
    for (uint32_t pixel : image[0])
    {
      std::cout << std::hex << pixel << " ";
    }
    std::cout << std::endl;
  }
  else
  {
    std::cerr << "A imagem está vazia." << std::endl;
  }

  int state = radio.beginFSK();
  if (state == RADIOLIB_ERR_NONE)
  {
    printf("success!\n");
  }
  else
  {
    printf("failed, code %i\n", state);
  }

  printf("Inicializando SSTV!\n");
  state = sstv.begin(915.0, Martin2);
  if (state == RADIOLIB_ERR_NONE)
  {
    printf("success sstv!\n");
  }
  else
  {
    printf("failed, code %i\n", state);
  }

  printf("Setting correction ...");
  state = sstv.setCorrection(1.0);
  if (state == RADIOLIB_ERR_NONE)
  {
    printf("success correction!\n");
  }
  else
  {
    printf("failed, code %i\n", state);
  }
  signal(SIGINT, sigHandler);



  
  while (keepRunning)
  {
    uint32_t line[320];
    printf("Sending test picture ...");
    hal->delay(100);
    sstv.sendHeader();
    for (uint32_t j = 0; j < sstv.getPictureHeight(); j++)
    {
      for (size_t i = 0; i < 320; ++i)
      {
        line[i] = image[j][i];
      }
      if (keepRunning)
      {
        sstv.sendLine(line);
      }
      else
      {
        radio.reset();
        break;
      }
    }
    radio.standby();
    printf("Done!");
    hal->delay(1000);
  }
  file.close();

  return 0;
}
