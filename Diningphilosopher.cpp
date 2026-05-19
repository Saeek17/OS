#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
using namespace std;

#define N 5

mutex chopstick[N];
mutex mtx;

void philosopher(int id){
    int left = id;
    int right = (id+1)%N;

    if(id%2==0){
        chopstick[left].lock();
        chopstick[right].lock();
    }
    else{
        chopstick[right].lock();
        chopstick[left].lock();
    }
    mtx.lock();
    cout<<"Philosopher "<<id<<" is eating."<<endl;
    mtx.unlock();

    chopstcik[left].unlock();
    chopstick[right].unlock();
}
int main(){
    vector<thread> philosophers;

    for(int i=0;i<N;i++){
        philosophers.push_back(thread(philosopher,i));
    }
    for(int i=0;i<N;i++){
        philosophers[i].join();
    }
    return 0;
}

