# Automated-Plant-Waterer---ECE4180
David Martinez , Nathanael Kim – ECE 4180 Final Project

## Introduction

In modern agriculture and smart home applications, automation plays a key role in improving efficiency and reliability. This project, the Automatic Plant Watering System, is designed to address one of the most basic but critical tasks in plant care—maintaining consistent soil moisture. Leveraging principles from embedded systems design, this project demonstrates how sensors, actuators, and microcontrollers can work together to create an autonomous, intelligent system that mimics real-world irrigation control.

Developed using an Mbed-compatible microcontroller, the system uses real-time feedback from a soil moisture sensor to decide when to activate a DC water pump via a TB6612FNG motor driver. A uLCD display provides live status updates, while a water level sensor and speaker ensure the plant isn’t watered when the reservoir is empty. The goal was to build a functional prototype that emphasizes reliability, responsiveness, and user awareness—all within the scope of a course-level embedded system.

This project not only reflects technical understanding of real-time systems but also offers practical insight into product design, debugging, and the realities of hardware interfacing under variable conditions.

## System Description

The core functionality revolves around a continuous soil moisture monitoring process. An analog soil moisture sensor provides readings between 0.0 (completely dry) and 1.0 (fully saturated). These readings are scaled to a percentage and compared against a preset threshold. When the moisture level falls below this threshold, a DC water pump, driven by a TB6612FNG motor driver, is activated to hydrate the soil.

The system is enhanced by a uLCD display, which presents live feedback on moisture levels and system activity. A water level sensor is installed in the water tank to ensure the plant isn’t watered if the supply is too low. In such cases, the speaker issues an audible alert, warning the user to refill the water tank.

## Component Breakdown:

* Mbed Microcontroller: Handles sensor readings, logic control, and actuator output.
* Soil Moisture Sensor (Analog): Detects current soil moisture level.
* Motor Driver (TB6612FNG): Bridges control logic and motor power safely.
* DC Water Pump (): Dispenses water when activated.
* uLCD: Displays real-time feedback for soil moisture and water level status.
* Water Level Sensor: Detects current water level in the water tank.
* Speaker: Alerts user when the reservoir is dry.
* 3D printed pot: To hold the plant and soil moisture.

## Hardware Setup

## Developmental Challenges

Several practical challenges arose during implementation. PWM configuration for the speaker interfered with analog sensor reads, requiring careful timing and pin allocation. Tuning the soil moisture threshold for varying soil types involved trial-and-error, as no single value fits all soil conditions. Additionally, pump activation had to be stabilized through the motor driver to avoid voltage dips and unpredictable motor behavior.

Before the final demo, the system was fully functional and tested. However, during the presentation, the water level sensor failed to operate correctly. Upon inspection, we discovered the sensor had likely been damaged due to improper storage or transport prior to the demo, which prevented the low-water alert feature from working as intended. This highlighted the importance of robust packaging and pre-demo hardware verification in embedded system deployments.

## Comparison to Real-World Systems

This project mimics real-world smart irrigation systems in its autonomy and responsiveness. However, it differs in scale and complexity. Commercial solutions typically feature wireless connectivity, solar power, and multi-sensor integration (temperature, humidity, weather forecasting), whereas this project is self-contained and wired. Still, the fundamental control logic and sensor-actuator relationship are shared traits.

## Potential Improvements

Given more time and resources, several improvements would enhance this system’s utility:

* Wireless Connectivity: Integration with WiFi for remote monitoring and control.
* Mobile App Dashboard: A companion app could offer remote insights and manual overrides.
* Data Logging: Adding SD card or cloud-based logging for historical soil trends.
* Battery/Solar Operation: To allow outdoor deployment without reliance on AC power.
* Environmental Expansion: Adding sensors for light, temperature, and humidity to adjust watering dynamically.

## Conclusion

The Automatic Plant Watering System successfully demonstrates how embedded systems can be applied to real-world automation challenges in agriculture and home gardening. By combining sensor inputs, actuator outputs, and intelligent control logic, the system responds autonomously to soil conditions, ensuring that plants receive water only when needed. It also incorporates safety and usability features, such as a water level alert, to prevent system misuse and enhance user experience.

Although the system encountered a hardware setback during the final demo—specifically, the failure of the water level sensor due to damage in storage—it had been fully functional during development and testing. This highlights a key learning experience in hardware reliability, especially in systems meant for continuous deployment.

Overall, this project reflects the practical application of embedded concepts learned in ECE 4180. It goes beyond the classroom by addressing real-world constraints and demonstrating how to integrate hardware components into a cohesive, functional solution. With more time and resources, the system could be extended to include wireless communication, environmental data logging, and solar-powered operation—bringing it closer to commercially viable smart irrigation systems. This project has laid a strong foundation for further exploration in embedded automation and IoT-driven sustainability solutions.

## Links to Hardware Parts

- [SparkFun Soil Moisture Sensor](https://www.sparkfun.com/sparkfun-soil-moisture-sensor.html?gQT=1)  
- [Water Level Sensor (DGZZI)](https://www.amazon.com/DGZZI-Surface-Detection-Arduino-Raspberry/dp/B08C7L7GBK/ref=asc_df_B08C7L7GBK?mcid=0e7b20e941b632edac97d17412eb3aa2&hvocijid=1677781364128291944-B08C7L7GBK-&hvexpln=73&tag=hyprod-20&linkCode=df0&hvadid=721245378154&hvpos=&hvnetw=g&hvrand=1677781364128291944&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9199231&hvtargid=pla-2281435177378&psc=1)  
- [GG01D Mini DC Water Pump](https://www.amazon.com/dp/B097F4576N?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1)  
- [SparkFun PCB-Mount Piezo Speaker](https://www.sparkfun.com/speaker-pcb-mount-1.html)  
- [SparkFun 1.44" uLCD Display Module (uLCD-144-G2-GFX)](https://www.sparkfun.com/serial-miniature-lcd-module-1-44-ulcd-144-g2-gfx.html)
