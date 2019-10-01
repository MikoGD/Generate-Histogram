#include <stdio.h>
#include "getio.h"

#define NBYTES 32

int main ()
{
    char *userInput;
    size_t nBytes = NBYTES;
    userInput = (char *) malloc(nBytes);

    getInput(userInput, &nBytes);
    printf("You entered: %s\n", userInput);

    return 0;
}//END main()
