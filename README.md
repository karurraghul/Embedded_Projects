# Embedded Systems Projects

A comprehensive collection of embedded systems projects organized by microcontroller family. This repository contains implementations for various peripherals, communication protocols, and sensor interfacing across multiple microcontroller platforms.

## Repository Structure

```
Embedded_Projects/
├── 8051/              # AT89C51 (MCS-51) projects
├── ARM/               # ARM7 (LPC2138) projects
├── AVR/               # AVR microcontroller projects
├── PIC16/             # PIC16 family projects
└── PIC18/             # PIC18 family projects
```

## Microcontroller Families

### 8051 (AT89C51)
Projects using the 8051 architecture (AT89C51 microcontroller):
- **ADC** - Analog-to-Digital Converter interfacing
- **ADC_A** - Alternative ADC implementation
- **ADC_POT** - ADC with potentiometer input
- **7-Segment Display** - 7-segment display driver
- **LCD_Interfacing** - LCD display interfacing
- **LED_BLINK** - Basic LED blinking
- **LED_TRAFFIC** - Traffic light simulation

**IDE:** Keil uVision  
**Simulation:** Proteus Design Suite (.pdsprj files)

### ARM7 (LPC2138)
Projects using ARM7TDMI architecture (LPC2138 microcontroller):
- **ADC_ARM** - ADC implementation for ARM
- **CAN_PROTOCOL** - CAN bus communication protocol
- **CAN_WORKING** - Working CAN implementation
- **I2C_EEPROM** - I2C EEPROM interfacing (2 variants)
- **PIR_Sensor** - PIR motion sensor interfacing
- **RFID** - RFID reader interfacing
- **TouchSensor** - Touch sensor implementation

**IDE:** Keil uVision  
**Simulation:** Proteus Design Suite (.pdsprj files)

### AVR
Projects using AVR microcontrollers:
- **AVR_LED** - LED control implementation

**IDE:** Atmel Studio  
**Simulation:** Proteus Design Suite (.pdsprj files)

### PIC16
Projects using PIC16 family microcontrollers:
- **7_SEGMENT** - 7-segment display driver
- **7seg_multiplex** - Multiplexed 7-segment display
- **LEDPIC** - LED control
- **pwm** - PWM signal generation
- **stepper_motor** - Stepper motor control
- **timer** - Timer implementation with interrupts
- **unipolarDCMotor** - DC motor control

**IDE:** MPLAB  
**Simulation:** Proteus Design Suite (.pdsprj files)

### PIC18
Projects using PIC18 family microcontrollers:
- **LCD_Display_8_bit** - 8-bit LCD interfacing
- **LED_blink** - LED blinking patterns
- **LED_Pattern_blink** - Advanced LED patterns
- **NewPic18SPI** - SPI communication (SD card)
- **PIC_18_LCD_REV** - LCD revision implementation
- **PIC18_I2C** - I2C communication
- **PIC18SPI** - SPI communication
- **PICADC** - ADC implementation

**IDE:** MPLAB  
**Simulation:** Proteus Design Suite (.pdsprj files)

## Requirements

### Software Tools
- **Keil uVision** - For 8051 and ARM projects
- **MPLAB** - For PIC16 and PIC18 projects
- **Atmel Studio** - For AVR projects
- **Proteus Design Suite** - For simulation (.pdsprj files)

### Hardware
- Various development boards and microcontrollers as specified in each project
- Peripherals: LCDs, sensors, motors, displays, etc.

## Project Files

Each project typically contains:
- **Source files** (.c, .asm, .s, .h) - Main source code
- **Project files** (.uvproj, .mcp, .cproj) - IDE project configuration
- **Simulation files** (.pdsprj) - Proteus simulation schematics
- **Startup files** (STARTUP.A51, Startup.s) - Microcontroller initialization code

## Usage

1. **Open Project:**
   - For 8051/ARM: Open `.uvproj` files in Keil uVision
   - For PIC16/PIC18: Open `.mcp` files in MPLAB
   - For AVR: Open `.cproj` or `.atsln` files in Atmel Studio

2. **Simulate:**
   - Open `.pdsprj` files in Proteus Design Suite
   - Load the compiled `.hex` file into the microcontroller in the simulation

3. **Build:**
   - Build the project in the respective IDE
   - The output `.hex` file can be used for programming or simulation

## File Organization

- **Source Code:** All `.c`, `.asm`, `.s`, and `.h` files are included
- **Project Files:** IDE project files (`.uvproj`, `.mcp`, etc.) are included
- **Simulation Files:** All Proteus simulation files (`.pdsprj`) are included
- **Build Artifacts:** Excluded (see `.gitignore`)

## Excluded Files

The following files are excluded from this repository:
- Build outputs: `.hex`, `.obj`, `.axf`, `.cof`, `.o`, `.elf`, etc.
- Build directories: `Objects/`, `Listings/`, `Debug/`
- User-specific files: `.uvgui.*`, `.workspace`, `.bak`, `.pdsbak`
- Intermediate files: `.dep`, `.crf`, `.d`, `.lnp`, etc.

## Notes

- All simulation files (`.pdsprj`) are preserved as they are essential for understanding and testing projects
- Project files are included so projects can be opened directly in their respective IDEs
- Source code is organized by microcontroller family for easy navigation
- Each project is self-contained with its necessary files

## Contributing

When adding new projects:
1. Place them in the appropriate microcontroller family folder
2. Include source files, project files, and simulation files
3. Exclude build artifacts and user-specific files
4. Update this README if adding new project categories

## License

This repository contains educational embedded systems projects. Use as reference for learning embedded systems programming.

