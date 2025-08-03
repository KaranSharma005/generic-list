#include<iostream>
#include "./nodeClass.h"
using namespace std;

template<typename T>
class List {
    Node<T>* head = NULL;
    public : 
    //add Node
    void addAtStart(T data);
    void addInMiddle(int index, T data);
    void addAtLast(T data);

    //display list
    void display();

    //delete
    Node<T>* deleteHead();
    Node<T>* deleteatIndex(int index);  //0 indexed
    Node<T>* deleteFromLast();

    //getNode
    Node<T>* getNode(int index);
};

template<typename T>
void List<T>::addAtStart(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = head; 
    head = newNode;  
    delete newNode;   
}

//add after the given index (0 indexed)
template<typename T>
void List<T> :: addInMiddle(int index, T data){
    Node<T>* temp = head;
    Node<T>* tail = NULL;
    
    if(index == 0){
        addAtStart(data);
        return;
    }
    Node<T>* newNode = new Node<T>(data);

    int i=0;
    while(temp && i < index){
        tail = temp;
        temp = temp -> next;
        i++;
    }

    if(temp){
        newNode -> next = temp;
        tail -> next = newNode;
    }
    else{
        tail -> next = newNode;
    }
    delete newNode;
}

template<typename T>
Node<T>* List<T> :: getNode(int index){
    int i=0;
    Node<T>* temp = head;

    while(temp && i<index){
        temp = temp -> next;
        i++;
    }
    return temp;
}

template<typename T>
void List<T> :: addAtLast(T data){
    if(head == NULL){
        addAtStart(data);
        return;
    }

    Node<T>* temp = head;
    while(temp -> next){
        temp = temp -> next;
    }
    Node<T>* newNode = new Node<T>(data);
    temp -> next = newNode;
    delete newNode;
}

template<typename T>
void List<T> :: display(){
    Node<T>* temp = head;
    while(temp){
        cout<<(temp -> val)<<"\n";
        temp = temp -> next;
    }
}

template<typename T>
Node<T>* List<T> :: deleteHead(){
    if(head == NULL){
        cout<<"List undeflow\n";
        return NULL;
    }
    Node<T>* temp = head;
    head = head -> next;
    return temp;
}

template<typename T>
Node<T>* List<T> :: deleteFromLast(){
    if(head == NULL){
        cout<<"List Underflow\n";
        return NULL;
    }
    if(head -> next == NULL){
        Node<T>* temp = head;
        head = NULL;
        return head;
    }
    Node<T>* temp = head;
    Node<T>* tail = NULL;
    while(temp -> next){
        tail = temp;
        temp = temp -> next;
    }
    tail -> next = NULL;
    return temp;
}

template<typename T>
Node<T>* List<T> :: deleteatIndex(int index){
    int i = 0;
    Node<T>* temp = head;
    if(head == NULL){
        cout<<"List Underflow";
        return NULL;
    }
    if(index == 0){
        Node<T>* t = head;
        head = head -> next;
        return t;
    }
    Node<T>* tail = NULL;
    while(temp && i<index){
        tail = temp;
        temp = temp -> next;
        i++;
    }
    if(temp == NULL){
        cout<<"NO node exist";
        return NULL;
    }
    Node<T>* t = temp;
    tail -> next = temp -> next;
    return t;
}