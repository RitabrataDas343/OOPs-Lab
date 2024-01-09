#include"MyTempLinkedList.h"
#include<iostream> 
#include<iomanip>
using namespace std; 

int choicefn;                // to choose hash function 

int randkeyval[100];                 
void generate_hundred_rand_key_val()
{
	for(int i=0;i<100;i++)
	  randkeyval[i] = myrand();
}

template <class T = int>
class hashing
{
	private:
    	LinkedList<T> *ht;
    	int  htsize;
    	int hashfn(T key);
    
    public:
    	hashing()              // constructor
    	{
	    	if(choicefn == 1)
			  htsize = 10;
	  		else if(choicefn == 2)
			  htsize = (100/4);
	    	ht = new LinkedList<T>[htsize];
	    	for(int i=0;i<100;i++)
	    	{
	    		int j = hashfn(randkeyval[i]);
	    		ht[j].insertBeg(randkeyval[i]);
			}
		}
		
    	~hashing()          // destructor
    	{
			delete []ht;
		}
		
    	bool search(int);
    	int insert(int);
    	bool delet(int);
    	void display(void);
    	void TableLoadDistr();
};

template <class T>
int hashing<T>::hashfn(T x)
{
	if(choicefn == 1)
      return (x%10);
	else if(choicefn == 2)
      return (x-1)/4 ;
}
  
template <class T> 
bool hashing<T>::delet(int key)
{
	int i = hashfn(key);
    return ht[i].deleteNode(key);
}

template <class T> 
int hashing<T>::insert(int key)
{
	int i = hashfn(key);
    ht[i].insertBeg(key);
}

template <class T>
bool hashing<T>::search(int key)
{
    int i = hashfn(key);
    return ht[i].search(key);
}

template <class T>
void hashing<T>::display(void)
{
    cout<<" Hash table:"<<endl;
    for(int i=0;i<htsize;i++)
    {
    	cout << "ht[" <<setw(2) << i << "] ---->  ";
		ht[i].display();
	}
}

template <class T>
void hashing<T>::TableLoadDistr()
{
	int total_no_of_nodes=0;
	for(int i=0;i<htsize;i++)
	  total_no_of_nodes += ht[i].no_of_nodes();

	cout << "displaying % of load in each bucket of the hash table" << endl;
	for(int i=0;i<htsize;i++)
	{
		float percentageload = ((float)(ht[i].no_of_nodes())/total_no_of_nodes)*100;
		cout << " ht[" << setw(2) << i << "] ---> " << percentageload << " % load" << endl;
	}	  
}

int main(void)
{
	generate_hundred_rand_key_val();
	
	choicefn = 1;  hashing<int> h1;
	choicefn = 2;  hashing<int> h2;
	
	cout  << "1. x % 10" << endl
	      << "2. (x-1)/10" << endl
	      << "choose your Hash function : ";
	cin >> choicefn;
	
	cout << "\n Operations to perform :" << endl
	     << " 1.search an item in hash table" << endl
		 <<	" 2.insert an item in hash table" << endl
		 <<	" 3.delete at item from the hash table" << endl
		 << " 4.display hash table" << endl
		 << " 5.display % of load in each bucket of the hash table" << endl
		 << " 6.change hash function" << endl
		 <<	" 7.Quit" << endl
		 << endl;
	while(1)
	{
		cout << "Enter your choice : ";
		int choice;  cin >> choice;
		switch(choice)
		{
			case 1:
			{
				cout << "Enter the item to be searched : ";
				int key;  cin >> key;
				
				bool successful_search;
				if(choicefn==1)
				  successful_search = h1.search(key);
				else if(choicefn==2)
				  successful_search = h2.search(key);
				  
				if(successful_search)
				  cout << "item is present in the Hash table" << endl;
				else
				  cout << "item not found in the Hash table!" << endl;
			}       
		    break;
			  	
			case 2:
			{
				int key = myrand();
				if(choicefn==1)
				  h1.insert(key);
				else if(choicefn==2)
				  h2.insert(key);
				cout << key << " is inserted in the hash table" << endl;
			}      
		    break;
		    
			case 3:
			{
				cout << " Enter the item to be deleted : ";
			    int key;  cin >> key;
			    
			    bool successful_deletion;
			    if(choicefn==1)
				  successful_deletion = h1.delet(key);
				else if(choicefn==2)
				  successful_deletion = h2.delet(key);
				  
			    if(successful_deletion)
			      cout << key << " is deleted from the Hash table" << endl;
			    else
			      cout << key << " not found in the Hash table\ndeletion failed!" << endl;
			}
			break;
			        
			case 4:
			{
				if(choicefn==1)
				  h1.display();
				else if(choicefn==2)
				  h2.display();
			}
		    break;
			
			case 5:
		    {
		    	if(choicefn==1)
		    	  h1.TableLoadDistr();
		    	else if(choicefn==2)
		    	  h2.TableLoadDistr();
			}
			break;       
			
			case 6:
			{
				if(choicefn==1)
				  choicefn = 2;
				else if(choicefn==2)
				  choicefn = 1;
			}
			break;
			
			case 7: return 0;
			
			default: cout << "Wrong choice!" << endl;
		}
		cout << endl;
	}

    return 0;
}