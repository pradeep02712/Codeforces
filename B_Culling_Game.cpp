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
struct BIT{
    int n;
    vll b;
    BIT(int n) : n(n), b(n+1,0) {}
    void add(int i, ll x) {
        for (; i <= n; i += i & -i)
            b[i] += x;
    }
    ll sum(int i){
        ll s = 0;
        for (; i > 0; i -= i & -i)
            s += b[i];
        return s;
    }
    ll qry(int l, int r){
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};
void solve(){
    int n;
    cin >> n;
    vll a(n+1);
    vint p(n+1);
    reprng(i, 1,n+1)
        cin >> a[i];
    reprng(i, 1,n +1)
        cin >> p[i];
    BIT f(n);

    set<int> s;
    vint r(n + 1);
    for (int i = n; i >= 1; i--){
        int x = p[i];
        f.add(x, a[x]);
        auto it = s.lower_bound(x);
        int c;
        if (it == s.begin()){
            s.insert(x);
            c = x;
        }
        else{
            auto q = prev(it);
            int y = *q;
            ll z = f.qry(y, x - 1);
            if (z < a[x]) {
                s.insert(x);
                c = x;
            }
            else {
                c = y;
            }
        }
        while (true){
            auto it = s.upper_bound(c);
            if (it == s.end())
                break;
            int x = *it;
            ll z = f.qry(c, x-1);
            if (z >= a[x])
                s.erase(it);
            else
                break;
        }
        r[i] = (int)s.size() - 1;
    }
    reprng(i,1,n+1){
        cout << r[i] << " ";
    }
    cout << endl;
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