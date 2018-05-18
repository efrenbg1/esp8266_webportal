void recovery(){
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  digitalWrite(2,LOW);
  String ssid_name = "esp_" + prom[0];
  ssid = ssid_name.c_str();
  Serial.println("");
  Serial.println("Entering recovery mode...");
  Serial.println(String("Connect to: "+String(ssid)+", and access 192.168.1.1 to change the settings."));
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig (ip, gateway, subnet);
  WiFi.softAP(ssid);
  http.on("/", indice);
  http.on("/wifi", wifi);
  http.on("/wifi_commit", wifi_commit);
  http.on("/name", name);
  http.on("/name_commit", name_commit);
  http.begin();
  while(true){
    http.handleClient(); 
  }
}
