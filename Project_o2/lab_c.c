/****************************************************************************
Lab 2 student file

 To enable gdb logging
   gdb <binary>
   set logging file <file>
   set logging overwrite on
   set logging on

         gcc -std=c99  -g -O0 lab_d.c -o lab_d

 10/05/2019 R. Repka    Initial release
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    char *text_p;        // do not change

    /*------------------------------------------------------------------------
      String with Malloc
    ------------------------------------------------------------------------*/
    // char is 1 byte, so sizeof(char) * 12 gives 12 bytes
    text_p = (char *)malloc(12);
    if (text_p == NULL) {
        perror("ERROR: malloc failed");
        return 1;  // Exit the program if memory allocation fails
    }

    strncpy(text_p, "CMPE380 lab malloc try 1.", sizeof(text_p)-1);

    printf("'%s'", text_p);
    /*------------------------------------------------------------------------
          String with realloc
     ------------------------------------------------------------------------*/
    text_p = (char *)realloc(text_p, 20);
    if (text_p == NULL) {
        perror("ERROR: malloc failed");
        return exit;  // Exit the program if memory allocation fails
    }

    strncat(text_p, "--Realloc", 20 - strlen(text_p));
    printf("\n");
    printf("'%s'", text_p);

    free(text_p);
    /*------------------------------------------------------------------------
              String to int/float conversion
    ------------------------------------------------------------------------*/
    char numstr[11] = " 0005.6000 ";
    int integer = atoi(numstr);
    float floatingpoint = atof(numstr);

    printf("\n\n' 0005.6000 ' to integer: %i\n", integer);
    printf("' 0005.6000 ' to integer: %f\n", floatingpoint);

    return 0;
}
