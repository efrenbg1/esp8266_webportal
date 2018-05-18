void eeRead(){
  char eRead[25];
  int character = 0;
  int chunk = 0;
  for (int i = 1; i <= 512; i++)
  {
    if((char)EEPROM.read(i) == '#'){
      eRead[character] = '\0';
      character = 0;
      prom[chunk] = String(eRead);
      if(chunk == 2){
      break;
      }
      chunk++;
      } else {
      eRead[character] = (char)EEPROM.read(i);
      character++;
    }
  }
}


void eeprom_init(){
  if((char)EEPROM.read(0) == '#'){
    eeRead();
    Serial.println("");
    Serial.println("Current settings:");
    Serial.println("");
    Serial.println(String("-Name: " + prom[0]));
    Serial.println(String("-SSID: " + prom[1]));
    Serial.println(String("-Password: " + prom[2]));
    ssid = prom[1].c_str();
    password = prom[2].c_str();
    host = "espPC_" + prom[0];
  } else {
    Serial.println("Oops! The memory is empty or corrupted. Resetting it...");
    defaults();
  }
}


void defaults(){
  String message = "#default#wifi#password#";
  for(int n=0; n< message.length();n++){
  EEPROM.write(n,message[n]);
}
  EEPROM.commit();
  eeRead();
  recovery();
}
