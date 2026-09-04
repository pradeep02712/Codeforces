#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#define endl '\n'
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)

template<class T> bool umin(T& a, const T& b) {
    return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) { 
    return a<b?a=b, 1:0;
} 

ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb)/2;
        f(mb)?rb=mb:lb=mb+1; 
    } 
    return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb+1)/2;
        f(mb)?lb=mb:rb=mb-1; 
    } 
    return lb;
}

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
    cin >> x;
}
void read(double& d) {
    string t;
    read(t);
    d=stod(t);
}
void read(long double& d) {
    string t;
    read(t);
    d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
template<class A> void read(vt<A>& x) {
    EACH(a, x)
        read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
    EACH(a, x)
        read(a);
}

string to_string(char c) {
    return string(1, c);
}
string to_string(bool b) {
    return b?"true":"false";
}
string to_string(const char* s) {
    return string(s);
}
string to_string(string s) {
    return s;
}
string to_string(vt<bool> v) {
    string res;
    FOR(sz(v))
        res+=char('0'+v[i]);
    return res;
}

template<size_t S> string to_string(bitset<S> b) {
    string res;
    FOR(S)
        res+=char('0'+b[i]);
    return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
        if(!f)
            res+=' ';
        f=0;
        res+=to_string(x);
    }
    return res;
}

template<class A> void write(A x) {
    cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
    write(h);
    write(t...);
}
void print() {
    write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
    write(h);
    if(sizeof...(t))
        write(' ');
    print(t...);
}

void DBG() {
    cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t))
        cerr << ", ";
    DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

template<class T> void offset(ll o, T& x) {
    x+=o;
}
template<class T> void offset(ll o, vt<T>& x) {
    EACH(a, x)
        offset(o, a);
}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
    EACH(a, x)
        offset(o, a);
}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}

template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
    v=vt<T>(n, x);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
    v=vt<T>(n);
    EACH(a, v)
        vti(a, x, m);
}

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};  

const int M=998244353;
const int MX=3005;
ll pw(ll a,ll b){
	ll r=1;
	while(b){
		if(b&1) r=r*a%M;
		a=a*a%M;
		b>>=1;
	}
	return r;
}
void solve_one(){
	int n,m;
	read(n,m);

	vt<int> p(n),q(n),s(n+1),a(n),v(n),f(1,1);
	read(p,q);

	FOR(i,n){
        s[q[i]]=i;
    }
	FOR(i,n){
       a[i]=s[p[i]];
    }
	vt<ll> F(n+1,1),I(n+1,1);

	FOR(i,1,n+1){
		F[i]=F[i-1]*i%M;
    }
	I[n]=pw(F[n],M-2);

	FOR(i,n,0,-1){
		I[i-1]=I[i]*i%M;
    }
	auto C=[&](int x,int y)->ll {
		if(y<0||y>x) return 0;
		return F[x]*I[y]%M*I[x-y]%M;
	};
	FOR(i,n) if(!v[i]){
		int x=i,l=0;
		while(!v[x]){
			v[x]=1;
			x=a[x];
			l++;
		}
		vt<int> h(l/2+1),g(sz(f)+l/2);

		FOR(j,l/2+1){
			ll z=(ll)l*F[l-j-1]%M*I[j]%M*I[l-2*j]%M;
			h[j]=(j&1?M-z:z)%M;
		}
		FOR(j,sz(f))
			FOR(k,sz(h))
				g[j+k]=(g[j+k]+(ll)f[j]*h[k])%M;

		f.swap(g);
	}
	int d=n/2;
	vt<vt<int>> w(n+1,vt<int>(d+1));

	FOR(j,sz(f))
		FOR(e,j+1){
			ll z=(ll)f[j]*C(j,e)%M;
			if(e&1) z=(M-z)%M;

			FOR(k,j,n-j+1){
				w[k][e]=(w[k][e]+z*C(n-2*j,k-j))%M;
            }
		}
	vt<vt<int>> b(n+1,vt<int>(d+2)),c=b;
	b[n][0]=1;
	FOR(t,m){
		EACH(x,c){ 
            fill(all(x),0);
        }
		FOR(e,d+1)
			FOR(k,e,n-e+1){
				ll x=k-e,y=n-k-e;
				ll z=(1LL*n*(n-1)+2*e-2LL*e*e-2*x*y)*b[k][e]%M;

				if(e) z=(z+2LL*e*e*b[k][e-1])%M;
				if(x&&y) z=(z+2*x*y*b[k][e+1])%M;
				if(x) z=(z+x*b[k-1][e])%M;
				if(y) z=(z+y*b[k+1][e])%M;

				c[k][e]=z;
			}
		b.swap(c);
	}
	ll r=0;
	FOR(e,d+1)
		FOR(k,e,n-e+1)
			r=(r+(ll)b[k][e]*w[k][e])%M;
	print(r);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt=1;
    //read(tt);
    FOR(tt) {
        
        solve_one();
    }
}