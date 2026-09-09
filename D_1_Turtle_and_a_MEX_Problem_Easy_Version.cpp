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
    int n;
    ll m;
    cin >> n >> m;

    int s = 0;
    vvint a(n);
    vint x(n),y(n);
    rep(i,n){
        int k;
        cin >> k;
        s+=k;
        rep(j,k){
            int v;
            cin >>v;
            a[i].pb(v);
        }
        set<int> st;
        frlp(a[i]) st.insert(ele);
        int z=0;
        while (st.count(z)) z++;
        x[i] = z;
        z++;
        while (st.count(z)) z++;
        y[i] = z;
    }
    vvint g(s+2);
    rep(i,n)
        g[x[i]].pb(y[i]);
    vint d(s+2);
    rreprng(i,s+1,0){
        d[i] = i;
        frlp(g[i])
            chmax(d[i], d[ele]);
    }
    int mx=0;
    rep(i,n)
        chmax(mx,d[x[i]]);
    ll r=0;
    ll q = min(m,(ll)s);
    for (ll i = 0;i <= q;i++)
        r += max((ll)mx, i);
    if (m > s){
        r += 1LL*s*(m-s);
        ll v = m-s;
        r += v*(v+1)/2;
    }
    cout <<r<< endl;
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