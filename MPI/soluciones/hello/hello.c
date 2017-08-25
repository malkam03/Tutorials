#include <mpi.h>
#include <stdio.h>
int main(int argc, char** argv) {
	int world_size, rank, name_len;
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	MPI_Init(NULL, NULL);// Inicializa el ambiente MPI
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);// Guarda la cantidad de procesos
   	MPI_Comm_rank(MPI_COMM_WORLD, &rank);// Guarda el número del rank
	MPI_Get_processor_name(processor_name, &name_len);// Guarda el nombre del procesador
	printf("Hola CIC desde el procesador %s, rank %d"
		" de %d procesos\n",
		processor_name, rank, world_size);//Imprime el mensaje
	MPI_Finalize(); // Finaliza el ambiente MPI.
}

