
// This file is named kagent to get it imported after keypair lol

class Agent {  
  private:
    Automata automata;
    AsyncTrainer asynctrainer;
    void start_session_fetcher();
    static void _fetch_stats(void *);
    String session();
  public:
    Agent();
    void init(JsonObject, Keypair);
    void start();
    uint32_t started_at;
    uint32_t _current_channel;
    uint32_t _tot_aps;
    uint32_t _aps_on_channel;
    uint32_t _access_points[1024];
    uint32_t _history[1024];
    uint32_t _handshakes[1024];
    String _last_pwnd;
    String mode;
};

Agent::Agent() {}

void Agent::init(JsonObject config, Keypair keypair) {
  // init Client
  automata.init(config); // Emotions of pwnagotchi
  // init AsyncAdvertiser, p2p advertiser to other pwnagotchis
  asynctrainer.init(config); // trains the AI
  
  this->started_at = millis();
  // filter
  this->_current_channel = 0;
  this->_tot_aps = 0;
  this->_aps_on_channel = 0;
  // view
  // webui?

  //this->last_session = ;
  this->mode = "auto";
}

String Agent::session() {
  // this should return the bettercap session, not available until a bettercap port
  return "a";
}

void Agent::_fetch_stats(void *parameter) {
  Agent* agent = reinterpret_cast<Agent*>(parameter); // get the "this" argument 
  for (;;) {
    String s = agent->session();
    // _update_uptime
    // _update_advertisement
    // _update_peers
    // _update_counters
    // _update_handshakes
    delay(1);
  }
}

void Agent::start_session_fetcher() {
  xTaskCreate(&Agent::_fetch_stats, "Session fetcher", 1000, this, 1, NULL);
}

void Agent::start() {
  asynctrainer.start_ai(); // AI worker to another thread
  // TODO: wait_bettercap <- gotta make my own bettercap implementation/alternative :))))
  // TODO: setup_events <- silences bettercap events
  // TODO: set_starting <- pwnagotchi starting face, draws to screen
  // TODO: start_monitor_mode <- starts wifi module and monitoring, start_advertising()
  // TODO: start_event_polling <- event_poller to another thread
  start_session_fetcher(); // fetch_stats to another thread

  // TODO: next_epoch <- advances epoch, sets automata stuff
  // TODO: set_ready <- turns plugins on
}
