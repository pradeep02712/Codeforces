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
    int n,q;
    cin >>n>>q;
    vint a(n+1), p(n+1);
    for (int i=1; i<=n;i++){
        cin >> a[i];
        p[a[i]] = i;
    }
    vll x(n+1,0);
    vll y(n+2,0);
    vll d(n+1,0);
    vector<vector<pll>> b(n+2);
    for (int i = 1;i <= n;i++){
        d[p[i]] = 1;
        for (int j = i; j <= n; j += i){
            for (int k = j; k <= n; k += j){
                if (p[k] > p[j]){
                    d[p[k]] += d[p[j]];
                }
            }
        }
        for (int j = 2*i; j<=n; j+=i){
            if (p[j] > p[i]){
                b[p[i] + 1].pb({p[j], d[p[j]]});
                x[p[i]] += d[p[j]];
                y[p[j]] += d[p[j]];
            }
        }
        x[p[i]]++;
        y[p[i]]++;
        for (int j=i;j<=n;j+=i){
            d[p[j]] = 0;
        }
    }
    for (int i=1;i<=n;i++){
        x[i] += x[i - 1];
    }
    for (int i=n;i>=1;i--){
        y[i] += y[i + 1];
    }
    vll z(q,0);
    vector<vector<pint>> c(n+2);
    rep(i,q){
        int l,r;
        cin >>l>>r;
        z[i] = x[n]-x[l-1] - y[r+1];
        c[l].pb({r,i});
    }
    vll f(n+1,0);
    auto ad = [&](int x,ll v){
        for (int i = x; i <= n; i += i & (-i)){
            f[i] += v;
        }
    };
    auto qr = [&](int x){
        ll s=0;
        for (int i = x; i > 0; i -= i & (-i)){
            s += f[i];
        }
        return s;
    };
    for (int i = 1; i <= n; i++){
        for (auto [r, v] : b[i]){
            ad(r,v);
        }
        for (auto [r, j] : c[i]){
            z[j] += qr(n) - qr(r);
        }
    }
    for (auto v : z){
        cout << v << " ";
    }
    cout<<endl;
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