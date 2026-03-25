#include "MicroBit.h"

MicroBit uBit;


int main()
{
    uBit.init();

    while(true){
        uBit.io.P0.setDigitalValue(1);
        uBit.io.P1.setDigitalValue(1);
        uBit.io.P2.setDigitalValue(1);
        uBit.sleep(100);
        uBit.io.P0.setDigitalValue(0);
        uBit.io.P1.setDigitalValue(0);
        uBit.io.P2.setDigitalValue(0);
        uBit.sleep(100);
    }

    release_fiber();
}