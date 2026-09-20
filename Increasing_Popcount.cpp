#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

using str = string;

using pi = pair<int,int>;
using pl = pair<ll,ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;

#define f first
#define s second

#define pb push_back
#define eb emplace_back
#define ins insert

#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))

#define lb lower_bound
#define ub upper_bound

#define FOR(i,n) for(int i=0;i<(n);i++)
#define F(i, j, k) for(int i = (j); i < (k); i++)
#define R(i, j, k) for(int i = (j); i > (k); i--)
#define EACH(x,a) for(auto &x:a)

#define set_bits(x) __builtin_popcountll(x)

#define endl '\n'

const ll MOD=1e9+7;
const ll MOD1=998244353;
const ll INF=(1LL<<62);
const ld PI=acosl(-1.0L);

// ---------------- DEBUG ----------------

void _pu128(u128 x){
    if(!x){
        cerr<<0;
        return;
    }

    str s;
    while(x){
        s+=char('0'+x%10);
        x/=10;
    }

    rev(s);
    cerr<<s;
}

void _print(i128 x){
    if(x<0){
        cerr<<'-';
        _pu128(-(u128)x);
    }else _pu128((u128)x);
}

void _print(u128 x){
    _pu128(x);
}

void _print(f128 x){
    cerr<<(ld)x;
}

void _print(const str &x){
    cerr<<'"'<<x<<'"';
}

void _print(const char *x){
    cerr<<x;
}

void _print(char x){
    cerr<<'\''<<x<<'\'';
}

void _print(bool x){
    cerr<<(x?"true":"false");
}

template<class T>
void _print(const T &x){
    cerr<<x;
}

template<class A,class B>
void _print(const pair<A,B> &p){
    cerr<<'{';
    _print(p.f);
    cerr<<',';
    _print(p.s);
    cerr<<'}';
}

template<class T>
void _range(const T &a){
    cerr<<"[ ";
    for(const auto &x:a){
        _print(x);
        cerr<<' ';
    }
    cerr<<']';
}

template<class T>
void _print(const vector<T> &a){
    _range(a);
}

template<class T>
void _print(const deque<T> &a){
    _range(a);
}

template<class T>
void _print(const set<T> &a){
    _range(a);
}

template<class T>
void _print(const multiset<T> &a){
    _range(a);
}

template<class T>
void _print(const unordered_set<T> &a){
    _range(a);
}

template<class T,size_t N>
void _print(const array<T,N> &a){
    _range(a);
}

template<class K,class V>
void _print(const map<K,V> &a){
    _range(a);
}

template<class K,class V>
void _print(const unordered_map<K,V> &a){
    _range(a);
}

template<size_t N>
void _print(const bitset<N> &a){
    cerr<<a;
}

template<class... T>
void _dbg(T&&... x){
    int c=0;
    ((cerr<<(c++?", ":""),_print(x)),...);
    cerr<<endl;
}

#ifdef LOCAL
#define debug(...) cerr<<"["<<#__VA_ARGS__<<"] = ",_dbg(__VA_ARGS__)
#else
#define debug(...) ((void)0)
#endif

// ---------------- UTILITY ----------------

ll floor_div(ll x,ll y){
    assert(y);

    if(y<0)
        y=-y,x=-x;

    if(x>=0)
        return x/y;

    return (x+1)/y-1;
}

ll ceil_div(ll x,ll y){
    assert(y);

    if(y<0)
        y=-y,x=-x;

    if(x<=0)
        return x/y;

    return (x-1)/y+1;
}

template<class T>
T sqr(T x){
    return x*x;
}
ll d[61][61][61],dp[65],ndp[65];
int k,c;
void dc(int l,int r,int L,int R){
    if(l>r) return;
    int m=(l+r)/2;
    int p=max(m,L);
    ll ans=-1;
    for(int j=p;j<=R;j++){
        ll cur=dp[c+j]+d[k][m][j];
        if(cur>=ans){
            ans=cur;
            p=j;
        }
    }
    ndp[m]=ans;
    dc(l,m-1,L,p);
    dc(m+1,r,p,R);
}
void add(int x,int y){
    k=x,c=y;
    dc(0,k,0,k);
    FOR(i,c)
        dp[i]=max(dp[i],ndp[0]);
    for(int i=0;i<=k;i++)
        dp[c+i]=max(dp[c+i],ndp[i]);
}
ll get(ull l,ull r){
    fill(dp,dp+65,0);
    for(ull x=l;x<=r;){
        ull len=r-x+1;
        int y=min(__builtin_ctzll(x),63-__builtin_clzll(len));
        add(y,set_bits(x>>y));
        x+=(1ULL<<y);
    }
    return dp[0];
}
void pre(){
    d[0][0][0]=1;
    F(x,1,61){
        for(int i=0;i<=x;i++){
            for(int j=i;j<=x;j++){
                if(j==x){
                    d[x][i][j]=d[x-1][max(0,i-1)][x-1];
                    continue;
                }
                ll &ans=d[x][i][j];
                ans=i?0:d[x-1][0][j];
                for(int y=max(1,i);y<=j;y++){
                    ans=max(
                        ans,
                        d[x-1][max(0,i-1)][y-1]
                        +d[x-1][y][j]
                    );
                }
            }
        }
    }
}
// ---------------- SOLVE ----------------
void solve(){
    ull l,r;
    cin>>l>>r;
    cout<<get(l,r)<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

    #ifdef LOCAL
         //freopen("Error2.txt","w",stderr);
    #endif

    pre();

    int t=1;
    cin>>t;

    while(t--){
        solve();
    }
}

