class Automata {  
  private:
    JsonObject config;
  public:
    Automata();
    void init(JsonObject);
    // _epoch
};

Automata::Automata() {}

void Automata::init(JsonObject config) {
  this->config = config;
}
