void scan() {
  int match = 0;
  int n = WiFi.scanNetworks();
  if (n == 0) {
    recovery();
  } else {
    for (int i = 0; i < n; ++i) {
      if(WiFi.SSID(i) == ssid){
        Serial.println("");
        Serial.println("Found an access point! Trying to connect...");
        match = 1;
        break;
      }
      delay(10);
    }
    if(match == 0){
      Serial.println("");
      Serial.println("No access point found.");
      recovery();
    }
    }
}
