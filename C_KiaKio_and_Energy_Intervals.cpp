
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

// ---------------- TRIE ----------------

const int B=18;
struct T{
    struct N{
        int c[2]={},ct=0;
    };
    vector<N> t;
    vi r;
    int z=1;
    int cp(int x){
        t[z]=t[x];
        return z++;
    }
    T(const vi &p):
        t(sz(p)*(B+1)+2),r(sz(p)+1){
        FOR(i,sz(p)){
            int u=r[i],v=r[i+1]=cp(u);
            ++t[v].ct;
            R(b,B-1,-1){
                int k=(p[i]>>b)&1;
                int x=t[u].c[k],y=cp(x);
                t[v].c[k]=y;
                ++t[y].ct;
                u=x;
                v=y;
            }
        }
    }
    void dfs(int u,int v,int b,int x,int m,int q,int &a){
        if(t[u].ct==t[v].ct ||
           (q|(m&((1<<(b+1))-1)))<=a)
            return;
        if(b<0){
            a=max(a,q);
            return;
        }
        int k=(m>>b)&1;
        int h=(x>>b)&1;
        FOR(i,2){
            if(a>=m) break;
            int y=k?(h^(1-i)):i;
            dfs(t[u].c[y],t[v].c[y],b-1,
                x,m,q|((k&&!i)<<b),a);
        }
    }
    void qr(int l,int r,int x,int m,int &a){
        if(l<=r && a<m)
            dfs(this->r[r+1],this->r[l],
                B-1,x,m,0,a);
    }
};
// ---------------- SOLVE ----------------

void solve(){
    int n;
    cin>>n;
    vi a(n),p(n+1);
    FOR(i,n){
        cin>>a[i];
        p[i+1]=p[i]^a[i];
    }
    vi lc(n,-1),rc(n,-1);
    vi lo(n),hi(n),st,od;
    FOR(i,n){
        int x=-1;
        while(!st.empty() && a[st.back()]<a[i]){
            x=st.back();
            st.pop_back();
        }
        if(!st.empty()) rc[st.back()]=i;
        if(x!=-1) lc[i]=x;
        st.pb(i);
    }
    int rt=st.front();
    st={rt};
    while(!st.empty()){
        int v=st.back();
        st.pop_back();
        od.pb(v);
        if(lc[v]!=-1) st.pb(lc[v]);
        if(rc[v]!=-1) st.pb(rc[v]);
    }
    T tr(p);
    int ans=0;
    R(z,n-1,-1){
        int v=od[z];
        
        lo[v]=lc[v]<0?v:lo[lc[v]];
        hi[v]=rc[v]<0?v:hi[rc[v]];
        int l=lo[v],r=hi[v],m=a[v];
        if(m<=ans) continue;
        if(v-l<=r-v){
            for(int i=l;i<=v && ans<m;i++)
                tr.qr(v+1+(i==v),
                      r+1,p[i],m,ans);
        }
        else{
            for(int j=v+1;j<=r+1 && ans<m;j++)
                tr.qr(l,v-(j==v+1),
                      p[j],m,ans);
        }
    }
    cout<<ans<<endl;
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
