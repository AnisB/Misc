// Hash table inmplementation

#include <iostream>

#define INITIAL_SIZE 20
// template<typename Key>
// int binarySearch(Key* ids, int size, const Key& val)
// {
// 	int first = 0;
// 	int last = size - 1;
// 	int middle = (first+last)/2;
// 	while( first <= last )
// 	{
// 		if ( ids[middle] < val )
// 			first = middle + 1;    
// 		else if ( ids[middle] == val ) 
// 		{
// 			break;
// 		}
// 		else
// 			last = middle - 1;
// 		middle = (first + last)/2;
//    }
//    if ( first > last )
// 		return -1;
// 	return middle+1;
// }

template <typename Key>
struct KeyHash {
    int operator()(const Key& key) const
    {
        return reinterpret_cast<int>(key) % INITIAL_SIZE;
    }
};

template<typename Key, typename Object>
class THashEntry
{
public:
	THashEntry(const Key& parKey, const Object& parObject)
	: key(parKey)
	, obj(parObject)
	, next(NULL)
	{

	}
	THashEntry(const Key& parKey)
	: key(parKey)
	, obj(0)
	, next(NULL)
	{

	}
	~THashEntry(){}

	Key& getKey(){return key;}
	Object& getObject(){return obj;}
	THashEntry*& getNext(){return next;}

protected:
	Key key;
	Object obj;
	THashEntry* next;
};


template <typename Key, typename Object>
class THashMap
{
public:
	THashMap()
	: F()
	{
		nodes = new THashEntry<Key,Object> *[INITIAL_SIZE];
	}
	~THashMap()
	{
		delete [] nodes;
	}

	Object& operator[](const Key& parKey)
	{
		int index = F(parKey);
		THashEntry<Key,Object>* prev = NULL;
		THashEntry<Key,Object>* current = nodes[index];
		while(current!=NULL)
		{
			if(current->getKey()!=parKey)
			{
				prev = current;
				current = current->getNext();
			}
			else
				break;
		}
		if(current == NULL)
		{
			current = new THashEntry<Key,Object>(parKey);
			if(prev == NULL)
			{
				nodes[index] = current;
			}
			else
			{
				prev->getNext() = current;
			}
		}
		return current->getObject();
	}
	void display()
	{
		for(int i = 0; i < INITIAL_SIZE; ++i)
		{
			THashEntry<Key,Object>* current = nodes[i];
			while(current!=NULL)
			{
				std::cout<<current->getKey()<<" "<<current->getObject()<<std::endl;
				current = current->getNext();
			}
		}
	}
protected:
	THashEntry<Key,Object> ** nodes;
	KeyHash<Key> F;
};


int main()
{
	THashMap<int, double> ht;
	ht[0] = 3.0;
	ht[1] = 5.0;
	// std::cout<<"Assigned"<<std::endl;
	std::cout<<ht[0]<<std::endl;
	std::cout<<ht[1]<<std::endl;
	// ht.display();
	return 0;
}