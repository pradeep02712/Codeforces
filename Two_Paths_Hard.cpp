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
const int I=1000000000;
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
struct S{
    int l=-1,r=-1;
    int d[4]={I,I,I,I};
};
S mg(const S &a,const S &b,int m){
    if(a.l<0) return b;
    if(b.l<0) return a;
    S c;
    c.l=a.l,c.r=b.r;
    int x=(a.r/m==b.l/m);
    int y=(a.r%m==b.l%m);
    FOR(i,2) FOR(j,2)
        c.d[2*i+j]=min({
            a.d[2*i]+b.d[j]-x,
            a.d[2*i]+b.d[j+2],
            a.d[2*i+1]+b.d[j],
            a.d[2*i+1]+b.d[j+2]-y
        });
    return c;
}
// ---------------- SOLVE ----------------
void solve(){
    int n,m;
    cin>>n>>m;
    int k=n*m,h=n+m-1,w=1;
    while(w<h) w<<=1;

    vi t(k),a(k),g(k),b(k);
    vi l(h,I),r(h,I),p(h);
    vector<S> v(2*w);
    vector<vpi> e(k+1);

    F(i,1,k+1){
        int x,y,c;
        cin>>x>>y>>c;
        int j=(x-1)*m+y-1;
        t[j]=i,a[j]=c;
    }
    FOR(i,k)
        g[i]=max(t[i],i==0?0:
            min(i>=m?g[i-m]:I , i%m?g[i-1]:I));

    R(i,k-1,-1)
        b[i]=max(t[i],i==k-1?0:
            min(i+m<k?b[i+m]:I,
                i%m+1<m?b[i+1]:I));
    FOR(i,k){
        int j=i/m+i%m,z=max(g[i],b[i]);
        if(z<l[j])
            r[j]=l[j],l[j]=z,p[j]=i;
        else r[j]=min(r[j],z);
    }
    int q=*min_element(all(r));
    FOR(i,h){
        if(l[i]<r[i] && a[p[i]]==1){
            e[l[i]].eb(i,p[i]);
            if(r[i]<=k) e[r[i]].eb(i,-1);
        }
    }
    F(i,1,k+1){
        for(auto [j,z]:e[i]){
            S u;
            if(z>=0)
                u.l=u.r=z,u.d[0]=u.d[3]=1;
            int x=w+j;
            v[x]=u;
            while(x>>=1)
                v[x]=mg(v[x<<1],v[x<<1|1],m);
        }
        int z=v[1].l<0?0:
            *min_element(v[1].d,v[1].d+4);
        cout<<(i<q?-1:z)<<endl;
    }
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

