#include <Arduino.h>
#include <ESP8266WiFi.h>      // Include the Wi-Fi library

char *ssid = ""; // The SSID (name) of the Wi-Fi network you want to connect to
char *password = "";     // The password of the Wi-Fi network

void startWifi()
{
  WiFi.begin(ssid, password); // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED)
  { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i);
    Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP()); // Send the IP address of the ESP8266 to the computer
}