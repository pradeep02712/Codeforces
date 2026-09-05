#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define F(i, a, b) for(int i = (a); i < (b); ++i)
#define R(i, a, b) for(int i = (a); i >= (b); --i)

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    F(i, 0, n) cin >> a[i];
    string s;
    cin >> s;

    vector<int> r;
    int z = 0;
    
    R(i, n - 1, 0) {
        if (a[i] == 0) z++;
        else r.pb(z);
    }
    
    reverse(all(r)); 

    int c = sz(r);
    vector<int> f(c + 1, 0);
    F(i, 0, c) f[i + 1] = f[i] + r[i];

    int p = 0, q = 0;
    int k = c;

    auto g = [&]() -> int {
        while (k > 0 && r[k - 1] <= q) k--;
        
        if (p >= c || k <= p) return 0;
        return (f[k] - f[p]) - (k - p) * q;
    };

    cout << g() << " ";
    F(i, 0, n) {
        if (s[i] == '1') p++;
        else q++;
        cout << g() << (i == n - 1 ? "" : " ");
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