#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getNumberOfTests(FILE *inputFile);
void readMatrix(FILE *inputFile, int *rows, int *cols, int ***test);


#endif