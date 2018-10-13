#include <Arduino.h>

#include <ESP8266mDNS.h>      // Include the mDNS library
#include <ESP8266WebServer.h> // Include the WebServer library
#include <FS.h>               // Include the SPIFFS library

ESP8266WebServer server(80);

void serverHandleClient()
{
    server.handleClient();
}
void handleRoot()
{
    server.send(200, "text/plain", "Hello world1231!"); // Send HTTP status 200 (Ok) and send some text to the browser/client
}

void handleNotFound()
{
    server.send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}

String getContentType(String filename)
{ // convert the file extension to the MIME type
    if (filename.endsWith(".html"))
        return "text/html";
    else if (filename.endsWith(".css"))
        return "text/css";
    else if (filename.endsWith(".js"))
        return "application/javascript";
    else if (filename.endsWith(".ico"))
        return "image/x-icon";
    return "text/plain";
}

bool handleFileRead(String path)
{ // send the right file to the client (if it exists)
    Serial.println("handleFileRead: " + path);
    if (path.endsWith("/"))
        path += "index.html";                  // If a folder is requested, send the index file
    String contentType = getContentType(path); // Get the MIME type
    if (SPIFFS.exists(path))
    {                                                       // If the file exists
        File file = SPIFFS.open(path, "r");                 // Open it
        size_t sent = server.streamFile(file, contentType); // And send it to the client
        file.close();                                       // Then close the file again
        return true;
    }
    Serial.println("\tFile Not Found");
    return false; // If the file doesn't exist, return false
}

void startMDNS()
{
    if (!MDNS.begin("test"))
    { // Start the mDNS responder for esp8266.local
        Serial.println("Error setting up MDNS responder!");
    }
    Serial.println("mDNS responder started");
}

void startSPIFFS()
{
    SPIFFS.begin(); // Start the SPI Flash Files System
}

void startServer()
{
    server.onNotFound([]() {                                  // If the client requests any URI
        if (!handleFileRead(server.uri()))                    // send it if it exists
            server.send(404, "text/plain", "404: Not Found"); // otherwise, respond with a 404 (Not Found) error
    });

    server.begin(); // Actually start the server
    Serial.println("HTTP server started");
}