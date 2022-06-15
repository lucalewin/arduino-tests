// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// 
// Edited by Luca Lewin (15 June 2022)
// ---------------------------------------------------------------- //

#define ECHO_PIN 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define TRIG_PIN 3 // attach pin D3 Arduino to pin Trig of HC-SR04

#define SPEED_OF_SOUND 0.034                   // in [cm*ms^-1]
#define HALF_SPEED_OF_SOUND SPEED_OF_SOUND / 2 // in [cm*ms^-1]

// defines variables
unsigned long duration; // variable for the duration of sound wave travel
unsigned int distance;  // variable for the distance measurement

void setup() {
	pinMode(TRIG_PIN, OUTPUT); // Sets the TRIG_PIN as an OUTPUT
	pinMode(ECHO_PIN, INPUT);  // Sets the ECHO_PIN as an INPUT
	
	// Serial Communication is starting with 9600 of baudrate speed
	Serial.begin(9600);
	Serial.println("Ultrasonic Sensor HC-SR04 Test");
	Serial.println("with Arduino UNO R3");
}

void loop() {
	// Clears the TRIG_PIN condition
	digitalWrite(TRIG_PIN, LOW);
	delayMicroseconds(2);
	
	// Sets the TRIG_PIN HIGH (ACTIVE) for 10 microseconds
	digitalWrite(TRIG_PIN, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG_PIN, LOW);
	
	// Reads the ECHO_PIN, returns the sound wave travel time in microseconds
	duration = pulseIn(ECHO_PIN, HIGH);
	
	// Calculating the distance
	distance = duration * HALF_SPEED_OF_SOUND;
	
	// Displays the distance on the Serial Monitor
	Serial.print("Distance: ");
	Serial.print(distance);
	Serial.println(" cm");
}
