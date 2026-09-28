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
#define F(i,j,k) for(int i=(j);i<(k);i++)
#define R(i,j,k) for(int i=(j);i>(k);i--)
#define EACH(x,a) for(auto &x:a)

#define set_bits(x) __builtin_popcountll(x)

#define endl '\n'

const ll MOD=1e9+7;
const ll MOD1=998244353;
const ll INF=(1LL<<62);
const ld PI=acosl(-1.0L);

const int MX=200000;
const int MD=998244353;

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

int pw(int a,int b){
    int r=1;
    while(b){
        if(b&1)
            r=(ll)r*a%MD;
        a=(ll)a*a%MD;
        b>>=1;
    }
    return r;
}
struct Z{
    int n;
    vi r,w;
    Z(int x):n(x),r(x),w(x){
        int l=__builtin_ctz((unsigned)n);
        F(i,1,n)
            r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
        int z=pw(3,(MD-1)/n);
        w[0]=1;
        F(i,1,n)
            w[i]=(ll)w[i-1]*z%MD;
    }
    void go(vi &a){
        FOR(i,n){
            if(i<r[i])
                swap(a[i],a[r[i]]);
        }
        for(int l=2;l<=n;l<<=1){
            for(int i=0;i<n;i+=l){
                FOR(j,l/2){
                    int x=a[i+j];
                    int y=(ll)a[i+j+l/2]
                         *w[j*(n/l)]%MD;
                    a[i+j]=(x+y)%MD;
                    a[i+j+l/2]=(x-y+MD)%MD;
                }
            }
        }
    }
};

vi iv(MX+2),c(MX+1);
void init(){
    iv[1]=1;
    c[0]=1;

    F(i,2,MX+2)
        iv[i]=MD-(ll)(MD/i)*iv[MD%i]%MD;

    F(i,1,MX+1)
        c[i]=(ll)c[i-1]*(4LL*i-2)%MD
            *iv[i+1]%MD;
}

// ---------------- SOLVE ----------------

void solve(){
    int n;
    cin>>n;
    vi p(n+1);

    F(i,1,n+1){
        int x;
        cin>>x;
        p[i]=p[i-1]^x;
    }
    if(n==1){
        cout<<0<<endl;
        return;
    }
    int m=1;
    while(m<2*n)
        m<<=1;
    Z z(m);
    vi a(m),s(m);
    F(i,1,n)
        a[i]=(ll)c[i]*c[n-i]%MD;
    z.go(a);
    int b=(ll)(n-1)*c[n]%MD;
    int q=pw(m,MD-2);
    int an=(ll)b*((1<<18)-1)%MD;
    FOR(k,18){
        if(p[n]&(1<<k))
            continue;
        fill(all(s),0);
        F(i,0,n+1)
            s[i]=((p[i]>>k)&1)?MD-1:1;
        z.go(s);
        int v=0;
        FOR(i,m){
            int x=(ll)a[i]*s[i]%MD * s[(m-i)&(m-1)]%MD;
            v+=x;
            if(v>=MD)
                v-=MD;
        }
        v=(ll)v*q%MD;
        an=(an-(ll)v*(1<<k)%MD+MD)%MD;
    }
    cout<<an<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    #ifdef LOCAL
        //freopen("Error2.txt","w",stderr);
    #endif

    init();

    int t=1;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}