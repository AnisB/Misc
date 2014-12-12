#define PI 3.14159265359
const int count = 100;
#include <stdio.h>
#include <math.h>
#include <omp.h>

float root(float val)
{
    return sqrt(val);
}

float square(float val)
{
    return (val*val);
}
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
    	float v = root(data[i]);
        data[i] = v*square(data[i]);
    }
	return 0;
}