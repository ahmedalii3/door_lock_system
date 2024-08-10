Here's the revised README with mentions of UART and I2C:

---

# Door Locker Security System

## Overview
This project implements a Door Locker Security System that unlocks a door using a password. The system is designed using ATmega32 microcontrollers and features components such as an LCD, keypad, EEPROM, DC motor, buzzer, UART, and I2C communication. The system architecture follows a layered model to separate the Human Machine Interface (HMI) from control logic.

## Features
- **Password Protection:** Users can set, change, and confirm a password for door unlocking.
- **LCD Interface:** Displays prompts and status messages to the user.
- **Keypad Input:** Allows users to input passwords and navigate options.
- **EEPROM Storage:** Stores the password securely using I2C communication.
- **Motor Control:** Operates the door locking mechanism based on password validation.
- **Buzzer Alert:** Activates on multiple failed password attempts for security.
- **UART Communication:** Facilitates data exchange between microcontrollers.

## System Components
- **Microcontrollers:** 2x ATmega32 running at 8MHz.
- **LCD:** 2x16 character display for user interaction.
- **Keypad:** 4x4 matrix for password input.
- **EEPROM:** External storage for saving the password, interfaced via I2C.
- **DC Motor:** Drives the door lock mechanism.
- **Buzzer:** Provides auditory feedback for security breaches.
- **UART:** Used for communication between the HMI and Control microcontrollers.
- **I2C:** Used for communication between the Control microcontroller and EEPROM.

## Project Structure
- **/src:** Contains all the source code for microcontroller programming.
- **/drivers:** Drivers for LCD, Keypad, DC Motor, EEPROM, UART, I2C, Timer, and GPIO.
- **/docs:** Documentation for system design and architecture.
- **/schematics:** Circuit diagrams and hardware connections.

## Getting Started
### Prerequisites
- AVR-GCC Compiler
- AVRDUDE for programming the microcontroller
- Atmel Studio (optional)

### Usage
1. Power on the system.
2. Set a new password via the keypad following the LCD prompts.
3. Use the password to unlock the door or change the existing password.
4. The system will automatically lock the door and return to the main menu after a set time.

## Acknowledgments
- Eng/Mohamed Tarek for providing the initial system requirements and guidance.




