#define BUTTON_PIN 2
#define LED_PIN 9
#define TIMEOUT 60000 // 60 seconds in milliseconds

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  unsigned long pulseWidth = pulseIn(BUTTON_PIN, HIGH, TIMEOUT);

  if (pulseWidth > 0) {
    int brightness = pulseWidth / 1000; // Convert pulse width to seconds
    brightness = min(brightness, 10); // Limit to 10 seconds
    brightness = map(brightness, 0, 10, 0, 255); // Convert to brightness scale (0 - 255)

    analogWrite(LED_PIN, brightness);
  } else {
    analogWrite(LED_PIN, 0); // Turn off LED after timeout
  }
}
