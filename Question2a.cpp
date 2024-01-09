#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

class max_heap{
    int *arr;
    int cap;
    int curr;
    public:
        max_heap(int);
        void insertElement(int);
        void deleteElement();
        void heapify(int*,int);
        void display();
        void dealloc();
};

class min_heap{
    int *arr;
    int cap;
    int curr;
    public:
        min_heap(int);
        void insertElement(int);
        void deleteElement();
        void heapify(int*,int);
        void display();
        void dealloc();
};

min_heap::min_heap(int size){
    cap = size;
    arr = new int[cap];
    curr = 0;
}

void min_heap::dealloc(){
    delete[] arr;
}

max_heap::max_heap(int size){
    cap = size;
    arr = new int[cap];
    curr = 0;
}

void max_heap::dealloc(){
    delete[] arr;
}

void max_heap::heapify(int *arr, int i){
    int l=(2*i), r=(2*i)+1, max=0;
    if(l <= cap && arr[l] > arr[i]){
        max = l;
    } else {
        max = i;
    }
    if(r <= cap && arr[r] > arr[max]){
        max = r;
    }
    if(max != i){
        swap(arr[max], arr[i]);
        heapify(arr, max);
    }
}

void min_heap::heapify(int *arr, int i){
    int l=(2*i), r=(2*i)+1, min = 0;
    if(l <= cap && arr[l] < arr[i]){
        min = l;
    } else {
        min = i;
    }
    if(r <= cap && arr[r] < arr[min]){
        min = r;
    }
    if(min != i){
        swap(arr[min], arr[i]);
        heapify(arr, min);
    }
}

void max_heap::insertElement(int val){
    if(curr >= cap){
        cout << "Invalid Operation.\n";
        return;
    } else {
        curr += 1;   
        arr[curr-1] = val;
        int index = curr - 1;
        while(index != 0 && arr[index] > arr[index/2]){
            swap(arr[index], arr[index/2]);
            index = index/2;
        }
    }
}

void min_heap::insertElement(int val){
    if(curr >= cap){
        cout << "Invalid Operation.\n";
        return;
    } else {
        curr += 1;   
        arr[curr-1] = val;
        int index = curr-1;
        while(index!=0 && arr[index] < arr[index/2]){
            swap(arr[index], arr[index/2]);
            index = index/2;
        }
    }
}

void max_heap::deleteElement(){
    int val = arr[0];
    arr[0] = arr[curr-1];
    arr[curr-1] = -1;
    max_heap::heapify(arr, 0);
}

void min_heap::deleteElement(){
    int val = arr[0];
    arr[0] = arr[curr-1];
    arr[curr-1] = -1;
    min_heap::heapify(arr, 0);
}

void max_heap::display(){
    for(int i = 0; i < cap; i++){
        if(arr[i] != -1){
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void min_heap::display(){
    for(int i = 0; i < cap;i++){
        if(arr[i] != -1){
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main(){
    int cap, value;
    cout << "Enter the length of the heap: ";
    cin >> cap;
    cout << "ENTER 1 FOR MAX-HEAP and 2 for MIN-HEAP: ";
    bool check = true;
    int choice, choice2, choice3, count = 0, min_count = 0;
    cin >> choice;
    min_heap arr_min(cap);
    max_heap arr_max(cap);
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
        default: 
            cout << "Invalid Input.\n";    
    }
    arr_min.dealloc();
    arr_max.dealloc();
    return 0;
}