#include<bits/stdc++.h>
using namespace std;
class max_heap{
    int *arr;
    int cap;
    int current_size;
    public:
        max_heap(int);
        void insertOps(int);
        void deleteOps();
        void heapify(int*,int);
        int getMax();
        void display();
        void dealloc();
};
class min_heap{
    int *arr;
    int cap;
    int current_size;
    public:
        min_heap(int);
        void insertOps(int);
        void deleteOps();
        void heapify(int*,int);
        int getMin();
        void display();
        void dealloc();
};
min_heap::min_heap(int sz)
{
    cap = sz;
    arr = new int[cap];
    current_size = 0;
}
void min_heap::dealloc(){
    delete[] arr;
}
max_heap::max_heap(int sz)
{
    cap = sz;
    arr = new int[cap];
    current_size = 0;
}
void max_heap::dealloc(){
    delete[] arr;
}
void max_heap::heapify(int *arr, int i)
{
    int l=(2*i),r=(2*i)+1,large=0;
    if(l<=cap && arr[l]>arr[i]){
        large = l;
    } else {
        large = i;
    }
    if(r<=cap && arr[r]>arr[large]){
        large = r;
    }
    if(large!=i){
        swap(arr[large],arr[i]);
        heapify(arr,large);
    }
}

void min_heap::heapify(int *arr, int i)
{
    int l=(2*i),r=(2*i)+1,large=0;
    if(l<=cap && arr[l]<arr[i]){
        large = l;
    } else {
        large = i;
    }
    if(r<=cap && arr[r]<arr[large]){
        large = r;
    }
    if(large!=i){
        swap(arr[large],arr[i]);
        heapify(arr,large);
    }
}

void max_heap::insertOps(int val)
{
    // cout<<current_size<<" "<<cap<<"\n";
    if(current_size>=cap){
        cout<<"Heap size overload seen!\n";
    } else {
        current_size+=1;   
        arr[current_size-1] = val;
        int calc = current_size-1;
        while(calc!=0 && arr[calc]>arr[calc/2]){
            swap(arr[calc],arr[calc/2]);
            calc = calc/2;
        }
    }
}
void max_heap::deleteOps()
{
    int val = arr[0];
    arr[0] = arr[current_size-1];
    arr[current_size-1] = -1;
    max_heap::heapify(arr,0);
}
void min_heap::deleteOps()
{
    int val = arr[0];
    arr[0] = arr[current_size-1];
    arr[current_size-1] = -1;
    min_heap::heapify(arr,0);
}
void max_heap::display()
{
    for(int i=0;i<cap;i++){
        if(arr[i]!=-1){
            cout<<arr[i]<<" ";
        }
    }
    cout<<"\n";
}
void min_heap::insertOps(int val)
{
    // cout<<current_size<<" "<<cap<<"\n";
    if(current_size>=cap){
        cout<<"Heap size overload seen!\n";
        return;
    } else {
        current_size+=1;   
        arr[current_size-1] = val;
        int calc = current_size-1;
        while(calc!=0 && arr[calc]<arr[calc/2]){
            swap(arr[calc],arr[calc/2]);
            calc = calc/2;
        }
    }
}
void min_heap::display()
{
    for(int i=0;i<cap;i++){
        if(arr[i]!=-1){
            cout<<arr[i]<<" ";
        }
    }
    cout<<"\n";
}
int main()
{
    int cap,val;
    cout<<"Enter the capacity of the heap"<<endl;
    cin>>cap;
    cout<<"Choose one of the options : "<<"\n";
    cout<<"1. Max Heap. "<<"\n";
    cout<<"2. Min Heap. "<<"\n";
    bool check = true;
    int ch,t,t1;
    cin>>ch;
    min_heap ins1(cap);
    max_heap ins(cap);
    int cnt = 0;
    switch(ch){
        case 1:
            cout<<"Enter the elements : ";
            while(check){
                cin>>val;
                cnt++;
                if(cnt>cap){
                    cout<<"Limit Exceeded!\n";
                    break;
                }
                ins.insertOps(val);
            }
            cout<<"\nThe Max Heap is : ";
            ins.display();
            cout<<"Enter 1 to delete else 0 to exit!\n";
            cin>>t;
            while(t==1){
                ins.deleteOps();
                cout<<"\nThe Modified-Max Heap is : ";
                ins.display();
                cout<<"If you want to delete more press 1 else 0 to exit!\n";
                cin>>t;
            }
            break;
        case 2:
            cout<<"Enter the elements : ";
            while(check){
                cin>>val;
                cnt++;
                if(cnt>cap){
                    cout<<"Limit Exceeded!\n";
                    break;
                }
                ins1.insertOps(val);
            }
            cout<<"\nThe Min Heap is : ";
            ins1.display();
            cout<<"Enter 1 to delete else 0 to exit!\n";
            cin>>t1;
            while(t1==1){
                ins1.deleteOps();
                cout<<"\nThe Modified-Min Heap is : ";
                ins1.display();
                cout<<"If you want to delete more press 1 else 0 to exit!\n";
                cin>>t1;
            }
            break;
        default: 
            cout<<"Wrong input!\n";    
    }
    ins.dealloc();
    ins1.dealloc();
    return 0;
}