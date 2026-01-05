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
    
    /*Declare the while loop to run every 1 sec*/
    printf("This is the Digital clock\n\n");
    time_t seconds_dump;
    bool isTrue = true;
    struct tm *pTime = NULL;

    while (isTrue)
    {
        /* Below code runs while isTrue value is True */
        time(&seconds_dump);
        pTime = localtime(&seconds_dump);

        printf("\r%02d:%02d:%02d", pTime->tm_hour, pTime->tm_min, pTime->tm_sec);
        fflush(stdout); // This line will flush the buffer as it's the time is not being updated, it was just stuck on one stdout line. So adding this mean the \r is handled by the C standard library (stdio) and not the terminal ide nor the editor line ending...
        sleep(1);
    }
    

    return 0;
}