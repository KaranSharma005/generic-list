#include<iostream>
#include "./library/operations.h"
using namespace std;
int main(){
    List<int> myList;
    myList.addAtStart(0);
    myList.addAtStart(1);
    myList.addAtStart(2);
    myList.addInMiddle(5,4);
    myList.addAtLast(6);

    Node<int>* result = myList.deleteatIndex(0);
    if(result)
    cout<<(result -> val)<<"deleted node \n";
    myList.display();
    return 0;
}