#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

template <class T>
class max_heap{
    private:
        T *arr;
        int cap;
        int curr;

    public:
        max_heap(int);
        void insertElement(T);
        void deleteElement();
        void heapify(int);
        int getMax();
        void display();
        void dealloc();
};

template <class T>
class min_heap{
    private: 
        T *arr;
        int cap;
        int curr;

    public:
        min_heap(int);
        void insertElement(T);
        void deleteElement();
        void heapify(int);
        int getMin();
        void display();
        void dealloc();
};

template <class T>
min_heap<T>::min_heap(int size){
    cap = size;
    arr = new int[cap];
    curr = 0;
}

template <class T>
void min_heap<T>::dealloc(){
    delete[] arr;
}

template <class T>
max_heap<T>::max_heap(int size){
    cap = size;
    arr = new int[cap];
    curr = 0;
}

template <class T>
void max_heap<T>::dealloc(){
    delete[] arr;
}

template <class T>
void max_heap<T>::heapify(int i){
    int l = (2 * i), r = (2 * i) + 1, large = i;
    if (l <= curr && arr[l] > arr[i]){
        large = l;
    } else {
        large = i;
    }
    if (r <= curr && arr[r] > arr[large]){
        large = r;
    }
    if (large != i){
        swap(arr[large], arr[i]);
        max_heap<T>::heapify(large);
    }
}

template <class T>
void min_heap<T>::heapify(int i){
    int l = (2 * i), r = (2 * i) + 1, smallest = i;
    if (l <= curr && arr[l] < arr[i]){
        smallest = l;
    }
    if (r <= curr && arr[r] < arr[smallest]){
        smallest = r;
    }
    if (smallest != i){
        swap(arr[i], arr[smallest]);
        min_heap<T>::heapify(smallest);
    }
}

template <class T>
void max_heap<T>::insertElement(T val){
    if (curr >= cap){
        return;
    } else {
        curr = curr + 1;
        arr[curr - 1] = val;
        int calc = curr - 1;
        while (calc != 0 && arr[calc] > arr[calc / 2]){
            swap(arr[calc], arr[calc / 2]);
            calc = calc / 2;
        }
    }
}

template <class T>
void max_heap<T>::deleteElement(){
    if (curr == 0){
        return;
    } else {
        int val = arr[0];
        arr[0] = arr[curr - 1];
        arr[curr - 1] = -1;
        max_heap<T>::heapify(0);
        curr--;
    }
}

template <class T>
void min_heap<T>::deleteElement(){
    if (curr == 0){
        return;
    } else {
        int val = arr[0];
        arr[0] = arr[curr - 1];
        arr[curr - 1] = -1;
        min_heap<T>::heapify(0);
        curr--;
    }
}

template <class T>
void max_heap<T>::display(){
    for (int i = 0; i < cap; i++){
        if (arr[i] != -1){
            cout << arr[i] << " ";
        }
    }
    cout << "\n";
}

template <class T>
void min_heap<T>::insertElement(T val){
    if (curr >= cap){
        cout << "Heap size overload seen!\n";
        return;
    } else {
        curr += 1;
        arr[curr - 1] = val;
        int calc = curr - 1;
        while (calc != 0 && arr[calc] < arr[calc / 2]){
            swap(arr[calc], arr[calc / 2]);
            calc = calc / 2;
        }
    }
}

template <class T>
void min_heap<T>::display(){
    for (int i = 0; i < cap; i++){
        if (arr[i] != -1){
            cout << arr[i] << " ";
        }
    }
    cout << "\n";
}

template <class T>
int max_heap<T>::getMax(){
    return arr[0];
}

template <class T>
int min_heap<T>::getMin(){
    return arr[0];
}

int main(){
    int cap, value;
    cout << "Enter the length of the heap: ";
    cin >> cap;
    cout << "ENTER 1 FOR MAX-HEAP and 2 for MIN-HEAP: ";
    bool check = true;
    int choice, choice2, choice3, count = 0, min_count = 0;
    cin >> choice;
    min_heap<int> arr_min(cap);
    max_heap<int> arr_max(cap);
    switch(choice){
        case 1:
            cout << "Enter the elements: ";
            while(check != false){
                cin >> value;
                count++;
                arr_max.insertElement(value);
                if(count >= cap){
                    cout<<"End of Array reached.\n";
                    break;
                }
            }
            cout << "\nThe max-heap created is: ";
            arr_max.display();
            cout << "Enter 1 to DELETE and 0 to QUIT.\n";
            cin >> choice2;
            min_count = cap;
            while(choice2 == 1){
                arr_max.deleteElement();
                min_count--;
                if (min_count == 0){
                    cout << "No more elements left to delete.\n";
                    break;
                }
                cout << "\nThe max-heap after deletion is: ";
                arr_max.display();
                cout << "Enter 1 to DELETE and 0 to QUIT.\n";
                cin >> choice2;
            }
            cout << endl << "The max element of the heap is: " <<
            arr_max.getMax() << endl;
            break;
        case 2:
            cout << "Enter the elements: ";
            while(check != false){
                cin >> value;
                count++;
                arr_min.insertElement(value);
                if(count > cap){
                    cout << "End of Array reached.\n";
                    break;
                }
            }
            cout << "\nThe min-heap created is: ";
            arr_min.display();
            cout << "Enter 1 to DELETE and 0 to QUIT.\n";
            cin >> choice3;
            min_count = cap;
            while(choice3 == 1){
                arr_min.deleteElement();
                min_count--;
                if (min_count == 0){
                    cout << "No more elements left to delete.\n";
                    break;
                }
                cout << "\nThe min-heap after deletion is: ";
                arr_min.display();
                cout << "Enter 1 to DELETE and 0 to QUIT.\n";
                cin >> choice3;
            }
            break;
            cout << endl << "The min element of the heap is: " << arr_min.getMin() << endl;
        default:
            cout << "Wrong Choice.\n";
    }
    arr_min.dealloc();
    arr_max.dealloc();
    return 0;
}