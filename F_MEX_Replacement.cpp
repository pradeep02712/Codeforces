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
bool f(ll k,vector<pll>& a,ll s){
    ll r=1,p=k-1;
    ll z=(a[0].first==0 ? a[0].second : 0);
    rrep(i, a.size()){
        ll x=a[i].first;
        ll y=a[i].second;
        if (x==0) break;
        ll d=p-x;
        if (d>60 || (__int128)r*(1LL<<d)>s)
            return false;
        r<<=d;
        if (y<r)
            r=2*r-y;
        else
            z+=y-r;
        if (r>s)
            return false;
        p=x-1;
    }
    if (p>60 || (__int128)r*(1LL << p)>s)
        return false;
    r<<=p;
    return r<=z;
}
void solve(){
    int n;
    cin >> n;
    vector<pll> a(n);
    ll s=0;
    rep(i,n){
        cin >> a[i].first >> a[i].second;
        s += a[i].second;
    }
    sort(all(a));
    ll m=lmnt(a).first;
    while (m<s && f(m+1,a,s))
        m++;
    cout<<m<<endl;
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