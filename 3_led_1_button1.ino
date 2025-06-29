// Define LED pins
const int led1 = 13;
const int led2 = 12;
const int led3 = 11;

// Define button pin
const int buttonPin = 2;

// Variables to hold the state
bool ledsOn = false;      // current state: are LEDs on or off
bool lastButtonState = HIGH;  // previous reading from the button

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  // Check if button changed from HIGH to LOW (pressed)
  if (buttonState == LOW && lastButtonState == HIGH) {
    ledsOn = !ledsOn;  // toggle state
    delay(50); // simple debounce delay
  }

  lastButtonState = buttonState;

  // Set LEDs according to state
  if (ledsOn) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
}
