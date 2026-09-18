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
const int mod = 1e9 + 7;
const int mx = 1000001;

struct mi{
    ll v;
    mi(ll x = 0) {
        v = x % mod;
        if (v < 0) v += mod;
    }
    mi& operator*=(const mi& x){
        v = v * x.v % mod;
        return *this;
    }
    friend mi operator*(mi a, const mi& b){
        return a *= b;
    }
    friend ostream& operator<<(ostream& o, const mi& x){
        return o << x.v;
    }
};
mi pw(mi a,ll b){
    mi r = 1;
    while (b){
        if (b & 1) r *= a;
        a *= a;
        b >>= 1;
    }
    return r;
}
mi f[mx],iv[mx];
void init(){
    f[0] = 1;
    reprng(i,1,mx){
        f[i] = f[i - 1] * i;
    }
    iv[mx-1] = pw(f[mx-1], mod-2);
    for (int i=mx-2; i>=0;i--){
        iv[i] = iv[i+1] * (i+1);
    }
}
mi c(int n, int r){
    if (r < 0 || r > n) return 0;
    return f[n] * iv[r] * iv[n - r];
}
mi go(vint &a){
    int r = lmnt(a);
    mi s = 1;
    for (int i = (int)a.size() - 2; i >= 0; i--) {
        r--;
        int d = a[i + 1] - a[i] - 1;
        s *= c(r, d);
        s *= f[d];
        r -= d;
    }
    return s;
}
void solve(){
    int n,x,y;
    cin >> n >> x >> y;
    vint a(x),b(y);
    frlpr(a) cin >> ele;
    frlpr(b) cin >> ele;
    if (a[0] != 1 || b.back() != n || a.back() != b[0]){
        cout << 0 << endl;
        return;
    }
    frlpr(a) ele--;
    reverse(all(b));
    frlpr(b){
        ele = n - ele;
    }
    mi p = go(a);
    mi q = go(b);
    cout << p*q*c(n-1,lmnt(a)) << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int test1=1;
    cin >> test1;

    while (test1--) {
        solve();
    }

    return 0;
}