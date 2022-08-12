#include "Keyboard.h"
#include <WiFiNINA.h>
#include "secrets.h"

int wifi_status = WL_IDLE_STATUS;

void setup() {
  Serial.begin(9600);
  while (wifi_status != WL_CONNECTED) {
    status = Wifi.begin(SSID, WIFI_KEY);
  }
  Serial.println("Connected!");cd Doc 
}

void loop() {
  
}