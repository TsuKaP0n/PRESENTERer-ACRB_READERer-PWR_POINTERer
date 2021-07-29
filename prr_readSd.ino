void readFromSD() {
  String config_ini;
  File file = SD.open("/json/presenterer.json");
  if (file) {
    while (file.available()) {
      config_ini = config_ini + file.readString();
    }
    file.close();
  }else{
    sleepTimerOfPC = 5;
    return;
  }

  StaticJsonDocument<128> doc;
  DeserializationError error = deserializeJson(doc, config_ini);
  if (error) {
    return;
  }else {
    const char* username = doc["username"];
    userName = username;
    int sleep = doc["sleep"];
    if(sleep) {
      sleepTimerOfPC = sleep;
    }
  }
}
