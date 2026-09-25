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

void solve() {
    int n, m;
    ll c;
    cin >> n >> m >> c;
    vector<vector<pint>> g(n + 1);
    reprng(i, 1, m + 1){
        int u, v;
        cin >> u >> v;
        g[u].pb({v,i});
        g[v].pb({u,i});
    }
    vint t(n + 1), p(n + 1), e(n + 1), q(n + 1);
    vint o,s;
    s.pb(1);
    o.pb(1);
    int z = 1;
    t[1] = 1;
    while (!s.empty()){
        int u = lmnt(s);
        if (q[u] == (int)g[u].size()) {
            s.qb();
            continue;
        }
        auto [v, id] = g[u][q[u]++];
        if (t[v]) continue;
        t[v] = ++z;
        p[v] = u;
        e[v] = id;
        o.pb(v);
        s.pb(v);
    }
    vint d(n+1),a;
    bool f = false;
    reprng(i,1,n){
        int v = o[i];
        if (!f){
            int k = -1;
            for (auto [u, id] : g[v])
                k += (t[u] < t[v]);
            if (c >= k){
                c -= k;
                a.pb(e[v]);
                d[v] = d[p[v]] + 1;
            }
            else{
                vector<array<int, 3>> x;
                for (auto [u, id] : g[v]){
                    if (t[u] < t[v])
                        x.pb({t[u], u, id});
                }
                int y =(int)c;
                nth_element(
                    x.begin(),
                    x.begin() + y,
                    x.end()
                );
                a.pb(x[y][2]);
                d[v] = d[x[y][1]] + 1;
                c = 0;
                f = true;
            }
        }
        else{
            int u = -1, id = -1;
            for (auto [w, j] : g[v]){
                if (t[w] < t[v] && 
                    (u == -1 || d[w] < d[u])) {
                    u = w;
                    id = j;
                }
            }
            a.pb(id);
            d[v] = d[u] + 1;
        }
    }
    print(a);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test1=1;
    cin >> test1;

    while (test1--) {
        solve();
    }

    return 0;
}
