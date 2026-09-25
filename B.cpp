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
const int P = 998244353;
const int N = 10000;

bitset<N> g[N];

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
    int n,m;
    cin >>n>>m;
    int z = 2*n;
    vint p(z),d(z,z-1);
    iota(all(p),0);
    rep(i,z){
        g[i].set();
        g[i][i] = 0;
    }
    while(m--){
        int k;
        cin>>k;
        --k;
        int u=p[k];
        reprng(j,k+1,z){
            int v = p[j];
            if (g[u][v]){
                g[u][v] = g[v][u] = 0;
                --d[u];
                --d[v];
            }
        }
        swap(p[k],p[k-1]);
    }
    vint o(z),r(z,-1);
    iota(all(o),0);
    sort(all(o), [&](int u,int v){
        if (d[u] != d[v]) return d[u] > d[v];
        return u < v;
    });
    rep(i,z){
        int u = o[i];
        rrep(j,i){
            if (g[u][o[j]]){
                r[u] = o[j];
                break;
            }
        }
    }
    vvint f(z);
    ll q = 1;
    rrep(i,z){
        int u = o[i];
        if (f[u].empty()) f[u] = {1};
        int s = (int)f[u].size();
        vint t(s + 1);
        rep(j, s){
            int x = f[u][j];
            if (!x) continue;
            t[j + 1] = (t[j + 1] + x) % P;
            if (j) {
                t[j-1] = (t[j-1] + (ll)x*j)%P;
            }
        }
        vint().swap(f[u]);
        int v = r[u];
        if (v == -1){
            q = q * t[0] % P;
        }
        else if (f[v].empty()) {
            f[v] = move(t);
        } 
        else{
            int a = (int)f[v].size();
            int b = (int)t.size();
            vint h(a + b - 1);
            rep(j, a){
                if (!f[v][j]) continue;
                rep(k,b){
                    if(!t[k]) continue;
                    h[j+k] =(h[j + k] + (ll)f[v][j] * t[k]) % P;
                }
            }
            f[v]=move(h);
        }
    }
    cout << q << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test1=1;
    //cin >> test1;

    while (test1--) {
        solve();
    }

    return 0;
}