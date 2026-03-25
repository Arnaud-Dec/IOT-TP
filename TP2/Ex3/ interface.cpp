#include "MicroBit.h"

MicroBit uBit;

int main() {
    uBit.init();

    uBit.serial.baud(115200);

    while(1) {

        int temp = uBit.thermometer.getTemperature();

        // Accéléromètre (X, Y, Z)
        int accX = uBit.accelerometer.getX();
        int accY = uBit.accelerometer.getY();
        int accZ = uBit.accelerometer.getZ();

        // Boussole
        int heading = uBit.compass.heading();

        // Niveau de lumière
        int light = uBit.display.readLightLevel();

        // Envoi formaté sur le port série
        uBit.serial.printf("Temp: %d C | Acc: X=%d Y=%d Z=%d | Boussole: %d deg | Lumiere: %d\r\n",
            temp, accX, accY, accZ, heading, light);

        uBit.sleep(500);
    }

    release_fiber();
}