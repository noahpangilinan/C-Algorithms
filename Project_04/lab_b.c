/****************************************************************************
 The purpose of this example is to exercise, creating, using and destroying
 pass by pointer and pass by value data structures

 student version

 gcc -O1 -Wall -std=c99 -pedantic -g  lab_a.c -o lab_a
 valgrind --tool=memcheck --leak-check=yes --track-origins=yes --error-exitcode=99 ./lab_a


 09/09/2019 R. Repka    Minor formatting changes
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*---------------------------------------------------------------------------
  The polynomial data structure contains the number of (size) of the
  allocated array of polynomial coefficients
  e.g     nterms = 4;
          polyCoef = malloc(sizeof(double)*4);
---------------------------------------------------------------------------*/
typedef struct {
    unsigned int nterms;      /* number of terms */
    double *polyCoef;         /* coefficients         */
} Poly;

// Function prototypes
void createPoly(Poly *p, int n);
Poly *createPoly_p(int n);
void destroyPoly(Poly *p);
void destroyPoly_p(Poly *p);
void printPolyRef(Poly *p);
void printPolyVal(Poly data);

int main(int argc, char *argv[]) {
   Poly stackPoly;         // Stack data structure
   Poly *poly_p = NULL;    // Pointer

   // Create and use the data structure
   // Print using pass by pointer AND value
   createPoly(&stackPoly, 10);
   printf("Print by Ref:\n");
   printPolyRef(&stackPoly);
   printf("\nPrint by Val:\n");
   printPolyVal(stackPoly);
   destroyPoly_p(&stackPoly);

   // Create and use the pointer as a data structure NOT using creatPoly_p()
   // Print using pass by pointer AND value
   poly_p = (Poly *)malloc(sizeof(Poly));
   createPoly(poly_p, 10);
   printf("\nPrint by Ref:\n");
   printPolyRef(poly_p);
   printf("\nPrint by Val:\n");
   printPolyVal(*poly_p);
   destroyPoly(poly_p);

   // Create and use the pointer as a data structure using creatPoly_p()
   // Print using pass by pointer AND value
   Poly *newpoly = createPoly_p(10);
   printf("\nPrint by Ref:\n");
   printPolyRef(newpoly);
   printf("\nPrint by Val:\n");
   printPolyVal(*newpoly);
   destroyPoly(newpoly);

   return 0;
}

/*---------------------------------------------------------------------------
  Create a test polynomial using a pointer to the data structure
  Be sure to initialize the elements aka: polyCoef[i]  2.0*i
---------------------------------------------------------------------------*/
void createPoly(Poly *p, int n){
  p->polyCoef = malloc(sizeof(double)*n);
  p->nterms = n;
  for(int i = 0; i < n; i++){
    p->polyCoef[i] = 2.0 * i;
  }
}

/*---------------------------------------------------------------------------
  Create a test polynomial using a pointer to the data structure
---------------------------------------------------------------------------*/
// Destroy data structure based test polynomial
void destroyPoly(Poly *p){
  p->nterms = 0;

  free(p->polyCoef);
  p->polyCoef = NULL;

  free(p);

  p = NULL;
}

/*---------------------------------------------------------------------------
  Create a test polynomial returning a pointer to the data structure
    Be sure to initialize the elements aka: polyCoef[i]  2.0*i
---------------------------------------------------------------------------*/
Poly *createPoly_p(int n){
  Poly *p = (Poly *)malloc(sizeof(Poly));
  p->polyCoef = (double *)malloc(sizeof(double) * n);
  p->nterms = n;
  for (int i = 0; i < n; i++) {
    p->polyCoef[i] = 2.0 * i;
  }
  return p;
}

/*---------------------------------------------------------------------------
  Destroy pointer based test polynomial
---------------------------------------------------------------------------*/
void destroyPoly_p(Poly *p){
  p->nterms = 0;

  free(p->polyCoef);
  p->polyCoef = NULL;

}

/*---------------------------------------------------------------------------
  Prints the polynomial data passing by reference use %3.0f
---------------------------------------------------------------------------*/
void printPolyRef(Poly *p){

  for(int i = 0; i < p->nterms; i++){
    printf("%3.0f ", p->polyCoef[i]);
  }
}

/*---------------------------------------------------------------------------
  Prints the polynomial data passing by value use %3.0f
---------------------------------------------------------------------------*/
void printPolyVal(Poly data){
  for(int i = 0; i < data.nterms; i++){
    printf("%3.0f ", data.polyCoef[i]);
  }
}



