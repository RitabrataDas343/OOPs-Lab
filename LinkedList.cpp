#include<bits/stdc++.h>
#include "Node.cpp"
using namespace std;
template <class T>
class List {
    Node<T> *head;
    public:
        List();
        void insert_node(T);
        void delete_node();
        void print_list();
        void operator+ (const List<T> &obj){
            Node<T> *ptr = head;
            while(ptr->link!=NULL){
                ptr = ptr->link;
            }
            ptr->link = obj.head;
        };
        void reverse();
        void operator~(){
            if(head->link==NULL)return;
            if(head->link->link==NULL){
                head->link->link = head;
                head->link = NULL;
                return;
            } 
            Node<T> *pre = head;
            Node<T> *cur = pre->link;
            Node<T> *nxt = cur->link;
            int cs = 0;
            while(cur->link!=NULL){
                cur->link = pre;
                if(cs==0){pre->link=NULL;cs++;}
                pre = cur;
                cur = nxt;
                nxt = nxt->link;
            }
            head = cur;
            head->link = pre;
        }
        ~List(){};
};

template <class T>
List<T>::List(){
    head = NULL;
}

template <class T>
void List<T>::insert_node(T val){
    Node<T> *childnode = new Node<T>(val);
    if(head==NULL){
        head = childnode;
    } else {
        Node<T> *ptr = head;
        while(ptr->link!=NULL){
            ptr = ptr->link;
        }
        ptr->link = childnode;
    }
}

template <class T>
void List<T>::delete_node(){
    Node<T> *ptr = head,*ptr2 = head;
    while(ptr->link!=NULL){
        ptr2 = ptr;
        ptr = ptr->link;
    }
    ptr2->link = NULL;
    delete ptr;
}

template <class T>
void List<T>::print_list(){
    Node<T> *ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->link;
    }cout<<endl;
    delete ptr;
}
int main(){
    List<int> LL,LL2;
    char opt = 'y';
    int n,val;
    while(opt=='y'){
        cout << "<-------Menu List------->" << endl;
        cout << "[0]: Insert elements into the list." << endl;
        cout << "[1]: Print List." << endl;
        cout << "[2]: Delete List Elements." << endl;
        cout << "[3]: Concatenate List." << endl;
        cout << "[4]: Reverse List." << endl;
        cout << "Choose from the following options : ";
        int ch; cin>>ch;
        switch (ch)
        {
            case 0:
                // Insert Elements into the 2 Lists
                printf("\nEnter the amount of elements you want to enter in List 1 : ");
                cin>>n;
                printf("\nEnter the elements : ");
                while(n--){
                    cin>>val;
                    LL.insert_node(val);
                }
                printf("\nEnter the amount of elements you want to enter in List 2 : ");
                cin>>n;
                printf("\nEnter the elements : ");
                while(n--){
                    cin>>val;
                    LL2.insert_node(val);
                }
                break;
            case 1:
                // Print Lists function() 
                cout<<"\nEnter [1] to print list 1 and [2] to print list 2 :";
                cin>>n;
                if(n==1)LL.print_list();
                else {LL2.print_list();}
                break;
            case 2:
                cout<<"\nEnter [1] to delete one element from list 1 and [2] to delete one element from list 2 :";
                cin>>n;
                if(n==1){
                    // Delete Node function() list 1
                    LL.delete_node();
                    cout<<"\nResultant List is :"; 
                    LL.print_list();
                    cout<<endl;
                }
                else {
                    // Delete Node function() list 2
                    LL2.delete_node();
                    cout<<"\nResultant List is :"; 
                    LL2.print_list();
                    cout<<endl;
                }
                break;
            case 3:
                cout<<"\nThe concatenated list is : ";
                // Overloaded '+' operator to concatenate 2 lists
                LL+LL2;
                LL.print_list();
                break;
            case 4:
                cout<<"\nThe Reversed List is :";
                // Overloaded '~' operator to reverse a linked list
                ~LL;    LL.print_list();
                break;
            default:
                cout<<"\nWrong input try again!";
            break;
        }
        printf("\nEnter y to continue operations else n to SIGKILL.(y/n)");
        cin>>opt;
    }
    return 0;
}