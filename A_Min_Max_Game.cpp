#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve(){
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)cin>>a[i];
   int c = count(a,a+n,1);
   int b = count(a,a+n,0);
   cout<<(c >= b ? "Bessie" : "Elsie")<<endl;

}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t= 1;
    cin >> t;
    while(t--){
        solve();
    }
}