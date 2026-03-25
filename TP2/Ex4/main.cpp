/*
GND : Ground
+3.3V : +3.3 Volt
SDA : Bidirectional Serial Data for I2C bus.
SCL : Clock for I2C bus.
*/

#include "MicroBit.h"
#include "bme280.h"
#include "tsl256x.h"
#include "veml6070.h"

MicroBit uBit;
MicroBitI2C i2c(I2C_SDA0,I2C_SCL0);

int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();

    bme280 bme(&uBit,&i2c);
    uint32_t pressure = 0;
    int32_t temp = 0;
    uint16_t humidite = 0;

    tsl256x tsl(&uBit,&i2c);
    uint16_t comb =0;
    uint16_t ir = 0;
    uint32_t lux = 0;

    veml6070 veml(&uBit,&i2c);
    uint16_t uv = 0;

    while(true)
    {
        //bme280
        bme.sensor_read(&pressure, &temp, &humidite);
        int tmp = bme.compensate_temperature(temp);
        int pres = bme.compensate_pressure(pressure)/100;
        int hum = bme.compensate_humidity(humidite);
        ManagedString display = "Temp:" + ManagedString(tmp/100) + "." + (tmp > 0 ? ManagedString(tmp%100): ManagedString((-tmp)%100))+" C";
        uBit.display.scroll(display.toCharArray());
        display = "Humi:" + ManagedString(hum/100) + "." + ManagedString(tmp%100)+" rH";
        uBit.display.scroll(display.toCharArray());
        display = "Pres:" + ManagedString(pres)+" hPa";
        uBit.display.scroll(display.toCharArray());

        //tsl2561
        tsl.sensor_read(&comb, &ir, &lux);
        display = "Lux:" + ManagedString((int)lux);
        uBit.display.scroll(display.toCharArray());

        //VEML6070
        veml.sensor_read(&uv);
        display = "UV:" + ManagedString(uv);
        uBit.display.scroll(display.toCharArray());

        uBit.sleep(2000);
    }

    release_fiber();

}