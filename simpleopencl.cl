__kernel void simplecl(__global float* input, __global float* output)                                           
{                                                                      
	int i = get_global_id(0);                                           
	output[i] = sin(input[i]);  
}