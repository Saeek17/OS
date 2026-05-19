#include<iostream>
using namespace std;
//First Fit
void firstfit(){
    int n, m;
    int blocks[m];
    int process[n];
    int allocation[n];

    cout<<"Enter no of blocks: ";
    cin>>m;

    cout<<"Enter no of processes: ";
    cin>>n;

    cout<<"Enter memory blocks: ";
    for(int i=0;i<m;i++){
        cin>>blocks[i];
    }

    cout<<"Enter processes: ";
    for(int i=0;i<n;i++){
        cin>>process[i];
    }

    for(int i=0;i<n;i++){
        allocation[i] = -1;

        for(int j=0;j<m;j++){
            if(blocks[j] >= process[i]){
                allocation[i]=j;
                blocks[j] -=  process[i];
                break;
            }
        }
    }
    cout << "First Fit Allocation:\n";
    for(int i = 0; i < n; i++) {
        cout << "Process " << i+1 << " (" << processSize[i] << ") -> ";
        if(allocation[i] != -1)
            cout << "Block " << allocation[i] + 1 << endl;
        else
            cout << "Not Allocated\n";
    }
}
//Best Fit
void bestFit(){
    int n, m;
    int blocks[m];
    int process[n];
    int allocation[n];

    cout<<"Enter no of blocks: ";;
    cin>>m;

    cout<<"Enter no of processes: ";
    cin>>n;

    cout<<"Enter memory blocks: ";
    for(int i=0;i<m;i++){
        cin>>blocks[i];
    }

    cout<<"Enter processes: ";
    for(int i=0;i<n;i++){
        cin>>process[i];
    }

    for(int i=0;i<n;i++){
        allocation[i] = -1;
    }
    for(int i=0;i<n;i++){
        int bestIdx = -1;

        for(int j=0;j<m;j++){
            if(blocks[j] >= process[i]){
                if(bestIdx==-1 || blocks[j]<blocks[bestIdx]){
                    bestIdx = j;
                }
            }
        }
        if(bestIdx!=-1){
            allocation[i] = bestIdx;
            blocks[bestIdx] -= process[i];
        }
    }
    cout<<"\nBest Fit Allocation:\n";
    for(int i=0;i<n;i++){
        cout<<"Process "<<i+1<<" -> ";
        if(allocation[i] != -1)
            cout<<"Block "<<allocation[i]+1<<"\n";
        else
            cout<<"Not Allocated\n";
    }
}
//Next Fit
void nextFit(){
    int n, m;
    int blocks[m];
    int process[n];
    int allocation[n];

    cout<<"Enter no of blocks: ";
    cin>>m;

    cout<<"Enter no of processes: ";
    cin>>n;

    cout<<"Enter memory blocks: ";
    for(int i=0;i<m;i++){
        cin>>blocks[i];
    }

    cout<<"Enter processes: ";
    for(int i=0;i<n;i++){
        cin>>process[i];
    }

    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
    int lastIdx = 0;
    for(int i=0;i<n;i++){
        int count = 0;
        while(count<m){
            if(blocks[lastIdx]>=process[i]){
                allocation[i] = lastIdx;
                blocks[lastIdx] -= process[i];
                break;
            }
            lastIdx = (lastIdx+1) % m;
            count++;
        }
    }
    cout<<"\nNext Fit Allocation:\n";
    for(int i=0;i<n;i++){
        cout<<"Process "<<i+1<<" -> ";
        if(allocation[i] != -1)
            cout<<"Block "<<allocation[i]+1<<"\n";
        else
            cout<<"Not Allocated\n";
    }
}
