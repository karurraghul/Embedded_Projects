# 🔌 Embedded Systems Projects

> A comprehensive collection of embedded systems projects organized by microcontroller family. This repository contains implementations for various peripherals, communication protocols, and sensor interfacing across multiple microcontroller platforms.

<div align="center">

![Total Projects](https://img.shields.io/badge/Projects-31-blue?style=for-the-badge)
![Microcontrollers](https://img.shields.io/badge/Microcontrollers-5-green?style=for-the-badge)
![Languages](https://img.shields.io/badge/Languages-C%20%7C%20Assembly-orange?style=for-the-badge)

[![8051](https://img.shields.io/badge/8051-7%20Projects-red)](8051/)
[![ARM](https://img.shields.io/badge/ARM7-8%20Projects-blue)](ARM/)
[![AVR](https://img.shields.io/badge/AVR-1%20Project-yellow)](AVR/)
[![PIC16](https://img.shields.io/badge/PIC16-7%20Projects-purple)](PIC16/)
[![PIC18](https://img.shields.io/badge/PIC18-8%20Projects-cyan)](PIC18/)

</div>

---

## 📋 Table of Contents

- [Quick Navigation](#-quick-navigation)
- [Project Statistics](#-project-statistics)
- [Interactive Project Matrix](#-interactive-project-matrix)
- [Featured Projects](#-featured-projects)
- [Microcontroller Families](#-microcontroller-families)
- [Technology Stack](#-technology-stack)
- [Getting Started](#-getting-started)
- [Project Catalog](#-project-catalog)

---

## 🚀 Quick Navigation

| [8051](#-8051-at89c51) | [ARM7](#-arm7-lpc2138) | [AVR](#-avr) | [PIC16](#-pic16) | [PIC18](#-pic18) |
|:---:|:---:|:---:|:---:|:---:|
| 7 Projects | 8 Projects | 1 Project | 7 Projects | 8 Projects |

---

## 📊 Project Statistics

<div align="center">

| Microcontroller Family | Projects | Technologies |
|:---|:---:|:---|
| **8051 (AT89C51)** | 7 | ADC, LCD, 7-Segment, LED, Traffic Control |
| **ARM7 (LPC2138)** | 8 | ADC, CAN, I2C, PIR, RFID, Touch Sensor |
| **AVR** | 1 | LED Control |
| **PIC16** | 7 | 7-Segment, LED, PWM, Stepper Motor, DC Motor, Timer |
| **PIC18** | 8 | LCD, LED, SPI, I2C, SPI, ADC |
| **TOTAL** | **31** | **20+ Technologies** |

</div>

---

## 🎯 Interactive Project Matrix

Click on any project name to navigate to its directory.

### 8051 (AT89C51) Projects

| Project | Description | Technologies | Type |
|:---|:---|:---|:---|
| [ADC](8051/ADC/) | Analog-to-Digital Converter interfacing | `ADC` `C` | Sensor |
| [ADC_A](8051/ADC_A/) | Alternative ADC implementation | `ADC` `C` | Sensor |
| [ADC_POT](8051/ADC_POT/) | ADC with potentiometer input | `ADC` `Potentiometer` `C` | Sensor |
| [7-Segment Display](8051/7-Segement%20Display/) | 7-segment display driver | `7-Segment` `Assembly` | Display |
| [LCD_Interfacing](8051/LCD_Interfacing/) | LCD display interfacing | `LCD` `C` | Display |
| [LED_BLINK](8051/LED_BLINK/) | Basic LED blinking | `LED` `Assembly` | Basic |
| [LED_TRAFFIC](8051/LED_TRAFFIC/) | Traffic light simulation | `LED` `Traffic Control` `Assembly` | Application |

### ARM7 (LPC2138) Projects

| Project | Description | Technologies | Type |
|:---|:---|:---|:---|
| [ADC_ARM](ARM/ADC_ARM/) | ADC implementation for ARM | `ADC` `LCD` `C` | Sensor |
| [CAN_PROTOCOL](ARM/CAN_PROTOCOL/) | CAN bus communication protocol | `CAN` `MCP2515` `C` | Communication |
| [CAN_WORKING](ARM/CAN_WORKING/) | Working CAN implementation | `CAN` `C` | Communication |
| [I2C_EEPROM_ARM7](ARM/I2C_EEPROM_ARM7/) | I2C EEPROM interfacing | `I2C` `EEPROM` `C` | Communication |
| [I2C-Proj2](ARM/I2C-Proj2/) | I2C EEPROM (variant 2) | `I2C` `EEPROM` `C` | Communication |
| [PIR_Sensor_ARM7](ARM/PIR_Sensor_ARM7/) | PIR motion sensor interfacing | `PIR` `Motion Sensor` `C` | Sensor |
| [RFID_ARM](ARM/RFID_ARM/) | RFID reader interfacing | `RFID` `UART` `LCD` `C` | Sensor |
| [TouchSensor](ARM/TouchSensor/) | Touch sensor implementation | `Touch Sensor` `C` | Sensor |

### AVR Projects

| Project | Description | Technologies | Type |
|:---|:---|:---|:---|
| [AVR_LED](AVR/AVR/AVR_LED/) | LED control implementation | `LED` `C` | Basic |

### PIC16 Projects

| Project | Description | Technologies | Type |
|:---|:---|:---|:---|
| [7_SEGMENT](PIC16/PIC16/7%20SEGMENT/) | 7-segment display driver | `7-Segment` `C` | Display |
| [7seg_multiplex](PIC16/PIC16/7seg_multiplex/) | Multiplexed 7-segment display | `7-Segment` `Multiplexing` `C` | Display |
| [LEDPIC](PIC16/PIC16/LEDPIC/) | LED control | `LED` `C` | Basic |
| [pwm](PIC16/PIC16/pwm/) | PWM signal generation | `PWM` `C` | Control |
| [stepper_motor](PIC16/PIC16/stepper_motor/) | Stepper motor control | `Stepper Motor` `C` | Motor |
| [timer](PIC16/PIC16/timer/) | Timer implementation with interrupts | `Timer` `ISR` `C` | Control |
| [unipolarDCMotor](PIC16/PIC16/unipolarDCMotor/) | DC motor control | `DC Motor` `C` | Motor |

### PIC18 Projects

| Project | Description | Technologies | Type |
|:---|:---|:---|:---|
| [LCD_Display_8_bit](PIC18/PIC18/LCD_DIsplay_8_bit/) | 8-bit LCD interfacing | `LCD` `8-bit` `C` | Display |
| [LED_blink](PIC18/PIC18/) | LED blinking patterns | `LED` `C` | Basic |
| [LED_Pattern_blink](PIC18/PIC18/LED_Pattern_blink/) | Advanced LED patterns | `LED` `Patterns` `C` | Basic |
| [NewPic18SPI](PIC18/PIC18/NewPic18SPI/) | SPI communication (SD card) | `SPI` `SD Card` `C` | Communication |
| [PIC_18_LCD_REV](PIC18/PIC18/PIC_18_LCD_REV/) | LCD revision implementation | `LCD` `C` | Display |
| [PIC18_I2C](PIC18/PIC18/PIC18_I2C/) | I2C communication | `I2C` `C` | Communication |
| [PIC18SPI](PIC18/PIC18/PIC18SPI/) | SPI communication | `SPI` `C` | Communication |
| [PICADC](PIC18/PIC18/PICADC/) | ADC implementation | `ADC` `LCD` `C` | Sensor |

---

## ⭐ Featured Projects

<div align="center">

### 🔥 High Complexity Projects

| Project | Microcontroller | Key Features |
|:---|:---|:---|
| **CAN Protocol** | ARM7 | CAN bus communication with MCP2515 controller |
| **RFID Reader** | ARM7 | RFID interfacing with UART and LCD display |
| **SPI SD Card** | PIC18 | SPI communication for SD card interfacing |
| **I2C EEPROM** | ARM7 | I2C protocol for EEPROM read/write operations |

### 🎨 Display Projects

| Project | Microcontroller | Description |
|:---|:---|:---|
| **LCD Interfacing** | 8051 | LCD display driver implementation |
| **7-Segment Multiplex** | PIC16 | Multiplexed 7-segment display control |
| **LCD 8-bit** | PIC18 | 8-bit parallel LCD interface |

### ⚙️ Motor Control Projects

| Project | Microcontroller | Description |
|:---|:---|:---|
| **Stepper Motor** | PIC16 | Stepper motor control |
| **DC Motor Control** | PIC16 | Unipolar DC motor control |
| **PWM Generation** | PIC16 | PWM signal generation for motor control |

</div>

---

## 🏗️ Microcontroller Families

<details>
<summary><b>📱 8051 (AT89C51)</b> - 7 Projects | Click to expand</summary>

### Overview
The 8051 microcontroller family projects using AT89C51. These projects demonstrate basic to intermediate embedded programming concepts.

**IDE:** Keil uVision  
**Simulation:** Proteus Design Suite

### Projects
- **ADC** - Analog-to-Digital Converter interfacing
- **ADC_A** - Alternative ADC implementation
- **ADC_POT** - ADC with potentiometer input
- **7-Segment Display** - 7-segment display driver
- **LCD_Interfacing** - LCD display interfacing
- **LED_BLINK** - Basic LED blinking
- **LED_TRAFFIC** - Traffic light simulation

</details>

<details>
<summary><b>💪 ARM7 (LPC2138)</b> - 8 Projects | Click to expand</summary>

### Overview
ARM7TDMI architecture projects using LPC2138 microcontroller. Advanced projects featuring communication protocols and sensor interfacing.

**IDE:** Keil uVision  
**Simulation:** Proteus Design Suite

### Projects
- **ADC_ARM** - ADC implementation for ARM
- **CAN_PROTOCOL** - CAN bus communication protocol
- **CAN_WORKING** - Working CAN implementation
- **I2C_EEPROM** - I2C EEPROM interfacing (2 variants)
- **PIR_Sensor** - PIR motion sensor interfacing
- **RFID** - RFID reader interfacing
- **TouchSensor** - Touch sensor implementation

</details>

<details>
<summary><b>🔷 AVR</b> - 1 Project | Click to expand</summary>

### Overview
AVR microcontroller projects demonstrating embedded programming.

**IDE:** Atmel Studio  
**Simulation:** Proteus Design Suite

### Projects
- **AVR_LED** - LED control implementation

</details>

<details>
<summary><b>🎯 PIC16</b> - 7 Projects | Click to expand</summary>

### Overview
PIC16 family microcontroller projects covering displays, motors, and control systems.

**IDE:** MPLAB  
**Simulation:** Proteus Design Suite

### Projects
- **7_SEGMENT** - 7-segment display driver
- **7seg_multiplex** - Multiplexed 7-segment display
- **LEDPIC** - LED control
- **pwm** - PWM signal generation
- **stepper_motor** - Stepper motor control
- **timer** - Timer implementation with interrupts
- **unipolarDCMotor** - DC motor control

</details>

<details>
<summary><b>🚀 PIC18</b> - 8 Projects | Click to expand</summary>

### Overview
PIC18 family microcontroller projects featuring advanced communication protocols and display interfacing.

**IDE:** MPLAB  
**Simulation:** Proteus Design Suite

### Projects
- **LCD_Display_8_bit** - 8-bit LCD interfacing
- **LED_blink** - LED blinking patterns
- **LED_Pattern_blink** - Advanced LED patterns
- **NewPic18SPI** - SPI communication (SD card)
- **PIC_18_LCD_REV** - LCD revision implementation
- **PIC18_I2C** - I2C communication
- **PIC18SPI** - SPI communication
- **PICADC** - ADC implementation

</details>

---

## 🛠️ Technology Stack

### Communication Protocols
![I2C](https://img.shields.io/badge/I2C-Protocol-blue)
![SPI](https://img.shields.io/badge/SPI-Protocol-green)
![CAN](https://img.shields.io/badge/CAN-Protocol-red)
![UART](https://img.shields.io/badge/UART-Protocol-orange)

### Sensors & Peripherals
![ADC](https://img.shields.io/badge/ADC-Sensor-yellow)
![PIR](https://img.shields.io/badge/PIR-Sensor-purple)
![RFID](https://img.shields.io/badge/RFID-Sensor-cyan)
![Touch](https://img.shields.io/badge/Touch-Sensor-pink)

### Displays
![LCD](https://img.shields.io/badge/LCD-Display-blue)
![7-Segment](https://img.shields.io/badge/7--Segment-Display-green)

### Actuators
![Stepper Motor](https://img.shields.io/badge/Stepper%20Motor-Actuator-red)
![DC Motor](https://img.shields.io/badge/DC%20Motor-Actuator-orange)
![PWM](https://img.shields.io/badge/PWM-Control-yellow)

### Development Tools
- **Keil uVision** - For 8051 and ARM projects
- **MPLAB** - For PIC16 and PIC18 projects
- **Atmel Studio** - For AVR projects
- **Proteus Design Suite** - For simulation

---

## 🚀 Getting Started

### Prerequisites

#### Software Tools
- **Keil uVision** - For 8051 and ARM projects
- **MPLAB** - For PIC16 and PIC18 projects
- **Atmel Studio** - For AVR projects
- **Proteus Design Suite** - For simulation (.pdsprj files)

#### Hardware
- Various development boards and microcontrollers as specified in each project
- Peripherals: LCDs, sensors, motors, displays, etc.

### Quick Start

1. **Choose a Project**
   - Browse the [Interactive Project Matrix](#-interactive-project-matrix) above
   - Select a project based on your microcontroller and interest

2. **Open Project**
   - **8051/ARM:** Open `.uvproj` files in Keil uVision
   - **PIC16/PIC18:** Open `.mcp` files in MPLAB
   - **AVR:** Open `.cproj` or `.atsln` files in Atmel Studio

3. **Simulate**
   - Open `.pdsprj` files in Proteus Design Suite
   - Load the compiled `.hex` file into the microcontroller in the simulation

4. **Build**
   - Build the project in the respective IDE
   - The output `.hex` file can be used for programming or simulation

---

## 📚 Project Catalog

For detailed information about each project, including descriptions, technologies, and file structures, see the **[PROJECTS.md](PROJECTS.md)** file.

---

## 📁 Repository Structure

```
Embedded_Projects/
├── 8051/              # AT89C51 (MCS-51) projects
│   ├── ADC/
│   ├── ADC_A/
│   ├── ADC_POT/
│   ├── 7-Segement Display/
│   ├── LCD_Interfacing/
│   ├── LED_BLINK/
│   └── LED_TRAFFIC/
├── ARM/               # ARM7 (LPC2138) projects
│   ├── ADC_ARM/
│   ├── CAN_PROTOCOL/
│   ├── CAN_WORKING/
│   ├── I2C_EEPROM_ARM7/
│   ├── I2C-Proj2/
│   ├── PIR_Sensor_ARM7/
│   ├── RFID_ARM/
│   └── TouchSensor/
├── AVR/               # AVR microcontroller projects
│   └── AVR/AVR_LED/
├── PIC16/             # PIC16 family projects
│   └── PIC16/
│       ├── 7 SEGMENT/
│       ├── 7seg_multiplex/
│       ├── LEDPIC/
│       ├── pwm/
│       ├── stepper_motor/
│       ├── timer/
│       └── unipolarDCMotor/
└── PIC18/             # PIC18 family projects
    └── PIC18/
        ├── LCD_DIsplay_8_bit/
        ├── LED_Pattern_blink/
        ├── NewPic18SPI/
        ├── PIC_18_LCD_REV/
        ├── PIC18_I2C/
        ├── PIC18SPI/
        └── PICADC/
```

---

## 📝 Project Files

Each project typically contains:
- **Source files** (`.c`, `.asm`, `.s`, `.h`) - Main source code
- **Project files** (`.uvproj`, `.mcp`, `.cproj`) - IDE project configuration
- **Simulation files** (`.pdsprj`) - Proteus simulation schematics
- **Startup files** (`STARTUP.A51`, `Startup.s`) - Microcontroller initialization code

---

## 🚫 Excluded Files

The following files are excluded from this repository:
- Build outputs: `.hex`, `.obj`, `.axf`, `.cof`, `.o`, `.elf`, etc.
- Build directories: `Objects/`, `Listings/`, `Debug/`
- User-specific files: `.uvgui.*`, `.workspace`, `.bak`, `.pdsbak`
- Intermediate files: `.dep`, `.crf`, `.d`, `.lnp`, etc.

---

## 📌 Notes

- All simulation files (`.pdsprj`) are preserved as they are essential for understanding and testing projects
- Project files are included so projects can be opened directly in their respective IDEs
- Source code is organized by microcontroller family for easy navigation
- Each project is self-contained with its necessary files

---

## 🤝 Contributing

When adding new projects:
1. Place them in the appropriate microcontroller family folder
2. Include source files, project files, and simulation files
3. Exclude build artifacts and user-specific files
4. Update this README if adding new project categories

---

## 📄 License

This repository contains educational embedded systems projects. Use as reference for learning embedded systems programming.

---

<div align="center">

**⭐ Star this repository if you find it helpful!**

Made with ❤️ for embedded systems enthusiasts

</div>
