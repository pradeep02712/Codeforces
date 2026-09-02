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
struct N{
    int l,r,v;
    u32 p;
    ll c,n,q;
};
vector<N> tr;
int tt;
u32 sd=123456789;

u32 rd(){
    sd^=sd<<13;
    sd^=sd>>17;
    sd^=sd<<5;
    return sd;
}

ll cn(int x){
    return x?tr[x].n:0;
}

ll sm(int x){
    return x?tr[x].q:0;
}

void up(int x){
    if(!x) return;

    tr[x].n=tr[x].c+cn(tr[x].l)+cn(tr[x].r);
    tr[x].q=1LL*tr[x].v*tr[x].c+sm(tr[x].l)+sm(tr[x].r);
}

int nw(int v,ll c){
    ++tt;
    tr[tt]={0,0,v,rd(),c,c,1LL*v*c};
    return tt;
}

void sp(int x,int v,int &a,int &b){
    if(!x){
        a=b=0;
        return;
    }

    if(tr[x].v<v){
        a=x;
        sp(tr[x].r,v,tr[x].r,b);
        up(a);
    }else{
        b=x;
        sp(tr[x].l,v,a,tr[x].l);
        up(b);
    }
}

int mg(int a,int b){
    if(!a||!b) return a?a:b;

    if(tr[a].p>tr[b].p){
        tr[a].r=mg(tr[a].r,b);
        up(a);
        return a;
    }

    tr[b].l=mg(a,tr[b].l);
    up(b);
    return b;
}

int ad(int x,int v,ll c){
    int a,b,p,q;

    sp(x,v,a,b);
    sp(b,v+1,p,q);

    if(p){
        tr[p].c+=c;
        up(p);
    }else{
        p=nw(v,c);
    }

    return mg(mg(a,p),q);
}

pl qr(int x,int v){
    if(!x) return {0,0};

    if(tr[x].v>v)
        return qr(tr[x].l,v);

    pl q=qr(tr[x].r,v);

    q.f+=cn(tr[x].l)+tr[x].c;
    q.s+=sm(tr[x].l)+1LL*tr[x].v*tr[x].c;

    return q;
}

ll f1(int x,int y,int m,ll c,ll z){
    if(!x) return 0;

    ll r=f1(tr[x].l,y,m,c,z)
        +f1(tr[x].r,y,m,c,z);

    pl q=qr(y,tr[x].v-m);

    r+=tr[x].c*
       (q.f*tr[x].v+
        (c-q.f)*m+
        z-q.s);

    return r;
}

ll f2(int x,int y,int m,ll z){
    if(!x) return 0;

    ll r=f2(tr[x].l,y,m,z)
        +f2(tr[x].r,y,m,z);

    ll v=m+tr[x].v;
    pl q=qr(y,v);

    r+=tr[x].c*(q.f*v+z-q.s);

    return r;
}

// ---------------- SOLVE ----------------

void solve(){
    int n;
    cin>>n;

    vi a(n);
    EACH(x,a) cin>>x;

    vi l(n,-1),r(n,-1),st;

    FOR(i,n){
        int x=-1;

        while(sz(st)&&a[st.back()]<=a[i]){
            x=st.back();
            st.pop_back();
        }

        if(sz(st))
            r[st.back()]=i;

        if(x!=-1)
            l[i]=x;

        st.pb(i);
    }

    int rt=st[0];

    vi o;
    st.clear();
    st.pb(rt);

    while(sz(st)){
        int u=st.back();
        st.pop_back();

        o.pb(u);

        if(l[u]!=-1) st.pb(l[u]);
        if(r[u]!=-1) st.pb(r[u]);
    }

    rev(o);

    tr.assign(2*n+10,{});
    tt=0;

    vi z(n),x(n),y(n);
    vl d(n);

    EACH(u,o){
        int L=l[u],R=r[u];

        ll p=L==-1?0:z[L];
        ll q=R==-1?0:z[R];

        ll A=L==-1?0:sm(x[L]);
        ll B=R==-1?0:sm(y[R]);

        ll w=0;

        if(L!=-1&&R!=-1){
            if(p<=q)
                w=f1(x[L],y[R],a[u],q,B);
            else
                w=f2(y[R],x[L],a[u],A);
        }

        d[u]=w;

        if(L!=-1)
            d[u]+=d[L]+A;

        if(R!=-1)
            d[u]+=d[R]+1LL*a[u]*q+B;

        z[u]=1+p+q;

        y[u]=L==-1?0:y[L];
        y[u]=ad(y[u],a[u],q+1);

        if(R==-1){
            x[u]=L==-1?0:x[L];
            x[u]=ad(x[u],0,1);
        }else{
            int v=L==-1?0:x[L];
            int p1,p2;
            int w=a[u]+a[R];

            sp(v,w,p1,p2);

            ll c=cn(p1);

            p2=ad(p2,w,c+1);
            x[u]=mg(x[R],p2);
        }
    }

    cout<<d[rt]<<endl;
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

