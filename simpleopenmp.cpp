#define PI 3.14159265359
const int count = 100;
#include <stdio.h>
#include <math.h>
#include <omp.h>
int main()
{

    float *data =  new float[count];
    for (int i = 0; i < count; ++i)
    {
    	data[i] = i*PI/(float)(count-1);
    }
    #pragma omp parallel
    for(int i = 0; i < count; ++i)
    {
    	data[i] = sin(data[i]);
    }
	return 0;
}