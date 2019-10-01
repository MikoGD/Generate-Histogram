#ifndef GETIO
    #define GETIO

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    
    typedef enum isNatNumCode {valid, negative, float_num, not_number, empty} isNatNumCode; 

    void displayErrorMessage(isNatNumCode);
    void getInput(char *, size_t *);

    isNatNumCode isNatNum(char *);
#endif
