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
const int N = 3005;

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
int n,z,h;
ll k,a[N],d[N];
int c[N];
void ad(int i,int x){
    if (c[i] > 0 && c[i] < 10) h--;
    if (c[i] == 0) z--;
    if (x == 0) c[i] += 10;
    else c[i]++;
    if (c[i] < 10) h++;
}
void rm(int i, int x){
    if (c[i] > 0 && c[i] < 10) h--;
    if (x == 0) c[i] -= 10;
    else c[i]--;
    if (c[i] > 0 && c[i] < 10) h++;
    if (c[i] == 0) z++;
}
void solve(){
    cin >>n>>k;
    reprng(i,1,n+1) cin >> a[i];
    reprng(i,1,n+1) cin >> d[i];
    int r=n;
    reprng(i,1,n+1){
        vector<pair<ll, pint>> v;

        reprng(j, 1, n + 1) c[j] = 0;

        z = n;
        h = 0;

        ll x = a[i] * d[i];

        v.pb({x, {i, 0}});

        reprng(j, 1, n + 1) {
            if (i == j) continue;

            ll l = (x / a[j]) * a[j];

            v.pb({a[j] * d[j], {j, 0}});

            if (l != 0)
                v.pb({l, {j, 1}});

            v.pb({l + a[j], {j, 1}});
        }

        sort(all(v));

        int p = 0;

        rep(j, v.size()) {
            while (p < (int)v.size() && v[p].first <= v[j].first + k) {
                ad(v[p].second.first, v[p].second.second);
                p++;
            }

            if (z == 0)
                chmin(r, h);

            rm(v[j].second.first, v[j].second.second);
        }
    }

    cout << r << endl;
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