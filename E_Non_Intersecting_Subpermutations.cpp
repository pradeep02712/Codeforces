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
const ll mod = 998244353;

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
    vll p(n-k+1);
    p[0] = 1;
    reprng(i,0,n-k){
        p[i+1] = p[i] * k%mod;
    }
    vll f(k+1);
    f[0] = 1;
    reprng(i,1,k+1){
        f[i] = f[i - 1] * i % mod;
    }
    vvll d(n-k+2, vll(n-k+1,0));
    reprng(i,0,n-k+1){
        d[i + 1][i] = p[i] * f[k] % mod;
    }
    reprng(i,1,n-k+1){
        rep(j, i) {
            d[i + 1][j] += d[i][j];
            d[i + 1][j] %= mod;

            if (i - j < k) {
                d[i + 1][i] += mod - d[i][j] * f[i - j] % mod;
                d[i + 1][i] %= mod;
            }
        }
    }
    ll a=0;
    reprng(i,0,n-k+1){
        a += d[n-k+1][i] * p[n-k-i] % mod;
        a %= mod;
    }
    cout << a << endl;
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