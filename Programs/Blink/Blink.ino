#define LED_PIN 2 // We use pin 2 on the Arduino to switch from 0 to 5V

// This function is executed as soon as the microcontroller gets power
void setup() {
  pinMode(LED_PIN, OUTPUT); // Sets pin 2 as an output so we can control the voltage
}

// This function will be executed in a loop forever
void loop() {
  digitalWrite(LED_PIN, HIGH); // Sets the voltage at pin 2 to 5V
  delay(1000);                 // Waits for 1 second
  digitalWrite(LED_PIN, LOW);  // Sets the voltage at pin 2 to 0V
  delay(1000);                 // Waits for 1 second
}
