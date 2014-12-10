//given a number print it in words

//Map of numbers and their form
// From 0 to 9 => 10
// 10 20 30 40 50.. 90 => 9
// 11 12 .. 19 => 9

#include <iostream>
#include <vector>
char numbers[10][100] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
char dizaines[9][100] = {"Ten", "twenty", "thirty", "fourty", "Fifty", "sixty", "seventy", "eighty", "ninety"};

int main(int argc, char** argv)
{
	int number;
	std::cin>>number;
	std::string finalForm;
	if(number<0)
	{
		finalForm+="minus ";
		number*=-1;
	}
	std::vector<int> nbList;
	nbList.push_back(number%10);
	int currentValue = number/10;
	while(currentValue > 0)
	{
		nbList.push_back(currentValue%10);
		currentValue = currentValue/10;
	}
	if(nbList.size()==1)
	{
		std::cout<<numbers[nbList[0]]<<std::endl;
	}
	int counter = nbList.size();
	// while(counter !=0)
	// {
		
	// }
	return 0;
}