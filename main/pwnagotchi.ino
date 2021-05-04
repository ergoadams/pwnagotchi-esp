
String pwna_name = "pwnagotchi";
Agent agent;


void pwna_setup() {
  JsonObject config = load_config();

  // TODO: logging?
  // TODO: fonts for eink display
  // TODO: Set pwnagotchi name <- loading from config
  // TODO: Clear display, ain't even got a display yet
  Keypair keypair = Keypair();
  agent.init(config, keypair);
  do_auto_mode();
}

void do_auto_mode() {
  Serial.println("Entering auto mode...");
  agent.mode = "auto";
  agent.start();

  for (;;) {
    // agent.recon();
    // this is the pwn and have fun part :)
  }
}
