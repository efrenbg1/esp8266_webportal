/*void data() {
  String message;
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += server.arg(i) + "#";
  }
    for(int n=0; n< message.length();n++){
  EEPROM.write(n,message[n]);
}
  EEPROM.commit();
  Serial.println(message);
  server.send(200, "text/plain", "Success  " + message);
  string_Value = String(eeRead(2));
  Serial.println(string_Value);
}
*/
void indice() {
  http.send(200, "text/html", index_html);
}

void wifi() {
  http.send(200, "text/html", String(wifi1_html + String(ssid) + wifi2_html));
}

void wifi_commit() {
  String message;
  for (uint8_t i = 0; i < http.args(); i++) {
    message += http.arg(i) + "#";
  }
  message = "#" + prom[0] + "#" + message;
  Serial.println(message);
  http.send(200, "text/html", String(reboot1_html + message + reboot2_html));
  for(int n=0; n< message.length();n++){
  EEPROM.write(n,message[n]);
}
  EEPROM.commit();
  delay(5000);
  ESP.restart();
  }

void name() {
  http.send(200, "text/html", String(name1_html + prom[0] + name2_html));
}

void name_commit() {
  String message;
  for (uint8_t i = 0; i < http.args(); i++) {
    message += http.arg(i) + "#";
  }
  message = "#" + message + prom[1] + "#" + prom[2] + "#";
  Serial.println(message);
  http.send(200, "text/html", String(reboot1_html + message + reboot2_html));
  for(int n=0; n< message.length();n++){
  EEPROM.write(n,message[n]);
}
  EEPROM.commit();
  delay(5000);
  ESP.restart();
  }
