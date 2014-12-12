#include <iostream>
void printMatrix(float**& parBuff, size_t sizeBuf)
{
	for(int i = 0; i < sizeBuf; ++i)
	for(int j = 0; j < sizeBuf; ++j)
	{
		std::cout<<i<<" "<<j<<std::endl;
		std::cout<<parBuff[i][j]<<" "; 
	}
	std::cout<<std::endl;
}
int main()
{	
	float buf [3][3] ={{1,2,3},{4,5,6},{7,8,9}};
	printMatrix((float**)((void*)buf), 3);
	return 0;
}