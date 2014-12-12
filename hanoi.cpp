#include <iostream>

#define EMPTY_STACK 1
#define HANOI_ERROR 2

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
		if(FTop!=NULL)
		if(parT>FTop->val)
			throw(HANOI_ERROR);
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
	void display()
	{
		TStackNode<T>* current = FTop;
		while(current!=NULL)
		{
			std::cout<<current->val<<"->";
			current = current->next;
		}
		std::cout<<"NIL"<<std::endl;
	}
protected:
	TStackNode<T>* FTop;
};

void moveTop(TStack<int>* parStacks, int origin, int dest)
{
	parStacks[dest].push(parStacks[origin].pop());
}

void hanoi(TStack<int>* parStacks, int origin, int dest, int index)
{
	for( int i = 0; i < 3; ++i )
	{
		std::cout<<"Tower "<<i<<" ";
		parStacks[i].display();
	}
	if(index==0)
	{
		moveTop(parStacks, origin, dest);
		return;
	}
	hanoi(parStacks, origin, 3-origin-dest, index-1);
	moveTop(parStacks, origin, dest);
	hanoi(parStacks, 3-origin-dest, dest, index-1);
}

int main()
{
	TStack<int> stacks[3];
	stacks[0].push(4);
	stacks[0].push(3);
	stacks[0].push(2);
	stacks[0].push(1);
	for( int i = 0; i < 3; ++i )
	{
		std::cout<<"Tower "<<i<<" ";
		stacks[i].display();
	}
	std::cout<<"Hanoi"<<std::endl;
	hanoi(stacks, 0, 1, 3);
	std::cout<<"Done"<<std::endl;
	for( int i = 0; i < 3; ++i )
	{
		std::cout<<"Tower "<<i<<" ";
		stacks[i].display();
	}
	return 0;
}