int moisturePin = A0;     // Soil sensor analog pin
int relayPin = 8;         // Relay control pin
int threshold = 500;      // Adjust this based on calibration

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Make sure pump is OFF initially

  Serial.println("Timed Irrigation System Ready");
}

void loop() {
  int moistureVal = analogRead(moisturePin);
  Serial.print("Moisture Value: ");
  Serial.println(moistureVal);

  if (moistureVal > threshold) {
    Serial.println("Soil is DRY – Pump ON");
    digitalWrite(relayPin, HIGH);  // Turn ON pump
    delay(5000);                   // Run pump for 5 seconds
    digitalWrite(relayPin, LOW);   // Turn OFF pump
  } else {
    Serial.println("Soil is WET – No watering needed");
    digitalWrite(relayPin, LOW);   // Ensure pump stays OFF
  }

  delay(10000); // Wait 10 seconds before checking again
}
