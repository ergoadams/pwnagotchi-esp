

JsonObject load_config() {
  if (!LITTLEFS.exists("/config.json")) {
    Serial.println("Config file does not exist, making defaults");

    File file = LITTLEFS.open("/config.json", "w");

    StaticJsonDocument<200> jsonBuffer;
    JsonObject obj = jsonBuffer.to<JsonObject>(); 
    
    obj["main"]["name"] = pwna_name;
    
    obj["ai"]["enabled"] = false;

    obj["personality"]["recon_time"] = 30;
    obj["personality"]["max_inactive_scale"] = 2;
    obj["personality"]["recon_inactive_multiplier"] = 2;
    obj["personality"].createNestedArray("channels");

    String jsonString;
    serializeJson(jsonBuffer, jsonString);
    
    file.println(jsonString);
    file.close();

    Serial.println("Printed config: ");
    Serial.println(jsonString);
    return obj;
    
  } else {
    
    Serial.println("Loading existing config");
    File file = LITTLEFS.open("/config.json", "r");
    
    String jsonString;
    while (file.available()) {
      jsonString += char(file.read());
    }
    
    file.close();

    StaticJsonDocument<200> jsonBuffer;
    deserializeJson(jsonBuffer, jsonString);
    JsonObject obj = jsonBuffer.to<JsonObject>(); 

    Serial.println("Read config:");
    Serial.println(jsonString);
    
    pwna_name = obj["main"]["name"].as<String>();
    return obj;
  }
}
