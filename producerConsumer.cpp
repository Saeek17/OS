#include<iostream>
#include<semaphore>
#include<thread>
#include<mutex>
using namespace std;
#define SIZE 5

int buffer[SIZE];
int in=0, out=0;

counting_semaphore<SIZE> empty(SIZE);
counting_semaphore<SIZE> full(0);

mutex mtx;

void producer(){
    for(int i=1;i<=5;i++){
        empty.aquire();

        mtx.lock();
        buffer[in]=i;
        cout<<"Produced "<<i<<endl;
        in = (in+1) % SIZE;
        mtx.unlock();

        full.release();
    }
}
void consumer(){
    for(int i=1;i<=5;i++){
        full.aquire();

        mtx.lock();
        int item = buffer[out];
        cout<<"Consumed: "<<item<<endl;
        out = (out+1) % SIZE;
        mtx.unlock();

        empty.release();
    }
}
int main(){
    thread p(producer);
    thread c(consumer);

    p.join();
    c.join();

    return 0;
}
