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
const int N = 5e5 + 5;
const int LOG = 20;
int pal[N];
int sp[LOG][N];
int nxt[N];
ll dp[N];
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l=0, r=0;
    rep(i, n){
        if (i >= r)
            pal[i]=0;
        else
            pal[i] = min(pal[l + r - i], r - i);
        while(
            i - pal[i] - 1 >= 0 &&
            i + pal[i] < n &&
            s[i - pal[i] - 1] == s[i + pal[i]]
        ) 
        {
            pal[i]++;
        }
        if (i+pal[i]>r){
            l = i-pal[i];
            r = i+pal[i];
        }
    }
    rep(i,n){
        sp[0][i] = i - pal[i];
    }
    reprng(k,1,LOG){
        int len = (1 << k);
        int half = len >> 1;
        rep(i, n - len + 1){
            sp[k][i] = min(
                sp[k - 1][i],
                sp[k - 1][i + half]
            );
        }
    }
    rep(i,n){
        int j = i+1;
        rrep(k,LOG){
            int len = (1 << k);
            if(
                j + len <= n &&
                sp[k][j] > i
            ) 
            {
                j += len;
            }
        }
        if (j < n && 2 * j - i <= n)
            nxt[i] = 2 * j - i;
        else
            nxt[i] = n + 1;
    }
    dp[n] = 0;
    ll ans = 0;
    rrep(i,n){
        dp[i] = 0;
        if (nxt[i] <= n){
            dp[i] = dp[nxt[i]] + 1;
        }
        ans += dp[i];
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test1 = 1;
    cin >> test1;

    while (test1--){
        solve();
    }

    return 0;
}