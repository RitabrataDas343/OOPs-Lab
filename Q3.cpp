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
        Node(T);
        void display();
        ~Node(){
            cout << "Node destroyed." << endl;
        };
};

template <class T> Node<T>::Node(T val){
    data = val;
    link = NULL;
    cout << "Node created." << endl;
}

template <class T> void Node<T>::display(){
    cout << "The value of node is: " << data << endl;
}

int main(){
    int value;
    cout << "Enter the value of the node: ";
    cin >> value;
    Node<int> node(value);
    node.display();
    return 0;
}