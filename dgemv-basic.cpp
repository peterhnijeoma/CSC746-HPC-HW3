/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by
 * 1 vectors.
 * On exit, A and X maintain their input values.
 */

#include <iostream>

const char* dgemv_desc = "Basic implementation of matrix-vector multiply.";
//double cvalue;

void my_dgemv(int n, double* A, double* x, double* y)
{
   printf("vector matrix multiply is starting \n");
   // insert your code here: implementation of basic matrix multiply
   for (int i = 0; i < n; i++) // iterate for n rows
   {
      //cvalue = 0.0;
      for (int j = 0; j < n; j++)
      {
         y[i] += A[i*n +j] * x[j];   // A is in row major
      }
      // y[i] += cvalue;
   }
   printf("vector matrix multiply is done \n");
}
