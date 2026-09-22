#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F(i, a, b) for(int i = (a); i < (b); i++)

void solve(){
    int n,k;
    cin >>n>>k;
    vector<int> a(n);
    int m = 0;
    F(i,0,n){
        cin >> a[i];
        m = max(m,a[i]);
    }
    vector<int> d(m+1,1e18);
    F(i,1,min(k,m)+1){
        d[i] = 0;
    }
    vector<int> p;
    vector<bool> b(m+1,true);
    F(i,2,m+1){
        if (b[i]){
            p.push_back(i);
            for (int j=2*i; j<=m; j+=i){
                b[j] = false;
            }
        }
    }
    F(i,1,m+1){
        if (d[i]==1e18) continue; 
        for (int j : p){ 
            int y = i*j;
            if (y > m){
                break; 
            }
            d[y] = min(d[y], 1+j*d[i]);
        }
    }
    int r=0;
    F(i,0,n){
        r+=d[a[i]];
    }
    cout <<r<< endl;
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