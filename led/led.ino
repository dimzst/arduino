class LED {
  unsigned long previousMilis;
  long interval;
  public:
    int pin, state;
    LED(int pin, long interval);
    void toggle();
};

LED::LED(int pin, long interval) {
  this->pin = pin;
  this->interval = interval;
  state = LOW;
  previousMilis = 0;
}

void LED::toggle() {
  unsigned long currentMilis = millis();
  if (currentMilis - previousMilis >= interval) {
    previousMilis = currentMilis;
    if (state == LOW) {
      state = HIGH;
    } else {
      state = LOW;
    }
    digitalWrite(pin, state);
  }
}

LED redLed(7, 300);
LED blueLed(9, 800);
LED yellowLed(11, 1200);

void setup() {
  // put your setup code here, to run once:
  pinMode(redLed.pin, OUTPUT);
  pinMode(blueLed.pin, OUTPUT);
  pinMode(yellowLed.pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  redLed.toggle();
  blueLed.toggle();
  yellowLed.toggle();
}