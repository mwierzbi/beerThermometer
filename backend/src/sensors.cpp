#include <Arduino.h>
#include "webSocket.hpp"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ArduinoJson.h>

#define ONE_WIRE_BUS 2
#define TEMPERATURE_PRECISION 10
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress devices[2];
int devicesFound = 0;

String getAddress(DeviceAddress deviceAddress)
{
  String address = "";

  for (uint8_t i = 0; i < 8; i++)
  {
    address += (String(deviceAddress[i], HEX));
  }

  return address;
}

void findSensors()
{
  devicesFound = sensors.getDeviceCount();

  for (int i = 0; i < devicesFound; i++) {
    sensors.getAddress(devices[i], i);
    sensors.setResolution(devices[i], TEMPERATURE_PRECISION);
  }
  sensors.setCheckForConversion(false);
}

void startSensors()
{
  sensors.begin();
  findSensors();
}

void sendSensorsValues() 
{
  String json = "";
  const size_t bufferSize = JSON_ARRAY_SIZE(devicesFound) + 2 * JSON_OBJECT_SIZE(2);
  DynamicJsonBuffer jsonBuffer(bufferSize);
  JsonArray &root = jsonBuffer.createArray();

  for (int i = 0; i < devicesFound; i++)
  {
    JsonObject &obj = jsonBuffer.createObject();
    obj["id"] = getAddress(devices[i]);
    obj["value"] = sensors.getTempC(devices[i]);
    root.add(obj);
  }
  root.printTo(json);
  sendToWebSocket(json);
}

void handleSensors()
{
  sensors.requestTemperatures();
}
