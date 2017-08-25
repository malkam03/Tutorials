#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

  const int LIMIT = 10;

  // Initialize the MPI environment
  MPI_Init(&argc, &argv);
  // Find out rank, size
  int myRank, world_size;
  MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // We are assuming at least 2 processes for this task
  if (world_size != 2) {
    fprintf(stderr, "World size must be two for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  int ping_pong_count = 0;
  int partner_rank = (myRank + 1) % 2;
  while (ping_pong_count < LIMIT) {
    if (myRank == 0) {
          
      MPI_Send(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD);
      printf("%d sent ping_pong_count %d to %d\n",
             myRank, ping_pong_count, partner_rank);
      MPI_Recv(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD,
               MPI_STATUS_IGNORE);
    } 
    else if(myRank==1) {
      MPI_Recv(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD,
               MPI_STATUS_IGNORE);
      // Increment the ping pong count before you send it 
      ping_pong_count++;
      printf("%d received and incremented ping_pong_count %d from %d\n",
             myRank, ping_pong_count, partner_rank);
      MPI_Send(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD);
    }
  }
  MPI_Finalize();
}