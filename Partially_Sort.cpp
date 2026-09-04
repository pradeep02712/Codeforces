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

const int M = 998244353;
const int MX = 3005;

struct BIT{
	int n;
	vt<int> t;
	BIT(int n): n(n), t(n+1) {}
	void add(int x){
		for(;x<=n;x+=x&-x) t[x]++;
	}
	int sum(int x){
		int r=0;
		for(;x;x-=x&-x) r+=t[x];
		return r;
	}
};
void solve_one(){
	int n;
	read(n);

	vt<int> p(n),pw(n+1,1),iv(n+1),a(n),b(n),s(n),c(n);
	read(p);
	offset(-1,p);
	iv[1]=1;
	FOR(i,n){
		pw[i+1]=2LL*pw[i]%M;
    }
	FOR(i,2,n+1){
		iv[i]=M-1LL*(M/i)*iv[M%i]%M;
    }
	BIT f(n);
	vt<ar<int,3>> q;
	ll z=0;
	FOR(i,n){
		a[i]=i-f.sum(p[i]);
		b[i]=a[i]-i+p[i];
		z+=a[i];

		f.add(p[i]+1);

		int v=min(a[i],b[i]);
		if(v) q.pb({a[i]+b[i],v-1,i});
	}
	int bs=max(1,(int)sqrt(n/2.0));

	sort(all(q),[&](ar<int,3> x,ar<int,3> y){
		int u=x[0]/bs,v=y[0]/bs;

		if(u!=v) return u<v;
		if(u&1) return x[1]>y[1];
		return x[1]<y[1];
	});

	int x=0,y=0,cc=1,ss=1,h=(M+1)/2;
	auto yd=[&](){
		ss-=cc;
		if(ss<0){
            ss+=M;
        }
		cc=1LL*cc*y%M*iv[x-y+1]%M;
		--y;
	};
	auto yu=[&](){
		cc=1LL*cc*(x-y)%M*iv[y+1]%M;
		++y;
		ss+=cc;
		if(ss>=M) ss-=M;
	};
	auto xu=[&](){
		ss=(2LL*ss-cc+M)%M;
		++x;
		cc=1LL*cc*x%M*iv[x-y]%M;
	};
	auto xd=[&](){
		int t=1LL*cc*(x-y)%M*iv[x]%M;
		ss=1LL*(ss+t)*h%M;
		cc=t;
		--x;
	};
	EACH(e,q){
		int m=e[0],k=e[1],i=e[2];
		while(y>k) yd();
		while(x<m) xu();
		while(x>m) xd();
		while(y<k) yu();
		s[i]=ss;
		c[i]=cc;
	}
	ll r=z%M*pw[n-2]%M;
	FOR(i,n){
		int x=a[i],y=b[i],m=x+y;
		int v=min(x,y),d=abs(x-y);

		if(!m) continue;
		ll t;
		if(!v)
			t=1LL*m*pw[m-1]%M;
		else {
			ll C=1LL*c[i]*(m-v+1)%M*iv[v]%M;
			t=(v*C+1LL*d*(pw[m-1]-s[i]+M))%M;
		}
		r=(r+1LL*pw[n-1-m]*t)%M;
	}
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