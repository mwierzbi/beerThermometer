#include <Arduino.h>
#include <WebSocketsServer.h>

WebSocketsServer webSocket(81);

void handleWebSocket()
{
    webSocket.loop();
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t lenght)
{ // When a WebSocket message is received
    switch (type)
    {
    case WStype_DISCONNECTED: // if the websocket is disconnected
        Serial.printf("[%u] Disconnected!\n", num);
        break;
    case WStype_CONNECTED:
    { // if a new websocket connection is established
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
    }
    break;
    }
}

void startWebSocket()
{
    webSocket.begin();
    webSocket.onEvent(webSocketEvent);
    Serial.println("WebSocket server started.");
}

void sendToWebSocket(String playload)
{
    webSocket.broadcastTXT(playload);
}