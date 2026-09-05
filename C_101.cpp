#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int f = -1, l = -1;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] == 1) {
            if (f == -1) f = i;
            l = i;
        }
    }
    if (f == -1){
        f = n;
        l = -1;
    }
    for (int i = 0; i < f; i++){
        if (a[i] == -1) {
            a[i] = 1;
            break;
        }
    }
    for (int i = n - 1; i > l; i--){
        if (a[i] == -1) {
            a[i] = 1;
            break;
        }
    }
    for (int i = 0; i < n; i++){
        if (a[i] == -1) {
            a[i] = 0;
        }
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
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