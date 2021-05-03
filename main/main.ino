String __version__ = "0.0.1";

void do_clear() {
  Serial.println("Would clear display...");
}


void setup() {
  Serial.begin(115200);
  Serial.println("Starting pwnagotchi!");
  Serial.print("Current version: ");
  Serial.println(__version__);

  // Pwnagotchi setup

  config = load_config();
  Serial.println("Current config: ");


  do_auto_mode(agent);
}
