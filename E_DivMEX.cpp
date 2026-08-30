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
const int M=400010;

vi sp(M),q;
void init(){
    F(i,2,M) if(!sp[i]){
        for(int j=i;j<M;j+=i)
            if(!sp[j]) sp[j]=i;

        for(ll x=i;x<M;x*=i) q.pb(x);
    }
    sor(q);
}
struct Seg{
    int n;
    vi t,lz;

    Seg(int n):n(n),t(4*n),lz(4*n,-1){
        b(1,1,n);
    }
    void b(int p,int l,int r){
        t[p]=r;
        if(l==r) return;

        int m=(l+r)/2;
        b(p*2,l,m);
        b(p*2+1,m+1,r);
    }
    void ps(int p){
        if(lz[p]<0) return;

        t[p*2]=t[p*2+1]=lz[p];
        lz[p*2]=lz[p*2+1]=lz[p];
        lz[p]=-1;
    }
    void u(int p,int l,int r,int ql,int qr,int x){
        if(r<ql||qr<l) return;

        if(ql<=l&&r<=qr){
            t[p]=lz[p]=x;
            return;
        }

        ps(p);

        int m=(l+r)/2;

        u(p*2,l,m,ql,qr,x);
        u(p*2+1,m+1,r,ql,qr,x);

        t[p]=max(t[p*2],t[p*2+1]);
    }
    int g(int p,int l,int r,int x){
        if(t[p]<=x) return n+1;
        if(l==r) return l;

        ps(p);

        int m=(l+r)/2;

        if(t[p*2]>x)
            return g(p*2,l,m,x);

        return g(p*2+1,m+1,r,x);
    }
    bool u(int r,int x){
        if(r<1) return 0;

        int p=g(1,1,n,x);

        if(p>r) return 0;

        u(1,1,n,p,r,x);

        return 1;
    }
};
// ---------------- SOLVE ----------------
void solve(){
    int n;
    cin>>n;

    vi a(n+1);
    vector<vi> p(n+1);
    F(i,1,n+1){
        cin>>a[i];
        int x=a[i];
        while(x>1){
            int d=sp[x],y=1;

            while(x%d==0){
                x/=d;
                y*=d;
                p[y].pb(i);
            }
        }
    }
    Seg st(n);
    vi ans;
    EACH(x,q){
        if(x>n||p[x].empty()){
            if(st.u(n,0)) ans.pb(x);
            break;
        }

        vi &v=p[x];
        bool ok=st.u(v[0]-1,0);
        FOR(i,sz(v)){
            int r=n;
            if(i+1<sz(v))
                r=v[i+1]-1;

            ok|=st.u(r,v[i]);
        }
        if(ok) ans.pb(x);
    }
    cout<<sz(ans)<<endl;
    EACH(x,ans)
        cout<<x<<" ";
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

    init();

    int t=1;
    cin>>t;

    while(t--){
        solve();
    }
}

