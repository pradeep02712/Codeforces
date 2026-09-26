#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F(i, a, b) for(int i = (a); i < (b); i++)

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    F(i, 0, n){
        cin >> a[i];
    }
    if (x == 1){
        cout << 0 << endl;
        return;
    }
    vector<int> v;
    int m = x;
    for (int i = 2; i * i <= m; ++i){
        if (m % i == 0) {
            v.push_back(i);
            while (m % i == 0){
                m /= i;
            }
        }
    }
    if (m > 1){
        v.push_back(m);
    }
    int r = 0;
    for (int p : v){
        int s = 0;
        F(i, 0, n){
            if (a[i] % p == 0){
                s += a[i];
            }
        }
        r = max(r, s);
    }
    cout << r << endl;
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