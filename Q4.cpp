#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

template <class T>
class Node{
    public:
        T data;
        Node *link;

        Node(){
            data = 0;
            link = NULL;
        };

        Node(T val){
            data = val;
            link = NULL;
        };

        ~Node(){};
};

template <class T>
class List {
    Node<T> *head;

    public:
        List(){
            head = NULL;
        };

        void insert_node(T);
        void delete_node();
        void display();

        void operator+ (const List<T> &obj){
            Node<T> *ptr = head;
            while(ptr->link != NULL){
                ptr = ptr->link;
            }
            ptr->link = obj.head;
        };

        void reverse();

        void operator~(){
            if(head->link == NULL)return;
            if(head->link->link == NULL){
                head->link->link = head;
                head->link = NULL;
                return;
            } 
            Node<T> *pre = head;
            Node<T> *cur = pre->link;
            Node<T> *next = cur->link;
            int count = 0;
            while(cur->link != NULL){
                cur->link = pre;
                if(count == 0){
                    pre->link=NULL;
                    count++;
                }
                pre = cur;
                cur = next;
                next = next->link;
            }
            head = cur;
            head->link = pre;
        }

        ~List(){};
};

template <class T>
void List<T>::insert_node(T val){
    Node<T> *childnode = new Node<T>(val);
    if(head == NULL){
        head = childnode;
    } else {
        Node<T> *ptr = head;
        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = childnode;
    }
}

template <class T>
void List<T>::delete_node(){
    Node<T> *ptr = head, *ptr2 = head;
    while(ptr->link!=NULL){
        ptr2 = ptr;
        ptr = ptr->link;
    }
    ptr2->link = NULL;
    delete ptr;
}

template <class T>
void List<T>::display(){
    Node<T> *ptr = head;
    cout << "LIST -> ";
    while(ptr != NULL){
        cout << ptr->data << " -> ";
        ptr = ptr->link;
    }
    cout << "NULL" << endl;
    delete ptr;
}

int main(){
    List<int> sll1, sll2;
    int times, choice, value, n;
    cout << "Enter the number of operations: ";
    cin >> times;
    while(times--){
        cout << "\nENTER 1 to INSERT elements in the list.\nENTER 2 to DELETE element.\nENTER 3 to DISPLAY the List.\nENTER 4 to CONCATENATE the Lists.\nENTER 5 to REVERSE the List.\nENTER CHOICE: ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "\nEnter the NUMBER of elements to enter in List 1: ";
                cin >> n;
                while(n--){
                    cout << "Enter value: ";
                    cin >> value;
                    sll1.insert_node(value);
                }
                cout << "\nEnter the number of elements to enter in List 2: ";
                cin >> n;
                while(n--){
                    cout << "Enter value: ";
                    cin >> value;
                    sll2.insert_node(value);
                }
                break;
            case 2:
                cout<<"\nEnter 1 to delete one element from List 1.\nEnter 2 to delete one element from List 2.\nENTER CHOICE: ";
                cin >> n;
                if(n == 1){
                    sll1.delete_node();
                    cout<<"Last node of List 1 deleted."; 
                } else {
                    sll2.delete_node();
                    cout<<"Last node of List 2 deleted."; 
                }
                break;
            case 3:
                cout<<"\nEnter 1 to DISPLAY List 1.\nEnter 2 to DISPLAY List 2.\nENTER CHOICE: ";
                cin >> n;
                if(n == 1){
                    sll1.display();
                } else {
                    sll2.display();
                }
                break;
            case 4:
                cout << "\nThe CONCATENATED list is: ";
                sll1+sll2;
                sll1.display();
                break;
            case 5:
                cout<<"\nEnter 1 to REVERSE List 1.\nEnter 2 to REVERSE List 2.\nENTER CHOICE: ";
                cin >> n;
                if(n == 1){
                    cout<<"\nThe REVERSED List is :";
                    ~sll1;    
                    sll1.display();
                } else {
                    cout<<"\nThe REVERSED List is :";
                    ~sll2;    
                    sll2.display();
                }
                break;
            default:
                cout<<"\nWrong Choice.";
            break;
        }
    }
    return 0;
}