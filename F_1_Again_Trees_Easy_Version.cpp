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
const ll mod = 1e9 + 7;

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
    int n,k;
    cin >>n>>k;
    vvint g(n);
    reprng(i, 1, n){
        int u,v;
        cin >>u>>v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vint a(n),b(k);
    frlpr(a) cin >> ele;
    frlpr(b) cin >> ele;
    int m = 1 << k;
    vint x(m);
    reprng(s, 1, m){
        rep(i, k){
            if (s >> i & 1){
                x[s] = x[s ^ (1 << i)] ^ b[i];
                break;
            }
        }
    }
    vint p(n,-1), o={0};
    p[0] = -2;
    rep(z, n){
        int u = o[z];
        frlp(g[u]){
            int v = ele;
            if (v != p[u]){
                p[v] = u;
                o.pb(v);
            }
        }
    }
    vint s = a;
    for (int i = n - 1; i; i--)
        s[p[o[i]]] ^= s[o[i]];
    vvll dp(n, vll(m));
    rrep(ii, n){
        int u = o[ii];
        vll f(m);
        f[0] = 1;
        frlp(g[u]){
            int v = ele;
            if (p[v] != u) continue;
            vll nf(m);
            rep(i, m){
                rep(j, m){
                    ll w = f[i] * dp[v][j] % mod;
                    nf[i ^ j] = (nf[i ^ j] + w) % mod;
                    int z = s[v] ^ x[j];
                    rep(q, k){
                        if (z == b[q]) {
                            int id = i ^ j ^ (1 << q);
                            nf[id] = (nf[id] + w) % mod;
                        }
                    }
                }
            }
            f.swap(nf);
        }
        dp[u] = f;
    }
    ll ans = 0;
    rep(mask, m){
        int z = s[0] ^ x[mask];
        rep(j, k){
            if (z == b[j])
                ans = (ans + dp[0][mask]) % mod;
        }
    }
    cout << ans << endl;
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