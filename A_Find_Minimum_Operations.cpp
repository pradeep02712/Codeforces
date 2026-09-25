#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve(){
  int n,k;
  cin>>n>>k;
  if(k==1){
    cout<<n<<endl;
    return;
  }
  int a=0;
  while(n){
     a += n%k;
     n /= k;    
  }
  cout<<a<<endl;
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