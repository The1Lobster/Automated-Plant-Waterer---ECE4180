#include "mbed.h"
#include "uLCD.hpp"
#include "Motor.h"

AnalogIn soil_sensor(p15);
AnalogIn water_level_sensor(p16);
DigitalOut pump(p5);
PwmOut speaker(p21);
Motor m(p23, p6, p5);
uLCD screen(p9, p10, p11, uLCD::BAUD_9600);

const int moisture_threshold = 20;    // Below this = dry
const int water_level_threshold = 45; // Below this = low water

void play_alert(bool on) {
    if (on) {
        speaker.period(1.0 / 1000);
        speaker = 0.5;
        thread_sleep_for(500);
        speaker = 0.0;
    }
}

int main() {
    screen.reset();  
    screen.cls();
    screen.setFontSize(2, 2);

    while (true) {
        float soil_raw = soil_sensor.read();
        float water_raw = water_level_sensor.read();

        int soil_val = soil_raw * 100;               // percentage
        int water_val = water_raw * 100;

        screen.cls();  
        screen.locate(0, 0);

        if (soil_val < moisture_threshold) {
            if (water_val < water_level_threshold) {
                // Dry soil but not enough water
                screen.setTextColor(uLCD::get4DGLColor(0xFF0000));  // red
                screen.printf("Status:\nPlant is Dry\nWater Empty");
                play_alert(true);
                m.speed(0); // make sure pump is off
            } else {
                // Dry soil, water available
                screen.setTextColor(uLCD::get4DGLColor(0xFFFF00));  // yellow
                screen.printf("Status:\nDry Soil!\nWatering...");
                m.speed(0.4); // turn on pump
                thread_sleep_for(3000); // run pump for 3 sec
                m.speed(0); // stop pump
            }
        } else {
                //soil moist, no water 
            if (water_val < water_level_threshold) {
                screen.setTextColor(uLCD::get4DGLColor(0xFFFF00));  // Yellow
                screen.printf("Status:\nPlant is watered\nWater Refill Needed");
                m.speed(0); // make sure pump is off

                
            } else {  //soil moist,  water
                screen.setTextColor(uLCD::get4DGLColor(0x00FF00));  // Green
                screen.printf("Status:\nPlant is watered!\nWater Tank is Full!");
                m.speed(0); // make sure pump is off
            }
        }

        thread_sleep_for(2000); // pause before next loop
    }
}
