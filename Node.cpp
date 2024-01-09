#pragma once
#include "bits/stdc++.h"
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
        ~Node(){};
};
template <class T> 
Node<T>::Node(T val){
    data = val;
    link = NULL;
}