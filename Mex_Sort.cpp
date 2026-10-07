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

// ---------------- SOLVE ----------------
void solve(){
    int n;
    cin>>n;
    vi a(n),p(n);
    FOR(i,n) cin>>a[i],p[a[i]]=i;
    int l=p[0],r=l,x=-1;
    F(i,1,n){
        if(l<p[i]&&p[i]<r){
            x=i;
            break;
        }
        l=min(l,p[i]);
        r=max(r,p[i]);
    }
    if(x<0){
    FOR(i,n) if(a[i]!=i){
        cout<<-1<<endl;
        return;
    }
    cout<<0<<endl;
    return;
    }
    int u=p[x];
    auto go=[&](vi &b,int z){
        cout<<n-1<<endl;
        FOR(i,n) if(i!=z) cout<<i<<" ";
        cout<<endl;
        FOR(i,n) if(i!=z) cout<<b[i]<<" ";
        cout<<endl;
    };
    vi d(n);
    iota(all(d),0);
    if(u==x){
        cout<<1<<endl;
        go(d,x);
        return;
    }
    int q=2;
    if(q==x||q==u) q=n-2;
    if(q==x||q==u) q=3;
    vi b(n,-1),v(n);
    b[u]=x,b[q]=q;
    v[x]=v[q]=1;
    if(x<q){
        int z=u<q?q+1:q-1;
        b[z]=0;
        v[0]=1;
    }
    else{
        int l=q-1-(u==q-1),r=q+1+(u==q+1);
        b[l]=0,b[r]=1;
        v[0]=v[1]=1;
    }
    int j=0;
    FOR(i,n) if(b[i]<0){
        while(v[j]) j++;
        b[i]=j;
        v[j]=1;
    }
    cout<<2<<endl;
    go(b,u);
    go(d,q);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

    #ifdef LOCAL
         //freopen("Error2.txt","w",stderr);
    #endif

    int t=1;
    cin>>t;

    while(t--){
        solve();
    }
}

