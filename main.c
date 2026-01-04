#include <stdio.h> // This is to be able to use the printf functiona nd the rest
#include <stdbool.h>
#include <stdlib.h>
#include <time.h> // This is because we'll use a time function
#include <unistd.h> // This is to be able to run a unix command: sleep

int main(){

    /*
        First is to declare some variables: 
        1. a variable of datatype time_t to store the seconds
        2. a boolean variable to use for the while loop
        3. a struct pointer variable of tm struct
     */
    time_t seconds_from_start = 0; //to clear any unwanted data from prev prog.
    bool isRunning = true;
    struct tm *pTime = NULL;
    
    /*Declare the while loop to run every 1 sec*/
    while (isRunning)
    {
        time(&seconds_from_start);
        pTime = localtime(&seconds_from_start);
        
        printf("%02d:%02d:%02d\n\n", pTime->tm_hour, pTime->tm_min, pTime->tm_sec);

        sleep(1);
    }
    

    printf("This is the Digital clock");
    return 0;
}