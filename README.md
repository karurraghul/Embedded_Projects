# Embedded Systems Projects

A curated collection of embedded systems projects organized by microcontroller family (8051, ARM7, AVR, PIC16, PIC18). Each project includes source code, IDE project files, and (where applicable) Proteus simulation files.

<div align="center">
  <img src="https://raw.githubusercontent.com/tabler/tabler-icons/master/icons/svg/cpu.svg" width="44" height="44" alt="CPU" title="Microcontrollers" />
  <img src="https://raw.githubusercontent.com/tabler/tabler-icons/master/icons/svg/circuit-board.svg" width="44" height="44" alt="Circuit board" title="Peripherals + protocols" />
  <img src="https://raw.githubusercontent.com/tabler/tabler-icons/master/icons/svg/terminal-2.svg" width="44" height="44" alt="Code" title="C + Assembly" />
</div>

<div align="center">

<a href="#project-matrix" title="Browse projects by microcontroller family">
  <img src="https://img.shields.io/badge/Explore-Project_Matrix-0ea5e9?style=for-the-badge" alt="Explore Project Matrix" />
</a>
<a href="#featured" title="Jump to highlighted projects">
  <img src="https://img.shields.io/badge/See-Featured_Projects-f472b6?style=for-the-badge" alt="See Featured Projects" />
</a>
<a href="PROJECTS.md" title="Open the detailed catalog">
  <img src="https://img.shields.io/badge/Open-Project_Catalog-22c55e?style=for-the-badge" alt="Open Project Catalog" />
</a>

</div>

<div align="center">

<img src="https://img.shields.io/badge/Projects-31-2563eb?style=for-the-badge" alt="Projects: 31" title="Total projects" />
<img src="https://img.shields.io/badge/Microcontroller_Families-5-16a34a?style=for-the-badge" alt="Families: 5" title="8051, ARM7, AVR, PIC16, PIC18" />
<img src="https://img.shields.io/badge/Languages-C_|_Assembly-f59e0b?style=for-the-badge" alt="Languages" title="C and Assembly" />

</div>

---

## Table of contents

- [How to use this README](#how-to-use)
- [Quick navigation](#quick-nav)
- [Project statistics](#stats)
- [Project matrix](#project-matrix)
- [Featured projects](#featured)
- [Microcontroller families](#families)
- [Technology stack](#tech)
- [Getting started](#getting-started)

---

<a id="how-to-use"></a>
## How to use this README

- Open **Project matrix** and expand a microcontroller family.
- Hover over tech tags (tooltips) to learn acronyms.
- Use **Featured projects** if you want the "best hits" first.
- Use `PROJECTS.md` for deeper per-project detail.

---

<a id="quick-nav"></a>
## Quick navigation

<div align="center">

<a href="#family-8051" title="Jump to 8051">
  <img src="https://img.shields.io/badge/8051-7_projects-ef4444?style=for-the-badge" alt="8051" />
</a>
<a href="#family-arm7" title="Jump to ARM7">
  <img src="https://img.shields.io/badge/ARM7-8_projects-3b82f6?style=for-the-badge" alt="ARM7" />
</a>
<a href="#family-avr" title="Jump to AVR">
  <img src="https://img.shields.io/badge/AVR-1_project-facc15?style=for-the-badge" alt="AVR" />
</a>
<a href="#family-pic16" title="Jump to PIC16">
  <img src="https://img.shields.io/badge/PIC16-7_projects-a855f7?style=for-the-badge" alt="PIC16" />
</a>
<a href="#family-pic18" title="Jump to PIC18">
  <img src="https://img.shields.io/badge/PIC18-8_projects-06b6d4?style=for-the-badge" alt="PIC18" />
</a>

</div>

---

<a id="stats"></a>
## Project statistics

| Family | Projects | Highlights |
|:--|--:|:--|
| **8051 (AT89C51)** | 7 | ADC, LCD, 7-seg, LEDs, traffic sequencing |
| **ARM7 (LPC2138)** | 8 | CAN, I2C EEPROM, RFID, PIR, ADC+LCD |
| **AVR** | 1 | LED control |
| **PIC16** | 7 | 7-seg, PWM, timers/ISRs, stepper/DC motor |
| **PIC18** | 8 | SPI, I2C, ADC, LCD, LED patterns |

---

<a id="project-matrix"></a>
## Project matrix (click-to-open)

Tip: Expand only the family you care about. Each row links straight into the project folder.

<details open>
<summary><img src="https://raw.githubusercontent.com/simple-icons/simple-icons/develop/icons/microchiptechnology.svg" width="14" height="14" alt="Microchip" title="Microchip Technology" /> <strong>8051 (AT89C51)</strong> - 7 projects - ADC/LCD/LED fundamentals</summary>

| Project | What it demonstrates | Key tech |
|:--|:--|:--|
| [ADC](8051/ADC/) | ADC read + basic processing | <a href="PROJECTS.md#t-adc" title="See ADC in Technology index"><code title="Analog-to-Digital Converter">ADC</code></a> <code title="C language">C</code> |
| [ADC_A](8051/ADC_A/) | ADC variant implementation | <a href="PROJECTS.md#t-adc" title="See ADC in Technology index"><code title="Analog-to-Digital Converter">ADC</code></a> <code title="C language">C</code> |
| [ADC_POT](8051/ADC_POT/) | ADC with potentiometer input | <a href="PROJECTS.md#t-adc" title="See ADC in Technology index"><code title="Analog-to-Digital Converter">ADC</code></a> <code title="Potentiometer input">POT</code> <code title="C language">C</code> |
| [7-Segement Display](8051/7-Segement%20Display/) | 7-seg display driving | <code title="7-segment display">7SEG</code> <code title="Assembly language">ASM</code> |
| [LCD_Interfacing](8051/LCD_Interfacing/) | Character LCD control | <code title="Liquid Crystal Display">LCD</code> <code title="C language">C</code> |
| [LED_BLINK](8051/LED_BLINK/) | GPIO blink basics | <code title="Light Emitting Diode">LED</code> <code title="Assembly language">ASM</code> |
| [LED_TRAFFIC](8051/LED_TRAFFIC/) | Sequencing/state logic | <code title="State machine">FSM</code> <code title="Assembly language">ASM</code> |

</details>

<details>
<summary><img src="https://raw.githubusercontent.com/simple-icons/simple-icons/develop/icons/arm.svg" width="14" height="14" alt="ARM" title="ARM" /> <strong>ARM7 (LPC2138)</strong> - 8 projects - protocols + sensors</summary>

| Project | What it demonstrates | Key tech |
|:--|:--|:--|
| [ADC_ARM](ARM/ADC_ARM/) | ADC + LCD output | <a href="PROJECTS.md#t-adc" title="See ADC in Technology index"><code title="Analog-to-Digital Converter">ADC</code></a> <code title="Liquid Crystal Display">LCD</code> |
| [CAN_PROTOCOL](ARM/CAN_PROTOCOL/) | CAN with external controller | <a href="PROJECTS.md#t-can" title="See CAN in Technology index"><code title="Controller Area Network">CAN</code></a> <code title="MCP2515 CAN controller">MCP2515</code> |
| [CAN_WORKING](ARM/CAN_WORKING/) | CAN working baseline | <a href="PROJECTS.md#t-can" title="See CAN in Technology index"><code title="Controller Area Network">CAN</code></a> |
| [I2C_EEPROM_ARM7](ARM/I2C_EEPROM_ARM7/) | I2C EEPROM read/write | <a href="PROJECTS.md#t-i2c" title="See I2C in Technology index"><code title="Inter-Integrated Circuit">I2C</code></a> <code title="Electrically Erasable Programmable Read-Only Memory">EEPROM</code> |
| [I2C-Proj2](ARM/I2C-Proj2/) | I2C variant 2 | <a href="PROJECTS.md#t-i2c" title="See I2C in Technology index"><code title="Inter-Integrated Circuit">I2C</code></a> |
| [PIR_Sensor_ARM7](ARM/PIR_Sensor_ARM7/) | Motion sensing | <code title="Passive Infrared Sensor">PIR</code> |
| [RFID_ARM](ARM/RFID_ARM/) | RFID + UART + LCD | <code title="Radio-frequency identification">RFID</code> <a href="PROJECTS.md#t-uart" title="See UART in Technology index"><code title="UART serial">UART</code></a> <code title="Liquid Crystal Display">LCD</code> |
| [TouchSensor](ARM/TouchSensor/) | Touch sensing | <code title="Touch sensor input">TOUCH</code> |

</details>

<details>
<summary><img src="https://raw.githubusercontent.com/simple-icons/simple-icons/develop/icons/atmel.svg" width="14" height="14" alt="Atmel" title="Atmel (AVR ecosystem)" /> <strong>AVR</strong> - 1 project - GPIO baseline</summary>

| Project | What it demonstrates | Key tech |
|:--|:--|:--|
| [AVR_LED](AVR/AVR/AVR_LED/) | LED control | <code title="Light Emitting Diode">LED</code> <code title="C language">C</code> |

</details>

<details>
<summary><img src="https://raw.githubusercontent.com/simple-icons/simple-icons/develop/icons/microchiptechnology.svg" width="14" height="14" alt="Microchip" title="Microchip Technology" /> <strong>PIC16</strong> - 7 projects - displays + PWM + motors</summary>

| Project | What it demonstrates | Key tech |
|:--|:--|:--|
| [7 SEGMENT](PIC16/PIC16/7%20SEGMENT/) | 7-seg display | <code title="7-segment display">7SEG</code> |
| [7seg_multiplex](PIC16/PIC16/7seg_multiplex/) | Multiplexing | <code title="Multiplexing">MUX</code> |
| [LEDPIC](PIC16/PIC16/LEDPIC/) | LED control | <code title="Light Emitting Diode">LED</code> |
| [pwm](PIC16/PIC16/pwm/) | PWM generation | <code title="Pulse Width Modulation">PWM</code> |
| [stepper_motor](PIC16/PIC16/stepper_motor/) | Stepper sequencing | <code title="Stepper motor control">STEPPER</code> |
| [timer](PIC16/PIC16/timer/) | Timers + ISRs | <code title="Interrupt Service Routine">ISR</code> <code title="Timer peripheral">TIMER</code> |
| [unipolarDCMotor](PIC16/PIC16/unipolarDCMotor/) | DC motor drive | <code title="Direct Current motor">DC</code> |

</details>

<details>
<summary><img src="https://raw.githubusercontent.com/simple-icons/simple-icons/develop/icons/microchiptechnology.svg" width="14" height="14" alt="Microchip" title="Microchip Technology" /> <strong>PIC18</strong> - 8 projects - SPI/I2C + LCD/ADC</summary>

| Project | What it demonstrates | Key tech |
|:--|:--|:--|
| [LCD_DIsplay_8_bit](PIC18/PIC18/LCD_DIsplay_8_bit/) | 8-bit LCD interface | <code title="Liquid Crystal Display">LCD</code> <code title="8-bit parallel bus">8BIT</code> |
| [LED_blink](PIC18/PIC18/) | LED blink patterns | <code title="Light Emitting Diode">LED</code> |
| [LED_Pattern_blink](PIC18/PIC18/LED_Pattern_blink/) | Advanced patterns | <code title="Pattern generation">PATTERN</code> |
| [NewPic18SPI](PIC18/PIC18/NewPic18SPI/) | SPI + SD card | <a href="PROJECTS.md#t-spi" title="See SPI in Technology index"><code title="Serial Peripheral Interface">SPI</code></a> <code title="Secure Digital">SD</code> |
| [PIC_18_LCD_REV](PIC18/PIC18/PIC_18_LCD_REV/) | LCD driver variant | <code title="Liquid Crystal Display">LCD</code> |
| [PIC18_I2C](PIC18/PIC18/PIC18_I2C/) | I2C comms | <a href="PROJECTS.md#t-i2c" title="See I2C in Technology index"><code title="Inter-Integrated Circuit">I2C</code></a> |
| [PIC18SPI](PIC18/PIC18/PIC18SPI/) | SPI comms | <a href="PROJECTS.md#t-spi" title="See SPI in Technology index"><code title="Serial Peripheral Interface">SPI</code></a> |
| [PICADC](PIC18/PIC18/PICADC/) | ADC + LCD | <a href="PROJECTS.md#t-adc" title="See ADC in Technology index"><code title="Analog-to-Digital Converter">ADC</code></a> <code title="Liquid Crystal Display">LCD</code> |

</details>

---

<a id="featured"></a>
## Featured projects (fast portfolio scan)

| Category | Project | Why it matters | Open |
|:--|:--|:--|:--|
| Protocols | CAN Protocol (ARM7) | Real-world CAN framing + MCP2515 driver | [folder](ARM/CAN_PROTOCOL/) |
| Protocols | I2C EEPROM (ARM7) | Clean I2C transactions + EEPROM ops | [folder](ARM/I2C_EEPROM_ARM7/) |
| Sensors | RFID (ARM7) | UART + RFID parsing + LCD output | [folder](ARM/RFID_ARM/) |
| Storage | SPI SD Card (PIC18) | SPI stack + SD communication | [folder](PIC18/PIC18/NewPic18SPI/) |
| Motors | Stepper Motor (PIC16) | Sequencing + timing | [folder](PIC16/PIC16/stepper_motor/) |

---

<a id="families"></a>
## Microcontroller families

<a id="family-8051"></a>
### 8051 (AT89C51)
- IDE: Keil uVision
- Simulation: Proteus (`.pdsprj`)

<a id="family-arm7"></a>
### ARM7 (LPC2138)
- IDE: Keil uVision
- Simulation: Proteus (`.pdsprj`)

<a id="family-avr"></a>
### AVR
- IDE: Atmel Studio

<a id="family-pic16"></a>
### PIC16
- IDE: MPLAB
- Simulation: Proteus (`.pdsprj`)

<a id="family-pic18"></a>
### PIC18
- IDE: MPLAB
- Simulation: Proteus (`.pdsprj`)

---

<a id="tech"></a>
## Technology stack (hover for meaning)

<div align="center">
  <img src="https://img.shields.io/badge/I2C-Protocol-2563eb" alt="I2C" title="Inter-Integrated Circuit" />
  <img src="https://img.shields.io/badge/SPI-Protocol-16a34a" alt="SPI" title="Serial Peripheral Interface" />
  <img src="https://img.shields.io/badge/CAN-Protocol-ef4444" alt="CAN" title="Controller Area Network" />
  <img src="https://img.shields.io/badge/UART-Protocol-f59e0b" alt="UART" title="Universal Asynchronous Receiver/Transmitter" />
</div>

<div align="center">
  <img src="https://img.shields.io/badge/ADC-Peripheral-7c3aed" alt="ADC" title="Analog-to-Digital Converter" />
  <img src="https://img.shields.io/badge/LCD-Display-0ea5e9" alt="LCD" title="Liquid Crystal Display" />
  <img src="https://img.shields.io/badge/PWM-Control-22c55e" alt="PWM" title="Pulse Width Modulation" />
</div>

---

<a id="getting-started"></a>
## Getting started

1. Pick a project from the [project matrix](#project-matrix).
2. Open the corresponding IDE project file:
   - Keil: `.uvproj`
   - MPLAB: `.mcp`
   - Atmel Studio: `.cproj` / `.atsln`
3. If there is a Proteus file (`.pdsprj`), open it and load the built `.hex`.

---

If you like this collection, consider starring the repo.