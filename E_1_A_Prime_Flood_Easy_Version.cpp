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
const int N = 3e3;
const ll M = 998244353;
int d[N+1];
int f[N+1][N+1];
ll p[N+1];
void init(){
    fill(d,d+N+1,1);
    for (int i=2; i<=N; i++){
        if (d[i] == 1){
            for (int j=i; j<=N; j+=i)
                d[j] *= i;
        }
    }
    for(int i=1; i<=N; i++)
        f[i][i] = i;
    for(int r=2; r<=N; r++){
        for (int l=1; l<r; l++){
            if (d[l] % d[r] == 0)
                f[l][r] = f[l-1][r-1];
            else
                f[l][r] = f[l][r-1];
        }
    }
    p[0] = 1;
    for (int i=1; i<=N; i++)
        p[i] = p[i-1] * 2 % M;
}
void solve(){
    int n,x;
    cin >> n;
    vint c(n+1),s(n+1);
    rep(i,n){
        cin >> x;
        c[x]++;
    }
    for (int i=1; i<=n;i++)
        s[i] = s[i-1]+c[i];
    ll a = 0;
    for (int l=1; l<=n; l++){

        if (!c[l]) continue;
        ll q = (p[c[l]]-1+M) % M;

        a = (a+q*l) % M;
        for (int r=l+1; r<=n; r++){
            if (!c[r]) continue;
            ll w = q*(p[c[r]]-1+M) % M;
            w = w*p[s[r-1]-s[l]] % M;
            a = (a+w*f[l][r]) % M;
        }
    }
    cout << a << endl;
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