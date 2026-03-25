#include "MicroBit.h"

extern "C" {
    #include "neopixel.h"
}

#define PIXEL_COUNT 2
#define PIN_P0 3

MicroBit uBit;

int main() {
    uBit.init();

    neopixel_strip_t strip;
    neopixel_init(&strip, PIN_P0, PIXEL_COUNT);
    neopixel_clear(&strip);

    while(1) {
        // Allume chaque LED avec une couleur différente
        for (int i = 0; i < PIXEL_COUNT; i++) {

            if(i == 0){
                neopixel_set_color(&strip, i, 50, 0, 0);  
            }else{
                neopixel_set_color(&strip, i, 0, 50, 0); 
            }
        }
        neopixel_show(&strip);
        uBit.sleep(1000);

        neopixel_clear(&strip);
        uBit.sleep(1000);
    }

    neopixel_destroy(&strip);
    release_fiber();
}