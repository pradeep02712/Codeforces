#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define endl '\n'

#define F(i, a, b) for(int i = (a); i < (b); i++)
#define R(i, a, b) for(int i = (a); i > (b); i--)


ll gcd(ll a,ll b){
    return b ? gcd(b,a % b) : a ;
}

ll lcm(ll a,ll b){
    return a / gcd(a,b) * b;
}

void solve(){
    int n;cin>>n;
    int arr[n];
    F(i,0,n){
        cin>>arr[i];
    }
    
    cout<<*min_element(arr,arr+n)<<endl;

}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }

}