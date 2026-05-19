#include<iostream>
using namespace std;
int main(){
    int n;
    int logicalAddress, physicalAddress, pageSize, pageNumber, offset, frameNumber;
    cout<<"Enter no of pages: ";
    cin>>n;

    int pageTable[n];
    cout<<"Enter Page Table: ";
    for(int i=0;i<n;i++){
        cin>>pageTable[i];
    }

    cout<<"Enter Page Size: ";
    cin>>pageSize;

    cout<<endl;

    cout<<"Enter logical Address: ";
    cin>>logicalAddress;

    pageNumber = logicalAddress / pageSize;
    offset = logicalAddress % pageSize;

    if(pageNumber>n){
        cout<<"Invalid logical Address!"<<endl;
    }

    frameNumber = pageTable[pageNumber];

    physicalAddress = (frameNumber * pageSize) + offset;

    cout<<endl;
    cout<<"Physical Address: "<<physicalAddress;

    return 0;
}
