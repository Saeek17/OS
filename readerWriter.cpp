#include<iostream>
#include<thread>
#include<mutex>
#include<semaphore>
using namespace std;

counting_semaphore<1> mutex(1);
counting_semaphore<1> rw_mutex(1);

int read_count = 0;

void reader(int id){
    mutex.aquire();

    read_count++;
    if(read_count==1){
        rw_mutex.aquire();
    }
    mutex.release();

    cout<<"Reader "<<id<<" is reading."<<endl;

    mutex.aquire();
    read_count--;

    if(read_count==0){
        rw_mutex.release();
    }
    mutex.release();
}
void  writer(int id){
    rw_mutex.aquire();
    cout<<"Writer "<<id<<" is writing."<<endl;
    rw_mutex.release();
}
int main(){
    thread r1(reader,1);
    thread r2(reader,2);
    thread w1(writer,1);

    r1.join();
    r2.join();
    w1.join();
}
