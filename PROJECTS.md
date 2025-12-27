# 📚 Detailed Project Catalog

This document provides comprehensive information about each project in the repository, including descriptions, technologies used, complexity levels, and file structures.

---

## 📊 Project Overview

| Microcontroller | Projects | Difficulty Range |
|:---|:---:|:---|
| 8051 (AT89C51) | 7 | Beginner to Intermediate |
| ARM7 (LPC2138) | 8 | Intermediate to Advanced |
| AVR | 1 | Beginner |
| PIC16 | 7 | Beginner to Intermediate |
| PIC18 | 8 | Intermediate to Advanced |

---

## 🔴 8051 (AT89C51) Projects

### 1. ADC
**Path:** [`8051/ADC/`](../8051/ADC/)  
**Difficulty:** ⭐⭐ Intermediate  
**Technologies:** ADC, C Programming  
**Description:** Analog-to-Digital Converter interfacing implementation for the 8051 microcontroller. Demonstrates reading analog signals and converting them to digital values.

**Key Features:**
- ADC initialization and configuration
- Analog signal reading
- Digital value processing

**Files:**
- `ADC_Program.C` - Main source code
- `ADC_Proj.uvproj` - Keil uVision project file
- `ADC_!.pdsprj` - Proteus simulation file
- `STARTUP.A51` - Startup code

---

### 2. ADC_A
**Path:** [`8051/ADC_A/`](../8051/ADC_A/)  
**Difficulty:** ⭐⭐ Intermediate  
**Technologies:** ADC, C Programming  
**Description:** Alternative ADC implementation with different configuration approach. Provides an alternative method for ADC interfacing.

**Key Features:**
- Alternative ADC configuration
- Different sampling approach
- Code structure variation

**Files:**
- `ADC_1.C` - Main source code
- `ADC-1.uvproj` - Keil uVision project file
- `ASDC_1.pdsprj` - Proteus simulation file
- `STARTUP.A51` - Startup code

---

### 3. ADC_POT
**Path:** [`8051/ADC_POT/`](../8051/ADC_POT/)  
**Difficulty:** ⭐⭐ Intermediate  
**Technologies:** ADC, Potentiometer, C Programming  
**Description:** ADC implementation with potentiometer input. Demonstrates reading variable analog voltage from a potentiometer and converting it to digital values.

**Key Features:**
- Potentiometer voltage reading
- Variable analog input handling
- Real-time ADC conversion

**Files:**
- `adc_potentiometer.C` - Main source code
- `adc_pot.uvproj` - Keil uVision project file
- `adc_pot.pdsprj` - Proteus simulation file
- `STARTUP.A51` - Startup code

---

### 4. 7-Segment Display
**Path:** [`8051/7-Segement Display/`](../8051/7-Segement%20Display/)  
**Difficulty:** ⭐ Beginner  
**Technologies:** 7-Segment Display, Assembly Language  
**Description:** 7-segment display driver implementation using assembly language. Controls a 7-segment display to show numeric values.

**Key Features:**
- 7-segment display control
- Assembly language programming
- Display pattern generation

**Files:**
- `7_seg_display.asm` - Assembly source code
- `7seg_display.uvproj` - Keil uVision project file
- `CA_SEG_DISPLAY.pdsprj` - Proteus simulation file
- `STARTUP.A51` - Startup code

---

### 5. LCD_Interfacing
**Path:** [`8051/LCD_Interfacing/`](../8051/LCD_Interfacing/)  
**Difficulty:** ⭐⭐ Intermediate  
**Technologies:** LCD, C Programming  
**Description:** LCD display interfacing implementation. Demonstrates how to interface and control a 16x2 LCD display with the 8051 microcontroller.

**Key Features:**
- LCD initialization
- Text display functions
- Custom character generation
- Display control commands

**Files:**
- `lcd.C` - Main source code
- `LCD_Data.uvproj` - Keil uVision project file
- `lcd_stream_interfacing.pdsprj` - Proteus simulation file
- `STARTUP.A51` - Startup code

---

### 6. LED_BLINK
**Path:** [`8051/LED_BLINK/`](../8051/LED_BLINK/)  
**Difficulty:** ⭐ Beginner  
**Technologies:** LED, Assembly Language  
**Description:** Basic LED blinking program using assembly language. The simplest embedded program demonstrating GPIO control.

**Key Features:**
- GPIO pin configuration
- LED on/off control
- Timing delay implementation
- Assembly language basics

**Files:**
- `LED.asm` - Assembly source code
- `LED_BLINK.uvproj` - Keil uVision project file
- `led_sim.pdsprj` - Proteus simulation file
- `STARTUP.A51` - Startup code

---

### 7. LED_TRAFFIC
**Path:** [`8051/LED_TRAFFIC/`](../8051/LED_TRAFFIC/)  
**Difficulty:** ⭐⭐ Intermediate  
**Technologies:** LED, Traffic Control, Assembly Language  
**Description:** Traffic light simulation using LEDs. Implements a traffic light controller with timing sequences for red, yellow, and green lights.

**Key Features:**
- Multi-LED control
- Timing sequences
- Traffic light state machine
- Real-world application simulation

**Files:**
- `traffic.asm` - Assembly source code
- `traffic_lights.uvproj` - Keil uVision project file
- `traffic_sim.pdsprj` - Proteus simulation file
- `STARTUP.A51` - Startup code

---

## 💪 ARM7 (LPC2138) Projects

### 1. ADC_ARM
**Path:** [`ARM/ADC_ARM/`](../ARM/ADC_ARM/)  
**Difficulty:** ⭐⭐ Intermediate  
**Technologies:** ADC, LCD, C Programming  
**Description:** ADC implementation for ARM7 microcontroller with LCD display output. Demonstrates ADC reading and displaying results on LCD.

**Key Features:**
- ARM ADC peripheral configuration
- LCD integration
- Analog value display
- Multi-channel ADC support

**Files:**
- `main.c` - Main source code
- `ADC.h` - ADC header file
- `LCD.h` - LCD header file
- `ADC_Proj.uvproj` - Keil uVision project file
- `ARM_ADC.pdsprj` - Proteus simulation file
- `Startup.s` - ARM startup code

---

### 2. CAN_PROTOCOL
**Path:** [`ARM/CAN_PROTOCOL/`](../ARM/CAN_PROTOCOL/)  
**Difficulty:** ⭐⭐⭐ Advanced  
**Technologies:** CAN Bus, MCP2515, C Programming  
**Description:** CAN bus communication protocol implementation using MCP2515 CAN controller. Demonstrates CAN message transmission and reception.

**Key Features:**
- CAN bus protocol implementation
- MCP2515 controller interfacing
- CAN message framing
- Error handling

**Files:**
- `main.c` - Main source code
- `can.h` - CAN protocol header
- `can_lpc.c` - LPC CAN implementation
- `can_mcp2515.c` - MCP2515 driver
- `CAN_Proj.uvproj` - Keil uVision project file
- `Startup.s` - ARM startup code

---

### 3. CAN_WORKING
**Path:** [`ARM/CAN_WORKING/`](../ARM/CAN_WORKING/)  
**Difficulty:** ⭐⭐⭐ Advanced  
**Technologies:** CAN Bus, C Programming  
**Description:** Working CAN implementation using inbuilt CAN peripheral of LPC2138. Demonstrates native CAN bus communication.

**Key Features:**
- Inbuilt CAN peripheral usage
- CAN message handling
- Real-time communication
- Working implementation

**Files:**
- `main.c` - Main source code
- `can.h` - CAN header file
- `can_lpc.c` - LPC CAN driver
- `CAN_INBUILT.uvproj` - Keil uVision project file
- `Startup.s` - ARM startup code

---

### 4. I2C_EEPROM_ARM7
**Path:** [`ARM/I2C_EEPROM_ARM7/`](../ARM/I2C_EEPROM_ARM7/)  
**Difficulty:** ⭐⭐⭐ Advanced  
**Technologies:** I2C, EEPROM, C Programming  
**Description:** I2C EEPROM interfacing implementation. Demonstrates I2C protocol for reading and writing data to EEPROM memory.

**Key Features:**
- I2C protocol implementation
- EEPROM read/write operations
- Data storage and retrieval
- I2C bus management

**Files:**
- `I2C.c` - I2C implementation
- `I2C.uvproj` - Keil uVision project file
- `I2C_PROJ.pdsprj` - Proteus simulation file
- `Startup.s` - ARM startup code

---

### 5. I2C-Proj2
**Path:** [`ARM/I2C-Proj2/`](../ARM/I2C-Proj2/)  
**Difficulty:** ⭐⭐⭐ Advanced  
**Technologies:** I2C, EEPROM, C Programming  
**Description:** Alternative I2C EEPROM implementation (variant 2). Provides a different approach to I2C EEPROM interfacing.

**Key Features:**
- Alternative I2C implementation
- Enhanced error handling
- Different code structure
- EEPROM operations

**Files:**
- `I2C.c` - I2C implementation
- `I2C.uvproj` - Keil uVision project file
- `I2C_PROJ.pdsprj` - Proteus simulation file
- `Startup.s` - ARM startup code

---

### 6. PIR_Sensor_ARM7
**Path:** [`ARM/PIR_Sensor_ARM7/`](../ARM/PIR_Sensor_ARM7/)  
**Difficulty:** ⭐⭐ Intermediate  
**Technologies:** PIR Sensor, Motion Detection, C Programming  
**Description:** PIR (Passive Infrared) motion sensor interfacing. Detects motion and triggers appropriate responses.

**Key Features:**
- PIR sensor interfacing
- Motion detection logic
- Interrupt handling
- Real-time sensing

**Files:**
- `PIR.c` - PIR sensor code
- `PIR_Sensor.uvproj` - Keil uVision project file
- `PIR_SENSING.pdsprj` - Proteus simulation file
- `Startup.s` - ARM startup code

---

### 7. RFID_ARM
**Path:** [`ARM/RFID_ARM/`](../ARM/RFID_ARM/)  
**Difficulty:** ⭐⭐⭐ Advanced  
**Technologies:** RFID, UART, LCD, C Programming  
**Description:** RFID reader interfacing with UART communication and LCD display. Reads RFID card data and displays it on LCD.

**Key Features:**
- RFID reader interfacing
- UART communication
- LCD display integration
- Card data processing

**Files:**
- `RFID.c` - RFID implementation
- `uart.h` - UART header file
- `lcd.h` - LCD header file
- `RFID.uvproj` - Keil uVision project file
- `rfid_simulation.pdsprj` - Proteus simulation file
- `Startup.s` - ARM startup code

---

### 8. TouchSensor
**Path:** [`ARM/TouchSensor/`](../ARM/TouchSensor/)  
**Difficulty:** ⭐⭐ Intermediate  
**Technologies:** Touch Sensor, C Programming  
**Description:** Touch sensor implementation for ARM7. Detects touch input and processes touch events.

**Key Features:**
- Touch sensor interfacing
- Touch detection logic
- Event handling
- Sensor calibration

**Files:**
- `touch_sensing.C` - Touch sensor code
- `Touch_Sensor.uvproj` - Keil uVision project file
- `touch_sensor.pdsprj` - Proteus simulation file
- `Startup.s` - ARM startup code

---

## 🔷 AVR Projects

### 1. AVR_LED
**Path:** [`AVR/AVR/AVR_LED/`](../AVR/AVR/AVR_LED/)  
**Difficulty:** ⭐ Beginner  
**Technologies:** LED, C Programming  
**Description:** LED control implementation for AVR microcontroller. Basic GPIO control for LED blinking.

**Key Features:**
- AVR GPIO configuration
- LED control
- Timing delays
- Basic embedded programming

**Files:**
- Multiple header files (16 `.h` files)
- Source files (2 `.c` files)
- Project configuration files

---

## 🎯 PIC16 Projects

### 1. 7_SEGMENT
**Path:** [`PIC16/PIC16/7 SEGMENT/`](../PIC16/PIC16/7%20SEGMENT/)  
**Difficulty:** ⭐ Beginner  
**Technologies:** 7-Segment Display, C Programming  
**Description:** 7-segment display driver for PIC16. Controls a 7-segment display to show numeric values.

**Key Features:**
- 7-segment display control
- Number display functions
- Display pattern generation

**Files:**
- `7_SEG.c` - Main source code
- `7_SEGMENT.mcp` - MPLAB project file
- `7seg_pic.pdsprj` - Proteus simulation file
- `startup.as` - Startup code

---

### 2. 7seg_multiplex
**Path:** [`PIC16/PIC16/7seg_multiplex/`](../PIC16/PIC16/7seg_multiplex/)  
**Difficulty:** ⭐⭐ Intermediate  
**Technologies:** 7-Segment Display, Multiplexing, C Programming  
**Description:** Multiplexed 7-segment display implementation. Controls multiple 7-segment displays using time-division multiplexing.

**Key Features:**
- Display multiplexing
- Multiple digit control
- Timing management
- Efficient resource usage

**Files:**
- `7seg_multiplex.c` - Main source code
- `7segplex.mcp` - MPLAB project file

---

### 3. LEDPIC
**Path:** [`PIC16/PIC16/LEDPIC/`](../PIC16/PIC16/LEDPIC/)  
**Difficulty:** ⭐ Beginner  
**Technologies:** LED, C Programming  
**Description:** LED control for PIC16 microcontroller. Basic LED blinking and control patterns.

**Key Features:**
- GPIO configuration
- LED control
- Pattern generation

**Files:**
- `ledb.c` - Main source code
- `ledb.as` - Assembly file
- `ledb.mcp` - MPLAB project file
- `led_sim.pdsprj` - Proteus simulation file
- `startup.as` - Startup code

---

### 4. pwm
**Path:** [`PIC16/PIC16/pwm/`](../PIC16/PIC16/pwm/)  
**Difficulty:** ⭐⭐ Intermediate  
**Technologies:** PWM, C Programming  
**Description:** PWM (Pulse Width Modulation) signal generation. Generates PWM signals for motor control or dimming applications.

**Key Features:**
- PWM signal generation
- Duty cycle control
- Frequency adjustment
- Timer-based PWM

**Files:**
- `main.c` - Main source code
- `pwm.c` - PWM implementation
- `pwm.h` - PWM header file
- `includes.h` - Header includes
- `pwm.mcp` - MPLAB project file
- `pwmsims.pdsprj` - Proteus simulation file
- `startup.as` - Startup code

---

### 5. stepper_motor
**Path:** [`PIC16/PIC16/stepper_motor/`](../PIC16/PIC16/stepper_motor/)  
**Difficulty:** ⭐⭐ Intermediate  
**Technologies:** Stepper Motor, C Programming  
**Description:** Stepper motor control implementation. Controls stepper motor rotation with precise step control.

**Key Features:**
- Stepper motor control
- Step sequence generation
- Direction control
- Speed control

**Files:**
- `stepper_motor.c` - Main source code
- `stepper_motor.as` - Assembly file
- `stepper_motor.mcp` - MPLAB project file
- `stepper_motor.pdsprj` - Proteus simulation file
- `startup.as` - Startup code

---

### 6. timer
**Path:** [`PIC16/PIC16/timer/`](../PIC16/PIC16/timer/)  
**Difficulty:** ⭐⭐ Intermediate  
**Technologies:** Timer, ISR, Interrupts, C Programming  
**Description:** Timer implementation with interrupt service routines. Demonstrates timer-based operations and interrupt handling.

**Key Features:**
- Timer configuration
- Interrupt service routines (ISR)
- Timer-based timing
- Event-driven programming

**Files:**
- `Main.c` - Main source code
- `Timer.c` - Timer implementation
- `Timer.h` - Timer header
- `ISR.c` - Interrupt service routines
- `ISR.h` - ISR header
- `Includes.h` - Header includes
- `timer.mcp` - MPLAB project file
- `timersim.pdsprj` - Proteus simulation file
- `startup.as` - Startup code

---

### 7. unipolarDCMotor
**Path:** [`PIC16/PIC16/unipolarDCMotor/`](../PIC16/PIC16/unipolarDCMotor/)  
**Difficulty:** ⭐⭐ Intermediate  
**Technologies:** DC Motor, C Programming  
**Description:** Unipolar DC motor control implementation. Controls DC motor speed and direction.

**Key Features:**
- DC motor control
- Speed control
- Direction control
- Motor driver interfacing

**Files:**
- `dcmotor.c.c` - Main source code
- `dcmotor.as` - Assembly file
- `dcmotor.mcp` - MPLAB project file
- `dcmotorsim.pdsprj` - Proteus simulation file
- `startup.as` - Startup code

---

## 🚀 PIC18 Projects

### 1. LCD_Display_8_bit
**Path:** [`PIC18/PIC18/LCD_DIsplay_8_bit/`](../PIC18/PIC18/LCD_DIsplay_8_bit/)  
**Difficulty:** ⭐⭐ Intermediate  
**Technologies:** LCD, 8-bit Interface, C Programming  
**Description:** 8-bit LCD interfacing for PIC18. Controls LCD display using 8-bit parallel interface.

**Key Features:**
- 8-bit parallel LCD interface
- LCD initialization
- Text display functions
- Display control

**Files:**
- `lcd_display8.c` - Main source code
- `LCD_Display8.mcp` - MPLAB project file

---

### 2. LED_blink
**Path:** [`PIC18/PIC18/`](../PIC18/PIC18/)  
**Difficulty:** ⭐ Beginner  
**Technologies:** LED, C Programming  
**Description:** LED blinking patterns for PIC18. Basic LED control with various blinking patterns.

**Key Features:**
- LED control
- Blinking patterns
- GPIO configuration

**Files:**
- `led_blink.c` - Main source code
- `LED_blink.mcp` - MPLAB project file

---

### 3. LED_Pattern_blink
**Path:** [`PIC18/PIC18/LED_Pattern_blink/`](../PIC18/PIC18/LED_Pattern_blink/)  
**Difficulty:** ⭐⭐ Intermediate  
**Technologies:** LED, Patterns, C Programming  
**Description:** Advanced LED pattern blinking. Creates complex LED patterns and sequences.

**Key Features:**
- Advanced LED patterns
- Pattern sequences
- Timing control
- Visual effects

**Files:**
- `led_by_blink.c` - Main source code
- `LED_sim_blink.mcp` - MPLAB project file
- `led_common.pdsprj` - Proteus simulation file

---

### 4. NewPic18SPI
**Path:** [`PIC18/PIC18/NewPic18SPI/`](../PIC18/PIC18/NewPic18SPI/)  
**Difficulty:** ⭐⭐⭐ Advanced  
**Technologies:** SPI, SD Card, C Programming  
**Description:** SPI communication for SD card interfacing. Demonstrates SPI protocol for SD card read/write operations.

**Key Features:**
- SPI protocol implementation
- SD card interfacing
- File system operations
- Data storage

**Files:**
- `PIC18SPIRev.c` - Main source code
- `PIC184550SPI.mcp` - MPLAB project file
- `SPI_SD_CARD_Sim.pdsprj` - Proteus simulation file

---

### 5. PIC_18_LCD_REV
**Path:** [`PIC18/PIC18/PIC_18_LCD_REV/`](../PIC18/PIC18/PIC_18_LCD_REV/)  
**Difficulty:** ⭐⭐ Intermediate  
**Technologies:** LCD, C Programming  
**Description:** LCD revision implementation for PIC18. Enhanced LCD interfacing with additional features.

**Key Features:**
- Enhanced LCD control
- Configuration options
- Display functions
- Revision improvements

**Files:**
- `LCD 16x2.c` - Main source code
- `Configuration_Header_File.h` - Configuration header
- `config_intosc.h` - Internal oscillator config
- `PIC_18_REV.mcp` - MPLAB project file

---

### 6. PIC18_I2C
**Path:** [`PIC18/PIC18/PIC18_I2C/`](../PIC18/PIC18/PIC18_I2C/)  
**Difficulty:** ⭐⭐⭐ Advanced  
**Technologies:** I2C, C Programming  
**Description:** I2C communication protocol implementation for PIC18. Demonstrates I2C master/slave communication.

**Key Features:**
- I2C protocol implementation
- Master/slave configuration
- Data transmission
- Error handling

**Files:**
- `PIC_18_I2C.c` - Main source code
- `PIC_18_I2C.mcp` - MPLAB project file
- `PIC_18_I2C_Sim.pdsprj` - Proteus simulation file

---

### 7. PIC18SPI
**Path:** [`PIC18/PIC18/PIC18SPI/`](../PIC18/PIC18/PIC18SPI/)  
**Difficulty:** ⭐⭐⭐ Advanced  
**Technologies:** SPI, C Programming  
**Description:** SPI communication protocol implementation for PIC18. Demonstrates SPI master/slave communication.

**Key Features:**
- SPI protocol implementation
- Master/slave configuration
- Data transmission
- Clock control

**Files:**
- `PIC18SPI.c` - Main source code
- `PIC18SPI.mcp` - MPLAB project file
- `SPI_Communication.pdsprj` - Proteus simulation file

---

### 8. PICADC
**Path:** [`PIC18/PIC18/PICADC/`](../PIC18/PIC18/PICADC/)  
**Difficulty:** ⭐⭐ Intermediate  
**Technologies:** ADC, LCD, C Programming  
**Description:** ADC implementation for PIC18 with LCD display. Reads analog values and displays them on LCD.

**Key Features:**
- ADC configuration
- Analog reading
- LCD display integration
- Value conversion

**Files:**
- `adc.c` - ADC implementation
- `lcd.h` - LCD header file
- `PIADC.mcp` - MPLAB project file
- `ADC_PIC_WORKING.pdsprj` - Proteus simulation file

---

## 📈 Project Complexity Guide

### ⭐ Beginner
- Basic GPIO control
- Simple LED blinking
- Basic display control
- Fundamental concepts

### ⭐⭐ Intermediate
- Peripheral interfacing
- Communication basics
- Sensor integration
- Motor control

### ⭐⭐⭐ Advanced
- Complex protocols (CAN, I2C, SPI)
- Multi-peripheral integration
- Advanced sensor systems
- Real-time communication

---

## 🔍 Technology Index

### Communication Protocols
- **I2C** - Used in: ARM I2C_EEPROM, PIC18_I2C
- **SPI** - Used in: PIC18SPI, NewPic18SPI
- **CAN** - Used in: CAN_PROTOCOL, CAN_WORKING
- **UART** - Used in: RFID_ARM

### Sensors
- **ADC** - Used in: Multiple projects across all families
- **PIR** - Used in: PIR_Sensor_ARM7
- **RFID** - Used in: RFID_ARM
- **Touch** - Used in: TouchSensor

### Displays
- **LCD** - Used in: LCD_Interfacing, ADC_ARM, RFID_ARM, PIC18 LCD projects
- **7-Segment** - Used in: 7-Segment Display, 7_SEGMENT, 7seg_multiplex

### Actuators
- **Stepper Motor** - Used in: stepper_motor
- **DC Motor** - Used in: unipolarDCMotor
- **PWM** - Used in: pwm

### Control Systems
- **Timer** - Used in: timer
- **ISR** - Used in: timer
- **Traffic Control** - Used in: LED_TRAFFIC

---

## 📝 Notes

- All projects include simulation files (`.pdsprj`) for Proteus Design Suite
- Project files are included for direct IDE opening
- Source code is well-organized and commented
- Each project is self-contained with necessary files
- Build artifacts are excluded (see `.gitignore`)

---

<div align="center">

**For more information, see the main [README.md](../README.md)**

**Total Projects: 31 | Microcontroller Families: 5 | Technologies: 20+**

</div>

