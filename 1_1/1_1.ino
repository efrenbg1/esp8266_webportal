//////////////////////////////////////////////////
//            Code by: Efrén Boyarizo           //
//     Web design by: my anonimous girlfriend   //
//                                              //
//    All code is free to use for any purpose.  //
// !!Remember to help others by sharing errors, //
//          problems and improvements!!         //
//                                              //
//https://github.com/efrenbg1/esp8266_webportal //
//////////////////////////////////////////////////

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>

const char *ssid = "default";
const char *password = "";
String prom[3];
char eRead[25];
String host = "esp_default";
int timeout = 0;

IPAddress ip(192, 168, 1, 1);
IPAddress gateway(192,168,1,2);
IPAddress subnet(255,255,255,0);
ESP8266WebServer http(80);


void setup() {
  Serial.begin(9600);
  EEPROM.begin(512);
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
  Serial.println("");
  
  eeprom_init();
  
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  
  scan();
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  timeout++;
  if(timeout>15){
    WiFi.disconnect();
    Serial.println(String("Could not connect to: " + String(ssid) +". Password might be wrong."));
    recovery();
  }
 
  }
  Serial.println("Connected to WiFi");
}

void loop() {

}





