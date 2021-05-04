String __version__ = "0.0.1";

#include "FS.h"
#include "LITTLEFS.h"
#include <ArduinoJson.h>

// TODO: use sd card, littlefs is pretty smol

void setup() {
  Serial.begin(115200);
  Serial.println("Starting pwnagotchi!");
  Serial.print("Current version: ");
  Serial.println(__version__);

  if (!LITTLEFS.begin()) {
    Serial.println("Failed to mount LITTLEFS");
  }
  LITTLEFS.format();

  // Pwnagotchi setup

  pwna_setup();
}

void loop() {
  
}
