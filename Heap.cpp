#include <bits/stdc++.h>
using namespace std;
template <class T>
class max_heap
{
    T *arr;
    int cap;
    int current_size;

public:
    max_heap(int);
    void insertOps(T);
    void deleteOps();
    void heapify(int);
    int getMax();
    void display();
    void dealloc();
};
template <class T>
class min_heap
{
    T *arr;
    int cap;
    int current_size;

public:
    min_heap(int);
    void insertOps(T);
    void deleteOps();
    void heapify(int);
    int getMin();
    void display();
    void dealloc();
};
template <class T>
min_heap<T>::min_heap(int sz)
{
    cap = sz;
    arr = new int[cap];
    current_size = 0;
}
template <class T>
void min_heap<T>::dealloc()
{
    delete[] arr;
}
template <class T>
max_heap<T>::max_heap(int sz)
{
    cap = sz;
    arr = new int[cap];
    current_size = 0;
}
template <class T>
void max_heap<T>::dealloc()
{
    delete[] arr;
}
template <class T>
void max_heap<T>::heapify(int i)
{
    int l = (2 * i), r = (2 * i) + 1, large = i;
    if (l <= current_size && arr[l] > arr[i])
    {
        large = l;
    }
    else
    {
        large = i;
    }
    if (r <= current_size && arr[r] > arr[large])
    {
        large = r;
    }
    if (large != i)
    {
        swap(arr[large], arr[i]);
        max_heap<T>::heapify(large);
    }
}
template <class T>
void min_heap<T>::heapify(int i)
{
    int l = (2 * i), r = (2 * i) + 1, smallest = i;
    if (l <= current_size && arr[l] < arr[i])
        smallest = l;
    if (r <= current_size && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        min_heap<T>::heapify(smallest);
    }
}
template <class T>
void max_heap<T>::insertOps(T val)
{
    // cout<<current_size<<" "<<cap<<"\n";
    if (current_size >= cap)
    {
        return;
    }
    else
    {
        current_size += 1;
        arr[current_size - 1] = val;
        int calc = current_size - 1;
        while (calc != 0 && arr[calc] > arr[calc / 2])
        {
            swap(arr[calc], arr[calc / 2]);
            calc = calc / 2;
        }
    }
}
template <class T>
void max_heap<T>::deleteOps()
{
    if (current_size == 0)
    {
        return;
    }
    else
    {
        int val = arr[0];
        arr[0] = arr[current_size - 1];
        arr[current_size - 1] = -1;
        max_heap<T>::heapify(0);
        current_size--;
    }
}
template <class T>
void min_heap<T>::deleteOps()
{
    if (current_size == 0)
    {
        return;
    }
    else
    {
        int val = arr[0];
        arr[0] = arr[current_size - 1];
        arr[current_size - 1] = -1;
        min_heap<T>::heapify(0);
        current_size--;
    }
}
template <class T>
void max_heap<T>::display()
{
    for (int i = 0; i < cap; i++)
    {
        if (arr[i] != -1)
        {
            cout << arr[i] << " ";
        }
    }
    cout << "\n";
}
template <class T>
void min_heap<T>::insertOps(T val)
{
    // cout<<current_size<<" "<<cap<<"\n";
    if (current_size >= cap)
    {
        cout << "Heap size overload seen!\n";
        return;
    }
    else
    {
        current_size += 1;
        arr[current_size - 1] = val;
        int calc = current_size - 1;
        while (calc != 0 && arr[calc] < arr[calc / 2])
        {
            swap(arr[calc], arr[calc / 2]);
            calc = calc / 2;
        }
    }
}
template <class T>
void min_heap<T>::display()
{
    for (int i = 0; i < cap; i++)
    {
        if (arr[i] != -1)
        {
            cout << arr[i] << " ";
        }
    }
    cout << "\n";
}
template <class T>
int max_heap<T>::getMax()
{
    return arr[0];
}
template <class T>
int min_heap<T>::getMin()
{
    return arr[0];
}
int main()
{
    int cap, val;
    cout << "Enter the capacity of the heap" << endl;
    cin >> cap;
    cout << "Choose one of the options : "
         << "\n";
    cout << "1. Max Heap. "
         << "\n";
    cout << "2. Min Heap. "
         << "\n";
    bool check = true;
    int ch, t, t1;
    cin >> ch;
    min_heap<int> ins1(cap);
    max_heap<int> ins(cap);
    int cnt = 0;
    switch (ch)
    {
    case 1:
        cout << "Enter the elements : ";
        while (check)
        {
            cin >> val;
            cnt++;
            if (cnt > cap)
            {
                cout << "Limit Exceeded!\n";
                break;
            }
            ins.insertOps(val);
        }
        cout << "\nThe Max Heap is : ";
        ins.display();
        cout << "Max value in the heap is : " << ins.getMax() << "\n";
        cout << "Enter 1 to delete else 0 to exit!\n";
        cin >> t;
        while (t == 1)
        {
            ins.deleteOps();
            cout << "\nThe Modified-Max Heap is : ";
            ins.display();
            cout << "If you want to delete more press 1 else 0 to exit !\n ";
            cin >>t;
        }
        break;
    case 2:
        cout << "Enter the elements : ";
        while (check)
        {
            cin >> val;
            cnt++;
            if (cnt > cap)
            {
                cout << "Limit Exceeded!\n";
                break;
            }
            ins1.insertOps(val);
        }
        cout << "\nThe Min Heap is : ";
        ins1.display();
        cout << "Min value in the heap is : " << ins1.getMin() << "\n";
        cout << "Enter 1 to delete else 0 to exit!\n";
        cin >> t1;
        while (t1 == 1)
        {
            ins1.deleteOps();
            cout << "\nThe Modified-Min Heap is : ";
            ins1.display();
            cout << "If you want to delete more press 1 else 0 to exit !\n ";
            cin >> t1;
        }
        break;
    default:
        cout << "Wrong input!\n";
    }
    ins.dealloc();
    ins1.dealloc();
    return 0;
}