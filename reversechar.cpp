//Write code to reverse a C-Style String. (C-String means that “abcd” is represented as
//five characters, including the null character.
#include <iostream>

void stringToReverse(char* toreverse, int size)
{
	if(size < 2)
		return;
	for(int i = 0; i < size/2; ++i)
	{
		char tmp = toreverse[i];
		toreverse[i] = toreverse[ size-1 -i];
		toreverse[size-1 - i] = tmp;
	}
}

int main()
{
	char toreverse[] = "lookatmedude";
	std::cout<<toreverse<<std::endl;
	stringToReverse(toreverse, sizeof(toreverse)-1);
	std::cout<<toreverse<<std::endl;
	return 0;
}