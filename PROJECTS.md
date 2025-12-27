# Detailed Project Catalog

This catalog is optimized for fast GitHub browsing: jump links, collapsible families, and consistent mini-cards for each project.

<div align="center">
  <img src="https://raw.githubusercontent.com/tabler/tabler-icons/master/icons/svg/book-2.svg" width="36" height="36" alt="Catalog" title="Project catalog" />
  <img src="https://raw.githubusercontent.com/tabler/tabler-icons/master/icons/svg/search.svg" width="36" height="36" alt="Search" title="Browse by family or technology" />
</div>

<div align="center">

<a href="#nav" title="Jump links">
  <img src="https://img.shields.io/badge/Jump-Links-64748b?style=for-the-badge" alt="Jump links" />
</a>
<a href="#tech-index" title="Browse by technology">
  <img src="https://img.shields.io/badge/Browse-Technology_Index-0ea5e9?style=for-the-badge" alt="Technology index" />
</a>
<a href="README.md" title="Back to the interactive matrix">
  <img src="https://img.shields.io/badge/Back-README-22c55e?style=for-the-badge" alt="Back to README" />
</a>

</div>

---

<a id="nav"></a>
## Jump links

- [8051](#p-8051)
- [ARM7](#p-arm7)
- [AVR](#p-avr)
- [PIC16](#p-pic16)
- [PIC18](#p-pic18)
- [Technology index](#tech-index)

---

## Project overview

| Family | Projects | Typical focus |
|:--|--:|:--|
| 8051 (AT89C51) | 7 | ADC/LCD/LED basics |
| ARM7 (LPC2138) | 8 | Protocols + sensors |
| AVR | 1 | GPIO basics |
| PIC16 | 7 | PWM/timers + motors + displays |
| PIC18 | 8 | SPI/I2C + LCD/ADC |

---

<a id="p-8051"></a>
<details open>
<summary><strong>8051 (AT89C51)</strong> - 7 projects</summary>

| Project | Difficulty | Key tech | What you learn |
|:--|:--|:--|:--|
| [ADC](8051/ADC/) | Intermediate | <a href="#t-adc" title="Jump to ADC in the Technology index"><code title="Analog-to-Digital Converter">ADC</code></a> | Setting up ADC and reading analog values |
| [ADC_A](8051/ADC_A/) | Intermediate | <a href="#t-adc" title="Jump to ADC in the Technology index"><code title="Analog-to-Digital Converter">ADC</code></a> | Alternative ADC approach and sampling |
| [ADC_POT](8051/ADC_POT/) | Intermediate | <code title="Potentiometer input">POT</code> <a href="#t-adc" title="Jump to ADC in the Technology index"><code title="Analog-to-Digital Converter">ADC</code></a> | Reading a variable analog source |
| [7-Segement Display](8051/7-Segement%20Display/) | Beginner | <code title="7-segment display">7SEG</code> <code title="Assembly">ASM</code> | Driving a 7-seg with lookup patterns |
| [LCD_Interfacing](8051/LCD_Interfacing/) | Intermediate | <code title="Liquid Crystal Display">LCD</code> | LCD init, commands, and text output |
| [LED_BLINK](8051/LED_BLINK/) | Beginner | <code title="GPIO">GPIO</code> <code title="Assembly">ASM</code> | Timing + toggling pins |
| [LED_TRAFFIC](8051/LED_TRAFFIC/) | Intermediate | <code title="State machine">FSM</code> | Sequencing and timing states |

<p><a href="#nav">Back to jump links</a> • <a href="#tech-index">Technology index</a></p>
</details>

<a id="p-arm7"></a>
<details>
<summary><strong>ARM7 (LPC2138)</strong> - 8 projects</summary>

| Project | Difficulty | Key tech | What you learn |
|:--|:--|:--|:--|
| [ADC_ARM](ARM/ADC_ARM/) | Intermediate | <a href="#t-adc" title="Jump to ADC in the Technology index"><code title="Analog-to-Digital Converter">ADC</code></a> <code title="Liquid Crystal Display">LCD</code> | ADC + UI on LCD |
| [CAN_PROTOCOL](ARM/CAN_PROTOCOL/) | Advanced | <a href="#t-can" title="Jump to CAN in the Technology index"><code title="Controller Area Network">CAN</code></a> <code title="MCP2515">MCP2515</code> | CAN framing + controller driver |
| [CAN_WORKING](ARM/CAN_WORKING/) | Advanced | <a href="#t-can" title="Jump to CAN in the Technology index"><code title="Controller Area Network">CAN</code></a> | Establishing a working CAN baseline |
| [I2C_EEPROM_ARM7](ARM/I2C_EEPROM_ARM7/) | Advanced | <a href="#t-i2c" title="Jump to I2C in the Technology index"><code title="Inter-Integrated Circuit">I2C</code></a> <code title="EEPROM">EEPROM</code> | Robust I2C transactions |
| [I2C-Proj2](ARM/I2C-Proj2/) | Advanced | <a href="#t-i2c" title="Jump to I2C in the Technology index"><code title="Inter-Integrated Circuit">I2C</code></a> | Alternative I2C flow |
| [PIR_Sensor_ARM7](ARM/PIR_Sensor_ARM7/) | Intermediate | <code title="Passive Infrared Sensor">PIR</code> | Motion detection + control logic |
| [RFID_ARM](ARM/RFID_ARM/) | Advanced | <code title="Radio-frequency identification">RFID</code> <a href="#t-uart" title="Jump to UART in the Technology index"><code title="UART">UART</code></a> | UART parsing + LCD output |
| [TouchSensor](ARM/TouchSensor/) | Intermediate | <code title="Touch sensing">TOUCH</code> | Touch input handling |

<p><a href="#nav">Back to jump links</a> • <a href="#tech-index">Technology index</a></p>
</details>

<a id="p-avr"></a>
<details>
<summary><strong>AVR</strong> - 1 project</summary>

| Project | Difficulty | Key tech | What you learn |
|:--|:--|:--|:--|
| [AVR_LED](AVR/AVR/AVR_LED/) | Beginner | <code title="GPIO">GPIO</code> | Clean LED control baseline |

<p><a href="#nav">Back to jump links</a> • <a href="#tech-index">Technology index</a></p>
</details>

<a id="p-pic16"></a>
<details>
<summary><strong>PIC16</strong> - 7 projects</summary>

| Project | Difficulty | Key tech | What you learn |
|:--|:--|:--|:--|
| [7 SEGMENT](PIC16/PIC16/7%20SEGMENT/) | Beginner | <code title="7-seg">7SEG</code> | Display driving |
| [7seg_multiplex](PIC16/PIC16/7seg_multiplex/) | Intermediate | <code title="Multiplexing">MUX</code> | Multi-digit multiplexing |
| [LEDPIC](PIC16/PIC16/LEDPIC/) | Beginner | <code title="GPIO">GPIO</code> | LED control |
| [pwm](PIC16/PIC16/pwm/) | Intermediate | <code title="Pulse Width Modulation">PWM</code> | PWM setup + tuning |
| [stepper_motor](PIC16/PIC16/stepper_motor/) | Intermediate | <code title="Stepper motor">STEPPER</code> | Step sequencing |
| [timer](PIC16/PIC16/timer/) | Intermediate | <code title="Interrupt Service Routine">ISR</code> <code title="Timer">TIMER</code> | Timers + interrupts |
| [unipolarDCMotor](PIC16/PIC16/unipolarDCMotor/) | Intermediate | <code title="DC motor">DC</code> | Motor control basics |

<p><a href="#nav">Back to jump links</a> • <a href="#tech-index">Technology index</a></p>
</details>

<a id="p-pic18"></a>
<details>
<summary><strong>PIC18</strong> - 8 projects</summary>

| Project | Difficulty | Key tech | What you learn |
|:--|:--|:--|:--|
| [LCD_DIsplay_8_bit](PIC18/PIC18/LCD_DIsplay_8_bit/) | Intermediate | <code title="Liquid Crystal Display">LCD</code> | 8-bit LCD interface |
| [LED_blink](PIC18/PIC18/) | Beginner | <code title="GPIO">GPIO</code> | LED blinking |
| [LED_Pattern_blink](PIC18/PIC18/LED_Pattern_blink/) | Intermediate | <code title="Patterns">PATTERN</code> | Pattern sequencing |
| [NewPic18SPI](PIC18/PIC18/NewPic18SPI/) | Advanced | <a href="#t-spi" title="Jump to SPI in the Technology index"><code title="Serial Peripheral Interface">SPI</code></a> <code title="Secure Digital">SD</code> | SPI stack + SD comms |
| [PIC_18_LCD_REV](PIC18/PIC18/PIC_18_LCD_REV/) | Intermediate | <code title="Liquid Crystal Display">LCD</code> | LCD driver variant |
| [PIC18_I2C](PIC18/PIC18/PIC18_I2C/) | Advanced | <a href="#t-i2c" title="Jump to I2C in the Technology index"><code title="Inter-Integrated Circuit">I2C</code></a> | I2C communication |
| [PIC18SPI](PIC18/PIC18/PIC18SPI/) | Advanced | <a href="#t-spi" title="Jump to SPI in the Technology index"><code title="Serial Peripheral Interface">SPI</code></a> | SPI communication |
| [PICADC](PIC18/PIC18/PICADC/) | Intermediate | <a href="#t-adc" title="Jump to ADC in the Technology index"><code title="Analog-to-Digital Converter">ADC</code></a> <code title="Liquid Crystal Display">LCD</code> | ADC read + display |

<p><a href="#nav">Back to jump links</a> • <a href="#tech-index">Technology index</a></p>
</details>

---

<a id="tech-index"></a>
## Technology index

Click a tech to see where it appears.

- <a id="t-i2c"></a> **I2C**: [ARM I2C_EEPROM](ARM/I2C_EEPROM_ARM7/), [ARM I2C-Proj2](ARM/I2C-Proj2/), [PIC18 I2C](PIC18/PIC18/PIC18_I2C/)
- <a id="t-spi"></a> **SPI**: [PIC18 SPI](PIC18/PIC18/PIC18SPI/), [PIC18 SD Card](PIC18/PIC18/NewPic18SPI/)
- <a id="t-can"></a> **CAN**: [ARM CAN Protocol](ARM/CAN_PROTOCOL/), [ARM CAN Working](ARM/CAN_WORKING/)
- <a id="t-uart"></a> **UART**: [ARM RFID](ARM/RFID_ARM/)
- <a id="t-adc"></a> **ADC**: [8051 ADC](8051/ADC/), [ARM ADC](ARM/ADC_ARM/), [PIC ADC](PIC18/PIC18/PICADC/)

---

Back to README: [README.md](README.md)