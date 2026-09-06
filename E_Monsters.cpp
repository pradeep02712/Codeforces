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
const int N = 2e5 + 69;
template<typename T>
bool chmax(T &a, const T b){ 
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
int n, m;
int r[N], z[N], a[N];
vint g[N];
set<int> c[N];
set<pint> e[N];
int fd(int x) {
    if (x == r[x]) return x;
    return r[x] = fd(r[x]);
}
void un(int x, int y){
    x = fd(x);
    y = fd(y);
    if (x == y) return;
    if (z[x] + e[x].size() < z[y] + e[y].size())
        swap(x, y);
    frlp(c[y]){
        c[x].insert(ele);
        e[x].erase({a[ele], ele});
    }
    frlp(e[y]){
        if (c[x].find(ele.second) == c[x].end())
            e[x].insert(ele);
    }
    z[x] += z[y];
    r[y] = x;
}
void solve(){
    cin >> n >> m;
    reprng(i,1,n+1)
        cin >> a[i];
    reprng(i,1,n+1){
        c[i].clear();
        c[i].insert(i);
        e[i].clear();
        g[i].clear();
        r[i] = i;
        z[i] = 1;
    }
    rep(i,m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        e[u].insert({a[v], v});
        e[v].insert({a[u], u});
    }
    reprng(i,1,n+1){
        if (a[i] != 0) continue;
        while (1){
            int x = fd(i);
            if (e[x].empty()) break;
            pint p = *e[x].begin();
            if (z[x] < p.first) break;
            un(x, p.second);
        }
    }
    int x = fd(1);
    reprng(i,1,n+1){
        if (fd(i) != x){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test1;
    cin >> test1;

    while (test1--) {
        solve();
    }

    return 0;
}

