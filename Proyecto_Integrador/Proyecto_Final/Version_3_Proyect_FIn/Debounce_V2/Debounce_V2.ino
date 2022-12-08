// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 8; 
const int buttonPin2 = 9; 
const int buttonPin3 = 10; // the number of the pushbutton pin


// Variables will change:        // the current state of the output pin
int buttonState1;             // the current reading from the input pin
int lastButtonState1 = LOW;   // the previous reading from the input pin
int buttonState2;
int lastButtonState2 = LOW;
int buttonState3;
int lastButtonState3 = LOW;

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime1 = 0;  // the last time the output pin was toggled
unsigned long lastDebounceTime2 = 0;
unsigned long lastDebounceTime3 = 0;
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

int n = 3;
int pulsadores[] = { 2, 9, 10 };

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);


  for (int i = 0; i < n; i++) {
    pinMode(pulsadores[i], INPUT_PULLUP);
  }

  // set initial LED state
  Serial.begin(9600);
}

void loop() {
  // read the state of the switch into a local variable:
  //////////////////////////////////////////////////////////////////////START BUTTON 1//////////////////////////////////////////////////////////////////////////////////////
  int reading = digitalRead(buttonPin1);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState1) {
    // reset the debouncing timer
    lastDebounceTime1 = millis();
  }

  if ((millis() - lastDebounceTime1) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState1) {
      buttonState1 = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState1 == HIGH) {
        Serial.println("Pulsador1: " + String());
      }
    }
/////////////////////////////////////////////////////////////////////END BUTTON 1 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
 ////////////////////////////////////////////////////////////////////START BUTTON 2//////////////////////////////////////////////////////////////////////////////////////////////////////////////   
    int reading = digitalRead(buttonPin2);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState2) {
    // reset the debouncing timer
    lastDebounceTime2 = millis();
  }

  if ((millis() - lastDebounceTime2) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState2) {
      buttonState2 = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState2 == HIGH) {
        Serial.println("Pulsador2: " + String());
      }
    }
//////////////////////////////////////////////////////////////////////////////END BUTTON 2//////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////START BUTTON 3////////////////////////////////////////////////////////////////////////////////////////////////

    int reading = digitalRead(buttonPin3);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState3) {
    // reset the debouncing timer
    lastDebounceTime3 = millis();
  }

  if ((millis() - lastDebounceTime3) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:
    // if the button state has changed:
    if (reading != buttonState3) {
      buttonState3 = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState3 == HIGH) {
        Serial.println("Pulsador3: " + String());
    }
  }

  // set the LED:
  

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState1 = reading;
  lastButtonState2 = reading;
  lastButtonState3 = reading;
  }
  }
  }
}
  
  
