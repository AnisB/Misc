#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <cl.h>
#endif

#include <iostream>
#include <fstream>
#include <ctime>

#define PI 3.14159265359
const int count = 30;

int main()
{
	// Initiating opencl
	cl_device_id device_id;
	cl_int err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_ALL, 1, &device_id, NULL);
    if (err != CL_SUCCESS)
    {
        std::cout<<"Error in device."<<std::endl;
        return EXIT_FAILURE;
    }
    cl_context context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
  	if (!context)
    {
        std::cout<<"Error in context."<<std::endl;
        return EXIT_FAILURE;
    }
    cl_command_queue commands = clCreateCommandQueue(context, device_id, 0, &err);
    if (!commands)
    {
        std::cout<<"Error in command queue."<<std::endl;
        return EXIT_FAILURE;
    }
	std::ifstream in("transpMatrix.cl");
	std::string contents((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    const char* kernelSource = contents.c_str();
    cl_program program = clCreateProgramWithSource(context, 1, &kernelSource, NULL, &err);
    if (!program)
    {
        std::cout<<"Error in program."<<std::endl;
        return EXIT_FAILURE;
    }
	err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        size_t len;
        char buffer[2048];
        std::cout<<"Error in compiling the opencl program."<<std::endl;
        clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
        std::cout<<buffer<<std::endl;
        return EXIT_FAILURE;
    }
    cl_kernel kernel = clCreateKernel(program, "simplecl", &err);
    if (!kernel || err != CL_SUCCESS)
    {
        std::cout<<"Error in kernel "<<err<<std::endl;
        return EXIT_FAILURE;
    }

    // Data to compute
    float* data =  new float[count*count];

    for(int i = 0; i < count; ++i)
    {
        for(int j = 0; j < count; ++j)
        {
            data[i*count+j] = rand()%10;
            std::cout<<data[i*count+j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    // Creating communication buffers
    cl_mem input = clCreateBuffer(context,  CL_MEM_READ_ONLY,  sizeof(float) * count*count, NULL, NULL);
    cl_mem output = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(float) * count*count, NULL, NULL);

	if (!input || !output)
    {
        std::cout<<"Error in allocation."<<std::endl;
        return EXIT_FAILURE;
    }  

    // Copy data to input buffer
    err = clEnqueueWriteBuffer(commands, input, CL_TRUE, 0, sizeof(float) * count*count, data, 0, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        std::cout<<"Error in copy."<<std::endl;
        return EXIT_FAILURE;
    }

 	err = 0;
    err  = clSetKernelArg(kernel, 0, sizeof(int), &count);
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &input);
    err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &output);
    if (err != CL_SUCCESS)
    {
        std::cout<<"Error in argument."<<std::endl;
        return EXIT_FAILURE;
    }
    size_t local[] = {1,1};
    size_t global[] = {10,10};
    // err = clGetKernelWorkGroupInfo(kernel, device_id, CL_KERNEL_WORK_GROUP_SIZE, sizeof(local), &local, NULL);
    // if (err != CL_SUCCESS)
    // {
    //     std::cout<<"Error in getting loal."<<std::endl;
    //     return EXIT_FAILURE;
    // }
    err = clEnqueueNDRangeKernel(commands, kernel, 2, NULL, global, local, 0, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        std::cout<<"Error in pushing to queue "<<err<<std::endl;
        return EXIT_FAILURE;
    }
    clFinish(commands);
    // Is done now

    err = clEnqueueReadBuffer( commands, output, CL_TRUE, 0, sizeof(float) * count*count, data, 0, NULL, NULL );  
    if (err != CL_SUCCESS)
    {
       std::cout<<"Error in reading back."<<std::endl;
       return EXIT_FAILURE;
    }

    for(int i = 0; i < count; ++i)
    {
        for(int j = 0; j < count; ++j)
        {
            std::cout<<data[i*count+j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
	return 0;
}