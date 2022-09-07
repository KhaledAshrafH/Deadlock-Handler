#include <iostream>
#include "Banker.h"
using namespace std;

int main() {
    int n,m;
    cout<<"Enter Number of Processes : ";cin>>n;
    cout<<"Enter Number of Resources : ";cin>>m;
    Banker b(n,m);
    b.Read();
    b.calcNeed();
    b.displayNeed();
    if (b.CheckSafeState()){
        cout<<"Safe Staaaaaaaaaaaaaaaaaaaaaaaaaaaaate\n";
    } else  cout<<"Not Safe Staaaaaaaaaaaaaaaaaaaaaaaaaaaaate\n";
}