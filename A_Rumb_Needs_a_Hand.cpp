#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    int l = 1e18; 
    bool f = true;
    for (int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        if (x != i) {
            if (x > l) {
                f = false;
            }
            l = x;
        }
    }
    if (f){
        cout << "YES" << endl;
    } 
    else{
        cout << "NO" << endl;
    }
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