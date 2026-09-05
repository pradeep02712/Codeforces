#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

// pairs
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdb;

// vectors
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<double> vdb;

// vectors of vectors
typedef vector<vint> vvint;
typedef vector<vll> vvll;
typedef vector<vdb> vvdb;

#define frlp(v) for (auto ele : v) 
#define frlpr(v) for (auto& ele : v) 

#define rep(i, n) for (int i = 0; i < (int)(n); i++) 
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; i--) 
#define reprng(i, s, e) for (int i = (int)(s); i < (int)(e); i++) 
#define rreprng(i, e, s) for (int i = (int)(e); i >= (int)(s); i--) 

#define pb push_back 
#define qb pop_back 
#define pf push_front 
#define qf pop_front 

#define maxe max_element 
#define mine min_element 

#define lmnt(x) x[(x).size() - 1] 

#define yn(ans) printf("%s\n", (ans) ? "yes" : "no"); 
#define YN(ans) printf("%s\n", (ans) ? "YES" : "NO"); 

const ll INF = 1e18;
const ll md = 1e9+7;

template<typename T>
bool chmax(T &a, const T b) { 
    if (a >= b) return false;
    a = b;
    return true;
}

template<typename T>
bool chmin(T &a, const T b) { 
    if (a <= b) return false;
    a = b;
    return true;
}

template<typename T>
void print(vector<T>& v, bool withSize = false) { 
    if (withSize) cout << v.size() << endl;
    rep(i, v.size()) cout << v[i] << " ";
    cout << endl;
}
void solve(){
    int n;
    cin >>n;

    vint a(n);
    frlpr(a) cin >> ele;
    vint d(n+1);
    bool q=0;
    rep(i,n){
        if (a[i] != -1) q=1;
        if (a[i] <= 0) continue;
        int l = max(0, i - a[i] + 1);
        int r = min(n - 1, i + a[i] - 1);
        d[l]++;
        d[r + 1]--;
    }
    vint b(n),p,id(n,-1);
    int s = 0;
    rep(i,n){
        s += d[i];
        b[i] = s > 0;
        if (!b[i]){
            id[i] = p.size();
            p.pb(i);
        }
    }
    int m = p.size();
    if (!m){
        cout << 0 << endl;
        return;
    }
    vint f(m), g(max(0, m - 1));
    rep(i, n){
        if (a[i] == -1) continue;
        if (!a[i]){
            if (b[i]) {
                cout << 0 << endl;
                return;
            }
            f[id[i]] = 1;
            continue;
        }
        int l = i - a[i];
        int r = i + a[i];
        bool x = l >= 0 && !b[l];
        bool y = r < n && !b[r];
        if (!x && !y){
            cout << 0 << endl;
            return;
        }
        if (x && y){
            int u = id[l];
            int v = id[r];

            if (v != u + 1){
                cout << 0 << endl;
                return;
            }

            g[u] = 1;
        } 
        else if (x) {
            f[id[l]] = 1;
        } 
        else {
            f[id[r]] = 1;
        }
    }
    ll x = f[0] ? 0:1;
    ll y = 1;
    reprng(i,1,m){
        ll z = (x+y) % md;
        ll u = z, v = 0;
        if (!f[i])
            v = g[i - 1] ? y : z;
        x = v;
        y = u;
    }
    ll z = (x + y) % md;
    if (!q)
        z = (z - 1 + md) % md;
    cout << z << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test1=1;
    cin >> test1;

    while (test1--) {
        solve();
    }

    return 0;
}