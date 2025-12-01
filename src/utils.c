#include <stdio.h>
#include <stdlib.h>
#include "../include/utils.h"

// Clears the console screen
void clearScreen() {
    system("clear");  
}

// Pauses the screen and waits for the user to press ENTER
void pauseScreen() {
    printf("\nPress ENTER to continue...");
    getchar();         
    getchar();    
}    
