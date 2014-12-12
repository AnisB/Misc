#include <iostream>

void dude( void* coucou, int sizeX, int sizeY)
{
        float* buf = (float*)coucou;
        for(int i = 0; i < sizeY; ++i)
        {
	        for(int j = 0; j < sizeX; ++j)
	        {
	        	std::cout<<buf[i*sizeY+j]<<" ";
	        }
	        std::cout<<std::endl;
        }

}
int main()
{
        float buf [2][2] = {{1,2},{3,4}};
        dude((void*)buf, 2, 2);
        return 0;
}