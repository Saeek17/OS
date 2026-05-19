#include <iostream>
using namespace std;

const int MAX = 10;

int n, m;
int Total[MAX];
int Available[MAX];
int Allocation[MAX][MAX];
int Request[MAX][MAX];


void calculateAvailable() {
    for(int j = 0; j < m; j++) {
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += Allocation[i][j];

        Available[j] = Total[j] - sum;
    }
}


bool detectDeadlock() {
    int Work[MAX];
    bool Finish[MAX];
    bool deadlocked = false;


    for(int j = 0; j < m; j++)
        Work[j] = Available[j];


    for(int i = 0; i < n; i++) {
        bool isZero = true;
        for(int j = 0; j < m; j++) {
            if(Allocation[i][j] != 0) {
                isZero = false;
                break;
            }
        }
        Finish[i] = isZero ? true : false;
    }


    while(true) {
        bool found = false;

        for(int i = 0; i < n; i++) {
            if(!Finish[i]) {
                bool possible = true;

                for(int j = 0; j < m; j++) {
                    if(Request[i][j] > Work[j]) {
                        possible = false;
                        break;
                    }
                }

                if(possible) {
                    for(int j = 0; j < m; j++)
                        Work[j] += Allocation[i][j];

                    Finish[i] = true;
                    found = true;
                }
            }
        }

        if(!found)
            break;
    }


    cout << "\nAvailable resources: ";
    for(int j = 0; j < m; j++)
        cout << Available[j] << " ";

    cout << "\nDeadlocked processes: ";
    for(int i = 0; i < n; i++) {
        if(!Finish[i]) {
            cout << "P" << i << " ";
            deadlocked = true;
        }
    }

    if(!deadlocked) {
        cout << "None\nSystem is NOT in deadlock\n";
    } else {
        cout << "\nSystem IS in deadlock\n";
    }

    return deadlocked;
}


int main() {
    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    cout << "Enter Allocation matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> Allocation[i][j];

    cout << "Enter Request matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> Request[i][j];

    cout << "Enter Total resources:\n";
    for(int i = 0; i < m; i++)
        cin >> Total[i];


    calculateAvailable();

    detectDeadlock();

    return 0;
}

