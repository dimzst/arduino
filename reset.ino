const int boardLed = LED_BUILTIN;

void setup() {
	pinMode(boardLed, OUTPUT);
}

void loop() {
	digitalWrite(boardLed, HIGH);
}
