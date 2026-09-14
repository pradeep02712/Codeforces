#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int M = 998244353;

int pw(int b, int e) {
    int r = 1;
    b %= M;
    while (e > 0) {
        if (e % 2 == 1) r = (r * b) % M;
        b = (b * b) % M;
        e /= 2;
    }
    return r;
}

int mi(int n) {
    return pw(n, M - 2);
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int f = 1;
    for (int i = 1; i < n; i++) {
        f = (f * i) % M;
    }

    int C = 0;
    int S = 0;

    for (int i = 0; i < n; i++) {
        int v = a[i] % M;

        int pc = (v * S) % M;
        pc = (pc * f) % M;

        int cc = 0;
        if (i < n - 1) {
            cc = (v * f) % M;
        }

        C = (C + pc - cc + M) % M;

        if (i < n - 1) {
            int it = mi(n- 1 - i);
            S = (S + it) % M;
        }
    }

    cout << C << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}