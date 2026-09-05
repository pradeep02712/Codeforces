#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> c(n + 2,0); 
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] <= n) {
            c[a[i]]++;
        }
    }
    int m1 = 0, m2 = 0, m3 = 0;
    while (c[m1] >= 1) m1++;
    while (c[m2] >= 2) m2++;
    while (c[m3] >= 3) m3++;

    int A = min(m1, m2 + m3);
    int B = m2;
    int C = m3;
    string s(n, 'C'); 
    vector<int> f(n + 2, 0); 
    for (int i = 0; i < n; i++) {
        int v = a[i];
        if (v > n) continue; 
        
        f[v]++;
        if (v < C) {
            if (f[v] == 1) s[i] = 'A';
            else if (f[v] == 2) s[i] = 'B';
            else if (f[v] == 3) s[i] = 'C';
            else s[i] = 'A'; 
        } 
        else if (v < B) {
            if (f[v] == 1) s[i] = 'A';
            else if (f[v] == 2) s[i] = 'B';
            else s[i] = 'A'; 
        } 
        else if (v < A) {
            s[i] = 'A';
        } 
    }
    int x = 0, y = 0, z = 0;
    vector<bool> p(n + 2, 0), q(n + 2, 0), r(n + 2, 0);
    
    for (int i = 0; i < n; i++) {
        if (a[i] <= n) {
            if (s[i] == 'A') p[a[i]] = 1;
            else if (s[i] == 'B') q[a[i]] = 1;
            else if (s[i] == 'C') r[a[i]] = 1;
        }
    }
    while (p[x]) x++;
    while (q[y]) y++;
    while (r[z]) z++;

    int m = max({x, y, z});
    
    if (x + y + z >= 2 * m) {
        cout << "YES" << endl << s << endl;
    } else {
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