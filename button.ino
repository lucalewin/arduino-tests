
class Button {
private:
  int pin;
  
  byte state;
  byte prevState;

  void (*pressed)();
  void (*released)();

  int downAt;

public:
  Button(const int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
      
    this->state = 0;
    this->prevState = 0;

    this->pressed = nullptr;
    this->released = nullptr;

    this->downAt = 0;
  }

  void update() {
    this->prevState = this->state;
    this->state = digitalRead(this->pin);

    if (this->prevState != this->state) {
      // button was pressed or released
      if (this->state == HIGH) {
        // button is pressed
        if (this->pressed != nullptr) {
          pressed();
        }
      } else {
        // button was released
        if (this->released != nullptr) {
          released();
        }
      }
    }
  }
  
  void addOnPressedListener(void (*pressed)()) {
    this->pressed = pressed;
  }

  bool isDown() {
    return state == HIGH;
  }

  const int getPin() {
    return this->pin;
  }
};

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
bool measurementRunning = false;

Button input_button = Button(2);

void onInputButtonPressed() {
  // printf("pressed\n");
}

void onInputButtonReleased() {
  // printf("released\n");
}

void setup() {
  
  //input_button.addOnPressedListener(onInputButtonPressed);

  Serial.begin(9600);
  Serial.print("setup()");
  Serial.println();

  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
}

// if the button is pressed the first time, start the voltage measurement
// if the button is pressed again, stop the measurement
void loop() {
  input_button.update();

  if (input_button.isDown()) {

    // if the button is pressed 3 seconds reset the program
    // if (input_button.downTime() > 3000) {

    // }

    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}





















