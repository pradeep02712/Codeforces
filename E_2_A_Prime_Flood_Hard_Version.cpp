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
const int N = 300000;
const ll M = 998244353;
const ll I = (M+1)/2;

vint r(N+1,1);
vll p(N+1,1), q(N+1,1);

template<typename T>
bool chmax(T &a, const T b){ 
    if (a >= b) return false;
    a = b;
    return true;
}

template<typename T>
bool chmin(T &a, const T b){ 
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
void init(){
    for (int i = 2;i<=N;i++)
        if (r[i] == 1)
            for (int j = i; j <= N; j += i)
                r[j] *= i;
    for (int i = 1; i <= N; i++) {
        p[i] = p[i-1] * 2 % M;
        q[i] = q[i-1] * I % M;
    }
}
void solve(){
    int n;
    cin >> n;
    vint c(n+1),d(n+1);
    vll w(n+1);
    rep(i,n){
        int x;
        cin >> x;
        c[x]++;
    }
    ll a = 0,s = 0;
    int f = 0;
    for (int y = 1; y <= n; y++){
        int z = r[y];
        for (int x = z; x < y; x += z){
            s += 1LL * (d[x-1] - d[x]) * w[x];
            s %= M;
            if (s<0)
                s+=M;
            d[x]=d[x-1];
        }
        ll v = (p[c[y]] - 1 + M) % M;
        a += v * p[f] % M * s;
        a += 1LL*y*v;
        a %= M;
        f += c[y];
        w[y] = v*q[f]%M;
        d[y] = y;
        s = (s+1LL*y*w[y]) % M;
    }
    cout << a << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int test1=1;
    cin >> test1;

    while (test1--){
        solve();
    }

    return 0;
}