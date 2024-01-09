#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>

using namespace std;

template <class T> 
class Stack{
    private: 
        T *arr;
        int cap;
        int count;

    public:
        Stack(T);
        void push(T);
        void pop();
        int top();
        bool isEmpty();
        bool isFull();
        void display();
        ~Stack();
};

template <class T> Stack<T>::Stack(T size){
    count = 0;
    cap = size;
    arr = new T[cap];
    cout << "Stack Created" << endl;
}

template <class T> bool Stack<T>::isFull(){
    if (count == cap){
        return true;
    }
    return false;
}

template <class T> bool Stack<T>::isEmpty(){
    if (count == 0){
        return true;
    }
    return false;
}

template <class T> void Stack<T>::push(T data){
    if (!Stack::isFull()){
        arr[count] = data;
        count++;
    }
}

template <class T> void Stack<T>::pop(){
    if (!Stack::isEmpty()){
        count = count - 1;
    }
}

template <class T> void Stack<T>::display(){
    if (isEmpty()){
        cout << "Empty Stack." << endl;
    } else {
        cout << "The stack is: " << endl;
        for (int i = count - 1; i >= 0; i--){
            cout << " | " << arr[i] << " | " << endl;
        }
        cout << endl;
    }
}

template <class T> int Stack<T>::top(){
    return arr[count - 1];
}

template <class T> Stack<T>::~Stack(){
    cout << "Stack Destroyed" << endl;
}

int main(void){
    int sz, times, choice, value;
    cout << "Enter the size of the stack: ";
    cin >> sz;
    Stack<int> st(sz);
    cout << "Enter the number of operations: ";
    cin >> times;
    while (times--){
        cout << "\nENTER 1 to PUSH an element.\nENTER 2 to POP element.\nENTER 3 to RETURN the top element.\nENTER 4 to CHECK whether the stack is FULL.\nENTER 5 to CHECK whether the stack is EMPTY.\nENTER 6 to DISPLAY the stack.\nENTER CHOICE: ";
        cin >> choice;
        switch (choice){
        case 1:
            if (st.isFull()){
                cout << "Stack Overflown. Cannot push element." << endl;
            } else {
                cout << "Enter the element to PUSH in the stack: ";
                cin >> value;
                st.push(value);
                cout << value << " is pushed into the stack." << endl;
            }
            break;
        case 2:
            if (st.isEmpty()){
                cout << "Stack Underflown. Cannot pop element." << endl;
            } else {
                value = st.top();
                st.pop();
                cout << value << " is popped out of the stack." << endl;
            }
            break;
        case 3:
            cout << "The top element of the Stack is: "<< st.top() << endl;
            break;
        case 4:
            if(st.isFull()){
                cout << "Stack is FULL." << endl;
            } else {
                cout << "Stack is not FULL." << endl;
            }
            break;
        case 5:
            if(st.isEmpty()){
                cout << "Stack is EMPTY." << endl;
            } else {
                cout << "Stack is not EMPTY." << endl;
            }
            break;
        case 6:
            st.display();
            break;
        default:
            cout << "Wrong option entered." << endl;
        }
    }
    return 0;
}