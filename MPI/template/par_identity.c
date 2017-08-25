/*
 * This code was used for a lab-session at the HPC school in Cenat 2017.
 * It is not meant for efficient production but it is only a training example
 *
 * The code implements initialization and parallel I/O of an identity matrix
 *
 * Author: I. Girotto
 * E-mail: igirotto@ictp.it
 * Last update: July 2017
 *
 *
 * README
 * 
 * Implement a parallel initialization of an Identity matrix of size (SIZZE) among npes processes
 *
 * The code should handle the case SIZE is not multiple of npes.
 *
 * Implement the following parallel I/O:
 *
 * 1) print the whole matrix on standard output if SIZE <= 10 and the DEBUG macro is enabled
 *
 * 2) print the matrix on a binary file if SIZE > 10 with serialized I/O on process 0 using blocking send and recv
 *
 * 3) print the matrix on a binary file if SIZE > 10 with serialized I/O on process 0 overlapping I/O and communication
 * 
 * 4) print the matrix on a binary file in parallel
 *
 * 5) mesure the I/O bandwidth for case 2, 3, and 4.
 *
 */

// header file including utility IO functions
#include "IO_utils.h"

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] ){

  int npes, rank; // number of processing elements and process Id, rispectively
  int loc_size; // local number of rows of the identity matrix
  int i, j; // rows and columns indexes
  int i_global; // global index of rows
  double * mat; // identity matrix
  int rest = 0; // resting elements in the matrix distribution among process 
  int offset = 0; // number of resting elements distributed before rank (only if rank >= rest)

  double t_start = 0, t_end = 0;

  MPI_Init( &argc, &argv );
  MPI_Comm_size( MPI_COMM_WORLD, &npes );
  MPI_Comm_rank( MPI_COMM_WORLD, &rank );

  if( SIZE < npes ){
    fprintf( stderr, "\n\n\t SIZE(%d) < npes(%d), configuration not supported. Program terminated ...", SIZE, npes );
    MPI_Abort( MPI_COMM_WORLD, 1 );
  }
  
  // Compute the Number of rows that are assigned to each processor, including rests 
  // *** TO DO ***

  // Compute the local size and the offset 
  // The offset is meant as the number of resting elements assigned to all processes < rank (only if rank >= rest)
  // Distribution of resting element is meant starting from prosess 0 and assigning one additional element 
  // To all processes where rank is < rest
  // *** TO DO ***

  // allocate the distributed Matrix 
  // *** TO DO ***

  // Initilize the identity distributed matrix 
  // *** TO DO ***

#ifdef DEBUG

  if( SIZE <= 10 )   serialized_print_distributed_matrix_std_output( mat, loc_size, rank, npes );

#endif // DEBUG

  t_start = seconds();
  
#ifdef SERIALIZED_IO_BLOCKING

  serialized_print_distributed_matrix_binary_file_blocking_sendrecv( mat, loc_size, rank, npes );

#endif // SERIALIZED_IO_BLOCKING

#ifdef SERIALIZED_IO_NOBLOCKING

  serialized_print_distributed_matrix_binary_file_noblocking_sendrecv( mat, loc_size, rank, npes );

#endif // SERIALIZED_IO_NOBLOCKING

#ifdef PARALLEL_IO

  par_print_matrix_binary_file( mat, loc_size, rank, npes );

#endif // PARALLEL_IO

  t_end = seconds();

#ifndef DEBUG

  size_t matrix_byte = ( size_t ) SIZE * ( size_t ) SIZE * sizeof( double );
  double Gbyte = ( ( double ) matrix_byte ) / 1e9;
  double time = t_end - t_start;
  if( rank == 0 )
    fprintf( stdout, "\nIO time = %.3g, Data size (GBytes) = %.3g, IO bandwidth (GBit/s) = %.3g\n\n", time, Gbyte, ( Gbyte * 8 ) / time ); 

#endif

  free(mat);  

  MPI_Finalize();

  return 0;
}


