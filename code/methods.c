#include <stdio.h>
#include <stdlib.h>

void copyArray(int * arrayToCopy, int * copyingArray, int arrayToCopyLength) {
    for (int i = 0; i < arrayToCopyLength; i++) {
        *(copyingArray + i) = *(arrayToCopy + i);
    }
}