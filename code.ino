#include <LiquidCrystal.h>
#include <Servo.h>
#include <Keypad.h>

Servo myservo;
int pos = 0; // Position of servo motor
LiquidCrystal lcd(A4, A5, A3, A2, A1, A0);

const byte rows = 4;
const byte cols = 3;

char key[rows][cols] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[rows] = {0, 1, 2, 3};
byte colPins[cols] = {4, 5, 6};

Keypad keypad = Keypad(makeKeymap(key), rowPins, colPins, rows, cols);

char* password = "2345"; // The correct password
char inputBuffer[5] = ""; // Buffer to store entered keys
int inputIndex = 0; // Current input position

int red = 13;
int green = 12;

void setup() {
  myservo.attach(8); // Servo motor connection
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  lcd.begin(16, 2);
  displayscreen();
}

void loop() {
  char code = keypad.getKey();
  if (code != NO_KEY) {
    if (code == '*' || code == '#') {
      // Reset on special keys
      resetInput();
      return;
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("PASSWORD:");

    // Add entered key to the input buffer
    if (inputIndex < 4) {
      inputBuffer[inputIndex] = code;
      inputIndex++;
      lcd.setCursor(7, 1);
      for (int i = 0; i < inputIndex; i++) {
        lcd.print("*");
      }
    }

    // Check password if 4 digits entered
    if (inputIndex == 4) {
      inputBuffer[4] = '\0'; // Null-terminate the string
      if (strcmp(inputBuffer, password) == 0) {
        unlockdoor();
      } else {
        incorrect();
      }
      resetInput();
    }
  }
}

// Reset the input buffer
void resetInput() {
  memset(inputBuffer, 0, sizeof(inputBuffer)); // Clear the buffer
  inputIndex = 0; // Reset the index
  displayscreen(); // Reset the display
}

//------------------ Function 1- OPEN THE DOOR--------------//
void unlockdoor() {
  delay(900);

  lcd.setCursor(0, 0);
  lcd.println(" ");
  lcd.setCursor(1, 0);
  lcd.print("Access Granted");
  lcd.setCursor(4, 1);
  lcd.println("WELCOME!!");

  for (pos = 180; pos >= 0; pos -= 5) { // Open the door
    myservo.write(pos);
    delay(5);
  }
  digitalWrite(green, HIGH);
  delay(1000);
  digitalWrite(green, LOW);
  delay(2000);

  delay(1000);
  counterbeep();

  delay(1000);

  for (pos = 0; pos <= 180; pos += 5) { // Close the door
    myservo.write(pos);
    delay(15);
  }
  digitalWrite(red, HIGH);
  delay(1000);
  digitalWrite(red, LOW);
  delay(500);

  lcd.clear();
  displayscreen();
}

//--------------------Function 2- Wrong code--------------//
void incorrect() {
  delay(500);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("CODE");
  lcd.setCursor(6, 0);
  lcd.print("INCORRECT");
  lcd.setCursor(4, 1);
  lcd.println("TRY AGAIN !!!");
  digitalWrite(red, HIGH);
  delay(1000);
  digitalWrite(red, LOW);
  delay(3000);
  lcd.clear();
  displayscreen();
}

//------------Function 3 - DISPLAY FUNCTION--------------------//
void displayscreen() {
  lcd.setCursor(0, 0);
  lcd.println("ENTER THE CODE");
  lcd.setCursor(1, 1);
  lcd.println("TO OPEN DOOR!!");
}

//--------------Function 5 - Count down------------------//
void counterbeep() {
  delay(1200);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.println("GET IN WITHIN:::");
  for (int i = 5; i > 0; i--) {
    lcd.setCursor(4, 1);
    lcd.print(i);
    delay(1000);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.println("GET IN WITHIN:::");
  }
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("LOCKED!");
  delay(1000);
}
