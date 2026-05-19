#include<iostream>
using namespace std;
#define MAX 10
int main(){
    int n, m;
    int Max[n][m];
    int Need[n][m];
    int allocation[n][m];
    int available[m];
    int total[m];
    cout<<"Enter no of processes: ";
    cin>>n;

    cout<<"Enter no of resources: ";
    cin>>m;

    cout<<"Enter Total Instances of each Resource: ";
    for(int i=0;i<m;i++){
        cin>>total[i];
    }

    cout<<"Enter Allocation Matrix: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>allocation[i][j];
        }
    }

    cout<<"Enter Max Matrix: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>Max[i][j];
        }
    }

    //Calculate Need matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Need[i][j] = Max[i][j] - allocation[i][j];
        }
    }

    for(int i=0;i<m;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            sum += allocation[j][i];
        }
        available[i] += sum;
    }
    cout<<"Available Resources: "<<endl;
    for(int i=0;i<m;i++){
        cout<<available[i]<<" ";
    }

    //SAFETY ALGORITHM
    int work[m];
    bool finish[n]={false};
    int safeSeq[n];

    for(int i=0;i<m;i++){
        work[j] = available[j];
    }

    int count = 0;
    while(count<n){
        bool found = false;

        for(int i=0;i<n;i++){
            if(!finish[i]){
                bool possible = true;
                for(int j=0;j<m;j++){
                    if(Need[i][j] > work[j]){
                        possible = false;
                        break;
                    }
                }
                if(possible){
                        for(int j=0;j<m;j++){
                            work[j] += allocation[i][j];
                        }
                    finish[i]=true;
                    safeSeq[count++] = i;
                    found = true;
                }
            }
        }
        if(!found){
            break;
        }
    }
    if(count==n){
        cout<<"System is safe!"<<endl;
        cout<<"Safe Sequence: "<<endl;
        for(int i=0;i<n;i++){
            cout<<"Process "<<safeSeq[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"System is unsafe!"<<endl;
    }
    return 0;
}
