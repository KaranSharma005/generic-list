#include<iostream>
using namespace std;
template <typename T>
class Node{
    public : 
    T val;
    Node* next;
    //Constructors
    Node(T val) {
        this -> val = val;
        this -> next = NULL;
    }
};