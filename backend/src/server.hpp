#ifndef SERVER_HPP
#define SERVER_HPP
void handleRoot();
void handleNotFound();
String getContentType(String filename);
bool handleFileRead(String path);
void startMDNS();
void startSPIFFS();
void startServer();
void serverHandleClient();
#endif
