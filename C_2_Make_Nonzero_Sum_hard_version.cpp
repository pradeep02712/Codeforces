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
    cin >> n;
    vint a(n), p;
    frlpr(a) cin >> ele;
    rep(i,n)
        if (a[i]) p.pb(i);
    if (p.size() & 1){
        cout << -1 << endl;
        return;
    }
    vector<pint> v;
    int l = 0;
    for (int i = 0; i < (int)p.size(); i += 2){
        int x = p[i], y = p[i + 1];

        while (l < x) {
            v.pb({l, l});
            l++;
        }
        if ((y - x) % 2 == (a[x] != a[y])){
            v.pb({x, x});
            v.pb({x + 1, y});
        } 
        else{
            v.pb({x, y});
        }
        l = y + 1;
    }
    while (l < n){
        v.pb({l, l});
        l++;
    }
    cout << v.size() << endl;
    for (auto [l, r] : v)
        cout << l + 1 << " " << r + 1 << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test1;
    cin >> test1;

    while (test1--) {
        solve();
    }

    return 0;
}