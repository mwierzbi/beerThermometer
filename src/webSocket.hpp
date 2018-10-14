#include <Arduino.h>
#include <WebSocketsServer.h>

#ifndef WEBSOCKET_HPP
#define WEBSOCKET_HPP

void handleWebSocket();
void startWebSocket();
void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t lenght);
void sendToWebSocket(String playload);

#endif
