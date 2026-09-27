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
struct Tr{
    vector<array<int,3>> t{{0, 0, 0}};
    int add(int p,int x,int b = 29){
        int u = t.size();
        t.pb(t[p]);
        t[u][2]++;

        if (b >= 0){
            int c = (x >> b) & 1;
            int v = add(t[p][c], x, b - 1);
            t[u][c] = v;
        }
        return u;
    }
    int get(int p,int x,int k){
        int y = 0;
        rrep(b, 30){
            int c =(x >> b) & 1;
            int s =t[t[p][c]][2];

            if (k > s){
                k-=s;
                c^=1;
                y |=1<<b;
            }
            p=t[p][c];
        }
        return y;
    }
};
vint nxt(const vint& a){
    int n = a.size();
    ll z = 0;
    for (int l=0,r; l<n;l=r){
        r=l+1;
        while (r < n && a[r] == a[l]) r++;
        z += 1LL * (r - l) * (r - l - 1) / 2;
    }
    if (z >= n) return vint(n, 0);
    Tr t;
    t.t.reserve(31*n+1);
    vint r(n + 1), v;
    v.reserve(n);
    rrep(i, n) r[i] = t.add(r[i + 1], a[i]);
    using T = array<int, 3>;
    priority_queue<T, vector<T>, greater<T>> h;

    auto f = [&](int i, int k) {
        h.push({t.get(r[i + 1], a[i], k), i, k});
    };
    rep(i, n-1) f(i,1);
    while ((int)v.size() < n){
        auto [x, i, k] = h.top();
        h.pop();
        v.pb(x);
        if ((int)v.size() < n && k < n - i - 1)
            f(i, k + 1);
    }
    return v;
}
void solve(){
    int n,q;
    cin >>n>>q;

    vint a(n),b(q),c;
    frlpr(a) cin >> ele;
    frlpr(b) cin >> ele;

    sort(all(a));
    int m = min(60,*maxe(all(b)));
    c.pb(a.back()-a.front());

    while(m-- && a.back()){
        a = nxt(a);
        c.pb(a.back()-a.front());
    }
    frlp(b){
        cout << c[min(ele,(int)c.size() - 1)] << endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test1=1;
    cin >> test1;

    while (test1--) {
        solve();
    }

    return 0;
}