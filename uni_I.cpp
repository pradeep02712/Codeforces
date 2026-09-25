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
using i128 = __int128_t;
void pr(i128 x){
    if (x == 0){
        cout << 0;
        return;
    }
    string s;
    while (x){
        s += char('0' + x % 10);
        x /= 10;
    }
    reverse(all(s));
    cout << s;
}
void solve(){
    int n;
    cin>>n;
    vll a;
    ll o=0;
    rep(i,n){
        ll x;
        cin>>x;
        if (x == 1)o++;
        else a.pb(x);
    }
    if (a.empty()){
        cout << o << endl;
        return;
    }
    sort(all(a));
    ll m = a.size();
    ll u = 0;
    i128 s = 0;
    i128 b = 0;
    rep(i, m){
        s += a[i];
        b += (i128)(i + 1) * a[i];
    }
    i128 c = b + (i128)o * (m + 1);
    i128 ans = c;
    rep(i, m){
        if (u >= o) break;
        ll k = min(a[i] - 2, o - u);
        if (k <= 0) continue;
        i128 d = s + o - m - i - 1 - 2 * u;
        ll t = max(0LL, min(k, (ll)(d / 2)));
        for (ll x = max(0LL, t - 1); x <= min(k, t + 1); x++) {
            chmax(ans, c + (i128)x * d - (i128)x * x);
        }
        c += (i128)k * d - (i128)k * k;
        u += k;
    }
    pr(ans);
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test1;
    cin >> test1;

    while (test1--) {
        solve();
    }

    return 0;
}