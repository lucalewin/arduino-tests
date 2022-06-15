int value = 0;
float voltage;

void setup(){
  Serial.begin(9600);
}

void loop(){
  value = analogRead(A0);
  // voltage = 41.44f * value + 1.71f;
  // voltage = value * (25.15f / 1024.0f);
  voltage = 0.02 * value - 0.04;
  Serial.print("Voltage =");
  Serial.println(voltage);
  delay(500);
}


/*

Voltage | Actual Voltage
--------+---------------
202     | 4.8
137.5   | 3.3
163     | 3.9
735     | 17.7

Geogebra:
A = (202, 4.8)
B = (137.5, 3.3)
C = (163, 3.9)
D = (735, 17.7)

f: Trendlinie({A,B,C,D})
--> y = 41.44x + 1.71

g: Trendlinie({E,F,G,H})
--> y = 0.02x - 0.04

*/

/*

int value = 0;
float voltage;

int count = 0;
float sum = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  value = analogRead(A0);
  // voltage = 41.44f * value + 1.71f;
  // voltage = value * (25.15f / 1024.0f);
  // voltage = 0.024 * value + 0.11;
  voltage = 0.02498 * value - 0.06; 

  sum += voltage;
  count++;

  Serial.print("Voltage = ");
  Serial.println(sum / (float) count);
  delay(500);
}


/*

Voltage | Actual Voltage
--------+---------------
202     | 4.8
137.5   | 3.3
163     | 3.9
735     | 17.7

Geogebra:
A = (202, 4.8)
B = (137.5, 3.3)
C = (163, 3.9)
D = (735, 17.7)

f: Trendlinie({A,B,C,D})
--> y = 41.44x + 1.71

g: Trendlinie({E,F,G,H})
--> y = 0.02x - 0.04

*/

*/