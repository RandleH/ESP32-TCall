
#include "rh_common.h"


namespace rh{

int PWR::on(){
    if( !app.i2c.isInitialized ){
        RH_CONSOLE("I2C port hasn't been initialized");
        return 1;
    }
    this->enable = true;
    uint8_t data[2] = {0x00,0x37};
    return app.i2c.send( 0x75, data, 2);
}


int PWR::off(){
    if( !app.i2c.isInitialized ){
        RH_CONSOLE("I2C port hasn't been initialized");
        return 1;
    }
    this->enable = false;
    uint8_t data[2] = {0x00,0x35};
    return app.i2c.send( 0x75, data, 2);
}


int PWR::status(){
    return this->enable==true;
}

}