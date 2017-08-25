#include "IO_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

double seconds(){

    struct timeval tmp;
    double sec;
    gettimeofday( &tmp, (struct timezone *)0 );
    sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
    return sec;
}

void print_matrix( double * mat, int loc_size ){
  
  int i, j;
  
  // print on standard output a slice of a matrix
  for( i = 0; i < loc_size; i++ ){
    for( j = 0; j < SIZE; j++ ){
      fprintf( stdout, "\t%.3g", mat[ i * SIZE + j ]);
    }
    printf("\n");
  }

}

void print_matrix_file( FILE * fp, double * mat, int loc_size ){

  fwrite( mat, SIZE * loc_size, sizeof( double ), fp );
}

void par_print_matrix_binary_file( double * mat, int loc_size, int rank, int npes ){

  long offset = 0; 
  int rest = SIZE % npes;
  FILE * fp;

  fp = fopen( "identity_par_IO.dat", "w+b" );
  
  // look the man page of fseek and compute the offset accordingly 
  if( rank < rest ) offset = (long) SIZE * loc_size * rank;
  else offset = (long) SIZE * ( loc_size * rank + rest );

  // the function fseek is used to set the correct position of the file pointer 
  fseek( fp, offset * sizeof( double ), SEEK_SET );
  print_matrix_file( fp, mat, loc_size );

  fclose( fp );
}

void serialized_print_distributed_matrix_binary_file_blocking_sendrecv( double * mat, int loc_size, int rank, int npes ){

  int count = 0;
  int rest = SIZE % npes;
  FILE * fp;

  // Rank 0 first prints his slice of matrix and then it receives from other processes
  if( rank == 0 ){

    fp = fopen( "identity_ser_IO_blocking.dat", "w+b" );
    print_matrix_file( fp, mat, loc_size );

    for( count = 1; count < npes; count++ ){

      if( count == rest) loc_size = loc_size - 1;
      
       MPI_Recv( mat, loc_size * SIZE, MPI_DOUBLE, count, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
       print_matrix_file( fp, mat, loc_size );
    }
    
    fclose( fp );
    
  } else {

    /* Send local data to Rank 0 */
    MPI_Send( mat, loc_size * SIZE, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD );
  }

}

void serialized_print_distributed_matrix_binary_file_noblocking_sendrecv( double * mat, int loc_size, int rank, int npes ){

  int count = 0, loc_size_prec = loc_size;
  int rest = SIZE % npes;
  FILE * fp;
  double * buf, * tmp;
  MPI_Request request;

  // Rank 0 first prints his slice of matrix and then it receives from other processes
  if( rank == 0 ){

    buf = (double *) malloc( loc_size * SIZE * sizeof( double ) );
    fp = fopen( "identity_ser_IO_noblocking.dat", "w+b" );

      for( count = 1; count < npes; count++ ){

	  if( count == rest ) loc_size = loc_size - 1;
	  if( count == rest + 1 ) loc_size_prec = loc_size_prec - 1;

	  MPI_Irecv( buf, loc_size * SIZE, MPI_DOUBLE, count, 0, MPI_COMM_WORLD, &request);
	  print_matrix_file( fp, mat, loc_size_prec );
	  MPI_Wait( &request, MPI_STATUS_IGNORE );
	  tmp = mat;
	  mat = buf; 
	  buf = tmp;
      }
      print_matrix_file( fp, mat, loc_size );
    
    fclose( fp );
    
  } else {

    /* Send local data to Rank 0 */
    MPI_Send( mat, loc_size * SIZE, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD );
  }

}


void serialized_print_distributed_matrix_std_output( double * mat, int loc_size, int rank, int npes ){

  int count = 0;
  int rest = SIZE % npes;

  // Rank 0 first prints his slice of matrix and then it receives from other processes
  if( rank == 0 ){

    print_matrix( mat, loc_size );

      for( count = 1; count < npes; count++ ){

	  if( count == rest) loc_size = loc_size - 1;

	  MPI_Recv( mat, loc_size * SIZE, MPI_DOUBLE, count, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	  print_matrix( mat, loc_size );
      }
  } else {

    /* Send local data to Rank 0 */
    MPI_Send( mat, loc_size * SIZE, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD );
  }

}

