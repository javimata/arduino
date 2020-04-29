#include <Arduino.h>
#ifdef ESP32
  #include <WiFi.h>
#else
  #include "ESP8266WiFi.h"
#endif
#include "fauxmoESP.h"

#define WIFI_SSID "XXXXXXXXXX"  //Cambiar por tu WIFI SSID
#define WIFI_PASS "XXXXXXXXXX"  //Cambiar por tu WIFI password
#define SERIAL_BAUDRATE 115200

fauxmoESP fauxmo;
#define RELAY1 0
#define ID_ONE "RELAY 1" // Es el nombre con el que lo identificará Alexa

// -----------------------------------------------------------------------------
// Wifi
// -----------------------------------------------------------------------------


void wifiSetup() {

    // Set WIFI module to STA mode
    WiFi.mode(WIFI_STA);

    // Connect
    Serial.printf("[WIFI] Connecting to %s ", WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    // Wait
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(100);
    }
    Serial.println();

    // Connected!
    Serial.printf("[WIFI] STATION Mode, SSID: %s, IP address: %s\n", WiFi.SSID().c_str(), WiFi.localIP().toString().c_str());

}

void setup() {
    pinMode(RELAY1, OUTPUT);
    //pinMode(buttonPin, INPUT_PULLUP);
    digitalWrite(RELAY1, LOW);
    // Init serial port and clean garbage
    Serial.begin(SERIAL_BAUDRATE);
    Serial.println("FauxMo demo sketch");
    Serial.println("After connection, ask Alexa/Echo to 'turn <devicename> on' or 'off'");

    // Wifi
    wifiSetup();

    fauxmo.createServer(true); // not needed, this is the default value
    fauxmo.setPort(80); // This is required for gen3 devices

    // You have to call enable(true) once you have a WiFi connection
    // You can enable or disable the library at any moment
    // Disabling it will prevent the devices from being discovered and switched
    fauxmo.enable(true);

    // Fauxmo
    fauxmo.addDevice(ID_ONE);

    fauxmo.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) {
        
        // Callback when a command from Alexa is received. 
        // You can use device_id or device_name to choose the element to perform an action onto (relay, LED,...)
        // State is a boolean (ON/OFF) and value a number from 0 to 255 (if you say "set kitchen light to 50%" you will receive a 128 here).
        // Just remember not to delay too much here, this is a callback, exit as soon as possible.
        // If you have to do something more involved here set a flag and process it in your main loop.
        
        Serial.printf("[MAIN] Device #%d (%s) state: %s value: %d\n", device_id, device_name, state ? "ON" : "OFF", value);

        // Checking for device_id is simpler if you are certain about the order they are loaded and it does not change.
        // Otherwise comparing the device_name is safer.

        if (strcmp(device_name, ID_ONE)==0) {
            digitalWrite(RELAY1, state ? HIGH : LOW);
        }
    });

}

void loop() {
  fauxmo.handle();
  
  // read the pushbutton input pin:
  /*buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == LOW) {
      Serial.println("on");
      digitalWrite(RELAY1, HIGH);
    }
    else {
      // if the current state is LOW then the button
      // went from on to off:
      Serial.println("off");
      digitalWrite(RELAY1, LOW);
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;*/
}
