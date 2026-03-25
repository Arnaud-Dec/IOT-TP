#include "MicroBit.h"

int main() {
    uBit.init();

    // Create a buffer for 8 pixels (3 bytes each: G, R, B)
    ManagedBuffer buffer(PIXEL_COUNT * 3);

    while(1) {
        // Set all pixels to Red
        for (int i = 0; i < PIXEL_COUNT * 3; i += 3) {
            buffer[i] = 0;     // Green
            buffer[i+1] = 255; // Red
            buffer[i+2] = 0;     // Blue
        }

        // Send the buffer to Pin 0
        uBit.io.P0.setDigitalValue(0);
        uBit.sleep(1); // Ensure line is low

        // Use the Neopixel send method provided by the DAL
        uBit.io.P0.sendBuffer(buffer);

        uBit.sleep(1000);
    }
}