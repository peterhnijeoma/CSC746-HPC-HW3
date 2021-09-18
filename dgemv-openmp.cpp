/*
 * This routine performs a dgemv operation 
 * Y :=  A * X + Y in parallel using OpenMP
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by
 *  1 vectors.
 * On exit, A and X maintain their input values.
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

const char* dgemv_desc = "OpenMP dgemv.";

void my_dgemv(int n, double* A, double* x, double* y)
{

   /* #pragma omp parallel
   {
      int nthreads = omp_get_num_threads();
      int thread_id = omp_get_thread_num();
      printf("Hello world: thread %d of %d checking in. \n", thread_id, nthreads);
   } */

   // insert your dgemv code here. you may need to create additional parallel regions,
   // and you may want to comment out the above parallel code block that prints out
   // nthreads and thread_id so as to not taint your timings

   #pragma omp parallel for
   for (int i = 0; i < n * n; i += n) // iterate for n rows
   {
      //#pragma omp parallel for reduction (+:y)
      for (int j = 0; j < n; j++)
      {
         y[i] += A[i+j] * x[j];   // A is in row major
      }
   }
}

