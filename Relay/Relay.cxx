/** @file Relay.cxx
 *  @brief Give a description of the file 
 *  
 *  Calculates Temperature, Humidity, Pressure, Altitude 
 *  
 *  @author Allen  
 *  @bug Didn't find any  
 */

/*
 *#####################################################################
 *  Initialization block
 *  ---------------------
 *  This block contains initialization code for this particular file.
 *  It typically contains Includes, constants or global variables used
 *  throughout the file.
 *#####################################################################
 */

/* --- Standard Includes --- */
#include <stdio.h>
#include <stdlib.h>

/* --- Project Includes --- */
#include <shunyaInterfaces.h>


/*
 *#####################################################################
 *  Process block
 *  -------------
 *  Solve all your problems here 
 *#####################################################################
 */

/** 
 *  @brief Description on main
 *  
 *  Initializes GPIO Pins
 *  Checks Condition
 *  to activate the corresponding 
 * Relay
 *
 *  @return 0
 */

void  Relay_Interface(const char Button, bool relay)
{
    
   
    /* Opening mssg */
    printf("----Starting----\n");
    /* Declaring Pins with Pinmodes */
    pinmode(7, OUTPUT);
    pinmode(8, OUTPUT);
    pinmode(9, OUTPUT);

    /* Checking for Condition */
    if(Button=='OPEN' && relay){
        /* If true Actuate the Open relay */
        prtinf("Opening....\n");
         digitalWrite(7, HIGH);
    }
    else if(Button=='CLOSE' && relay){
        /* If true Actuate the Close relay */
        prtinf("Closing....\n");
        digitalWrite(8, HIGH);
    }
    else if(Button=='STOP' && relay){
        /* If true Actuate the Stop relay */
        prtinf("Stopping....\n");
        digitalWrite(9, HIGH);
    }
    else{
        /* If no condition, no relay activated */
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
    }
    

    

    
}
