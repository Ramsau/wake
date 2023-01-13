#include <SPI.h>
#include <WiFiNINA.h>
#include "Keyboard.h"

#include "secrets.h" 
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key index number (needed only for WEP)

int status = WL_IDLE_STATUS;

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
WiFiSSLClient client;

const int relais_pin = A7;

void setup() {
  //Initialize serial and wait for port to open:
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.begin(9600);
  pinMode(relais_pin, OUTPUT);
  digitalWrite(relais_pin, LOW);

  Keyboard.begin();

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(500);
  }
  Serial.println("Connected to WiFi");
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {

  // if you get a connection, report back via serial:
  while (!client.connect("christophroyer.com", 443)){
    Serial.println("retry");
    delay(500);
  }
  // Make a HTTP request
  client.println("GET /toys/remote-boot/" BOOT_TOKEN " HTTP/1.1");
  client.println("Host: christophroyer.com");
  client.println("Connection: close");
  client.println();

  // if there are incoming bytes available
  // from the server, read them and print them:
  bool last_enter = false;
  bool header_done = false;
  char message[100] = {0};
  int msg_id = 0;
  Serial.print("Message: ");
  while (client.connected()) {
    if (!client.available()) continue;
    char c = client.read();
    if (c == '\r') continue;
    if (c == '\n') {
      header_done = last_enter;
      last_enter = true;
      continue;
    } else {
      last_enter = false;
    }
    if (header_done) {
      message[msg_id++] = c;
    } 
  }

  // if the server's disconnected, stop the client:
  Serial.write(message);
  Serial.println();
  client.stop();

  if (strcmp(message, "Linux") == 0) {
    linux();
  } else if (strcmp(message, "Windows") == 0) {
    windows();
  } else if (strcmp(message, "ForceShutdown") == 0) {
    forceShutdown();    
  } else if (strcmp(message, "TakeImage") == 0) {
    takeImage();
  }

  delay(30000);
}

void pressPower(int millis) {
  digitalWrite(relais_pin, HIGH);
  delay(millis);
  digitalWrite(relais_pin, LOW);
}

void linux() {
  Serial.println("Turning on Linux");
}

void windows() {
  pressPower(200);
  delay(15000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('1');
  Keyboard.releaseAll();
}

void forceShutdown() {
  pressPower(5000);
}

void takeImage() {
  pressPower(200);
  pressPower(500);  
}

