#include <iostream>
int addNoPlus(int a, int b)
{
	while(b)
	{
		int c = a^b;
		b = (a&b)<<1;
		a=c;
	}
	return a;
}
int main()
{
	int a,b;
	std::cin>>a;
	std::cin>>b;
	int c = addNoPlus(a,b);
	std::cout<<a<<" + "<<b<<" = "<<c<<std::endl;
	return 0;
}