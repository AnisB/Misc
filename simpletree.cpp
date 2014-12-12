#include <iostream>

template<typename T>
struct TTreeNode
{
	TTreeNode(T parVal)
	: val(parVal)
	, FRightSon(NULL)
	, FLeftSon(NULL)
	{

	}
	TTreeNode()
	: val()
	, FRightSon(NULL)
	, FLeftSon(NULL)
	{

	}
	void orderedInsert(TTreeNode<T>* parNode)
	{
		if(parNode->val<=val)
		{
			if(FRightSon) FRightSon->orderedInsert(parNode);
			else FRightSon = parNode;
		}
		else
		{
			if(FLeftSon) FLeftSon->orderedInsert(parNode);
			else FLeftSon = parNode;
		}
	}
	~TTreeNode()
	{
		if(FRightSon) delete FRightSon;
		if(FLeftSon) delete FLeftSon;
	}
	void display()
	{
		std::cout<<val<<"->(";
		if(FRightSon) FRightSon->display();
		else std::cout<<"NIL";
		std::cout<<",";
		if(FLeftSon) FLeftSon->display();
		else std::cout<<"NIL";
		std::cout<<")";
	}
	void getDepths(int& max, int& min )
	{
		int max1 =0, min1 =0;
		int max2 =0, min2 =0;
		if(FRightSon) 
		{
			FRightSon->getDepths(max1, min1);
			max1++;
			min1++;
		}
		if(FLeftSon) 
		{
			FLeftSon->getDepths(max2, min2);
			max2++;
			min2++;
		}
		max = std::max(max1,max2);
		min = std::min(min1,min2);
	}
	TTreeNode* FRightSon;
	TTreeNode* FLeftSon;
	T val;
};

template<typename T>
class TTree
{
public:
	TTree()
	: FRoot(NULL)
	{

	}
	~TTree()
	{
		if(FRoot) delete FRoot;
	}
	void orderedInsert(T parT)
	{
		TTreeNode<T>* newNode = new TTreeNode<T>(parT);
		if(FRoot) FRoot->orderedInsert(newNode);
		else FRoot = newNode; 
	}
	void display()
	{
		if(FRoot) FRoot->display();
		else std::cout<<"NIL";
		std::cout<<std::endl;
	}
	bool isbalanced()
	{
		if(FRoot)
		{
			int max = 0,min = 0;
			FRoot->getDepths(max, min);
			return ((max-min)<2);
		} 
		return true;
	}
protected:
	TTreeNode<T>* FRoot;
};

int main()
{
	TTree<int> tree;
	tree.orderedInsert(5);
	tree.orderedInsert(2);
	tree.orderedInsert(6);
	// tree.orderedInsert(2);
	// tree.orderedInsert(2);
	tree.orderedInsert(7);
	// tree.orderedInsert(0);
	tree.orderedInsert(9);
	tree.display();
	std::cout<<"Is balanced "<<tree.isbalanced()<<std::endl;
	return 0;
}