using namespace std;
#include "queue"

class Banker{
    int n,m; // n --> p  // m --> R
    int *available;
    int *work;
    bool *finish;

    int **Maximum;
    int **allocated;
    int **need;
public:
    void calcNeed() const;
    void displayNeed() const;
//    void displayAvailable() const;
    void Read();
    bool CheckAllocation(int);// NeedLessThanOrEqualWork

    bool CheckFinish();
    bool isFull();//work = available
    bool CheckSafeState();
    Banker(int,int);
    ~Banker();
};

Banker::Banker(int row, int col) {
        n=row,m=col;
        available = new int[m];
        work = new int[m];
        finish = new bool[n];

        Maximum = new int*[n];
        allocated = new int*[n];
        need = new int*[n];

        for (int i = 0; i < n; ++i) {
            Maximum[i] = new int[m];
            allocated[i] = new int[m];
            need[i] = new int[m];
        }
}

Banker::~Banker() {
        delete []available;
        delete []work;
        delete []finish;
        for (int i = 0; i < n; i++) {
            delete[] Maximum[i];
            delete[] allocated[i];
            delete[] need[i];
        }
        delete[] Maximum;
        delete[] allocated;
        delete[] need;
}

void Banker::calcNeed() const {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = Maximum[i][j] - allocated[i][j];
        }
    }
}

void Banker::displayNeed() const {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<need[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void Banker::Read(){

    cout << "Enter Matrix Allocated: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            allocated[i][j] = num;
        }
    }

    cout << "Enter Matrix Maximum: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            Maximum[i][j] = num;
        }
    }

    cout << "Enter Matrix Available: \n";
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        available[i] = num;
    }

    for (int i = 0; i < n; i++) {
        finish[i] = false;
    }

    for (int i = 0; i < m; i++) {
        work[i] = available[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
        available[j]+=allocated[i][j];
        }
    }

}

bool Banker::CheckSafeState() {
    queue <int> q;
    for (int i = 0; i < n; i++)q.push(i);
    int index = q.front();
    int Current=0;

    while(!q.empty()){
        if(!finish[index] && CheckAllocation(index)){

            for (int i = 0; i < m; i++) {
                work[i]+=allocated[index][i];
            }

            finish[index] = true;
            q.pop();
            Current = 0;
            index++;
        }
        else
        {
            Current++;
            index++;
            if (index == n )index=0;
            if(Current==q.size()+1)break;//base case
            continue;
        }
        if (index == n )index=0;
        if(Current==q.size())break;//base case
    }

    if(CheckFinish()){
        return true;
    } else return false;
}

bool Banker::isFull() {
    for (int i = 0; i < m; i++) {
       if (work[i] != available[i])return false;
    }
    return true;
}

bool Banker::CheckAllocation(int index) {
    for (int i = 0; i < m; i++) {
        if (need[index][i]>work[i]) return false;
    }
    return true;
}

bool Banker::CheckFinish() {
    for (int i = 0; i < n; i++) {
        if (!finish[i]) return false;
    }
    return true;
}

//void Banker::displayAvailable() const {
//    for (int j = 0; j < m; j++) {
//        cout << available[j] << " ";
//    }
//}
