#include<iostream>
#include "./library/operations.h"
using namespace std;
int main(){
    List<int> myList;
    cout<<"Start";
    myList.addAtStart(0);
    myList.addAtStart(1);
    myList.addAtStart(2);
    myList.addInMiddle(5,4);
    myList.addAtLast(6);

    // cout<<myList.deleteFromLast();
    myList.display();
    cout<<"End";
    return 0;
}