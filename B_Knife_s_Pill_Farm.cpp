#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve(){
    int n, m, s = 0, r = -2e18;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    priority_queue<int> q;
    for (int i = 0; i < m - 1; i++){
        q.push(a[i]);
        s += a[i];
    }
    for (int i = m - 1; i < n; ++i){
        r = max(r, m * a[i] - s);
        q.push(a[i]);
        s += a[i] - q.top();
        q.pop();
    }
    cout << r << endl;
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