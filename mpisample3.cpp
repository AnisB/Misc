#include <mpi.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
	int size, rank;
	MPI_Datatype staircase;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int* buff = (int*)malloc(sizeof(int)*size*size);
	for(int i = 0; i < size; ++i)
	{
		buff[i*size+i]=rank;
	}	
	MPI_Type_vector(size, 1, size+1, MPI_INT, &staircase);
	MPI_Type_commit(&staircase);
	MPI_Gather(buff, 1, staircase, buff, size, MPI_INT, 0, MPI_COMM_WORLD);
	if(rank==0)
	{		
		for(int i =0; i < size; ++i)
		{	
			for(int j =0; j < size; ++j)
			{
				printf("%i ",buff[i*size+j]);
			}
			printf("\n");
		}
	}
	MPI_Finalize();
	return 0;
}
