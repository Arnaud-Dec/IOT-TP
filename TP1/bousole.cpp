#include "MicroBit.h"

MicroBit uBit;

void onCompass(MicroBitEvent e) {
    int comp = uBit.compass.heading();

    if (comp > 330 || comp < 10) {
        uBit.display.scroll("N");
    } else if (comp >= 10 && comp < 180) {
        uBit.display.scroll("<-");
    } else {
        uBit.display.scroll("->");
    }
}

int main()
{
    uBit.init();

    uBit.messageBus.listen(MICROBIT_ID_COMPASS, MICROBIT_COMPASS_EVT_DATA_UPDATE, onCompass);

    release_fiber();
}