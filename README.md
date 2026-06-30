![IEEE](https://img.shields.io/badge/IEEE-Published-red)

# GPS-Based Power Theft Detection and Alert System using GSM

An IoT-based smart power theft detection system that identifies unauthorized electricity consumption, detects the theft location using GPS, and instantly alerts the Electricity Board through GSM communication.

## IEEE Conference Publication

This project was presented and published in an IEEE International Conference.

**Conference**

2023 International Conference on Research Methodologies in Knowledge Management, Artificial Intelligence and Telecommunication Engineering (RMKMATE)

**Conference Date**

1–2 November 2023

**Location**

Chennai, India

**Publisher**

IEEE

**DOI**

10.1109/RMKMATE59243.2023.10368907

**IEEE Xplore**

https://ieeexplore.ieee.org/document/10368907


## Abstract

Electricity theft is a major challenge for utility providers, resulting in significant economic losses and safety risks. This project proposes a GPS-based electricity theft detection system using an Arduino Uno, ACS712 current sensor, GSM module, GPS module, relay, buzzer, and LCD display.

Whenever abnormal current consumption exceeding a predefined threshold is detected, the system:

- Detects the theft
- Captures the GPS location
- Sends an SMS alert using the GSM module
- Displays the theft status on the LCD
- Activates a buzzer
- Disconnects power using a relay

The proposed system enables faster identification of illegal power tapping and improves response time for electricity authorities.


## Features

- Real-time power theft detection
- GPS location tracking
- GSM SMS alert system
- Relay-based automatic power cutoff
- LCD status display
- Audible buzzer alert
- Arduino Uno based
- Low-cost IoT implementation


## System Architecture

```
Power Line
     │
     ▼
ACS712 Current Sensor
     │
     ▼
Arduino Uno
     │
 ┌───┼─────────────┐
 │   │             │
 ▼   ▼             ▼
LCD GSM Module  GPS Module
 │               │
 ▼               ▼
Status        GPS Coordinates
 │               │
 └──────┬────────┘
        ▼
SMS Alert
        │
        ▼
Electricity Board
```

## Working Principle

1. The ACS712 continuously measures current.
2. The Arduino compares the measured current against a threshold.
3. If abnormal current is detected:
   - Relay disconnects the supply.
   - Buzzer activates.
   - LCD displays "Power Theft Detected".
   - GPS module fetches the current location.
   - GSM module sends an SMS containing the GPS location.
4. Authorities receive the alert and can respond immediately.


## Results

The prototype successfully:

- Detected abnormal current
- Triggered an alarm
- Displayed the theft message on LCD
- Retrieved GPS coordinates
- Sent SMS alerts through GSM
- Automatically disconnected the power supply

## Applications

- Smart Grid Monitoring
- Electricity Boards
- Rural Power Distribution
- Industrial Power Monitoring
- Commercial Buildings
- Utility Infrastructure


## Demo

A demonstration video is available inside the `demo/` folder.


## Authors

Tharani R.
Published in collaboration with the co-authors listed in the IEEE conference paper.


## Citation

If you use this work, please cite the published IEEE conference paper.

## License

MIT License
