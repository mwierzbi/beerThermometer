#include <Arduino.h>
#include <DallasTemperature.h>

#ifndef SENSORS_HPP
#define SENSORS_HPP
void startSensors();
void findSensors();
void sendSensorsValues();
String getAddress(DeviceAddress deviceAddress);
void handleSensors();
#endif