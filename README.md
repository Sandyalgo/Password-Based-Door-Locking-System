# Password-Based-Door-Locking-System

ABSTRACT

    The Password-Based Door Locking System is an innovative security solution designed to automate door locking and unlocking using a user-defined password. 
    The system integrates hardware components such as an Arduino Uno microcontroller, 16x2 LCD display, 4x3 keypad, servo motor, and LED indicators, ensuring 
    functionality and user feedback. It leverages the Arduino IDE for programming and employs libraries like Keypad and Servo to simplify implementation.

    The system operates by prompting the user to enter a password via the keypad. If the entered password matches the predefined password, the servo motor activates, 
    unlocking the door. A green LED lights up to indicate successful access, and the door relocks automatically after a predefined delay of 5 seconds. If an incorrect 
    password is entered, a red LED signals denied access, and the system resets for the next attempt. Additionally, the system offers flexibility by allowing users to 
    update the password through software modifications, providing a dynamic and customizable security solution.

    This project combines affordability and practicality, making it suitable for homes, offices, and other secure locations. The design emphasizes ease of use, reliability,
    and security. The system's functionality was tested extensively to ensure responsiveness to correct and incorrect password inputs, with consistent servo motor 
    performance and accurate LED feedback.

    Future enhancements could include integrating wireless communication for remote access control, biometric authentication, or a backup power supply for uninterrupted 
    operation. This project demonstrates the potential of Arduino-based solutions in developing scalable and cost-effective security systems, addressing the growing need
    for smart home automation and advanced security measures.

Component Requirement 

    Arduino Uno
    16*2 LCD Display
    Servo Motor
    4*3 Keypad
    2 Led

PROJECT WORK

1. Initialization
   
When the system is powered on:
•	The LCD display shows a welcome message, prompting the user to "Enter the Code to Open the Door."
•	The servo motor is positioned in its locked state (e.g., at 0°).
•	The red LED (error indicator) is off, and the system is in an idle state, waiting for user input.
________________________________________
2. Password Entry
   
The user interacts with the system by entering a 4-digit password via the 4x3 keypad:
•	Each digit is displayed as * on the LCD to maintain password confidentiality.
•	The system collects input until four digits are entered.
Input Buffer Management:
•	The entered digits are stored in an input buffer (e.g., char input Buffer[5]).
•	If special keys like * or # are pressed, the system clears the buffer and resets for a new input.
________________________________________
3. Password Validation
   
Once four digits are entered:
•	The system compares the entered password in input Buffer with the pre-defined password stored in the code (e.g., char* password = "2345";).
•	Two outcomes are possible:
o	Correct Password:
	The system moves to the unlocking sequence.
o	Incorrect Password:
	The system displays an error message and prompts the user to retry.
________________________________________
4. Unlocking Sequence
   
If the password is correct:
1.	The LCD display updates to show "Access Granted" and "WELCOME!!".
2.	The green LED (success indicator) lights up briefly.
3.	The servo motor rotates from its locked position (e.g., 0°) to its unlocked position (e.g., 180°).
4.	The system begins a countdown timer (5 seconds), displayed on the LCD as "GET IN WITHIN: 5...4...3...2...1".
5.	After 5 seconds:
o	The servo motor rotates back to its locked position (e.g., 0°).
o	The red LED may briefly flash to indicate relocking.
7.	The system resets to the idle state, ready for the next password input.
________________________________________
5. Incorrect Password Handling
   
If the password is incorrect:
1.	The LCD display shows a message: "CODE INCORRECT" followed by "TRY AGAIN!!!".
2.	The red LED lights up briefly to indicate an error.
3.	The system waits for 3 seconds before clearing the display and resetting to the idle state.
Error Prevention:
•	The system ensures that incomplete or invalid entries (e.g., fewer than 4 digits) are cleared and not processed.
•	Users can press special keys like * or # to manually reset their input.
________________________________________
6. Automatic Reset
   
The system includes mechanisms to reset to its idle state in various scenarios:
•	After completing the unlocking sequence.
•	After handling an incorrect password.
•	When the user presses the reset keys (* or #).
________________________________________
7. Key Features of the Working
   
A. Security
•	Masked Input: Password entries are masked as * on the LCD, preventing others from seeing the input.
•	Automatic Relocking: The door relocks automatically after a fixed period, ensuring it isn’t left open.
B. User Feedback
•	LCD Messages: Clear instructions and status updates keep the user informed at every stage.
•	LED Indicators: Visual cues (green for success, red for error) make the system intuitive.
C. Efficiency
•	The system processes inputs and validates passwords in real-time, ensuring quick response times.
D. Reliability
•	The servo motor ensures precise locking and unlocking motions, with minimal risk of mechanical failure.
________________________________________
8. Simplified Workflow Diagram
   
Idle State
→ Enter Password → Validate Password:
•	If Correct: Unlock Door → Countdown → Lock Door → Reset.
•	If Incorrect: Display Error → Reset.
________________________________________
9. How the System Handles Scenarios
    
•	Multiple Wrong Attempts: The system resets for every incorrect attempt, avoiding lockouts.
•	Power Failure: The servo motor defaults to the locked position, ensuring security.
•	Customizable Settings: The password and servo rotation angles can be modified via Arduino code.

REFERENCE

https://github.com/marofES/password-based-door-locking-system-using-arduino-proteus
