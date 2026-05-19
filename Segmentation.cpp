#include<iostream>
using namespace std;
struct Segment{
    int base;
    int limit;
};
int main(){
    Segment segmentTable[50];
    int n;
    int physicalAddress, offset, segmentNo;

    cout<<"Enter into Segment Table: ";
    for(int i=0;i<n;i++){
        cout<<"Segment "<<i<<" Base: ";
        cin>>segmentTable[i].base;
        cout<<"Segment "<<i<<" Limit: ";
        cin>>segmentTable[i].limit;
    }

    cout<<"Enter Logical Address (segmentNo,offset): ";
    cin>>segmentNo>>offset;

    if(segmentNo>=n){
        cout<<"Invalid Logical Address!"<<endl;
        return 0;
    }
    if(offset>=segmentTable[segmentNo].limit){
        cout<<"Offset exceeds segment Limit!"<<endl;
    }
    else{
        physicalAddress = segmentTable[segmentNo].base + offset;
        cout<<"Physical Address: "<<physicalAddress<<endl;
    }
    return 0;
}
