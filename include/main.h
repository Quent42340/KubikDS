#ifndef MAIN_H
#define MAIN_H

extern int i;

#include <nds.h> // Include NDS header
#include <fat.h> // File system

// Some other headers
#include <time.h> // Used for initializing random seed
#include <stdio.h> // Printing text
#include <malloc.h> // Memory allocation
#include <math.h> // Math functions
#include <string.h> // String functions

#define WAIT_FOR_START(text) { printf(text); while(!(keysDown() & KEY_START)) { scanKeys(); swiWaitForVBlank(); } }

#endif // MAIN_H
