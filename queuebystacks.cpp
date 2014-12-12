#include <iostream>

#define EMPTY_STACK 1
#define EMPTY_QUEUE 2

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
class TInefficientQueue
{
public:
	TInefficientQueue()
	: FMain()
	, FReversing()
	{

	}
	~TInefficientQueue()
	{
		
	}
	void push(T parT)
	{
		FMain.push(parT);
	}
	T peek()
	{
		if(FMain.canPop())
		{
			while(FMain.canPop())
			{
				T val = FMain.pop();
				FReversing.push(val);
			}
			T ret = FReversing.pop();
			while(FReversing.canPop())
			{
				T val = FReversing.pop();
				FMain.push(val);
			}
			return ret;
		}
		throw(EMPTY_QUEUE);
		return T();
	}
protected:
	TStack<T> FMain;
	TStack<T> FReversing;
};
int main()
{
	TInefficientQueue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);

	std::cout<<queue.peek()<<std::endl;
	std::cout<<queue.peek()<<std::endl;
	std::cout<<queue.peek()<<std::endl;
	std::cout<<queue.peek()<<std::endl;
	std::cout<<queue.peek()<<std::endl;
	return 0;
}