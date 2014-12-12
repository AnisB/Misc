
// ->|xxxxxx  ->|
// ->|xxxxx B ->|B
// ->|xxxx A ->|B
// ->|xxxxx ->|A
// ->|xxxx B ->|A
// ->|xxx0 ->|AB
// ->|xxx 0 ->|AB
// ->|xxxx 0 ->|A
// ->|xxxxx 0 ->|
// ->|xxxxx ->|0
// ->|xxx ->|0AB
// ...

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
	bool canPop()
	{
		return (FTop!=NULL);
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
		return T();
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


template<typename T>
void push(T val, TStack<T>& stack, TStack<T>& buf)
{
	while(stack.canPop())
	{
		T l = stack.pop();
		if(l<val)
		{
			buf.push(l);
		}
		else
		{
			stack.push(l);
			break;
		}
	}
	stack.push(val);
}

template<typename T>
void sort(TStack<T>& toSort)
{
	TStack<T> buffer;
	while(toSort.canPop())
	{
		T val = toSort.pop();
		push(val, buffer, toSort);
	}
	while(buffer.canPop())
	{
		toSort.push(buffer.pop());
	}

}
int main()
{
	TStack<int> stackToSort;
	stackToSort.push(0);
	stackToSort.push(7);
	stackToSort.push(2);
	stackToSort.push(4);
	stackToSort.push(3);
	stackToSort.push(11);
	stackToSort.push(9);

	stackToSort.display();
	sort<int>(stackToSort);
	stackToSort.display();
	return 0;
}
