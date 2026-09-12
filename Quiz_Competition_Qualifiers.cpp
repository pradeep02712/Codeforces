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
struct Node{
    int c[2];
    int z;
    Node(){
        c[0]=c[1]=0;
        z=0;
    }
};
struct Trie{
    vector<Node> tr;
    vector<int> fr;
    Trie(int n=0){
        tr.reserve(n);
        tr.pb(Node());
        tr.pb(Node());
    }
    int nw(){
        if(!fr.empty()){
            int u=fr.back();
            fr.pop_back();
            tr[u]=Node();
            return u;
        }
        tr.pb(Node());
        return sz(tr)-1;
    }
    void add(const str &x){
        int u=1;
        tr[u].z++;
        for(char ch:x){
            int b=ch-'0';
            if(!tr[u].c[b])
                tr[u].c[b]=nw();

            u=tr[u].c[b];
            tr[u].z++;
        }
    }
    void del(const str &x){
        vi p(sz(x)+1);

        int u=1;
        p[0]=u;
        FOR(i,sz(x)){
            u=tr[u].c[x[i]-'0'];
            p[i+1]=u;
        }
        for(int u:p)
            tr[u].z--;
        R(i,sz(x),0){
            int u=p[i];

            if(tr[u].z)
                break;
            int par=p[i-1];
            int b=x[i-1]-'0';
            tr[par].c[b]=0;
            fr.pb(u);
        }
    }
    bool ok(const str &x,int m){
        int u=1;
        int r=m;

        for(char ch:x){
            int b=ch-'0';
            int v=tr[u].c[1];
            int c1=v?tr[v].z:0;
            if(c1<=r){
                if(b==1)
                    return true;
                r-=c1;
                u=tr[u].c[0];
            }
            else{
                if(b==0)
                    return false;
                u=tr[u].c[1];
            }
            if(!u)
                return false;
        }
        return false;
    }
};
// ---------------- SOLVE ----------------
void solve(){

    int n,m,k;
    cin>>n>>m>>k;
    str t;
    cin>>t;
    vs ss(n);
    EACH(x,ss)
        cin>>x;
    vs a(n);
    FOR(i,n){
        a[i].resize(k);
        FOR(j,k)
            a[i][j]=(ss[i][j]==t[j]?'1':'0');
    }
    Trie tr(n*(k+1)+5);
    EACH(x,a)
        tr.add(x);
    int q;
    cin>>q;
    while(q--){
        int i,j;
        cin>>i>>j;
        --i;
        --j;
        tr.del(a[i]);
        a[i][j]=(a[i][j]=='1'?'0':'1');
        tr.add(a[i]);
        cout<<(tr.ok(a[i],m)?"Yes":"No")<<endl;
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
    //cin>>t;

    while(t--){
        solve();
    }
}

