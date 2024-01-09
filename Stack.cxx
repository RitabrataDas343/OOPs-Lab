#include <iostream>
using namespace std;
template <class T> class stack
{
    T *arr;
    int cap;
    int cnt;

public:
    stack(T);
    void push(T);
    void pop();
    bool isempty();
    bool isfull();
    void display();
    int top();
    ~stack();
};
template <class T> stack<T>::stack(T sz)
{
    cnt = 0;
    cap = sz;
    arr = new T[cap];
}
template <class T> bool stack<T>::isfull()
{
    if (cnt == cap)
    {
        return true;
    }
    return false;
}
template <class T> bool stack<T>::isempty()
{
    if (cnt == 0)
    {
        return true;
    }
    return false;
}
template <class T> stack<T>::~stack()
{
    cout << "Deconstructed the class object.." << endl;
}
template <class T> void stack<T>::push(T data)
{
    if (!stack::isfull())
    {
        arr[cnt] = data;
        cnt++;
    }
}
template <class T> void stack<T>::pop()
{
    if (!stack::isempty())
    {
        cnt--;
    }
}
template <class T> void stack<T>::display()
{
    if (isempty())
    {
        cout << "Empty Stack!" << endl;
    }
    else
    {
        for (int i = cnt - 1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
template <class T> int stack<T>::top()
{
    return arr[cnt - 1];
}
int main(void)
{
    cout << "Enter the size of the stack" << endl;
    int n;
    cin >> n;
    stack<int> stk1(n);
    char check = 'y';
    while (check == 'y')
    {
        cout << "Menu List" << endl;
        cout << "[0]: Push Elements." << endl;
        cout << "[1]: Pop Elements." << endl;
        cout << "[2]: Check Top Element." << endl;
        cout << "[3]: Display Stack." << endl;
        cout << "[4]: Destroy Stack." << endl;
        cout << "Choose from the following options : ";
        int opt, data, fr;
        cin >> opt;
        switch (opt)
        {
        case 0:
            cout << "Enter the number of elements to push in stack : ";
            cin >> fr;
            if (stk1.isfull())
            {
                cout << "Stack overflow" << endl;
            }
            else
            {
                for (int i = 0; i < fr; i++)
                {
                    cin >> data;
                    stk1.push(data);
                }
            }
            break;
        case 1:
            cout << stk1.top() << " popped out!" << endl;
            stk1.pop();
            break;
        case 2:
            cout << stk1.top() << " is the top element in the given stack!"
                 << endl;
            break;
        case 3:
            cout << "The stack is : ";
            stk1.display();
            break;
        case 4:
            cout << "Stack destroyed!" << endl;
            stk1.~stack();
        default:
            cout << "Wrong option entered!" << endl;
        }
        cout << "Do you want to continue with the operations enter (y/n) :";
        cin >>check;
    }
    return 0;
}