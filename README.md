# DASH_BOARD_DESIGN_USING_CAN_PROTOCOL
DASHBOARD DESIGN USING CAN PROTOCOL
Project Overview

The project involves designing a CAN-based dashboard system using two microcontrollers.
It simulates a vehicle dashboard where a potentiometer controls speed, and real-time speed data is displayed on an LCD.
The system includes headlight and turn signal controls.
Timer interrupts are used for precise speed data processing and indicator blinking delay.
Features and Functionalities

Real-time speed display using a potentiometer.
CAN communication between two microcontrollers.
Turn signals with LED indicators controlled by timer interrupts.
Headlight control synchronized over the CAN network.
Timer interrupts for accurate data handling and LED blinking delay.
System Architecture

Two microcontrollers communicate using the CAN protocol.
One microcontroller reads speed data and transmits it over CAN.
The second microcontroller receives speed data and displays it on an LCD.
LEDs are used for indicator lights and headlight status.
Technologies and Components Used

Microcontrollers with CAN support such as STM32, PIC, or Arduino with MCP2515 module.
Communication using the CAN protocol.
Potentiometer to simulate throttle control.
LCD or OLED display for speed visualization.
LEDs for turn signals and headlights.
Timer interrupts for precise data processing.
Implementation Details

CAN bus setup with two microcontrollers exchanging messages.
ADC conversion of potentiometer readings to simulate speed.
Speed data transmission over CAN with unique message IDs.
Reception and display of speed data on an LCD.
Timer interrupts for turn signal blinking and periodic speed updates.
Testing Approach

Functional testing for speed display, CAN message verification, turn signals, and headlights.
Boundary value testing for minimum and maximum speed values.
Negative testing with corrupt CAN messages and network failures.
Performance testing for real-time response and data transmission latency.
Stress testing for prolonged system operation and high-speed data transmission.
Challenges Faced and Solutions

Ensuring synchronization of CAN messages using unique identifiers.
Filtering ADC data to eliminate noise and provide stable speed readings.
Using timer interrupts for consistent speed updates and LED blinking.
Conclusion

The project demonstrates real-time vehicle data communication using CAN.
It ensures fast and reliable data exchange between microcontrollers.
The system integrates speed monitoring, headlight control, and turn signal functionality.
Possible Enhancements

Replacing the LCD with a TFT touch screen.
Implementing fault detection mechanisms for CAN errors.
Adding speed limit alerts using a buzzer.
Using PWM to control a real motor instead of a potentiometer.
Relevance for a Tester Role

Involves real-time embedded system testing.
Requires validation of CAN protocol communication.
Tests safety-critical automotive systems.
Includes hardware-software integration testing.
