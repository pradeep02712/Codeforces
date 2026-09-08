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
void print(vector<T>& v, bool withSize = false){ 
    if (withSize) cout << v.size() << endl;
    rep(i, v.size()) cout << v[i] << " ";
    cout << endl;
}
struct D{
    vint p;
    D(int n) : p(n){
        iota(all(p), 0);
    }
    int f(int x){
        return p[x] == x ? x : p[x] = f(p[x]);
    }
    bool u(int a, int b){
        a = f(a), b = f(b);
        if (a == b) return 0;
        p[b] = a;
        return 1;
    }
};
void solve(){
    int n,m;
    cin >>n>>m;
    vector<pint> e(m);
    vector<vector<pint>> g(n),tr(n);
    vint x, s(m);

    D d(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        --a, --b;
        e[i] = {a,b};
        g[a].pb({b,i});
        g[b].pb({a,i});
        if (d.u(a,b)){
            tr[a].pb({b, i});
            tr[b].pb({a, i});
        } else {
            x.pb(i);
        }
    }
    vint p(n,-1),q(n,-1),h(n);
    auto f = [&](auto&& f, int u) -> void{
        frlp(tr[u]) {
            int v = ele.first, i = ele.second;
            if (v == p[u]) continue;
            p[v] = u;
            q[v] = i;
            h[v] = h[u] + 1;
            f(f, v);
        }
    };
    f(f,0);
    rep(j, x.size()){
        int i = x[j];
        int a = e[i].first, b = e[i].second;
        int z = 1 << j;

        s[i] |= z;
        while (a != b) {
            if (h[a] < h[b]) swap(a, b);
            s[q[a]] |= z;
            a = p[a];
        }
    }
    int k = x.size();
    reprng(z,1,(1 << k)){
        vint v(n);
        queue<int> q;

        q.push(0);
        v[0] = 1;
        int c = 1;
        while (!q.empty()){
            int u = q.front();
            q.pop();
            frlp(g[u]){
                int w = ele.first, i = ele.second;

                if (!v[w] && !__builtin_parity(z & s[i])){
                    v[w] = 1;
                    q.push(w);
                    c++;
                }
            }
        }
        if (c==n){
            cout <<"YES"<< endl;
            return;
        }
    }
    cout << "NO" << endl;
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