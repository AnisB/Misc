#include <iostream>

#define EMPTY_STACK 1
template <typename T>
struct TStackNode
{
	TStackNode()
	: val()
	, next(NULL)
	{

	}
	TStackNode(const T& parT)
	: val(parT)
	, next(NULL)
	{

	}
	T val;
	TStackNode<T>* next;
};
template <typename T>
class TStack
{
public:
	TStack()
	: FTop(NULL)
	{

	}
	~TStack()
	{
		while(FTop!=NULL)
		{
			TStackNode<T>* next = FTop->next;
			delete FTop;
			FTop = next; 
		}
	}
	void push(T parT)
	{
		TStackNode<T>* newTop = new TStackNode<T>(parT);
		newTop->next = FTop;
		FTop = newTop;
	}
	T pop()
	{
		if(FTop!=NULL)
		{
			TStackNode<T>* head = FTop;
			T retVal = head->val;
			FTop = FTop->next;
			delete head;
			return retVal;
		}
		throw(EMPTY_STACK);
	}
protected:
	TStackNode<T>* FTop;
};

int main()
{
	TStack<double> stack;
	stack.push(3.0);
	stack.push(4.0);
	stack.push(5.0);

	for(int i = 0; i < 3 ; ++i)
	{
		std::cout<<stack.pop()<<std::endl;
	}	
	return 0;
}