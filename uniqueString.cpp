// Implement an algorithm to determine if a string has all unique characters. What if you
// can not use additional data structures?

// #include <iostream>
// #include <unordered_map>

// void getUniques(const std::string& parString, std::unordered_map<char, bool>& outUniques)
// {
// 	size_t stringSize = parString.size();
// 	for(int i = 0; i < stringSize; ++i)
// 	{
// 		bool& val = outUniques[parString[i]];
// 		val=val?false:true;
// 	}
// }
// int main()
// {
// 	std::string stringL;
// 	std::cin>>stringL;
// 	std::unordered_map<char,bool> uniques;
// 	getUniques(stringL, uniques);
// 	for(std::unordered_map<char,bool>::iterator it = uniques.begin(); it != uniques.end(); it++)
// 	{
// 		std::cout<<it->first<<std::endl;
// 	}
// 	return 0;
// }

#include <iostream>
#include <unordered_map>

void printBinary(uint64_t val)
{
	int counter = 0;
	while (val) 
	{
	    if (val & 1)
	    	std::cout<<(char)(counter+'a')<<std::endl;
	    
	    val >>= 1;
	    counter++;
	}
}
void getUniques(const std::string& parString, uint64_t& p0, uint64_t& u0)
{
	size_t stringSize = parString.size();
	for(int i = 0; i < stringSize; ++i)
	{
		char charVal = parString[i]-'a'; 
		{
			uint64_t dec = 0x1<<(charVal);
			int val = p0&dec;
			if(val)
			{
				u0 = u0&(0xFFFFFFFE<<(charVal-64));
			}
			else
			{
				u0 = u0|(0x1<<(charVal-64));
			}
		}
	}
}
int main()
{
	std::string stringL;
	std::cin>>stringL;
	uint64_t p0;
	uint64_t u0;
	getUniques(stringL, p0, u0);
	printBinary(u0);
	return 0;
}