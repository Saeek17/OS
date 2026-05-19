#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<climits>
using namespace std;

//FIFO
void FiFO(vector<int> pages,int capacity){
    int pageFaults=0;
    queue<int> q;
    unordered_map<int,int> inMemory;

    for(int i=0;i<pages.size();i++){
        if(inMemory.find(pages[i] == inMemory.end())){
            pageFaults++;

            if(q.size() == capacity){
                int val = q.front();
                q.pop();
                inMemory.erase(val);
            }
            q.push(pages[i]);
            inMemory(pages[i]) = 1;

            //Print
            cout<<"Step "<<i+1<<": ";
            queue<int> temp = q;
            while(!temp.empty()){
                cout<<temp.front()<<" ";
                temp.pop();
            }
            cout<<endl;
        }
    }
    cout<<"FIFO Page Faults: "<<pageFaults<<endl;
}
//LRU
void LRU(vector<int> pages,int capacity){
    int pageFaults=0;
    vector<int> frames;
    unordered_map<int,int> recent;

    for(int i=0;i<pages.size();i++){
        bool found = false;

        for(int j=0;j<frames.size();j++){
            if(pages[i]==frames[j]){
                found = true;
                break;
            }
        }
        if(!found){
                pageFaults++;
            if(frames.size() < capacity){
                frames.push_back(pages[i]);
            }else{
                int LRU = INT_MAX;
                int pos=-1;
                for(int j=0;j<frames.size();j++){
                    if(recent[frames[j]]<LRU){
                        LRU = recent[frames[i]];
                        pos = j;
                    }
                }
                frames[pos] = pages[i];
            }
        }
        recent[pages[i]] = i;
        cout<<"Step "<<i+1<<": ";
        for(int x : frames) cout<<x<<" ";
        cout<<endl;
    }
    cout<<"LRU OPTIMAL PAGE FAULTS: "<<pageFaults<<endl;
}
//OPTIMAL
void optimal(vector<int> pages, int capacity){
    int pageFaults = 0;
    vector<int> frames;

    for(int i=0;i<pages.size();i++){
        bool found = false;
        for(int j=0;j<frames.size();j++){
            if(pages[i]==frames[j]){
                found = true;
                break;
            }
        }
        if(!found){
            pageFaults++;
            if(frames.size() < capacity){
                frames.push_back(pages[i]);
            }
            else{
                int farther=-999;
                int pos = -1;
                for(int j=0;j<frames.size();j++){
                    int k;
                    for(k=i+1;k<pages.size();k++){
                        if(pages[k]==frames[j]){
                            break;
                        }
                    }
                    if(k==pages.size()){
                        pos = j;
                        break;
                    }
                    else if(k>farther){
                        farther = k;
                        pos = j;
                    }
                }
                frames[pos] = pages[i];
            }
        }
        cout << "Step " << i+1 << ": ";
        for (int x : frames) cout << x << " ";
        cout << endl;
    }
    cout<<"Page Faults for OPTIMAL ALGORITHM: "<<pageFaults<<endl;
}
int main(){

}
