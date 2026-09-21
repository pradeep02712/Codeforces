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

void solve(){
    int n,m;
    cin >>n>>m;
    vvll a(n,vll(m));
    vvll p(n,vll(m));
    vvll q(n,vll(m));
    rep(i,n){
        rep(j,m){
            cin >> a[i][j];
        }
    }
    rep(i,n){
        rep(j,m){
            if (i==0 && j==0) {
                p[i][j] = a[i][j];
                continue;
            }
            ll x = -INF;
            if (i > 0)
                x = max(x, p[i - 1][j]);
            if (j > 0)
                x = max(x, p[i][j - 1]);
            p[i][j] = x + a[i][j];
        }
    }
    rrep(i, n){
        rrep(j, m){
            if (i == n - 1 && j == m - 1) {
                q[i][j] = a[i][j];
                continue;
            }
            ll x = -INF;
            if (i+1 < n)
                x = max(x, q[i + 1][j]);
            if (j + 1 < m)
                x = max(x, q[i][j + 1]);
            q[i][j] = x + a[i][j];
        }
    }
    int z = n+m-1;

    vll f(z,-INF);
    vll s(z,-INF);
    rep(i, n){
        rep(j, m){
            ll x = p[i][j] + q[i][j] - a[i][j];
            int d = i+j;
            if (x > f[d]){
                s[d] = f[d];
                f[d] = x;
            }
            else if (x > s[d]){
                s[d] = x;
            }
        }
    }
    ll ans=INF;
    rep(i,n){
        rep(j, m){
            int d = i + j;
            ll x = p[i][j] + q[i][j] - a[i][j];
            ll y = x - 2 * a[i][j];
            ll z;
            if (x == f[d])
                z = s[d];
            else
                z = f[d];
            ll cur = max(y, z);
            ans = min(ans, cur);
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