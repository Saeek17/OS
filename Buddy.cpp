#include<iostream>
using namespace std;
int nextPowerof2(int n){
    return pow(2,ceil(log2(n)));
}
int main(){
    int totalMem;
    int n;
    int processSize[n];
    cout<<"Enter Total Memory: ";
    cin>>totalMem;
    cout<<"Enter no of Processes: ";
    cin>>n;
    cout<<"Enter Process Sizes: ";
    for(int i=0;i<n;i++){
        cin>>processSize[i];
    }
    cout<<"BUDDY SYSTEM ALLOCATION"<<endl;
    for(int i=0;i<n;i++){
        int required = nextPowerof2(processSize[i]);
        if(required>totalMem){
            cout<<"Process "<<i+1<<" "<<processSize[i]<<" not Allocated!"<<endl;
        }
        else{
            cout<<"Process "<<i+1<<" "<<processSize[i]<<" "<<required<<" memory allocated!"<<endl;
            totalMem -= required;
        }
    }
    cout<<"Remaining Memory: "<<totalMem;
    return 0;
}
