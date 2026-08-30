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
vl ad(vl a,ll x){
    a.ins(lb(all(a),x,greater<ll>()),x);
    return a;
}
vl sl(vpl &v){
    int n=sz(v),i=0,c;
    ll s=0,g=0;
    while(i<n&&v[i].f==3) s+=v[i++].s;
    if(i==n) return {s};

    vl a,e;
    c=v[i].f;
    s+=v[i++].s;
    F(j,i,n){
        if(v[j].f==3){
            g+=v[j].s;
            continue;
        }
        if(v[j].f==c) s+=g+v[j].s;
        else{
            a.pb(s);
            e.pb(g);
            s=v[j].s;
            c=v[j].f;
        }
        g=0;
    }
    a.pb(s+g);
    n=sz(a);

    if(n==1) return a;

    vl d[2]={{a[0]+e[0]},{a[0]}};
    F(i,1,n-1){
        vl q[2];

        FOR(j,2)
            q[j]=max(ad(d[0],a[i]+(!j)*e[i]),ad(d[1],a[i]+e[i-1]+(!j)*e[i]));

        FOR(j,2) d[j]=move(q[j]);
    }
    return max(ad(d[0],a[n-1]),
               ad(d[1],a[n-1]+e[n-2]));
}
// ---------------- SOLVE ----------------

void solve(){
    int n,m;
    cin>>n>>m;
    vector<array<ll,3>> e;

    FOR(c,2){
        int k=c?m:n;
        while(k--){
            ll l,r;
            cin>>l>>r;
            e.pb({l,c,1});
            e.pb({r+1,c,-1});
        }
    }
    sor(e);
    int c[2]={};
    ll p=e[0][0];

    vpl v;
    vl a;
    auto go=[&](){
        if(!sz(v)) return;

        vl x=sl(v);
        a.ins(a.end(),all(x));
        v.clear();
    };
    for(int i=0;i<sz(e);){
        ll x=e[i][0];
        if(x>p){
            int k=(c[0]>0)+2*(c[1]>0);
            ll d=x-p;
            if(!k) go();
            else if(sz(v)&&v.back().f==k) v.back().s+=d;
            else v.pb({k,d});
        }
        while(i<sz(e)&&e[i][0]==x){
            c[e[i][1]]+=e[i][2];
            i++;
        }
        p=x;
    }

    go();
    sort(rall(a));
    cout<<sz(a)<<endl;
    EACH(x,a) cout<<x<<' ';
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

    int t=1;
    cin>>t;

    while(t--){
        solve();
    }
}

