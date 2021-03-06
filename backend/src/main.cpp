#include <Arduino.h>

#include "ota.hpp"
#include "wifi.hpp"
#include "server.hpp"
#include "webSocket.hpp"
#include "sensors.hpp"

void setup()
{
  Serial.begin(115200); // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');

  startWifi();
  startMDNS();
  startSPIFFS();
  startServer();
  startWebSocket();
  startOTA();
  startSensors();

}

unsigned long last_10sec = 0;
void loop(void)
{
  serverHandleClient();
  handleWebSocket();
  otaHandle();
  handleSensors();

  unsigned long t = millis();
  if ((t - last_10sec) > 5 * 1000)
  {
    last_10sec = millis();
    sendSensorsValues();
  }
}
