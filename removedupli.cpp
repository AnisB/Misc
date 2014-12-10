// Design an algorithm and write code to remove the duplicate characters in a string
// without using any additional buffer. NOTE: One or two additional variables are fine.
// An extra copy of the array is not.
// #include <iostream>

// void removeDuplicates(char parOutString[], int size)
// {
// 	int currentEnd = size;
// 	for(int i = 0; i < currentEnd; i++)
// 	{
// 		int j = 0;
// 		for(int j = 0 ; j < i; ++j )
// 		{
// 			if(parOutString[i]==parOutString[j])
// 			{
// 				parOutString[i] = parOutString[currentEnd-1];
// 				currentEnd--;
// 				j =0;
// 			}
// 		}
// 	}
// 	parOutString[currentEnd]='\0';
// }

// int main ()
// {
// 	char stringToProcess[] = "directionaldipolesubsurfacescatteringdistributionfunctionxx";
// 	std::cout<<stringToProcess<<" "<<sizeof(stringToProcess)-1<<std::endl;
// 	removeDuplicates(stringToProcess, sizeof(stringToProcess)-1);
// 	std::cout<<stringToProcess<<std::endl;
// 	return 0;
// }

#include <iostream>

void removeDuplicates(char parOutString[], int size)
{
	bool flag[26];
	for(int i = 0 ; i < 26; ++i)
	{
		flag[i] = false;
	}

	int currentEnd = size;
	for(int i = 0; i < currentEnd; i++)
	{
		int charIndex = parOutString[i]-'a';
		while(flag[charIndex] && i < currentEnd)
		{
			parOutString[i] = parOutString[currentEnd-1];
			currentEnd--;
			charIndex = parOutString[i]-'a';
		}
		flag[charIndex] = true;
	}
	parOutString[currentEnd] = '\0';
}

int main ()
{
	char stringToProcess[] = "directionaldipolesubsurfacescatteringdistributionfunctionxx";
	std::cout<<stringToProcess<<" "<<sizeof(stringToProcess)-1<<std::endl;
	removeDuplicates(stringToProcess, sizeof(stringToProcess)-1);
	std::cout<<stringToProcess<<std::endl;
	return 0;
}