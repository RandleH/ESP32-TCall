#include <Arduino.h>
#include "rh_common.h"

#define TINY_GSM_MODEM_SIM800
#define TINY_GSM_RX_BUFFER      1024
#define TINY_GSM_DEBUG          Serial
#include <TinyGsmClient.h>

namespace rh{

int MODEM::init(void){
    pinMode( rst, OUTPUT);
    digitalWrite( rst, HIGH);

    pinMode( vdd, OUTPUT);
    digitalWrite( vdd, HIGH);

    pinMode( pwrkey, OUTPUT);
    digitalWrite( pwrkey, HIGH);

    vTaskDelay(100);
    digitalWrite( pwrkey, LOW);
    vTaskDelay(1000);
    digitalWrite( pwrkey, HIGH);
    
    pinMode( 13, OUTPUT);
    digitalWrite( 13, HIGH);
    
    Serial1.begin(115200, SERIAL_8N1, rx, tx);
    vTaskDelay(6000);

    core = new TinyGsm(Serial1);
 
    bool ret = ((TinyGsm*)core)->restart();
    
    vTaskDelay(10000);
    return true!=ret;
}

const char* MODEM::imei(void){
    static String IMEI;
    IMEI = ((TinyGsm*)core)->getIMEI();
    return IMEI.c_str();
}

}



