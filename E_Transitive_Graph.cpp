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

int n,m;
vint e[N],r[N];
bool v[N];

vint o;
set<int> c;
ll x[N],y[N],w[N];
int id[N];
set<int> g[N];
ll p[N],q[N];
void d1(int u){
    v[u] = true;
    for (auto z : e[u]){
        if (!v[z]) {
            d1(z);
        }
    }
    o.pb(u);
}
void d2(int u){
    v[u] = true;
    c.insert(u);
    for (auto z : r[u]){
        if (!v[z]) {
            d2(z);
        }
    }
}
void solve(){
    cin >>n>>m;
    reprng(i,1,n+1){
        e[i].clear();
        r[i].clear();
        g[i].clear();
        v[i] = false;
        p[i] = 0;
        q[i] = 0;
    }
    o.clear();
    c.clear();
    reprng(i,1,n+1){
        cin >> w[i];
    }
    rep(i,m){
        int a,b;
        cin >>a>>b;
        e[a].pb(b);
        r[b].pb(a);
    }
    reprng(i,1,n+1){
        if (!v[i]){
            d1(i);
        }
    }
    reprng(i,1,n+1){
        v[i] = false;
    }
    reverse(all(o));
    int k=1;
    for (auto z:o){
        if (!v[z]){
            d2(z);
            x[k]=0;
            y[k]=0;
            for (auto u : c){
                id[u] = k;
                x[k] += w[u];
                y[k]++;
            }
            k++;
            c.clear();
        }
    }
    reprng(i,1,n+1){
        for (auto z : e[i]){
            if (id[i] != id[z]){
                g[id[i]].insert(id[z]);
            }
        }
    }
    n = k-1;
    queue<int> qu;

    vint d(n+1,0);
    reprng(i,1,n+1){
        for (auto z : g[i]){
            d[z]++;
        }
    }
    reprng(i,1,n+1){
        if (d[i] == 0){
            qu.push(i);
        }
    }
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        p[u] += x[u];
        q[u] += y[u];
        for (auto z : g[u]){
            d[z]--;
            if (d[z] == 0){
                qu.push(z);
            }
            chmax(p[z],p[u]);
            chmax(q[z],q[u]);
        }
    }
    pll an = {0,0};
    reprng(i,1,n+1){
        an = max(an,make_pair(q[i],-p[i]));
    }
    cout << an.first << " " << -an.second << endl;
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