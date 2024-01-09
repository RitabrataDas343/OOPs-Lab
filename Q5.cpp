#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std; 

int choicefn;               
int randkeyval[100]; 

int myrand(int min=1, int max=100){
	int a=65539, m=2147483647;
	static long long int x = time(NULL);
	x = (x*a)%m;
	return x%(max-min+1)+min;
}

void generate_hundred_rand_key_val(){
	for(int i=0;i<100;i++){
        randkeyval[i] = myrand();
    }
}

template <class T = int>
class node{
	public:
		T info;               
		node *next;            
		node(T data = 0, node* link = NULL) : info(data), next(link) {};
};

template < class T = int>
class LinkedList{
	private:
		node<T> head;
		
	public:
		LinkedList(int nodecount = 0){
			head.info = nodecount;
			node <int>*prevnode;
			for(int i=0;i<nodecount;i++){
				int key = myrand();
				node<T> *newnode = new node<T>(key);
				if(i==0)
					head.next = newnode;
				else
					prevnode->next = newnode;
				prevnode = newnode;
			}
		}
		
		LinkedList(const LinkedList &LL){
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
		
		~LinkedList(){
			node<T> *curnode;
			for(int i=0;i<head.info;i++){
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
void LinkedList<T>::display(){
	cout << " ||" << head.info << " nodes||";
	node<T> *curnode = head.next;
	for(int i=0;i<head.info;i++){
		cout << "---->|" << curnode->info << "|";
		curnode = curnode->next;
	}
	cout << "---->xxxx" << endl;
}

template < class T>
T LinkedList<T>::insertBeg(T key){
	head.next = new node<T>(key,head.next);
	head.info++;
	return head.next->info;
}

template < class T>
T LinkedList<T>::deleteNode(T key){
	node<T> *prevnode = &head;
    for(int i=1;i<=head.info;i++){
      	node<T> *curnode = prevnode->next;
        if(curnode->info==key){
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
void LinkedList<T>::concatenate( LinkedList<T> &LL2){
	head.info += LL2.head.info;
	node<T> *lastnode = &head;
	while(lastnode->next!=NULL){
		lastnode = lastnode->next;
	}
	lastnode->next = LL2.head.next;
}

template < class T>
bool LinkedList<T>::search(T key){
	node<T> *curnode = head.next;
	for(int i=1;i<=head.info;i++){
		if(curnode->info==key){
            return 1;
        } else{
            curnode = curnode->next;
        }
	}
	return 0;
}

template < class T>
int LinkedList<T>::no_of_nodes(){
	return head.info;
}

template <class T = int>
class hashing{
	private:
    	LinkedList<T> *ht;
    	int  htsize;
    	int hashfn(T key);
    
    public:
    	hashing(){
	    	if(choicefn == 1){
                htsize = 10;
            } else if(choicefn == 2){
                htsize = (100/4);
            } 
	    	ht = new LinkedList<T>[htsize];
	    	for(int i=0;i<100;i++){
	    		int j = hashfn(randkeyval[i]);
	    		ht[j].insertBeg(randkeyval[i]);
			}
		}
		
    	~hashing(){
			delete []ht;
		}
		
    	bool search(int);
    	void insert(int);
    	bool delet(int);
    	void display(void);
    	void TableLoadDistr();
};

template <class T>
int hashing<T>::hashfn(T x){
	if(choicefn == 1){
        return (x%10);
    }else if(choicefn == 2){
        return (x-1)/4 ;
    }
    return 0;
}
  
template <class T> 
bool hashing<T>::delet(int key){
	int i = hashfn(key);
    return ht[i].deleteNode(key);
}

template <class T> 
void hashing<T>::insert(int key){
	int i = hashfn(key);
    ht[i].insertBeg(key);
}

template <class T>
bool hashing<T>::search(int key){
    int i = hashfn(key);
    return ht[i].search(key);
}

template <class T>
void hashing<T>::display(void){
    cout<<"Hash table:"<<endl;
    for(int i=0;i<htsize;i++){
    	cout << "ht[" <<setw(2) << i << "] ---->  ";
		ht[i].display();
	}
}

template <class T>
void hashing<T>::TableLoadDistr(){
	int total_no_of_nodes=0;
	for(int i=0;i<htsize;i++){
        total_no_of_nodes += ht[i].no_of_nodes();
    }
	cout << "Displaying % of load in each bucket of the hash table" << endl;
	for(int i=0;i<htsize;i++){
		float percentageload = ((float)(ht[i].no_of_nodes())/total_no_of_nodes)*100;
		cout << " ht[" << setw(2) << i << "] ---> " << percentageload << " % load" << endl;
	}	  
}

int main(void){
	generate_hundred_rand_key_val();
	choicefn = 1;  
    hashing<int> h1;
	choicefn = 2;  
    hashing<int> h2;
	cout << "1. x % 10" << endl << "2. (x-1)/10" << endl << "Choose your Hash function : ";
	cin >> choicefn;
	while(1){
		cout << "\nENTER 1 to SEARCH an item.\nENTER 2 to INSERT item.\nENTER 3 to DELETE item.\nENTER 4 to DISPLAY hash table.\nENTER 5 to DISPLAY percentage OF LOAD.\nENTER 6 to CHANGE HASH function.\nENTER 7 to QUIT.\nENTER CHOICE: ";
		int choice;  
        cin >> choice;
		switch(choice){
			case 1:
			{
				cout << "Enter the item to be searched: ";
				int key;  cin >> key;
				bool successful_search;
				if(choicefn == 1){
                    successful_search = h1.search(key);
                } else if(choicefn == 2){
                    successful_search = h2.search(key);
                }
				if(successful_search){
                    cout << "item is present in the Hash table." << endl;
                } else {
                    cout << "item not found in the Hash table." << endl;
                }  
			}       
		    break;	
			case 2:
			{
				int key = myrand();
				if(choicefn==1){
                    h1.insert(key);
                }else if(choicefn==2) {
                    h2.insert(key);
                }
				cout << key << " is inserted in the hash table." << endl;
			}      
		    break;
			case 3:
			{
				cout << "Enter the item to be deleted: ";
			    int key;  
                cin >> key;
			    bool successful_deletion;
			    if(choicefn==1){
                    successful_deletion = h1.delet(key);
                } else if(choicefn==2){
                    successful_deletion = h2.delet(key);
                }
			    if(successful_deletion){
			        cout << key << " is deleted from the Hash table." << endl;
                } else{
			        cout << key << " not found in the Hash table.\nDeletion failed!" << endl;
                }
			}
			break;     
			case 4:
			{
				if(choicefn==1){
                    h1.display();
                } else if(choicefn==2){
                    h2.display();
                }		  
			}
		    break;
			case 5:
		    {
		    	if(choicefn==1){
                    h1.TableLoadDistr();
                }else if(choicefn==2){
                    h2.TableLoadDistr();
                } 
			}
			break;       
			case 6:
			{
				if(choicefn==1){
                    choicefn = 2;
                } else if(choicefn==2){
                    choicefn = 1;
                }
			}
			break;
            case 7:
            return 0;
            break;
			default: 
            cout << "Wrong choice." << endl;
            break;
		}
		cout << endl;
	}
    return 0;
}