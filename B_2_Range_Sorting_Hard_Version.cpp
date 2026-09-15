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
struct fw{
    int n;
    vint b;
    fw(int n){
        this->n = n;
        b.assign(n+1,0);
    }
    void add(int i){
        while (i <= n) {
            b[i]++;
            i += i & -i;
        }
    }
    int sum(int i){
        int s=0;
        while(i>0){
            s+=b[i];
            i-=i&-i;
        }
        return s;
    }
    int kth(int k){
        int p = 0;
        int d = 1;
        while((d << 1) <= n)
            d <<= 1;
        while(d){
            int q = p + d;
            if (q <= n && b[q] < k){
                p = q;
                k -= b[q];
            }
            d >>= 1;
        }
        return p + 1;
    }
};
void solve(){
    int n;
    cin >> n;
    vint a(n+1);
    for (int i=1; i<=n;i++)
        cin >> a[i];
    ll ans = 1LL*n*(n-1)*(n+1) / 6;
    vint l(n + 1), r(n + 1), x(n + 1);
    vint st;
    for (int i = 1; i <= n; i++){
        while (!st.empty() && a[st.back()] > a[i])
            st.qb();
        l[i] = st.empty() ? 0 : st.back();
        st.pb(i);
    }
    st.clear();
    for (int i = n; i >= 1; i--){
        while (!st.empty() && a[st.back()] > a[i])
            st.qb();
        r[i] = st.empty() ? n + 1 : st.back();
        st.pb(i);
    }
    vint o(n);
    iota(all(o),1);
    sort(all(o),[&](int i,int j) {
        return a[i] > a[j];
    });
    fw f(n);
    for (auto i : o){
        int k = l[i];
        if (k>1){
            int c=f.sum(k-1);
            if (c)
                x[i] = f.kth(c);
        }
        f.add(i);
    }
    for (int i = 1; i <= n; i++){
        int k = l[i];
        if (k == 0)
            continue;
        ans -= 1LL*(k-x[i])*(r[i]-i);
    }
    cout << ans << endl;
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