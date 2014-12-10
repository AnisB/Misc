// 6 Given an image represented by an NxN matrix, where each pixel in the image is 4
// bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

#include <iostream>

void rotate(int matrix[], int size)
{
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j< size-i; ++j)
		{
			int tmp = matrix[i*size+j];
			std::cout<<i*size+j<<" "<<(size)*(j+1)-1-i<<std::endl;
			matrix[i*size+j] = matrix[(size)*(j+1)-1-i];
			matrix[(size)*(j+1)-1-i] = tmp;
		}
	}
}

int main()
{
	int m[]= {1,2,3,4,5,6,7,8};
	int size = 3;
	rotate(m, size);
	for(int i =0; size*size; ++i)
	{
		std::cout<<m[i]<<" ";
	}
	std::cout<<std::endl;
	return 0;
}