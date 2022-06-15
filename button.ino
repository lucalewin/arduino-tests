#define BUTTON_PIN 2

void setup() {
	// initialize the built-in LED pin as an output:
	pinMode(LED_BUILTIN, OUTPUT);
	
	// initialize the button pin as an input:
	pinMode(BUTTON_PIN, INPUT);
}

void loop() {
	if (digitalRead(BUTTON_PIN)) {
		digitalWrite(LED_BUILTIN, HIGH);
	} else {
		digitalWrite(LED_BUILTIN, LOW);
	}
}
