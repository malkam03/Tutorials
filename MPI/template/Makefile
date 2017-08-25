#define here the Matrix SIZE
MATRIX_SIZE=10000

MPICC=mpicc
CFLAGS=-O3 -g -I./ -DSIZE=$(MATRIX_SIZE)
CFDEBUG=-O0 -g -DDEBUG -DSIZE=$(MATRIX_SIZE) -I./

all: par_identity_ser_io_noblocking.x par_identity_ser_io_blocking.x par_identity_par_io.x

par_identity_ser_io_blocking.x: IO_utils.o par_identity.c
	$(MPICC) -o $@ $(CFLAGS) IO_utils.o par_identity.c -DSERIALIZED_IO_BLOCKING

par_identity_ser_io_noblocking.x: IO_utils.o par_identity.c
	$(MPICC) -o $@ $(CFLAGS) IO_utils.o par_identity.c -DSERIALIZED_IO_NOBLOCKING

par_identity_par_io.x: IO_utils.o par_identity.c
	$(MPICC) -o $@ $(CFLAGS) IO_utils.o par_identity.c -DPARALLEL_IO

par_identity.o: par_identity.c IO_utils.h
	$(MPICC) -c $(CFLAGS) par_identity.c

IO_utils.o: IO_utils.c IO_utils.h
	$(MPICC) -c $(CFLAGS) IO_utils.c

debug:	
	$(MPICC) -o par_identity_debug.x $(CFLAGS_DEBUG) IO_utils.c par_identity.c

clean:
	rm *.dat *.o *~ *.x
