#include <iostream>
#include <ctime>
using namespace std;

template <class T = int>
class node
{
	public:
		T info;               // data member
		node *next;             // data member
		
		node(T data = 0, node* link = NULL) : info(data), next(link) {};
};

int myrand(int min=1, int max=100)
{
	int a=65539, m=2147483647;
	static long long int x = time(NULL);
	x = (x*a)%m;
	return x%(max-min+1)+min;
}

template < class T = int>
class LinkedList
{
	private:
		node<T> head;
		
	public:
		LinkedList(int nodecount = 0)       // paramitarized constructor
		{
			head.info = nodecount;
			node <int>*prevnode;
			for(int i=0;i<nodecount;i++)
			{
				int key = myrand();
				node<T> *newnode = new node<T>(key);
				if(i==0)
					head.next = newnode;
				else
					prevnode->next = newnode;
				prevnode = newnode;
			}
		}
		
		LinkedList(const LinkedList &LL)       // copy constructor
		{
			head.info = LL.head.info;
			const node <T>*LLcurnode = LL.head.next;
			node<T> *prevnode;
			for(int i=0;i<head.info;i++)
			{
				node<T> *newnode = new node<T>(LLcurnode->info,NULL);
				if(i==0)
					head.next = newnode;
				else
					prevnode->next = newnode;
				prevnode = newnode;
				LLcurnode = LLcurnode->next;
			}
		}
		
		~LinkedList()        // destructor
		{
			node<T> *curnode;
			for(int i=0;i<head.info;i++)
			{
				curnode = head.next;
				head.next = curnode->next;
				delete curnode;
			}
		}
		
		void display();
		T insertBeg(T);
		T deleteNode(T);
		void concatenate(LinkedList<T> &);
		bool search(T);
		int no_of_nodes();
};

template < class T>
void LinkedList<T>::display()
{
	cout << " ||" << head.info << " nodes||";
	node<T> *curnode = head.next;
	for(int i=0;i<head.info;i++)
	{
		cout << "---->|" << curnode->info << "|";
		curnode = curnode->next;
	}
	cout << "---->xxxx" << endl;
}

template < class T>
T LinkedList<T>::insertBeg(T key)
{
	head.next = new node<T>(key,head.next);
	head.info++;
	return head.next->info;
}

template < class T>
T LinkedList<T>::deleteNode(T key)
{
	node<T> *prevnode = &head;
    for(int i=1;i<=head.info;i++)
    {
      	node<T> *curnode = prevnode->next;
        if(curnode->info==key)
        {
            prevnode->next = curnode->next;
            delete curnode;  
            head.info--;
            return i;
        }
        else prevnode = prevnode->next;
	}
	return 0;
}

template < class T>
void LinkedList<T>::concatenate( LinkedList<T> &LL2)
{
	head.info += LL2.head.info;
	node<T> *lastnode = &head;
	while(lastnode->next!=NULL)
	{
		lastnode = lastnode->next;
	}
	lastnode->next = LL2.head.next;
}

template < class T>
bool LinkedList<T>::search(T key)
{
	node<T> *curnode = head.next;
	for(int i=1;i<=head.info;i++)
	{
		if(curnode->info==key)
		  return 1;
		else
		  curnode = curnode->next;
	}
	return 0;
}

template < class T>
int LinkedList<T>::no_of_nodes()
{
	return head.info;
}