/** @file relay.cpp
 *  @brief contains functions for operating the relay.
 *
 *  @author Allen
 *  @bug Not Tested
 */

/* --- Standard Includes --- */
#include <stdio.h>
#include <stdlib.h>

/* --- Project Includes --- */
#include <si/shunyaInterfaces.h>

#define BARRIER_OPEN 1
#define BARRIER_CLOSE 2
#define BARRIER_STOP 3


/**
 * @brief Initialize the GPIO pins connected to the
 *          barrier
 *
 */
void initializeBoomBarrier()
{
    /* Declaring Pins with Pinmodes */
    pinmode(7, OUTPUT);
    pinmode(8, OUTPUT);
    pinmode(9, OUTPUT);
    /* No relay activated */
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
}


/**
 * @brief Actuate the boom barrier according to the status.
 *
 * @param status Status of the boom barrier (open, close, stop)
 * @param relayOn Turn on of off the relay.
 */
void actuateBoomBarrier(const int status, bool relayOn)
{
    /* Checking for Condition */
    if (status == BARRIER_OPEN && relayOn) {
        /* If true Actuate the Open relay */
        prtinf("Opening....\n");
        digitalWrite(7, HIGH);

    } else if (status == BARRIER_CLOSE && relayOn) {
        /* If true Actuate the Close relay */
        prtinf("Closing....\n");
        digitalWrite(8, HIGH);

    } else if (status == BARRIER_STOP  && relayOn) {
        /* If true Actuate the Stop relay */
        prtinf("Stopping....\n");
        digitalWrite(9, HIGH);

    } else {
        /* If no condition, no relay activated */
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
    }
}
