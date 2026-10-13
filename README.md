# IoT Based Smart Motor Protection System

## Project Overview

The IoT Based Smart Motor Protection System is a mini project developed using the ESP32 microcontroller, voltage and current sensors, and the Blynk IoT platform.

The system monitors voltage and current readings and sends the measured values to a Blynk dashboard over Wi-Fi. This helps users observe electrical parameters remotely.

## Objectives

- Monitor voltage and current readings.
- Use ESP32 for sensor data processing.
- Display measurements on the Blynk IoT dashboard.
- Explore IoT-based remote electrical monitoring.
- Build a foundation for future motor protection features.

## Hardware Requirements

- ESP32 development board
- ZMPT101B voltage sensor
- ACS712 30A current sensor
- Motor and suitable test setup
- Jumper wires
- Appropriate power supply
- Wi-Fi connection

## Software Requirements

- Arduino IDE
- ESP32 board support package
- Blynk IoT platform
- ZMPT101B sensor library
- Blynk library for ESP32

## Working Principle

1. The ZMPT101B sensor measures the AC voltage signal.
2. The ACS712 sensor measures the current signal.
3. The ESP32 reads the sensor outputs and calculates measurement values.
4. The ESP32 connects to Wi-Fi and communicates with Blynk.
5. Voltage and current readings are sent to the dashboard for remote monitoring.

## Project Features

- ESP32-based monitoring
- Voltage measurement
- Current measurement
- Wi-Fi connectivity
- Blynk dashboard integration
- Serial Monitor output for debugging

**Current implementation:** The uploaded source code focuses on measurement and remote monitoring. Automatic motor shutdown and fault alerts are not implemented in this version.

## Configuration

Before running the program:

1. Install the required ESP32 board package and libraries in Arduino IDE.
2. Configure your Blynk template and device.
3. Enter your Wi-Fi credentials and Blynk authentication token locally in the source code.
4. Verify the sensor connections and calibrate the readings.
5. Upload the program to the ESP32 and check the Serial Monitor and Blynk dashboard.

**Security:** Never upload real Wi-Fi passwords or Blynk authentication tokens to a public repository.

## Hardware Connections

The current source code uses these ESP32 input pins:

- ZMPT101B output: GPIO 34
- ACS712 output: GPIO 35

Verify the complete wiring, sensor supply requirements, grounding, and voltage compatibility against your actual hardware before powering the circuit.

## Applications

- Educational IoT projects
- Remote electrical parameter monitoring
- Demonstrations of sensor integration with cloud dashboards
- Foundation for future motor monitoring and protection systems

## Future Enhancements

- Overvoltage and undervoltage detection
- Overcurrent detection
- Fault notifications through Blynk
- Automatic motor cutoff using a properly rated, isolated switching device
- Historical data logging and monitoring

These are proposed enhancements and require additional implementation and testing.

## Safety Notice

This project is for educational development. Sensor calibration and electrical isolation are essential. Do not connect exposed low-voltage development hardware directly to mains circuits without appropriate isolation, protection, and qualified supervision.

## Author

**Sravya Naidu**

B.Tech – Computer Science and Engineering

## License

This project is available under the MIT License. See the `LICENSE` file for details.
