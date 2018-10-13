#include <Arduino.h>

#include "ota.hpp"
#include "wifi.hpp"
#include "server.hpp"

void setup()
{
  Serial.begin(115200); // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');

  startWifi();
  startMDNS();
  startSPIFFS();
  startServer();
  startOTA();
}

void loop(void)
{
  serverHandleClient();
  otaHandle();
}
