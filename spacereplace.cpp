// Write a method to replace all spaces in a string with ‘%20’

#include <iostream>
#include <algorithm>

int main()
{
	char s[] = "a b cfjenfj fe";
	int size = sizeof(s);
	size_t n = std::count(s, s +size, ' ');
	char* newChar = new char[size+2*n];
	int defferedIndex = size+2*n-1;
	for (int i = size-1; i >= 0; --i)
	{
		if(s[i]==' ')
		{
			newChar[defferedIndex--] = '0';
			newChar[defferedIndex--] = '2';
			newChar[defferedIndex] = '%';
		}
		else
		{
			newChar[defferedIndex] =s[i];
		}
		defferedIndex--;
	}
	newChar[size+2*n] = '\0';
	std::cout<<s<<std::endl;
	std::cout<<newChar<<std::endl;
	delete [] newChar;
	return 0;
}