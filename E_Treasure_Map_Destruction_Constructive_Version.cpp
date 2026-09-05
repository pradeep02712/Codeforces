#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i){
        cin >> b[i];
    }
    set<int> v;
    for (int i = 0; i < n; ++i){
        v.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        if (b[i] != -1) {
            int l = max(0LL, i - b[i] + 1);
            int r = min(n - 1, i + b[i] - 1);
            auto it = v.lower_bound(l);
            while (it != v.end() && *it <= r){
                it = v.erase(it); 
            }
        }
    }
    if (v.empty()){
        cout << -1 << endl;
        return;
    }
    bool p = true;
    for (int i = 0; i < n; ++i){
        if (b[i] != -1) {
            bool f = false;
            if (i - b[i] >= 0 && v.count(i - b[i])){
                f = true;
            }
            if (i + b[i] < n && v.count(i + b[i])){
                f = true;
            }
            if (!f){
                p = false;
                break;
            }
        }
    }
    if (p){
        string a(n, '0');
        for (int x : v) {
            a[x] = '1';
        }
        cout << a << endl;
    }
    else{
        cout << -1 << endl;
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
    return 0;
}