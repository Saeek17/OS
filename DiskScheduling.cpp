#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int req[50];
    int n;
    cout<<"Enter no  of processes in request queue: "<<endl;
    cin>>n;
    int head;
    cout<<"Enter head position: "<<endl;
    cin>>head;
    cout<<"Enter request sequence: "<<endl;
    for(int i=0;i<n;i++){
        cin>>req[i];
    }

    //FCFS
    cout<<"FCFS ALGORITHM"<<endl;
    int total =0;
    int curr = head;
    for(int i=0;i<n;i++){
        total += abs(req[i]-curr);
        curr = req[i];
    }
    cout<<"Total seek time: "<<total;

    //SSJF
    cout<<"SSJF ALGORITHM"<<endl;
    int total=0;
    int curr = head;
    int visited[50] = {0};
    for(int i=0;i<n;i++){
        int min=9999, pos=-1;
        for(int j=0;j<n;j++){
            int dist = abs(req[j]-curr);
            if(dist<min && !visited[j]){
                min=dist;
                pos=j;
            }
        }
        visited[pos]=1;
        total += abs(req[pos] - curr);
        curr = req[pos];
    }
    cout<<"Total seek Time: "<<total<<endl;

    //SCAN
    cout<<"SCAN ALGORITHM"<<endl;
    int total = 0;
    int curr = head;
    int l=0, r=0;
    int left[50];
    int right[50];
    int size = 200;
    int dir;
    cout<<"Enter dir (1=right 0=left): "<<endl;
    cin>>dir;

    for(int i=0;i<n;i++){
        if(req[i]<curr){
            left[l++]=req[i];
        }
        else{
            right[r++]=req[i];
        }
    }
    //sort left and right array
    for(int i=0;i<l-1;i++){
        for(int j=0;j<l-i-1;j++){
            if(left[j]>left[j+1]){
                int temp = left[j];
                left[j] = left[j+1];
                left[j+1] = temp;
            }
        }
    }
    for(int i=0;i<r-1;i++){
        for(int j=0;j<r-i-1;j++){
            if(right[j]>right[j+1]){
                int temp=right[j];
                right[j]=right[j+1];
                right[j+1]=temp;
            }
        }
    }
    if(dir==1){
        for(int i=0;i<r;i++){
            total += abs(right[i] - curr);
            curr = right[i];
        }
        total += abs((size-1)-curr);
        curr = size-1;
        for(int i=l-1;i>=0;i--){
            total += abs(left[i]-curr);
            curr = left[i];
        }
    }
    else{
        for(int i=l-1;i>=0;i--){
            total += abs(left[i]-curr);
            curr=left[i];
        }
        total += abs(0-curr);;
        curr = 0;
        for(int i=0;i<r;i++){
            total += abs(right[i]-curr);
            curr=right[i];
        }
    }
    cout<<"Total seek time: "<<total<<endl;

    //C-SCAN
    cout<<"C-SCAN ALGORITHM"<<endl;
    int total = 0;
    int curr = head;
    int l=0;
    int r=0;
    int left[50];
    int right[50];
    int dir;
    cout<<"Enter direction (1=right 0=left): "<<endl;
    cin>>dir;
    for(int i=0;i<n;i++){
        if(req[i]<curr){
            left[l++]=req[i];
        }else{
            right[r++]=req[i];
        }
    }
    //Sort left and right
    for(int i=0;i<l-1;i++){
        for(int j=0;j<l-i-1;j++)
        if(left[j]>left[j+1]){
            int temp=left[j];
            left[j]=left[j+1];
            left[j+1]=temp;
        }
        }
    }
    for(int i=0;i<r-1;i++){
        for(int j=0;j<r-i-1;j++)
        if(right[j]>right[j+1]){
            int temp=right[j];
            right[j]=right[j+1];
            right[j+1]=temp;
        }
        }
    }
    int size=200;
    if(dir==1){
        for(int i=0;i<r;i++){
            total += abs(right[i]-curr);
            curr=right[i];
        }
        total += abs((size-1)-curr);
        curr = size-1;
        total += abs(0-curr);
        curr=0;
        for(int i=0;i<l;i++){
            total += abs(left[i]-curr);
            curr=left[i];
        }
    }
    else{
        for(int i=l-1;i>=0;i--){
            total += abs(left[i]-curr);
            curr = left[i];
        }
        total += abs(0-curr);
        curr = 0;
        toatl += abs((size-1)-curr);
        curr = size-1;
        for(int i=r-1;i>=0;i--){
            total += abs(right[i]-curr);
            curr = right[i];
        }
    }
    cout<<"Total seek Time: "<<total<<endl;
}
