#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/utils.h"

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen() {
    printf("\nPress ENTER to continue...");
    getchar();
    getchar();
}

