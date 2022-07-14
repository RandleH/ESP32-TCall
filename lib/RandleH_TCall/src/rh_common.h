#ifndef RH_COMMON_H
#define RH_COMMON_H

#ifdef __cplusplus
extern "C"{
#endif


#include "esp32-hal-log.h"
#define RH_CONSOLE( format, ...)    log_e( format, ##__VA_ARGS__)




#define MODEM_RST             5
#define MODEM_PWRKEY          4
#define MODEM_POWER_ON       23
#define MODEM_TX             27
#define MODEM_RX             26

#define MODEM_DTR            32
#define MODEM_RI             33

#define RH_CFG__PIN_I2C_SDA              21
#define RH_CFG__PIN_I2C_SCL              22


#define LED_GPIO             13
#define LED_ON               HIGH
#define LED_OFF              LOW





#define IP5306_ADDR          0x75
#define IP5306_REG_SYS_CTL0  0x00

#ifdef __cplusplus
}
#endif

#include <string>

using namespace std;

namespace rh{

class ConfigI2C{
public:
    int sda;
    int scl;
    bool isValid;
    ConfigI2C():sda(0),scl(0),isValid(false){}
    
};


class I2C{
public:
    I2C():config(),isInitialized(false){} 
    ConfigI2C    config;
    bool         isInitialized;
    int init(void);
    int send(uint8_t addr, uint8_t *data, size_t len);
};

class PWR{
private:
    bool     enable;
public:
    PWR():enable(false){}
    int on();
    int off();
    int status();
};

class MODEM{
public:
    MODEM():vdd(23),pwrkey(4),rst(5),tx(27),rx(26),dtr(32),ri(33),core(nullptr){}
    int  vdd;
    int  pwrkey;
    int  rst;
    int  tx;      
    int  rx;        
    int  dtr;      
    int  ri;
    void *core;
    int           init(void);
    const char*   imei(void);
};

class Application{
public:
    Application(){}
    I2C       i2c;

    PWR       power;
    MODEM     modem;
};

extern Application app;
}




#endif

