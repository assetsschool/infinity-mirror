void setup() {
	pinMode(16, OUTPUT);
}

void loop() {
	digitalWrite(16, HIGH);
	delay(15);
	digitalWrite(16, LOW);
	delay(20);
}