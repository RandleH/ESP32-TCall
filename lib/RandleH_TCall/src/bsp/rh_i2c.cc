#include <Arduino.h>
#include "Wire.h"
#include "rh_common.h"

int rh_i2c__init(){
    return true!=Wire.begin( RH_CFG__PIN_I2C_SDA, RH_CFG__PIN_I2C_SCL );
}

int rh_i2c__send( uint8_t addr, uint8_t* data, size_t len ){
    Wire.beginTransmission(addr);
    while(len--)
        Wire.write(*data++);
    
    return 0!=Wire.endTransmission();
}




namespace rh{

int I2C::init(void){
    if( this->config.isValid ){
        if( true!=Wire.begin( this->config.sda, this->config.scl) ){
             return -1;
        }else{
            isInitialized = true;
            return 0;
        }
    }
    
    if( 0!=rh_i2c__init() ){
        return -1;
    }
    isInitialized = true;
    return 0;
}

int I2C::send(uint8_t addr, uint8_t* data, size_t len){
    return rh_i2c__send( addr, data, len);
}


}








