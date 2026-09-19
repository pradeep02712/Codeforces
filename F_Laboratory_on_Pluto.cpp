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
const int N = 700;

int u;
ll m;
vll p(N+1),f(N+1);

template<typename T>
bool chmax(T &a, const T b){ 
    if (a >= b) return false;
    a = b;
    return true;
}

template<typename T>
bool chmin(T &a, const T b){ 
    if (a <= b) return false;
    a = b;
    return true;
}

template<typename T>
void print(vector<T>& v, bool withSize = false){ 
    if (withSize) cout << v.size() << endl;
    rep(i, v.size()) cout << v[i] << " ";
    cout << endl;
}
void pre(){
    p[0]=1;
    reprng(i,1,N+1)
        reprng(j,i,N+1)
            p[j]=(p[j]+p[j-i])%m;
    f[0]=1;
    rep(k,4){
        vll g(N+1);
        rep(i,N+1)
            rep(j,N-i+1)
                g[i+j]=(g[i+j]+f[i]*p[j])%m;
        f=g;
    }
}
void solve(){
    int n;
    cin>>n;
    int s=sqrtl(4LL*n);
    if (1LL*s*s<4LL*n) s++;
    if (u==1){
    int h=1;
    while (1LL*h*(s-h) < n)
        h++;
    int w=s-h;
    int r=h*w-n;
    vector<string> a(h,string(w,'#'));
    rep(i,r)
        a[0][i]='.';
    cout <<h<< " " <<w<< endl;
    frlp(a)
        cout <<ele<< endl;
    return;
    }
    int l=s/2;
    while (l>1 && 1LL*(l-1)*(s-l+1)>=n)
        l--;
    ll a=0;
    reprng(h,l,s-l+1)
        a=(a+f[h*(s-h)-n])%m;
    cout <<2*s<< " " <<a<< endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test1=1;
    cin >> test1>>u;

    if(u==2){
        cin>>m;
        pre();
    }

    while (test1--){
        solve();
    }

    return 0;
}