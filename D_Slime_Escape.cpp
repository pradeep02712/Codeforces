#include<bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    for(int i=2;i<x;i++){
        if(x%i==0)return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        if(isPrime(i)){
            cout<<i<<" ";
        }
    }
}