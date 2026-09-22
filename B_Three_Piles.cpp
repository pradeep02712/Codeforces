#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int x = abs(a - b);
    int y = abs(a + c - b);
    cout << max(x, y) << endl;
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