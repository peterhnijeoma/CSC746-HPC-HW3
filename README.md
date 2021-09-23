# vector-matric multiplication


# Build instructions 

 from the code directory

1. on class VM

% mkdir build  
% cd build  
% cmake ../
% make


2. on Cori@NERSC

a. get an interactive KNL node:

% salloc --nodes 1 --qos interactive --time 01:00:00 --constraint knl --account m3930

b. change cmake version:
% module load cmake

c. swap Programming environment:
% module swap PrgEnv-intel PrgEnv-gnu

% mkdir build  
% cd build  
% cmake ../
% make


# Run instructions - from build directory

1. for basic VMM

% ./benchmark-basic

2. for Parallel VMM

% export OMP_SCHEDULE=<specify a schedule> [valid value is: static or dynamic]

% export OMP_NUM_THREADS=<concurrency level> [valid value is: 1,2,4,8,16,32, or 64]

% ./benchmark-openmp

3. for CBLAS VMM

% ./benchmark-blas

Note:
 % is the Linux prompt.

#eof
