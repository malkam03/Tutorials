#ifndef __IO_UTILS__
#define __IO_UTILS__

// If SIZE is not defined at compile time (see Makefile) defnine here the size of the Matrix
#ifndef SIZE
#define SIZE 10
#endif

double seconds();

void par_print_matrix_binary_file( double * mat, int loc_size, int rank, int npes );
void serialized_print_distributed_matrix_binary_file_blocking_sendrecv( double * mat, int loc_size, int rank, int npes );
void serialized_print_distributed_matrix_binary_file_noblocking_sendrecv( double * mat, int loc_size, int rank, int npes );
void serialized_print_distributed_matrix_std_output( double * mat, int loc_size, int rank, int npes );

#endif
