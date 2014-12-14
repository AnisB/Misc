__kernel void simplecl(const int count, __global float* input, __global float* output)                                           
{                                                                      
	int i = get_global_id(0);                                           
	int j = get_global_id(1);     
	__local float tmp [9];

	for(int k = 0; k < 3; ++k)
	{
		for(int l = 0; l < 3 ; ++l)
		{
			tmp[k*3+l] = input[(3*i+k)*count+3*j+l];
		}
	}
	for(int k = 0; k < 3; ++k)
	{
		for(int l = 0; l < 3 ; ++l)
		{
			output[(3*j+k)*count+3*i+l] = tmp[l*3+k];
		}
	}	                        
}


// float* [64] [64][64]