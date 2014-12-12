#include <iostream>

template<typename T>
struct TListNode
{
	TListNode(const TListNode& parLN)
	: val(parLN.val)
	, next(parLN.next)
	{

	}
	TListNode(const T& parT)
	: val(parT)
	, next(NULL)
	{

	}
	~TListNode()
	{

	}
	T val;
	TListNode<T>* next;
};

template<typename T>
class TList
{
	public:
	TList()
	: head(NULL)
	{

	}

	~TList()
	{
		TListNode<T>* nodes = head;
		while(nodes!=NULL)
		{
			TListNode<T>* next = nodes->next;
			delete nodes;
			nodes= next;
		}
	}

	void push_back(const T& parElement)
	{
		TListNode<T>* V = new TListNode<T>(parElement);
		if(head==NULL)
		{
			head = V;
			return;
		}
		TListNode<T>* prev = NULL;
		TListNode<T>* ptr = head;
		while(ptr!=NULL)
		{
			prev= ptr;
			ptr =ptr->next;
		}
		prev->next = V;
	}
	void display()
	{
		TListNode<T>* nodes = head;
		while(nodes!=NULL)
		{
			std::cout<<nodes->val<<std::endl;;
			nodes= nodes->next;
		}
	}
protected:
	TListNode<T>* head;

};
int main()
{
	TList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.display();
	return 0;
}