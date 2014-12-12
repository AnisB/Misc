#include <iostream>

void computeBinary(int ref[], int* output, int size, int index)
{
	if(size==0)
		return;
	if(size==1)
	{
		output[index-1] = ref[size-1];
		return;
	}
	int center = size/2;
	output[index-1] = ref[center-1];
	computeBinary(ref, output, center-1, 2*index);
	computeBinary(ref+center, output, size-center, 2*index+1);
}

int main()
{
	int array[] = {1, 4, 5, 9, 11, 66,77, 434,555, 646};
	int nbElements = sizeof(array)/sizeof(int);
	int* binary = new int[2*nbElements];
	std::cout<<nbElements<<std::endl;
	computeBinary(array, binary, nbElements	, 1);
	for(int i = 0; i < 2*nbElements; ++i)
	{
		std::cout<<binary[i]<<" ";
	}
	std::cout<<std::endl;
	return 0;
}