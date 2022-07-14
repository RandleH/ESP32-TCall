
#include "rh_common.h"
#include "bsp/rh_i2c.h"

#define TINY_GSM_MODEM_SIM800
#include <TinyGsmClient.h>

namespace rh{
Application app;
}



void setup() {
    // put your setup code here, to run once:
    RH_CONSOLE("App start!");

    0==rh::app.i2c.init()          ? RH_CONSOLE("[Y] i2c")    : RH_CONSOLE("[N] i2c");
    0==rh::app.power.on()          ? RH_CONSOLE("[Y] pwr")    : RH_CONSOLE("[N] pwr");
    0==rh::app.modem.init()        ? RH_CONSOLE("[Y] modem")  : RH_CONSOLE("[N] modem");
    
    Serial.read();
    RH_CONSOLE( "imei:%s", rh::app.modem.imei() );
    RH_CONSOLE( "imei:%s", rh::app.modem.imei() );
    RH_CONSOLE( "imei:%s", rh::app.modem.imei() );
    RH_CONSOLE( "imei:%s", rh::app.modem.imei() );
    RH_CONSOLE( "imei:%s", rh::app.modem.imei() );
    RH_CONSOLE("%s", ((TinyGsm*)rh::app.modem.core)->getModemInfo());
    RH_CONSOLE("%s", ((TinyGsm*)rh::app.modem.core)->getIMSI());
    RH_CONSOLE("%s", ((TinyGsm*)rh::app.modem.core)->getModemInfo());
}

void loop() {
    // put your main code here, to run repeatedly:
}

// #define SIM800 Serial1
// void loop() {
//     // put your main code here, to run repeatedly:
//     while( Serial.available() ){
//         SIM800.write(Serial.read());
//     }

//     while( SIM800.available()){
//         Serial.write(SIM800.read());
//     }
// }