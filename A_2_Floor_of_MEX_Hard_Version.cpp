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
const ll MOD = 1e9 + 7;
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
struct dsu{
    vint p;
    dsu(int n){
        p.resize(n + 1);
        iota(all(p), 0);
    }
    int f(int x){
        if (p[x] == x) return x;
        return p[x] = f(p[x]);
    }
    void e(int x){
        p[x] = f(x + 1);
    }
};
void solve(){
    int n;
    cin >> n;

    vll a(n+1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vint d(n+1,0);
    vint m(n,-1);
    for (ll k = 1; k <= n; k++){
        ll l = k * a[k];
        ll r = k * (a[k]+1) - 1;
        if (l < n){
            r = min(r,(ll)n - 1);
            d[l]++;
            if (r + 1 < n){
                d[r + 1]--;
            }
        }
        for (ll j = 0; j < a[k]; j++){
            ll x = k * j;
            ll y = k * (j + 1) - 1;
            if (x >= n) break;
            y = min(y, (ll)n - 1);
            m[y] = max(m[y], (int)x);
        }
    }
    vint b(n,0);
    int c=0;
    rep(i,n){
        c += d[i];
        if (c > 0) {
            b[i] = 1;
        }
    }
    vll p(n,0);
    ll s = 0;
    ll q = 1;
    int g = -1;
    rep(i,n){

        ll w=0;
        if (!b[i]){
            w = q;
        }
        s = (s+w) % MOD;
        p[i] = s;
        g = max(g,m[i]);
        ll z;
        if (g == -1){
            z = (s + 1) % MOD;
        }
        else{
            ll x = 0;
            if (g > 0){
                x = p[g-1];
            }
            z =(s-x+MOD) % MOD;
        }
        q = z;
    }
    cout << q << endl;
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