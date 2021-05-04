

class AsyncTrainer {
  private:
    JsonObject _config;
    bool _is_training;
    uint32_t _training_epochs;
    bool _model;
    bool load(JsonObject);
    
    // stats?
  public:
    AsyncTrainer();
    void init(JsonObject);
    static void _ai_worker(void *);
    void start_ai();
};

AsyncTrainer::AsyncTrainer() {}

void AsyncTrainer::init(JsonObject config) {
  this->_config = config;
  this->_is_training = false;
  this->_training_epochs = 0;
}

void AsyncTrainer::start_ai() {
  xTaskCreate(&AsyncTrainer::_ai_worker, "AI worker", 1000, this, 1, NULL);
}

bool AsyncTrainer::load(JsonObject config) {
  if (config["ai"]["enabled"]) {
    Serial.println("FATAL: AI should not be enabled in this state");
    return true;
  } else {
    Serial.println("AI not enabled, all good :)");
    return false;
  }
}

void AsyncTrainer::_ai_worker(void *parameter) {
  AsyncTrainer* asynctrainer = reinterpret_cast<AsyncTrainer*>(parameter); // get the "this" argument 
  asynctrainer->_model = asynctrainer->load(asynctrainer->_config);

  if (asynctrainer->_model) {
    Serial.println("Model loaded!");
  } else {
    Serial.println("AI disabled, destroying AI task");
    vTaskDelete(NULL);
  }
}
