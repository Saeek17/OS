#include<iostream>
using namespace std;

class Process{
public:
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int pr;
};
class Scheduler{
public:
    Process p[50];
    int n;

    //input data
    void input(){
        cout<<"Enter no of processes: ";
        cin>>n;

        for(int i=0;i<n;i++){
            cout<<"Enter arrival time of process "<<i+1<<": ";
            cin>>p[i].at;

            cout<<"Enter burst time of process "<<i+1<<": ";
            cin>>p[id].bt;

            cout<<"Enter priority of process  "<<i+1<<": ";
            cin>>p[id].pr;
        }
    }
    //Display
    void display(){
        float totWT, totTAT;

        cout<<"PID AT BT TAT WT"<<endl;

        for(int i=0;i<n;i++){
            cout<<p[i].pid<<" "<<p[i].at<<" "<<p[i].bt<<" "<<p[i].tat<<" "<<p[i].wt;

            totWT += p[i].wt;
            totTAT += p[i].tat;
        }
        cout << "\nAverage Waiting Time = " << totWT/n;
        cout << "\nAverage Turnaround Time = " << totTAT/n << endl;
    }
    //sort by arrival
    void sortArrival(){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(p[j].at>p[j+1].at){
                    int temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }
    //FCFS
    void fcfs(){
        sortArrival();

        int time = 0;
        for(int i=0;i<n;i++){
            if(time<p[i].at){
                time=p[i].at;
            }
            p[i].wt = time - p[i].at;
            time += p[i].bt;
            p[i].ct = time;
            p[i].tat = p[i].ct - p[i].at;
        }
        cout<<"FCFS scheduling: "<<endl;
        display();
    }
    //SJF non preemptive
    void sjfNon(){
        int completed=0;
        int time=0;
        int done[50]={0};
        while(completed<n){
            int idx=-1;
            int minBT=9999;
            for(int i=0;i<n;i++){
                if(done[i]==0 && time>=p[i].at && p[i].bt<minBT){
                   idx = i;
                   minBT = p[i].bt;
                }
            }
            if(idx==-1){
                time++;
                continue;
            }
            p[i].wt = time - p[i].at;
            time += p[i].bt;
            p[i].ct = time;
            p[i].tat = p[i].ct - p[i].at;

            done[idx]=1;

            completed++;
        }
        cout<<"SJF NON PREEMPTIVE: "<<endl;
        display();
    }
    //SJF PREEMPTIVE
    void sjfPremp(){
        int completed=0;
        int time=0;
        int rem[50];
        for(int i=0;i<n;i++){
            rem[i]=p[i].bt;
        }
        while(completed<n){
            int idx=-1;
            int minRem=999;

            for(int i=0;i<n;i++){
                if(p[i].at<=time && rem[i]>0 && rem[i]<minRem){
                    idx=i;
                    minRem=rem[i];
                }
            }
            if(idx==-1){
                time++;
                continue;
            }
            rem[idx]--;
            time++;
            if(rem[idx]==0){
                p[i].ct = time;
                p[i].tat = p[i].ct - p[i].at;
                p[i].wt = p[i].tat - p[i].bt;
                completed++;
            }
        }
        cout<<"SJF PREEMPTIVE"<<endl;
        display();
    }
    //PRIORITY PREEMPTIVE
    void priority(){
        int time=0;
        int completed=0;
        int rem[50];
        for(int i=0;i<n;i++){
            rem[i]=p[i].bt;
        }
        while(completed<n){
            int idx=-1;
            int bestPR = -999;
            for(int i=0;i<n;i++){
                if(p[i].at<=time && rem[i]>0 && p[i].pr>bestPR){
                    idx=i;
                    bestPR = p[i].pr;
                }
            }

        if(idx==-1){
            time++;
            continue;
        }
        rem[idx]--;
        time++;

        if(rem[idx]==0){
            p[i].ct=time;
            p[i].tat=p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
            completed++;
        }
        }
        cout<<"PRIORITY SCHEDULING PREEMPTIVE"<<endl;
        display();
    }
    //ROUND ROBIN
    void roundRobin(int quantum){
        int completed=0;
        int time=0;
        int rem[50];
        for(int i=0;i<n;i++){
            rem[i]=p[i].bt;
        }
        while(completed<n){
            int executed=0;
            for(int i=0;i<n;i++){
                if(p[i].at<=time && rem[i]>0){
                    executed=1;
                    if(rem[i]>quantum){
                        time += quantum;
                        rem[i] -= quantum;
                    }
                    else{
                        time += rem[i];
                        p[i].ct = time;
                        p[i].tat = p[i].ct - p[i].at;
                        p[i].wt = p[i].tat - p[i].bt;
                        rem[i]=0;
                        completed++;
                    }
                }
            }
            if(executed==0){
                time++;
            }
        }
        cout<<"ROUND ROBIN SCHEDULING"<<endl;
        display();
    }
};
