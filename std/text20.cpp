#include <bits/stdc++.h>
using namespace std;

bool ss(int n){
    int i=2;
    if (n==1)return false;
    for (;i<sqrt(n);i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}
void gdbh(int n){
    int i=2;
    for (;i<sqrt(n);i++){
        if (ss(i) && ss(n-i)){
            cout<<n<<"="<<i<<"+"<<n-i<<endl;
            break;
        }
    }
}
int main(){
    int n,i=2;
    cin>>n;
    for (;i<=n;i=i+2){
        gdbh(i);
    }
    return 0;
}
