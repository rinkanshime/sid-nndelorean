/*
 * -------------------------------------------------------------------
 * NNDeLorean SID
 * DeLorean DMC-12 Time Machine Status Indicator Display prop 
 * from Back to the Future trilogy 
 * created for NNDeLorean - first russian DMC-12 Time Machine
 * (C) 2024 Mark Michurin (Rinkanshime)
 * https://github.com/rinkanshime/SID_NNDeLorean
 * https://nndelorean.ru
 * 
 * License: AGPLv3
 * -------------------------------------------------------------------
 */

/*
 * Build instructions (for Arduino IDE)
 * 
 * - Install the Arduino IDE
 *   https://www.arduino.cc/en/software
 *    
 * - This firmware requires the "ESP32-Arduino" framework. To install this framework, 
 *   in the Arduino IDE, go to "File" > "Preferences" and add the URL   
 *   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
 *   to "Additional Boards Manager URLs". The list is comma-separated.
 *   
 * - Go to "Tools" > "Board" > "Boards Manager", then search for "esp32", and install 
 *   the latest version by Espressif Systems.
 *   Detailed instructions for this step:
 *   https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html
 *   
 *
 * - Install required libraries. In the Arduino IDE, go to "Tools" -> "Manage Libraries" 
 *   and install the following libraries:
 *   - WifiManager (tablatronix, tzapu) https://github.com/tzapu/WiFiManager
 *     (Tested with 2.0.13beta, 2.0.15-rc1, 2.0.16-rc2)
 *     For versions 2.0.16-rc2 and below, in order to avoid a delay when powering up
 *     several BTTFN-connected props, change _preloadwifiscan to false in WiFiManager.h 
 *     before compiling:
 *     -boolean       _preloadwifiscan        = true;
 *     +boolean       _preloadwifiscan        = false;
 *   - ArduinoJSON >= 6.19: https://arduinojson.org/v6/doc/installation/
 *
 * - Download the complete firmware source code:
 *   https://github.com/realA10001986/SID/archive/refs/heads/main.zip
 *   Extract this file somewhere. Enter the "sid-A10001986" folder and 
 *   double-click on "sid-A10001986.ino". This opens the firmware in the
 *   Arduino IDE.
 *
 * - Go to "Sketch" -> "Upload" to compile and upload the firmware to your ESP32 board.
 */


#include "sid_global.h"
#include <HardwareSerial.h>
#include <Arduino.h>
#include <Wire.h>

#include "sid_settings.h"
#include "sid_wifi.h"
#include "sid_main.h"

void setup()
{
    powerupMillis = millis();
    
    Serial.begin(115200);
    Serial.println();

    Wire.begin(-1, -1, 400000);

    main_boot();
    settings_setup();
    wifi_setup();
    main_setup();
    bttfn_loop();
}

void loop()
{    
    main_loop();
    wifi_loop();
    bttfn_loop();
}
