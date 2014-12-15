#include <mpi.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
	int size, rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int nbElem = 100;
	int length = nbElem / size;
	if(rank==0)
	{
		float* buff = (float*)malloc(sizeof(float)*nbElem);
		float* buff2 = (float*)malloc(sizeof(float)*nbElem);
		for(int i = 0; i < nbElem; ++i)
		{
			buff[i] = 3.14*i/(float)(nbElem-1);
		}		
				
		//printf("Coucou adrien je suis ton père %i on %i\n", rank, size);
		MPI_Request *requests=  (MPI_Request*)malloc(sizeof( MPI_Request)*(size-1));
		MPI_Status *statuts=  (MPI_Status*)malloc(sizeof( MPI_Status)*(size-1));
		for(int i = 1; i < size; ++i)
		{
			MPI_Isend(buff+(i-1)*length, length, MPI_FLOAT, i, 0, MPI_COMM_WORLD, requests+i-1); 
		} 
		MPI_Waitall(size-1, requests, statuts);
		int beginDad = length*(size-1)+1;
		//printf("Dad is computing %i %i\n", beginDad, nbElem-1);
		for(int i =beginDad-1; i < nbElem; ++i)
		{
			buff2[i] = sin(buff[i]);
		}
		for(int i = 1; i < size; ++i)
		{
			MPI_Irecv(buff2+(i-1)*length, length, MPI_FLOAT, i, 0, MPI_COMM_WORLD, requests+i-1); 
		}
		MPI_Waitall(size-1, requests, statuts);
		for(int i =0; i < nbElem; ++i)
		{
			printf("%f %f\n",buff[i],buff2[i]);
		}
		free(requests);
		free(status);
		free(buff);
		free(buff2)
	}
	else	
	{
		//printf("hi my name is adrien num %i on %i\n", rank, size);
		MPI_Request request;
		MPI_Status statut;
		float* buff = (float*)malloc(sizeof(float)*length);
		MPI_Irecv(buff, length, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, &request);
		MPI_Waitall(1, &request, &statut);
		for(int i = 0; i < length; ++i)
		{
			buff[i] = sin(buff[i]);
		}
		MPI_Isend(buff, length, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, &request);
		MPI_Waitall(1, &request, &statut);
		free(buff);
	}
	MPI_Finalize();
	return 0;
}
