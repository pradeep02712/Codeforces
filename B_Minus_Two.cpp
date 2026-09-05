#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    int f[3] = {0,0,0};
    for (int i = 0;i < n; ++i){
        int x;
        cin >> x;
        f[(x & 1) ? 0 : ((x & 3) == 0 ? 1 : 2)]++;
    }
    cout << max({f[0], f[1], f[2]}) << endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t; 
    while(t--){
        solve();
    }
}