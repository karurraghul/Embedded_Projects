# ðŸ”Œ Embedded Systems Projects

> A comprehensive collection of embedded systems projects organized by microcontroller family. This repository contains implementations for various peripherals, communication protocols, and sensor interfacing across multiple microcontroller platforms.

<div align="center">

<a href="#-8051-at89c51" title="Jump to 8051 family"><img src="https://img.shields.io/badge/8051-7%20Projects-red?style=for-the-badge" alt="8051"></a>
<a href="#-arm7-lpc2138" title="Jump to ARM7 family"><img src="https://img.shields.io/badge/ARM7-8%20Projects-blue?style=for-the-badge" alt="ARM7"></a>
<a href="#-avr" title="Jump to AVR projects"><img src="https://img.shields.io/badge/AVR-1%20Project-yellow?style=for-the-badge" alt="AVR"></a>
<a href="#-pic16" title="Jump to PIC16 family"><img src="https://img.shields.io/badge/PIC16-7%20Projects-purple?style=for-the-badge" alt="PIC16"></a>
<a href="#-pic18" title="Jump to PIC18 family"><img src="https://img.shields.io/badge/PIC18-8%20Projects-cyan?style=for-the-badge" alt="PIC18"></a>

</div>

<div align="center">

![Total Projects](https://img.shields.io/badge/Projects-31-blue?style=for-the-badge)
<a href="#-interactive-project-matrix" title="Jump to the project matrix"><img src="https://img.shields.io/badge/Jump%20to%20Matrix-lightgrey?style=for-the-badge" alt="Jump to matrix"></a>
<a href="#-featured-projects" title="Explore featured projects"><img src="https://img.shields.io/badge/Explore-Featured%20Projects-pink?style=for-the-badge" alt="Featured projects"></a>
<a href="PROJECTS.md" title="Open the project catalog"><img src="https://img.shields.io/badge/Project%20Catalog-green?style=for-the-badge" alt="Project catalog"></a>

</div>

<div align="center">

<img src="https://media.giphy.com/media/xUPGcguWZHRC2HyBRS/giphy.gif" alt="Simulation preview" width="320" title="Proteus simulation highlight">

</div>

<pre>
  ____  _   _  __  __  ____   _   _
 |  _ \| | | ||  \/  ||  _ \ / _| | |
 | |_) | | | || |\/| || |_) | |_  | |
 |  __/| |_| || |  | ||  _ <|  _| |_|
 |_|    \___/ |_|  |_||_| \_\_|(_)
</pre>

---

## ðŸ“‹ Table of Contents

- [Quick Navigation](#-quick-navigation)
- [Jump Links](#-jump-links)
- [Project Statistics](#-project-statistics)
- [Interactive Project Matrix](#-interactive-project-matrix)
- [Featured Projects](#-featured-projects)
- [Microcontroller Families](#-microcontroller-families)
- [Technology Stack](#-technology-stack)
- [Getting Started](#-getting-started)
- [Project Catalog](#-project-catalog)

---

## ðŸ§­ Jump Links

- [Jump to the matrix](#-interactive-project-matrix)
- [Jump to featured builds](#-featured-projects)
- [Jump to technology stack](#-technology-stack)
- [Browse the catalog](PROJECTS.md)
- [Jump to 8051](#-8051-at89c51)

---

## ðŸš€ Quick Navigation

| <a href="#-8051-at89c51" title="Scroll to 8051">8051</a> | <a href="#-arm7-lpc2138" title="Scroll to ARM7">ARM7</a> | <a href="#-avr" title="Scroll to AVR">AVR</a> | <a href="#-pic16" title="Scroll to PIC16">PIC16</a> | <a href="#-pic18" title="Scroll to PIC18">PIC18</a> |
|:---:|:---:|:---:|:---:|:---:|
| 7 Projects | 8 Projects | 1 Project | 7 Projects | 8 Projects |

---

## ðŸ“Š Project Statistics

<div align="center">

| Microcontroller Family | Projects | Technologies |
|:---|:---|:---|
| **8051 (AT89C51)** | 7 | ADC, LCD, 7-Segment, LED, Traffic Control |
| **ARM7 (LPC2138)** | 8 | ADC, CAN, I2C, PIR, RFID, Touch Sensor |
| **AVR** | 1 | LED Control |
| **PIC16** | 7 | 7-Segment, LED, PWM, Stepper Motor, DC Motor, Timer |
| **PIC18** | 8 | LCD, LED, SPI, I2C, SPI, ADC |
| **TOTAL** | **31** | **20+ Technologies** |

</div>

---

## ðŸŽ¯ Interactive Project Matrix

Dive into any card to open the corresponding folder.

<div align="center">

<img src="https://media.giphy.com/media/3oEjI6SIIHBdRxXI40/giphy.gif" alt="Embedded board preview" width="320" title="Embedded board simulation overview">

</div>

<details open>
<summary title="View 8051 project matrix"><strong>ðŸŽ¯ 8051 (AT89C51)</strong> â€¢ 7 Projects â€¢ Sensor + Display focus</summary>
<p>Classic 8051 demos covering ADC, LCD, and LEDs.</p>

| Project | Description | Technologies | Type |
|:---|:---|:---|:---|
| [ADC](8051/ADC/) | Analog-to-Digital Converter interfacing | <code title="Analog-to-Digital Converter">ADC</code><br><code title="C language">C</code> | Sensor |
| [ADC_A](8051/ADC_A/) | Alternative ADC implementation | <code title="Analog-to-Digital Converter">ADC</code><br><code title="C language">C</code> | Sensor |
| [ADC_POT](8051/ADC_POT/) | ADC with potentiometer input | <code title="Analog-to-Digital Converter">ADC</code><br><code title="Potentiometer">Potentiometer</code><br><code title="C language">C</code> | Sensor |
| [7-Segment Display](8051/7-Segement%20Display/) | 7-segment display driver | <code title="7-Segment Display">7-Segment</code><br><code title="Assembly">Assembly</code> | Display |
| [LCD_Interfacing](8051/LCD_Interfacing/) | LCD display interfacing | <code title="Liquid Crystal Display">LCD</code><br><code title="C language">C</code> | Display |
| [LED_BLINK](8051/LED_BLINK/) | Basic LED blinking | <code title="Light Emitting Diode">LED</code><br><code title="Assembly">Assembly</code> | Basic |
| [LED_TRAFFIC](8051/LED_TRAFFIC/) | Traffic light simulation | <code title="Light Emitting Diode">LED</code><br><code title="Traffic Control">Traffic Control</code><br><code title="Assembly">Assembly</code> | Application |
</details>

<details>
<summary title="View ARM7 project matrix"><strong>ðŸ’ª ARM7 (LPC2138)</strong> â€¢ 8 Projects â€¢ Communications + Sensors</summary>
<p>Advanced protocols, sensors, and communication stacks.</p>

| Project | Description | Technologies | Type |
|:---|:---|:---|:---|
| [ADC_ARM](ARM/ADC_ARM/) | ADC implementation for ARM | <code title="Analog-to-Digital Converter">ADC</code><br><code title="Liquid Crystal Display">LCD</code><br><code title="C language">C</code> | Sensor |
| [CAN_PROTOCOL](ARM/CAN_PROTOCOL/) | CAN bus communication protocol | <code title="Controller Area Network">CAN</code><br><code title="MCP2515 controller">MCP2515</code><br><code title="C language">C</code> | Communication |
| [CAN_WORKING](ARM/CAN_WORKING/) | Working CAN implementation | <code title="Controller Area Network">CAN</code><br><code title="C language">C</code> | Communication |
| [I2C_EEPROM_ARM7](ARM/I2C_EEPROM_ARM7/) | I2C EEPROM interfacing | <code title="Inter-Integrated Circuit">I2C</code><br><code title="EEPROM">EEPROM</code><br><code title="C language">C</code> | Communication |
| [I2C-Proj2](ARM/I2C-Proj2/) | I2C EEPROM (variant 2) | <code title="Inter-Integrated Circuit">I2C</code><br><code title="EEPROM">EEPROM</code><br><code title="C language">C</code> | Communication |
| [PIR_Sensor_ARM7](ARM/PIR_Sensor_ARM7/) | PIR motion sensor interfacing | <code title="Passive Infrared Sensor">PIR</code><br><code title="C language">C</code> | Sensor |
| [RFID_ARM](ARM/RFID_ARM/) | RFID reader interfacing | <code title="Radio-frequency identification">RFID</code><br><code title="Universal Asynchronous Receiver/Transmitter">UART</code><br><code title="Liquid Crystal Display">LCD</code><br><code title="C language">C</code> | Sensor |
| [TouchSensor](ARM/TouchSensor/) | Touch sensor implementation | <code title="Touch Sensor">Touch Sensor</code><br><code title="C language">C</code> | Sensor |
</details>

<details>
<summary title="View AVR project matrix"><strong>ðŸ”· AVR</strong> â€¢ 1 Project â€¢ LED focus</summary>
<p>AVR LED control is a quick GPIO showcase.</p>

| Project | Description | Technologies | Type |
|:---|:---|:---|:---|
| [AVR_LED](AVR/AVR/AVR_LED/) | LED control implementation | <code title="Light Emitting Diode">LED</code><br><code title="C language">C</code> | Basic |
</details>

<details>
<summary title="View PIC16 project matrix"><strong>ðŸŽ¯ PIC16</strong> â€¢ 7 Projects â€¢ Displays & Motors</summary>
<p>Multiplexed displays, PWM, and motor demos.</p>

| Project | Description | Technologies | Type |
|:---|:---|:---|:---|
| [7_SEGMENT](PIC16/PIC16/7%20SEGMENT/) | 7-segment display driver | <code title="7-Segment Display">7-Segment</code><br><code title="C language">C</code> | Display |
| [7seg_multiplex](PIC16/PIC16/7seg_multiplex/) | Multiplexed 7-segment display | <code title="7-Segment Display">7-Segment</code><br><code title="Multiplexing">Multiplexing</code><br><code title="C language">C</code> | Display |
| [LEDPIC](PIC16/PIC16/LEDPIC/) | LED control | <code title="Light Emitting Diode">LED</code><br><code title="C language">C</code> | Basic |
| [pwm](PIC16/PIC16/pwm/) | PWM signal generation | <code title="Pulse Width Modulation">PWM</code><br><code title="C language">C</code> | Control |
| [stepper_motor](PIC16/PIC16/stepper_motor/) | Stepper motor control | <code title="Stepper Motor">Stepper Motor</code><br><code title="C language">C</code> | Motor |
| [timer](PIC16/PIC16/timer/) | Timer implementation with interrupts | <code title="Timer">Timer</code><br><code title="Interrupt Service Routine">ISR</code><br><code title="C language">C</code> | Control |
| [unipolarDCMotor](PIC16/PIC16/unipolarDCMotor/) | DC motor control | <code title="DC Motor">DC Motor</code><br><code title="C language">C</code> | Motor |
</details>

<details>
<summary title="View PIC18 project matrix"><strong>ðŸš€ PIC18</strong> â€¢ 8 Projects â€¢ Communication-heavy</summary>
<p>PIC18 handles SPI, I2C, ADC, and LCD mixes.</p>

| Project | Description | Technologies | Type |
|:---|:---|:---|:---|
| [LCD_Display_8_bit](PIC18/PIC18/LCD_DIsplay_8_bit/) | 8-bit LCD interfacing | <code title="Liquid Crystal Display">LCD</code><br><code title="8-bit">8-bit</code><br><code title="C language">C</code> | Display |
| [LED_blink](PIC18/PIC18/) | LED blinking patterns | <code title="Light Emitting Diode">LED</code><br><code title="C language">C</code> | Basic |
| [LED_Pattern_blink](PIC18/PIC18/LED_Pattern_blink/) | Advanced LED patterns | <code title="Light Emitting Diode">LED</code><br><code title="Pattern">Patterns</code><br><code title="C language">C</code> | Basic |
| [NewPic18SPI](PIC18/PIC18/NewPic18SPI/) | SPI communication (SD card) | <code title="Serial Peripheral Interface">SPI</code><br><code title="Secure Digital">SD Card</code><br><code title="C language">C</code> | Communication |
| [PIC_18_LCD_REV](PIC18/PIC18/PIC_18_LCD_REV/) | LCD revision implementation | <code title="Liquid Crystal Display">LCD</code><br><code title="C language">C</code> | Display |
| [PIC18_I2C](PIC18/PIC18/PIC18_I2C/) | I2C communication | <code title="Inter-Integrated Circuit">I2C</code><br><code title="C language">C</code> | Communication |
| [PIC18SPI](PIC18/PIC18/PIC18SPI/) | SPI communication | <code title="Serial Peripheral Interface">SPI</code><br><code title="C language">C</code> | Communication |
| [PICADC](PIC18/PIC18/PICADC/) | ADC implementation | <code title="Analog-to-Digital Converter">ADC</code><br><code title="Liquid Crystal Display">LCD</code><br><code title="C language">C</code> | Sensor |
</details>

---

## â­ Featured Projects

<div style="margin: 0 auto; max-width: 900px;">

### ðŸ”¥ High Complexity Projects

| Project | Microcontroller | Key Features |
|:---|:---|:---|
| **CAN Protocol** | ARM7 | CAN bus communication with MCP2515 controller |
| **RFID Reader** | ARM7 | RFID interfacing with UART and LCD display |
| **SPI SD Card** | PIC18 | SPI communication for SD card interfacing |
| **I2C EEPROM** | ARM7 | I2C protocol for EEPROM read/write operations |

### ðŸŽ¨ Display Projects

| Project | Microcontroller | Description |
|:---|:---|:---|
| **LCD Interfacing** | 8051 | LCD display driver implementation |
| **7-Segment Multiplex** | PIC16 | Multiplexed 7-segment display control |
| **LCD 8-bit** | PIC18 | 8-bit parallel LCD interface |

### âš™ï¸ Motor Control Projects

| Project | Microcontroller | Description |
|:---|:---|:---|
| **Stepper Motor** | PIC16 | Stepper motor control |
| **DC Motor Control** | PIC16 | Unipolar DC motor control |
| **PWM Generation** | PIC16 | PWM signal generation for motor control |

</div>

---

## ðŸ—ï¸ Microcontroller Families

<details>
<summary><b>ðŸ“± 8051 (AT89C51)</b> - 7 Projects | Click to expand</summary>

### Overview
The 8051 microcontroller family projects using AT89C51. These projects demonstrate basic to intermediate embedded programming concepts.

**IDE:** Keil uVision  \
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
<summary><b>ðŸ’ª ARM7 (LPC2138)</b> - 8 Projects | Click to expand</summary>

### Overview
ARM7TDMI architecture projects using LPC2138 microcontroller. Advanced projects featuring communication protocols and sensor interfacing.

**IDE:** Keil uVision  \
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
<summary><b>ðŸ”· AVR</b> - 1 Project | Click to expand</summary>

### Overview
AVR microcontroller projects demonstrating embedded programming.

**IDE:** Atmel Studio  \
**Simulation:** Proteus Design Suite

### Projects
- **AVR_LED** - LED control implementation

</details>

<details>
<summary><b>ðŸŽ¯ PIC16</b> - 7 Projects | Click to expand</summary>

### Overview
PIC16 family microcontroller projects covering displays, motors, and control systems.

**IDE:** MPLAB  \
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
<summary><b>ðŸš€ PIC18</b> - 8 Projects | Click to expand</summary>

### Overview
PIC18 family microcontroller projects featuring advanced communication protocols and display interfacing.

**IDE:** MPLAB  \
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

## ðŸ› ï¸ Technology Stack

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

> Note: Hover over each badge to learn which protocols power the matrix above.

---

## ðŸš€ Getting Started

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

> Tip: Keep this README open while browsing the matrixâ€”jump links keep you oriented.

---

## ðŸ“š Project Catalog

For detailed information about each project, including descriptions, technologies, and file structures, see the **[PROJECTS.md](PROJECTS.md)** file.

---

## ðŸ“ Repository Structure

```
Embedded_Projects/
â”œâ”€â”€ 8051/              # AT89C51 (MCS-51) projects
â”‚   â”œâ”€â”€ ADC/
â”‚   â”œâ”€â”€ ADC_A/
â”‚   â”œâ”€â”€ ADC_POT/
â”‚   â”œâ”€â”€ 7-Segement Display/
â”‚   â”œâ”€â”€ LCD_Interfacing/
â”‚   â”œâ”€â”€ LED_BLINK/
â”‚   â””â”€â”€ LED_TRAFFIC/
â”œâ”€â”€ ARM/               # ARM7 (LPC2138) projects
â”‚   â”œâ”€â”€ ADC_ARM/
â”‚   â”œâ”€â”€ CAN_PROTOCOL/
â”‚   â”œâ”€â”€ CAN_WORKING/
â”‚   â”œâ”€â”€ I2C_EEPROM_ARM7/
â”‚   â”œâ”€â”€ I2C-Proj2/
â”‚   â”œâ”€â”€ PIR_Sensor_ARM7/
â”‚   â”œâ”€â”€ RFID_ARM/
â”‚   â””â”€â”€ TouchSensor/
â”œâ”€â”€ AVR/               # AVR microcontroller projects
â”‚   â””â”€â”€ AVR/AVR_LED/
â”œâ”€â”€ PIC16/             # PIC16 family projects
â”‚   â””â”€â”€ PIC16/
â”‚       â”œâ”€â”€ 7 SEGMENT/
â”‚       â”œâ”€â”€ 7seg_multiplex/
â”‚       â”œâ”€â”€ LEDPIC/
â”‚       â”œâ”€â”€ pwm/
â”‚       â”œâ”€â”€ stepper_motor/
â”‚       â”œâ”€â”€ timer/
â”‚       â””â”€â”€ unipolarDCMotor/
â””â”€â”€ PIC18/             # PIC18 family projects
    â””â”€â”€ PIC18/
        â”œâ”€â”€ LCD_DIsplay_8_bit/
        â”œâ”€â”€ LED_Pattern_blink/
        â”œâ”€â”€ NewPic18SPI/
        â”œâ”€â”€ PIC_18_LCD_REV/
        â”œâ”€â”€ PIC18_I2C/
        â”œâ”€â”€ PIC18SPI/
        â””â”€â”€ PICADC/
```

---

## ðŸ“ Project Files

Each project typically contains:
- **Source files** (`.c`, `.asm`, `.s`, `.h`) - Main source code
- **Project files** (`.uvproj`, `.mcp`, `.cproj`) - IDE project configuration
- **Simulation files** (`.pdsprj`) - Proteus simulation schematics
- **Startup files** (`STARTUP.A51`, `Startup.s`) - Microcontroller initialization code

---

## ðŸš« Excluded Files

The following files are excluded from this repository:
- Build outputs: `.hex`, `.obj`, `.axf`, `.cof`, `.o`, `.elf`, etc.
- Build directories: `Objects/`, `Listings/`, `Debug/`
- User-specific files: `.uvgui.*`, `.workspace`, `.bak`, `.pdsbak`
- Intermediate files: `.dep`, `.crf`, `.d`, `.lnp`, etc.

---

## ðŸ“Œ Notes

- All simulation files (`.pdsprj`) are preserved as they are essential for understanding and testing projects
- Project files are included so projects can be opened directly in their respective IDEs
- Source code is organized by microcontroller family for easy navigation
- Each project is self-contained with its necessary files

---

## ðŸ¤ Contributing

When adding new projects:
1. Place them in the appropriate microcontroller family folder
2. Include source files, project files, and simulation files
3. Exclude build artifacts and user-specific files
4. Update this README if adding new project categories

---

## ðŸ“„ License

This repository contains educational embedded systems projects. Use as reference for learning embedded systems programming.

---

<div align="center">

**â­ Star this repository if you find it helpful!**

Made with â¤ï¸ for embedded systems enthusiasts

</div>
