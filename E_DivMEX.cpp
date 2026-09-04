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

const int N=400005;

vi sp(N),p;

struct ST{
    int n;
    vi t;

    void in(int m){
        n=1;

        while(n<=m)
            n<<=1;

        t.assign(n<<1,N);

        EACH(x,p){
            if(x>m) break;
            t[n+x]=0;
        }

        R(i,n-1,0)
            t[i]=min(t[i<<1],t[i<<1|1]);
    }

    void up(int x,int v){
        x+=n;
        t[x]=v;

        while(x>>=1)
            t[x]=min(t[x<<1],t[x<<1|1]);
    }

    int qr(int l,int r){
        if(l>r) return N;

        int z=N;

        l+=n;
        r+=n;

        while(l<=r){
            if(l&1)
                z=min(z,t[l++]);

            if(!(r&1))
                z=min(z,t[r--]);

            l>>=1;
            r>>=1;
        }

        return z;
    }
};

void pre(){
    iota(all(sp),0);

    F(i,2,N){
        if(1LL*i*i>=N)
            break;

        if(sp[i]!=i)
            continue;

        for(int j=i*i;j<N;j+=i)
            if(sp[j]==j)
                sp[j]=i;
    }

    p.pb(1);

    F(i,2,N){
        if(sp[i]!=i)
            continue;

        ll x=i;

        while(x<N){
            p.pb(x);

            if(x>(N-1)/i)
                break;

            x*=i;
        }
    }

    sor(p);
}
// ---------------- SOLVE ----------------
void solve(){
    int n;
    cin>>n;

    vi a(n);

    EACH(x,a)
        cin>>x;

    int b=*ub(all(p),n);

    ST t;
    t.in(b);

    vi l(b+1),o(b+1);

    FOR(i,n){
        int y=a[i];
        vi d;

        while(y>1){
            int q=sp[y],z=1;

            while(y%q==0){
                y/=q;
                z*=q;
                d.pb(z);
            }
        }

        EACH(x,d){
            if(!o[x]&&t.qr(1,x-1)>l[x])
                o[x]=1;
        }

        t.up(1,i+1);

        EACH(x,d){
            l[x]=i+1;
            t.up(x,i+1);
        }
    }

    vi r;

    EACH(x,p){
        if(x==1)
            continue;

        if(x>b)
            break;

        if(!o[x]&&t.qr(1,x-1)>l[x])
            o[x]=1;

        if(o[x])
            r.pb(x);
    }

    cout<<sz(r)<<endl;

    EACH(x,r)
        cout<<x<<' ';

    cout<<endl;
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