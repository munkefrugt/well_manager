
// press the buttons. 
// each button represents a magnet reed switch. 
// if the float / magnet goes from orange to red the motor(relay) stops. 
// if it goes back to orange it starts again :)
//green = full
//yellow = mellem
//orange = critical
//red = empty


// Define pins for LEDs
#define TOP_LED_PIN 2    // Green LED for Top (Full)
#define MID_LED_PIN 3    // Yellow LED for Mid
#define LOW_LED_PIN 4    // Orange LED for Low
#define EMPTY_LED_PIN 5  // Red LED for Empty

// Define pins for buttons (simulating reed switches)
#define TOP_BUTTON_PIN 9   // Button for Top (Full)
#define MID_BUTTON_PIN 10  // Button for Mid
#define LOW_BUTTON_PIN 11  // Button for Low
#define EMPTY_BUTTON_PIN 12 // Button for Empty

// Define pin for Relay
#define RELAY_PIN 13 // Pin to control the relay (pump)

// Variable to track pump state (latched)
bool pumpOn = true;  // Initially, pump is ON

void setup() {
  // Set LED pins as output
  pinMode(TOP_LED_PIN, OUTPUT);
  pinMode(MID_LED_PIN, OUTPUT);
  pinMode(LOW_LED_PIN, OUTPUT);
  pinMode(EMPTY_LED_PIN, OUTPUT);
  
  // Set Relay pin as output
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Turn the pump ON initially

  // Set button pins as input with internal pull-up resistors
  pinMode(TOP_BUTTON_PIN, INPUT_PULLUP);
  pinMode(MID_BUTTON_PIN, INPUT_PULLUP);
  pinMode(LOW_BUTTON_PIN, INPUT_PULLUP);
  pinMode(EMPTY_BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // Check button states and control corresponding LEDs and relay
  if (digitalRead(EMPTY_BUTTON_PIN) == LOW) {
    // Turn on only the Red LED (Empty) and turn off all others
    digitalWrite(EMPTY_LED_PIN, HIGH);
    digitalWrite(LOW_LED_PIN, LOW);
    digitalWrite(MID_LED_PIN, LOW);
    digitalWrite(TOP_LED_PIN, LOW);
    
    // Turn the pump OFF
    pumpOn = false;
    digitalWrite(RELAY_PIN, LOW); // Turn OFF pump
  } 
  else if (digitalRead(LOW_BUTTON_PIN) == LOW) {
    // Turn on only the Orange LED (Low) and turn off all others
    digitalWrite(LOW_LED_PIN, HIGH);
    digitalWrite(EMPTY_LED_PIN, LOW);
    digitalWrite(MID_LED_PIN, LOW);
    digitalWrite(TOP_LED_PIN, LOW);

    // Turn the pump ON
    pumpOn = true;
    digitalWrite(RELAY_PIN, HIGH); // Turn ON pump
  } 
  else if (digitalRead(MID_BUTTON_PIN) == LOW) {
    // Turn on only the Yellow LED (Mid) and turn off all others
    digitalWrite(MID_LED_PIN, HIGH);
    digitalWrite(EMPTY_LED_PIN, LOW);
    digitalWrite(LOW_LED_PIN, LOW);
    digitalWrite(TOP_LED_PIN, LOW);
  } 
  else if (digitalRead(TOP_BUTTON_PIN) == LOW) {
    // Turn on only the Green LED (Top) and turn off all others
    digitalWrite(TOP_LED_PIN, HIGH);
    digitalWrite(EMPTY_LED_PIN, LOW);
    digitalWrite(LOW_LED_PIN, LOW);
    digitalWrite(MID_LED_PIN, LOW);
  }
}
