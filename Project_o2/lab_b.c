/****************************************************************************
Lab 2 student file
 10/05/2019 R. Repka    Initial release
****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*---------------------------------------------------------------------------
  Student data structure
---------------------------------------------------------------------------*/
struct bandMember {
    char f_name[256];
    char l_name[256];
    int  year;
};

union anumber1 { float floating_point; int integer; };
struct anumber2 {float floating_point; int integer;};


int main(int argc, char *argv[]) {
    /*------------------------------------------------------------------------
     *Struct vs Union
    ------------------------------------------------------------------------*/
    union anumber1 aNumber1;

    aNumber1.floating_point = 6.0;
    aNumber1.integer = 5;

    int size = sizeof(aNumber1);
    printf("UNION \nFloat: %f, Int: %i, Size: %i bytes", aNumber1.floating_point, aNumber1.integer, size);

    struct anumber2 aNumber2;
    aNumber2.floating_point = 6.0;
    aNumber2.integer = 5;
    size = sizeof(aNumber2);
    printf("\n\nSTRUCT \nFloat: %f, Int: %i, Size: %i bytes\n", aNumber2.floating_point, aNumber2.integer, size);
    /*---------------------------------------------------------------------------
      Beatles for loop
    ---------------------------------------------------------------------------*/
    typedef struct bandMember band;
    band beatles[] = {
        {"John", "Lennon", 1940},
        {"Paul","McCartney", 1942},
        {"George", "Harrison", 1943},
        {"Ringo", "Starr", 1940}
    };

    const int length = sizeof(beatles) / sizeof(beatles[0]);
    printf("\nBEATLES FOR LOOP:");
    for (int i = 0; i < length; i++) {
        char firstname [sizeof(beatles[i].f_name)];
        char lastname [sizeof(beatles[i].f_name)];
        strncpy(firstname, beatles[i].f_name, sizeof firstname - 1);
        strncpy(lastname, beatles[i].l_name, sizeof lastname - 1);

        printf("\nBeatle %s %s born %i", firstname, lastname, beatles[i].year);
    }
        /*---------------------------------------------------------------------------
          Beatles run on string for loop
        ---------------------------------------------------------------------------*/
    printf("\n\nBEATLES RUN ON STRING:");
        char beatles_firstnames [256] = "";
    unsigned long dest = 256-1;
    for (int i = 0; i < length; i++) {
        unsigned long firstname_size = strlen(beatles[i].f_name);

        strncat(beatles_firstnames, beatles[i].f_name, dest);
        dest -= firstname_size;
    }
    printf("\n%s", beatles_firstnames);
    /*---------------------------------------------------------------------------
        Find "Ringo" index
      ---------------------------------------------------------------------------*/
    printf("\n\nRINGO INDEX:");
    char ringo[sizeof("Ringo")-1] = "Ringo";
    for (int i = 0; i < length; i++) {
        if (strncmp(ringo, beatles[i].f_name, sizeof ringo - 1) == 0) {
            printf("\nThe Ringo index is %i", i);
        }

    }
    /*---------------------------------------------------------------------------
        Count to 255 without char or int and without checking for 255 specifically
      ---------------------------------------------------------------------------*/
    printf("\n\nCOUNTING TO 255:\n");
    uint8_t counter = 1;
    while (counter != 0 ) {
        printf("%i ", counter);
        counter++;
    }
    /*---------------------------------------------------------------------------
        Code guaranteed to create a 64 bit long integer on ANY machine and prove the
        value is 8 bytes long.
      ---------------------------------------------------------------------------*/
    int64_t sixtyfourbitint;
    printf("\n\nSIXTY FOUR BIT INT:");
    unsigned long sizeofsixtyfourbitint = sizeof(sixtyfourbitint);
    printf("\n64 bit long integer size in bytes (using sizeof()): %lu" , sizeofsixtyfourbitint);


}

