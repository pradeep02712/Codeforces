#ifndef LOCAL
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#endif
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
template<class A> void read(vt<A>& v);
template<class A,size_t S> void read(ar<A,S>& a);
template<class T> void read(T& x){ cin>>x; }
void read(double& d){ string t; read(t); d=stod(t); }
void read(ld& d){ string t; read(t); d=stold(t); }
template<class H,class...T> void read(H& h,T&...t){ read(h); read(t...); }
template<class A> void read(vt<A>&x){ EACH(a,x) read(a); }
template<class A,size_t S> void read(ar<A,S>&x){ EACH(a,x) read(a); }
struct C{
int k,b,l;
double s,la,bw,s1,s2,tu,tb,db,wt,wc;
vt<pair<int,double>> t[6];
};
struct R{ int s=-1,c=-1,n=0,x=0,g=-1; double a=0,r=0,p=0; };
using P=pair<double,int>;
double gt(C&c,int p,int x){
auto &v=c.t[p];
if(x<=v.front().first) return v.front().second;
if(x>=v.back().first) return v.back().second;
int r=lower_bound(all(v),make_pair(x,-1e100))-v.begin();
if(v[r].first==x) return v[r].second;
auto [a,b]=v[r-1]; auto [d,e]=v[r];
return b+(e-b)*(x-a)/(d-a);
}
double pf(C&c,int n){
double x=c.la+8.0*n*c.b/(c.bw*1e6);
return 3*c.s+gt(c,0,n)+gt(c,1,n)+gt(c,2,n)+2*x;
}
void old_run(C&c){
int k=c.k,l=c.l; double s=c.s;
vt<R> q;
vt<bool> w(k);
vt<int> ct(k),dc(k);
vt<double> pl(k);
vt<set<int>> pp(k),dp(k);
set<int> p0,p6,d8,d14;
bool e=0;
string h,u;
while(cin>>h){
if(h=="END") return;
int m; read(m); getline(cin,u);
FOR(m){
getline(cin,u);
stringstream ss(u); vt<string> v; string x;
while(ss>>x) v.pb(x);
if(!sz(v)) continue;
if(v[0]=="ARR"){
int r=stoi(v[1]);
if(r>=sz(q)) q.resize(r+1);
q[r].s=0; q[r].n=stoi(v[2]); p0.insert(r);
}else if(v[0]=="FIN"){
int r=stoi(v[1]); d8.erase(r);
if(q[r].s!=16&&q[r].c>=0){ ct[q[r].c]--; dc[q[r].c]--; }
q[r].s=16;
}else if(v[0]=="XDN"){
string d=v[1],p=v[4]; int x=stoi(v[5]);
FOR(j,x){
int r=stoi(v[6+j]); if(q[r].s==16) continue;
if(p=="PRE"){
if(d=="UP"){ q[r].s=3; pp[q[r].c].insert(r); }
else{ q[r].s=6; p6.insert(r); }
}else{
if(d=="UP"){ q[r].s=11; dp[q[r].c].insert(r); }
else{ q[r].s=14; d14.insert(r); }
}
}
}else if(v[0]=="TDN"){
string y=v[1],p=v[2],d=v[3];
if(y=="E") e=0;
else{ int x=stoi(y.substr(1)); if(x>=0&&x<k) w[x]=0; }
if(p=="P"){
int r=d=="PROC"?stoi(v[7]):stoi(v[5]);
if(q[r].s==16) continue;
if(d=="PRE") q[r].s=2;
else if(d=="POST"){ q[r].s=8; d8.insert(r); }
else{
q[r].x=stoi(v[5]);
if(q[r].x==l){
q[r].s=5; dc[q[r].c]++; pl[q[r].c]-=q[r].p;
if(pl[q[r].c]<0) pl[q[r].c]=0;
}else{ q[r].s=3; pp[q[r].c].insert(r); }
}
}else{
int x=stoi(v[5]);
FOR(j,x){
int r=stoi(v[6+j]); if(q[r].s==16) continue;
if(d=="PRE") q[r].s=10;
else if(d=="PROC") q[r].s=13;
else{ q[r].s=8; d8.insert(r); }
}
}
}
}
vt<string> o;
if(!e){
if(sz(d14)){
string x="E D POST -1 "+to_string(sz(d14));
EACH(r,d14){ x+=" "+to_string(r); q[r].s=15; }
d14.clear(); o.pb(x); e=1;
}else if(sz(p6)){
int r=*p6.begin(); p6.erase(p6.begin());
o.pb("E P POST "+to_string(q[r].c)+" "+to_string(r)); q[r].s=7; e=1;
}else if(sz(d8)){
string x="E D PRE -1 "+to_string(sz(d8));
EACH(r,d8){ x+=" "+to_string(r); q[r].s=9; }
d8.clear(); o.pb(x); e=1;
}else if(sz(p0)){
int r=*p0.begin(),z=0; p0.erase(p0.begin());
double mn=1e100,d=gt(c,4,1)+s;
FOR(j,k){ double x=pl[j]+(4.0*ct[j]+w[j])*d; if(x<mn){mn=x;z=j;} }
q[r].c=z; q[r].p=gt(c,1,q[r].n); pl[z]+=q[r].p; ct[z]++;
o.pb("E P PRE "+to_string(z)+" "+to_string(r)); q[r].s=1; e=1;
}
}
FOR(z,k){
if(w[z]) continue;
if(sz(dp[z])){
string x="C"+to_string(z)+" D PROC "+to_string(z)+" "+to_string(sz(dp[z]));
EACH(r,dp[z]){ x+=" "+to_string(r); q[r].s=12; }
dp[z].clear(); o.pb(x); w[z]=1; continue;
}
if(sz(pp[z])){
int r=*pp[z].begin(); pp[z].erase(pp[z].begin());
int x=q[r].x,y=l;
if(dc[z]){
double rm=q[r].p*(l-x)/l;
double tg=max(4.0*s,2.0*(gt(c,4,1)+s));
int a=min(8,max(1,(int)ceil(rm/tg)));
y=min(l,x+(l-x+a-1)/a);
}
o.pb("C"+to_string(z)+" P PROC "+to_string(x)+" "+to_string(y)+" "+to_string(z)+" "+to_string(r));
q[r].s=4; w[z]=1;
}
}
cout<<sz(o)<<endl; EACH(z,o) cout<<z<<endl; cout<<flush;
}
}
struct G{ vt<int> v; int d=0; bool z=0; double t=0; };
void new_run(C&c){
int k=c.k,b=c.b,l=c.l; double s=c.s,s1=c.s1,s2=c.s2,tu=c.tu,tb=c.tb,db=c.db,wt=c.wt,wc=c.wc,bw=c.bw,la=c.la;
double tr=8.0*b/(bw*1e6);
auto nt=[&](double x){ return max(0.0,min(1.0,(x-tb)/(tu-tb))); };
auto nc=[&](double d){ if(db==0) return d<=1e-12?1.0:0.0; return max(0.0,1-d/db); };
int B=1; double bs=-1;
FOR(m,1,2001){
int z=min(k,m),r=(m+z-1)/z;
double ep=s+gt(c,3,m),po=s+gt(c,5,m),rp=s+gt(c,4,r),lk=z*la+m*tr;
double cp=min({m/(ep+po),m/rp,m/lk});
double cy=ep+lk+rp+lk+po;
double ex=max(0.0,cy/s2-1);
double sc=wt*nt(cp)+wc*nc(ex);
if(sc>bs+1e-12||(abs(sc-bs)<1e-12&&((wc>.55&&m<B)||(wc<=.55&&m>B)))) bs=sc,B=m;
}
if(db==0&&wc>.2) B=min(B,4);
if(wt<.1) B=min(B,2);
int RB=max(1,(B+k-1)/k);
int EL=B<=2?1:B<=8?2:B<=64?4:8;
if(db==0&&wc>0) EL=1;
vt<R> q; vt<G> gs;
priority_queue<P,vt<P>,greater<P>> h0,h6,h8,hp;
vt<priority_queue<P,vt<P>,greater<P>>> p3(k),d1(k);
vt<char> cb(k); vt<int> ac(k),qs(k),ds(k); vt<double> pl(k);
bool eb=0; int es=0; string x,y;
auto clean=[&](auto&h,int st){ while(!h.empty()&&q[h.top().second].s!=st) h.pop(); };
auto top=[&](auto&h,int st){ clean(h,st); return h.empty()?-1:h.top().second; };
auto inf=[&](){
if(eb) return true;
EACH(z,cb) if(z) return true;
EACH(r,q) if(r.s==1||r.s==2||r.s==4||r.s==5||r.s==7||r.s==9||r.s==10||r.s==12||r.s==13||r.s==15) return true;
return false;
};
auto cnt=[&](){ clean(h8,8); return sz(h8); };
while(cin>>x){
if(x=="END") return;
double tm=stod(x); int m; read(m); getline(cin,y); vt<int> fn,dn;
FOR(m){
getline(cin,y); stringstream ss(y); vt<string> v; string z; while(ss>>z) v.pb(z); if(!sz(v)) continue;
if(v[0]=="ARR"){
int r=stoi(v[1]); if(r>=sz(q)) q.resize(r+1); q[r].s=0; q[r].n=stoi(v[2]); q[r].a=tm; h0.push({tm,r});
}else if(v[0]=="FIN") fn.pb(stoi(v[1]));
else if(v[0]=="XDN"){
string d=v[1],p=v[4]; int z=stoi(v[5]);
FOR(j,z){
int r=stoi(v[6+j]); if(q[r].s==16) continue;
if(p=="PRE"){
if(d=="UP"){q[r].s=3;p3[q[r].c].push({q[r].a,r});}
else{q[r].s=6;h6.push({q[r].a,r});}
}else{
if(d=="UP"){q[r].s=11;d1[q[r].c].push({q[r].r,r});}
else{
q[r].s=14; int g=q[r].g;
if(g>=0&&++gs[g].d==sz(gs[g].v)){gs[g].z=1;gs[g].t=tm;hp.push({tm,g});}
}
}
}
}else if(v[0]=="TDN"){
string sv=v[1],p=v[2],st=v[3];
if(sv=="E") eb=0; else{int z=stoi(sv.substr(1)); if(z>=0&&z<k) cb[z]=0;}
if(p=="P"){
int r=st=="PROC"?stoi(v[7]):stoi(v[5]); if(q[r].s==16) continue;
if(st=="PRE") q[r].s=2;
else if(st=="POST"){q[r].s=8;q[r].r=tm;ds[q[r].c]++;h8.push({tm,r});}
else{
int a=stoi(v[4]),e=stoi(v[5]); pl[q[r].c]-=q[r].p*(e-a)/l; if(pl[q[r].c]<0) pl[q[r].c]=0; q[r].x=e;
if(e==l) q[r].s=5; else{q[r].s=3;p3[q[r].c].push({q[r].a,r});}
}
}else{
int z=stoi(v[5]);
FOR(j,z){
int r=stoi(v[6+j]); if(q[r].s==16) continue;
if(st=="PRE") q[r].s=10; else if(st=="PROC") q[r].s=13; else{q[r].s=17;dn.pb(r);}
}
}
}
}
EACH(r,fn){ if(q[r].s==16) continue; if(q[r].c>=0){ac[q[r].c]--;ds[q[r].c]--;} q[r].s=16; }
EACH(r,dn){ if(q[r].s==16) continue; q[r].s=8;q[r].r=tm;q[r].g=-1;h8.push({tm,r}); }
vt<string> o;
if(!eb){
while(!hp.empty()){int g=hp.top().second;if(g<sz(gs)&&gs[g].z) break;hp.pop();}
int i0=top(h0,0),i6=top(h6,6),nr=cnt(); bool pg=i0>=0||i6>=0,gg=!hp.empty();
double wl=max(s2,B/max(tu,1e-12)); bool old=nr>0&&tm-h8.top().first>=wl; bool full=nr>=B||old; bool force=nr>0&&!full&&!inf()&&!pg; int ty=-1;
if(pg&&es>=EL) ty=1; else if(gg) ty=0; else if(full) ty=2; else if(i6>=0) ty=1; else if(i0>=0) ty=3; else if(force||(nr>0&&(B<=2||wc>.8))) ty=2;
if(ty==0){
vt<int> v; int z=0;
while(!hp.empty()){
int g=hp.top().second; if(!gs[g].z){hp.pop();continue;} if(z&&z+sz(gs[g].v)>B) break; hp.pop(); gs[g].z=0;
EACH(r,gs[g].v) if(q[r].s==14){v.pb(r);q[r].s=15;} z=sz(v); if(z>=B) break;
}
if(sz(v)){string z="E D POST -1 "+to_string(sz(v));EACH(r,v) z+=" "+to_string(r);o.pb(z);eb=1;es++;}
}else if(ty==1){
int r=i6>=0?i6:i0;
if(i6>=0){clean(h6,6);h6.pop();o.pb("E P POST "+to_string(q[r].c)+" "+to_string(r));q[r].s=7;}
else{
clean(h0,0);h0.pop();int z=0;FOR(j,1,k) if(make_pair(pl[j],ac[j])<make_pair(pl[z],ac[z])) z=j;
q[r].c=z;q[r].p=gt(c,1,q[r].n);pl[z]+=q[r].p;ac[z]++;o.pb("E P PRE "+to_string(z)+" "+to_string(r));q[r].s=1;
}
eb=1;es=0;
}else if(ty==3){
clean(h0,0);int r=h0.top().second;h0.pop();int z=0;FOR(j,1,k) if(make_pair(pl[j],ac[j])<make_pair(pl[z],ac[z])) z=j;
q[r].c=z;q[r].p=gt(c,1,q[r].n);pl[z]+=q[r].p;ac[z]++;o.pb("E P PRE "+to_string(z)+" "+to_string(r));q[r].s=1;eb=1;es=0;
}else if(ty==2){
clean(h8,8);int z=min(B,sz(h8));vt<int> v;v.reserve(z);
FOR(j,z){int r=h8.top().second;h8.pop();q[r].s=9;v.pb(r);} int g=sz(gs);gs.pb({v,0,0,0});string u="E D PRE -1 "+to_string(z);
EACH(r,v){q[r].g=g;u+=" "+to_string(r);}o.pb(u);eb=1;es++;
}
}
FOR(z,k){
if(cb[z]) continue; clean(d1[z],11);clean(p3[z],3);bool hd=!d1[z].empty(),pp=!p3[z].empty();int lm=B<=2?1:B<=8?2:B<=64?4:8;bool tp=pp&&(!hd||qs[z]>=lm);
if(hd&&!tp){
vt<int> v;int a=min(RB,sz(d1[z]));FOR(j,a){int r=d1[z].top().second;d1[z].pop();q[r].s=12;v.pb(r);}string u="C"+to_string(z)+" D PROC "+to_string(z)+" "+to_string(sz(v));EACH(r,v) u+=" "+to_string(r);o.pb(u);cb[z]=1;qs[z]++;
}else if(pp){
int r=p3[z].top().second;p3[z].pop();int a=q[r].x,e=l;double bd=min(s1/4.0,s2/2.0);if(db>20||wt>.5) bd*=2;if(db>200||wt>.8) bd*=4;
if(hd||ds[z]){double full=q[r].p*(l-a)/l;int pc=min(l-a,max(1,(int)ceil(full/max(bd,s+1e-9))));if(wc<.2) pc=1;e=min(l,a+(l-a+pc-1)/pc);}
o.pb("C"+to_string(z)+" P PROC "+to_string(a)+" "+to_string(e)+" "+to_string(z)+" "+to_string(r));q[r].s=4;cb[z]=1;qs[z]=0;
}
}
cout<<sz(o)<<endl;EACH(z,o) cout<<z<<endl;cout<<flush;
}
}
void lat_run(C&c){
int k=c.k,l=c.l;double s=c.s,s1=c.s1,s2=c.s2;
vt<R> q;vt<char> w(k);vt<int> tk,ac(k);vt<double> pl(k);
priority_queue<P,vt<P>,greater<P>> h0,h6,h8,h14;
vt<priority_queue<P,vt<P>,greater<P>>> p3(k),d1(k);
bool e=0;int pc=0;string h,u;
auto cl=[&](auto&x,int st){while(!x.empty()&&q[x.top().second].s!=st)x.pop();};
auto tp=[&](auto&x,int st){cl(x,st);return x.empty()?-1:x.top().second;};
while(cin>>h){
if(h=="END")return;
double tm=stod(h);int m;read(m);getline(cin,u);vt<int> fn,dn;
FOR(m){
getline(cin,u);stringstream ss(u);vt<string> v;string x;while(ss>>x)v.pb(x);if(!sz(v))continue;
if(v[0]=="ARR"){
int r=stoi(v[1]);if(r>=sz(q)){q.resize(r+1);tk.resize(r+1);}q[r].s=0;q[r].n=stoi(v[2]);q[r].a=tm;h0.push({tm,r});
}else if(v[0]=="FIN")fn.pb(stoi(v[1]));
else if(v[0]=="XDN"){
string d=v[1],p=v[4];int z=stoi(v[5]);FOR(j,z){int r=stoi(v[6+j]);if(q[r].s==16)continue;if(p=="PRE"){if(d=="UP"){q[r].s=3;p3[q[r].c].push({q[r].a,r});}else{q[r].s=6;h6.push({q[r].a,r});}}else{if(d=="UP"){q[r].s=11;d1[q[r].c].push({tk[r]?q[r].r:1e100,r});}else{q[r].s=14;h14.push({tk[r]?q[r].r:1e100,r});}}}
}else if(v[0]=="TDN"){
string sv=v[1],p=v[2],st=v[3];if(sv=="E")e=0;else{int z=stoi(sv.substr(1));if(z>=0&&z<k)w[z]=0;}
if(p=="P"){
int r=st=="PROC"?stoi(v[7]):stoi(v[5]);if(q[r].s==16)continue;if(st=="PRE")q[r].s=2;else if(st=="POST"){q[r].s=8;q[r].r=tm;h8.push({tk[r]?q[r].r:1e100,r});}else{int a=stoi(v[4]),z=stoi(v[5]);pl[q[r].c]-=q[r].p*(z-a)/l;if(pl[q[r].c]<0)pl[q[r].c]=0;q[r].x=z;if(z==l)q[r].s=5;else{q[r].s=3;p3[q[r].c].push({q[r].a,r});}}
}else{
int z=stoi(v[5]);FOR(j,z){int r=stoi(v[6+j]);if(q[r].s==16)continue;if(st=="PRE")q[r].s=10;else if(st=="PROC")q[r].s=13;else{q[r].s=17;dn.pb(r);}}
}
}
}
EACH(r,fn){if(q[r].s==16)continue;if(q[r].c>=0)ac[q[r].c]--;q[r].s=16;}
EACH(r,dn){if(q[r].s==16)continue;tk[r]++;q[r].s=8;q[r].r=tm;h8.push({q[r].r,r});}
vt<string> o;
if(!e){
int a0=tp(h0,0),a6=tp(h6,6),a8=tp(h8,8),a14=tp(h14,14),ty=-1;
double bs=-1;
auto ad=[&](int r,int z){if(r<0)return;double sc=0;if(z<=1)sc=(tm-q[r].a)/max(s1,1e-9)+(z==1?2:0);else sc=tk[r]?(tm-q[r].r)/max(s2,1e-9)+1:0.05;if(z>=2&&pc>=4)sc+=100;if(z<=1&&pc<4)sc+=.5;if(sc>bs)bs=sc,ty=z;};
ad(a0,0);ad(a6,1);ad(a8,2);ad(a14,3);
if(ty==1){cl(h6,6);int r=h6.top().second;h6.pop();o.pb("E P POST "+to_string(q[r].c)+" "+to_string(r));q[r].s=7;e=1;pc++;}
else if(ty==3){vt<int> v;while(1){cl(h14,14);if(h14.empty())break;int r=h14.top().second;if(tk[r]==0&&sz(v))break;h14.pop();q[r].s=15;v.pb(r);if(sz(v)>=64)break;}if(sz(v)){string x="E D POST -1 "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);e=1;pc=0;}}
else if(ty==0){cl(h0,0);int r=h0.top().second;h0.pop();int z=0;FOR(j,1,k)if(make_pair(ac[j],pl[j])<make_pair(ac[z],pl[z]))z=j;q[r].c=z;q[r].p=gt(c,1,q[r].n);pl[z]+=q[r].p;ac[z]++;o.pb("E P PRE "+to_string(z)+" "+to_string(r));q[r].s=1;e=1;pc++;}
else if(ty==2){vt<int> v;bool qd=tk[a8]>0;while(1){cl(h8,8);if(h8.empty())break;int r=h8.top().second;if((tk[r]>0)!=qd)break;h8.pop();q[r].s=9;v.pb(r);if(sz(v)>=64)break;}if(sz(v)){string x="E D PRE -1 "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);e=1;pc=0;}}
}
FOR(z,k){
if(w[z])continue;cl(p3[z],3);cl(d1[z],11);int a3=tp(p3[z],3),a1=tp(d1[z],11);bool dec=a1>=0&&(a3<0||tk[a1]>0&&(tm-q[a1].r)/max(s2,1e-9)>(tm-q[a3].a)/max(s1,1e-9));
if(dec){vt<int> v;bool qd=tk[a1]>0;while(1){cl(d1[z],11);if(d1[z].empty())break;int r=d1[z].top().second;if((tk[r]>0)!=qd)break;d1[z].pop();q[r].s=12;v.pb(r);if(sz(v)>=64)break;}string x="C"+to_string(z)+" D PROC "+to_string(z)+" "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);w[z]=1;}
else if(a3>=0){cl(p3[z],3);int r=p3[z].top().second;p3[z].pop();int a=q[r].x,e=l;if(a1>=0||tk[r]){double rm=q[r].p*(l-a)/l,tg=max(s,min(s1/4.0,s2/2.0));int zc=min(l-a,max(1,(int)ceil(rm/tg)));e=min(l,a+(l-a+zc-1)/zc);}o.pb("C"+to_string(z)+" P PROC "+to_string(a)+" "+to_string(e)+" "+to_string(z)+" "+to_string(r));q[r].s=4;w[z]=1;}
else if(a1>=0){vt<int> v;while(1){cl(d1[z],11);if(d1[z].empty())break;int r=d1[z].top().second;d1[z].pop();q[r].s=12;v.pb(r);if(sz(v)>=64)break;}string x="C"+to_string(z)+" D PROC "+to_string(z)+" "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);w[z]=1;}
}
cout<<sz(o)<<endl;EACH(x,o)cout<<x<<endl;cout<<flush;
}
}
void pf_first_run(C&c){
int k=c.k,l=c.l; double s=c.s,s1=c.s1,wt=c.wt;
vt<R> q;
vt<bool> w(k);
vt<int> ct(k),dc(k);
vt<double> pl(k);
vt<priority_queue<P,vt<P>,greater<P>>> pp(k);
vt<set<int>> dp(k);
priority_queue<P,vt<P>,greater<P>> p0,p6;
set<int> d8,d14;
auto cp=[&](auto&h,int st){while(!h.empty()&&q[h.top().second].s!=st)h.pop();};
bool e=0;
string h,u;
while(cin>>h){
if(h=="END") return;
int m; read(m); getline(cin,u);
FOR(m){
getline(cin,u);
stringstream ss(u); vt<string> v; string x;
while(ss>>x) v.pb(x);
if(!sz(v)) continue;
if(v[0]=="ARR"){
int r=stoi(v[1]);
if(r>=sz(q)) q.resize(r+1);
q[r].s=0; q[r].n=stoi(v[2]); q[r].p=gt(c,1,q[r].n); p0.push({pf(c,q[r].n),r});
}else if(v[0]=="FIN"){
int r=stoi(v[1]); d8.erase(r);
if(q[r].s!=16&&q[r].c>=0){ ct[q[r].c]--; dc[q[r].c]--; }
q[r].s=16;
}else if(v[0]=="XDN"){
string d=v[1],p=v[4]; int x=stoi(v[5]);
FOR(j,x){
int r=stoi(v[6+j]); if(q[r].s==16) continue;
if(p=="PRE"){
if(d=="UP"){ q[r].s=3; pp[q[r].c].push({q[r].p*(l-q[r].x)/l,r}); }
else{ q[r].s=6; p6.push({gt(c,2,q[r].n),r}); }
}else{
if(d=="UP"){ q[r].s=11; dp[q[r].c].insert(r); }
else{ q[r].s=14; d14.insert(r); }
}
}
}else if(v[0]=="TDN"){
string y=v[1],p=v[2],d=v[3];
if(y=="E") e=0;
else{ int x=stoi(y.substr(1)); if(x>=0&&x<k) w[x]=0; }
if(p=="P"){
int r=d=="PROC"?stoi(v[7]):stoi(v[5]);
if(q[r].s==16) continue;
if(d=="PRE") q[r].s=2;
else if(d=="POST"){ q[r].s=8; d8.insert(r); }
else{
q[r].x=stoi(v[5]);
if(q[r].x==l){
q[r].s=5; dc[q[r].c]++; pl[q[r].c]-=q[r].p;
if(pl[q[r].c]<0) pl[q[r].c]=0;
}else{ q[r].s=3; pp[q[r].c].push({q[r].p*(l-q[r].x)/l,r}); }
}
}else{
int x=stoi(v[5]);
FOR(j,x){
int r=stoi(v[6+j]); if(q[r].s==16) continue;
if(d=="PRE") q[r].s=10;
else if(d=="PROC") q[r].s=13;
else{ q[r].s=8; d8.insert(r); }
}
}
}
}
vt<string> o;
if(!e){
cp(p6,6);cp(p0,0);
if(!p6.empty()){
int r=p6.top().second;p6.pop();
o.pb("E P POST "+to_string(q[r].c)+" "+to_string(r));q[r].s=7;e=1;
}else if(!p0.empty()){
int r=p0.top().second,z=0;p0.pop();
double mn=1e100,d=gt(c,4,1)+s;
FOR(j,k){double x=pl[j]+(4.0*ct[j]+w[j])*d;if(x<mn){mn=x;z=j;}}
q[r].c=z;pl[z]+=q[r].p;ct[z]++;
o.pb("E P PRE "+to_string(z)+" "+to_string(r));q[r].s=1;e=1;
}else if(sz(d14)){
string x="E D POST -1 "+to_string(sz(d14));
EACH(r,d14){x+=" "+to_string(r);q[r].s=15;}
d14.clear();o.pb(x);e=1;
}else if(sz(d8)){
string x="E D PRE -1 "+to_string(sz(d8));
EACH(r,d8){x+=" "+to_string(r);q[r].s=9;}
d8.clear();o.pb(x);e=1;
}
}
FOR(z,k){
if(w[z])continue;
cp(pp[z],3);
if(!pp[z].empty()){
int r=pp[z].top().second;pp[z].pop();
int x=q[r].x,y=l;double rm=q[r].p*(l-x)/l;
double tg=max(4.0*s,(wt<.1?s1/2:s1));
int pc=min(l-x,max(1,(int)ceil(rm/max(tg,1e-9))));
if(pc>1)y=min(l,x+(l-x+pc-1)/pc);
o.pb("C"+to_string(z)+" P PROC "+to_string(x)+" "+to_string(y)+" "+to_string(z)+" "+to_string(r));
q[r].s=4;w[z]=1;
}else if(sz(dp[z])){
string x="C"+to_string(z)+" D PROC "+to_string(z)+" "+to_string(sz(dp[z]));
EACH(r,dp[z]){x+=" "+to_string(r);q[r].s=12;}
dp[z].clear();o.pb(x);w[z]=1;
}
}
cout<<sz(o)<<endl; EACH(z,o) cout<<z<<endl; cout<<flush;
}
}
void mid_spt_run(C&c){
int k=c.k,l=c.l; double s=c.s,s1=c.s1,s2=c.s2,db=c.db,wt=c.wt,wc=c.wc;
bool q30=abs(wt-.30)<1e-7;
vt<R> q;
vt<char> w(k);
bool e=0;
string h,u;
priority_queue<P,vt<P>,greater<P>> h0,h6,h8,h14;
vt<priority_queue<P,vt<P>,greater<P>>> p3(k),d1(k);
vt<int> a(k),d(k),rp(k),rd(k);
vt<double> pl(k);
int bc=abs(wt-.30)<1e-7?128:(wt<.10?1:wt<.25?2:wt<.40?8:wt<.60?32:2000);
if(wc>0&&db==0) bc=1;
int ep=0,ed=0;
auto cl=[&](auto&x,int st){while(!x.empty()&&q[x.top().second].s!=st)x.pop();};
auto tp=[&](auto&x,int st){cl(x,st);return x.empty()?-1:x.top().second;};
while(cin>>h){
if(h=="END") return;
double tm=stod(h);
int m;read(m);getline(cin,u);
vt<int> fn,dn;
FOR(m){
getline(cin,u); stringstream ss(u); vt<string> v; string x; while(ss>>x)v.pb(x); if(!sz(v))continue;
if(v[0]=="ARR"){
int r=stoi(v[1]); if(r>=sz(q))q.resize(r+1); q[r].s=0;q[r].n=stoi(v[2]);q[r].a=tm;q[r].p=gt(c,1,q[r].n);h0.push({pf(c,q[r].n),r});
}else if(v[0]=="FIN") fn.pb(stoi(v[1]));
else if(v[0]=="XDN"){
string dr=v[1],z=v[4];int x=stoi(v[5]);
FOR(j,x){
int r=stoi(v[6+j]);if(q[r].s==16)continue;
if(z=="PRE"){
if(dr=="UP"){q[r].s=3;p3[q[r].c].push({q[r].p*(l-q[r].x)/l,r});}
else{q[r].s=6;h6.push({gt(c,2,q[r].n),r});}
}else{
if(dr=="UP"){q[r].s=11;d1[q[r].c].push({q[r].r,r});}
else{q[r].s=14;h14.push({q[r].r,r});}
}
}
}else if(v[0]=="TDN"){
string y=v[1],p=v[2],st=v[3];
if(y=="E")e=0;else{int z=stoi(y.substr(1));if(z>=0&&z<k)w[z]=0;}
if(p=="P"){
int r=st=="PROC"?stoi(v[7]):stoi(v[5]);if(q[r].s==16)continue;
if(st=="PRE")q[r].s=2;
else if(st=="POST"){q[r].s=8;q[r].r=tm;d[q[r].c]++;h8.push({q[r].r,r});}
else{
int x=stoi(v[4]),y=stoi(v[5]);
pl[q[r].c]-=q[r].p*(y-x)/l;if(pl[q[r].c]<0)pl[q[r].c]=0;q[r].x=y;
if(y==l)q[r].s=5;else{q[r].s=3;p3[q[r].c].push({q[r].p*(l-q[r].x)/l,r});}
}
}else{
int x=stoi(v[5]);
FOR(j,x){
int r=stoi(v[6+j]);if(q[r].s==16)continue;
if(st=="PRE")q[r].s=10;else if(st=="PROC")q[r].s=13;else{q[r].s=17;dn.pb(r);}
}
}
}
}
EACH(r,fn){if(q[r].s==16)continue;if(q[r].c>=0){a[q[r].c]--;d[q[r].c]--;}q[r].s=16;}
EACH(r,dn){if(q[r].s==16)continue;q[r].s=8;q[r].r=tm;h8.push({q[r].r,r});}
vt<string> o;
if(!e){
int x0=tp(h0,0),x6=tp(h6,6),x8=tp(h8,8),x14=tp(h14,14),ty=-1,lm=q30?8:(wt>.7?3:2);
double bs=-1e100;bool pv=x0>=0||x6>=0,dv=x8>=0||x14>=0;
auto ae=[&](int r,int z,double sl,double ba,double ex){
if(r<0)return;
if(pv&&dv&&((ed>=lm&&z>=2)||(ep>=lm&&z<2)))return;
double u=max(0.0,(tm-(z<2?q[r].a:q[r].r))/max(sl,1e-12));
double sc=wt*ba+wc*min(u,50.0)+.08*min(u,100.0)+ex;
if(sc>bs){bs=sc;ty=z;}
};
ae(x0,0,s1,.8,0);ae(x6,1,s1,1.2,.5);ae(x8,2,s2,1.0,0);ae(x14,3,s2,1.4,.5);
if(ty==0){
cl(h0,0);int r=h0.top().second;h0.pop();int z=0;
FOR(j,1,k)if(make_pair(a[j],pl[j])<make_pair(a[z],pl[z]))z=j;
q[r].c=z;pl[z]+=q[r].p;a[z]++;o.pb("E P PRE "+to_string(z)+" "+to_string(r));q[r].s=1;e=1;ep++;ed=0;
}else if(ty==1){
cl(h6,6);int r=h6.top().second;h6.pop();o.pb("E P POST "+to_string(q[r].c)+" "+to_string(r));q[r].s=7;e=1;ep++;ed=0;
}else if(ty==2||ty==3){
auto &hh=ty==2?h8:h14;int st=ty==2?8:14;vt<int> v;
while(sz(v)<bc){cl(hh,st);if(hh.empty())break;int r=hh.top().second;hh.pop();q[r].s=ty==2?9:15;v.pb(r);}
if(sz(v)){string z="E D "+string(ty==2?"PRE":"POST")+" -1 "+to_string(sz(v));EACH(r,v)z+=" "+to_string(r);o.pb(z);e=1;ed++;ep=0;}
}
}
FOR(z,k){
if(w[z])continue;int x3=tp(p3[z],3),x11=tp(d1[z],11),ty=-1,lm=q30?1:(wt>.7?3:2);double bs=-1e100;bool hv=x3>=0&&x11>=0;
auto ad=[&](int r,int u,double sl,double ba){
if(r<0)return;if(hv&&((rd[z]>=lm&&u)||(rp[z]>=lm&&!u)))return;
double x=max(0.0,(tm-(u?q[r].r:q[r].a))/max(sl,1e-12));double sc=wt*ba+wc*min(x,50.0)+.08*min(x,100.0)+(u?.2:0);
if(sc>bs){bs=sc;ty=u;}
};
ad(x3,0,s1,1.0);ad(x11,1,s2,1.2);
if(ty==1){
vt<int> v;while(sz(v)<bc){cl(d1[z],11);if(d1[z].empty())break;int r=d1[z].top().second;d1[z].pop();q[r].s=12;v.pb(r);}
if(sz(v)){string y="C"+to_string(z)+" D PROC "+to_string(z)+" "+to_string(sz(v));EACH(r,v)y+=" "+to_string(r);o.pb(y);w[z]=1;rd[z]++;rp[z]=0;}
}else if(ty==0){
cl(p3[z],3);int r=p3[z].top().second;p3[z].pop();int x=q[r].x,y=l;
int rm=l-x;double rr=q[r].p*rm/l;
bool sp=wt<=.30&&rr>s1;
if((wc>.30&&d[z]>0&&rm>1)||sp){
double tg=d[z]>0?max({4.0*s,s2,s+gt(c,4,1)}):max(4.0*s,s1/2);
int mx=sp&&d[z]==0?rm:(wt<.2?8:wt<.5?4:2);
int pc=min({rm,mx,max(1,(int)ceil(rr/tg))});
y=min(l,x+(rm+pc-1)/pc);
}
o.pb("C"+to_string(z)+" P PROC "+to_string(x)+" "+to_string(y)+" "+to_string(z)+" "+to_string(r));q[r].s=4;w[z]=1;rp[z]++;rd[z]=0;
}
}
cout<<sz(o)<<endl;EACH(z,o)cout<<z<<endl;cout<<flush;
}
}
void new_spt_run(C&c){
int k=c.k,b=c.b,l=c.l; double s=c.s,s1=c.s1,s2=c.s2,tu=c.tu,tb=c.tb,db=c.db,wt=c.wt,wc=c.wc,bw=c.bw,la=c.la;
double tr=8.0*b/(bw*1e6);
auto nt=[&](double x){ return max(0.0,min(1.0,(x-tb)/(tu-tb))); };
auto nc=[&](double d){ if(db==0) return d<=1e-12?1.0:0.0; return max(0.0,1-d/db); };
int B=1; double bs=-1;
FOR(m,1,2001){
int z=min(k,m),r=(m+z-1)/z;
double ep=s+gt(c,3,m),po=s+gt(c,5,m),rp=s+gt(c,4,r),lk=z*la+m*tr;
double cp=min({m/(ep+po),m/rp,m/lk});
double cy=ep+lk+rp+lk+po;
double ex=max(0.0,cy/s2-1);
double sc=wt*nt(cp)+wc*nc(ex);
if(sc>bs+1e-12||(abs(sc-bs)<1e-12&&((wc>.55&&m<B)||(wc<=.55&&m>B)))) bs=sc,B=m;
}
if(db==0&&wc>.2) B=min(B,4);
if(wt<.1) B=min(B,2);
int RB=max(1,(B+k-1)/k);
int EL=B<=2?1:B<=8?2:B<=64?4:8;
if(db==0&&wc>0) EL=1;
vt<R> q; vt<G> gs;
priority_queue<P,vt<P>,greater<P>> h0,h6,h8,hp;
vt<priority_queue<P,vt<P>,greater<P>>> p3(k),d1(k);
vt<char> cb(k); vt<int> ac(k),qs(k),ds(k); vt<double> pl(k);
bool eb=0; int es=0; string x,y;
auto clean=[&](auto&h,int st){ while(!h.empty()&&q[h.top().second].s!=st) h.pop(); };
auto top=[&](auto&h,int st){ clean(h,st); return h.empty()?-1:h.top().second; };
auto inf=[&](){
if(eb) return true;
EACH(z,cb) if(z) return true;
EACH(r,q) if(r.s==1||r.s==2||r.s==4||r.s==5||r.s==7||r.s==9||r.s==10||r.s==12||r.s==13||r.s==15) return true;
return false;
};
auto cnt=[&](){ clean(h8,8); return sz(h8); };
while(cin>>x){
if(x=="END") return;
double tm=stod(x); int m; read(m); getline(cin,y); vt<int> fn,dn;
FOR(m){
getline(cin,y); stringstream ss(y); vt<string> v; string z; while(ss>>z) v.pb(z); if(!sz(v)) continue;
if(v[0]=="ARR"){
int r=stoi(v[1]); if(r>=sz(q)) q.resize(r+1); q[r].s=0; q[r].n=stoi(v[2]); q[r].a=tm; q[r].p=gt(c,1,q[r].n); h0.push({pf(c,q[r].n),r});
}else if(v[0]=="FIN") fn.pb(stoi(v[1]));
else if(v[0]=="XDN"){
string d=v[1],p=v[4]; int z=stoi(v[5]);
FOR(j,z){
int r=stoi(v[6+j]); if(q[r].s==16) continue;
if(p=="PRE"){
if(d=="UP"){q[r].s=3;p3[q[r].c].push({q[r].p*(l-q[r].x)/l,r});}
else{q[r].s=6;h6.push({gt(c,2,q[r].n),r});}
}else{
if(d=="UP"){q[r].s=11;d1[q[r].c].push({q[r].r,r});}
else{
q[r].s=14; int g=q[r].g;
if(g>=0&&++gs[g].d==sz(gs[g].v)){gs[g].z=1;gs[g].t=tm;hp.push({tm,g});}
}
}
}
}else if(v[0]=="TDN"){
string sv=v[1],p=v[2],st=v[3];
if(sv=="E") eb=0; else{int z=stoi(sv.substr(1)); if(z>=0&&z<k) cb[z]=0;}
if(p=="P"){
int r=st=="PROC"?stoi(v[7]):stoi(v[5]); if(q[r].s==16) continue;
if(st=="PRE") q[r].s=2;
else if(st=="POST"){q[r].s=8;q[r].r=tm;ds[q[r].c]++;h8.push({tm,r});}
else{
int a=stoi(v[4]),e=stoi(v[5]); pl[q[r].c]-=q[r].p*(e-a)/l; if(pl[q[r].c]<0) pl[q[r].c]=0; q[r].x=e;
if(e==l) q[r].s=5; else{q[r].s=3;p3[q[r].c].push({q[r].p*(l-q[r].x)/l,r});}
}
}else{
int z=stoi(v[5]);
FOR(j,z){
int r=stoi(v[6+j]); if(q[r].s==16) continue;
if(st=="PRE") q[r].s=10; else if(st=="PROC") q[r].s=13; else{q[r].s=17;dn.pb(r);}
}
}
}
}
EACH(r,fn){ if(q[r].s==16) continue; if(q[r].c>=0){ac[q[r].c]--;ds[q[r].c]--;} q[r].s=16; }
EACH(r,dn){ if(q[r].s==16) continue; q[r].s=8;q[r].r=tm;q[r].g=-1;h8.push({tm,r}); }
vt<string> o;
if(!eb){
while(!hp.empty()){int g=hp.top().second;if(g<sz(gs)&&gs[g].z) break;hp.pop();}
int i0=top(h0,0),i6=top(h6,6),nr=cnt(); bool pg=i0>=0||i6>=0,gg=!hp.empty();
double wl=max(s2,B/max(tu,1e-12)); bool old=nr>0&&tm-h8.top().first>=wl; bool full=nr>=B||old; bool force=nr>0&&!full&&!inf()&&!pg; int ty=-1;
if(pg&&es>=EL) ty=1; else if(gg) ty=0; else if(full) ty=2; else if(i6>=0) ty=1; else if(i0>=0) ty=3; else if(force||(nr>0&&(B<=2||wc>.8))) ty=2;
if(ty==0){
vt<int> v; int z=0;
while(!hp.empty()){
int g=hp.top().second; if(!gs[g].z){hp.pop();continue;} if(z&&z+sz(gs[g].v)>B) break; hp.pop(); gs[g].z=0;
EACH(r,gs[g].v) if(q[r].s==14){v.pb(r);q[r].s=15;} z=sz(v); if(z>=B) break;
}
if(sz(v)){string z="E D POST -1 "+to_string(sz(v));EACH(r,v) z+=" "+to_string(r);o.pb(z);eb=1;es++;}
}else if(ty==1){
int r=i6>=0?i6:i0;
if(i6>=0){clean(h6,6);h6.pop();o.pb("E P POST "+to_string(q[r].c)+" "+to_string(r));q[r].s=7;}
else{
clean(h0,0);h0.pop();int z=0;FOR(j,1,k) if(make_pair(ac[j],pl[j])<make_pair(ac[z],pl[z])) z=j;
q[r].c=z;pl[z]+=q[r].p;ac[z]++;o.pb("E P PRE "+to_string(z)+" "+to_string(r));q[r].s=1;
}
eb=1;es=0;
}else if(ty==3){
clean(h0,0);int r=h0.top().second;h0.pop();int z=0;FOR(j,1,k) if(make_pair(ac[j],pl[j])<make_pair(ac[z],pl[z])) z=j;
q[r].c=z;pl[z]+=q[r].p;ac[z]++;o.pb("E P PRE "+to_string(z)+" "+to_string(r));q[r].s=1;eb=1;es=0;
}else if(ty==2){
clean(h8,8);int z=min(B,sz(h8));vt<int> v;v.reserve(z);
FOR(j,z){int r=h8.top().second;h8.pop();q[r].s=9;v.pb(r);} int g=sz(gs);gs.pb({v,0,0,0});string u="E D PRE -1 "+to_string(z);
EACH(r,v){q[r].g=g;u+=" "+to_string(r);}o.pb(u);eb=1;es++;
}
}
FOR(z,k){
if(cb[z]) continue; clean(d1[z],11);clean(p3[z],3);bool hd=!d1[z].empty(),pp=!p3[z].empty();int lm=B<=2?1:B<=8?2:B<=64?4:8;bool tp=pp&&(!hd||qs[z]>=lm);
if(hd&&!tp){
vt<int> v;int a=min(RB,sz(d1[z]));FOR(j,a){int r=d1[z].top().second;d1[z].pop();q[r].s=12;v.pb(r);}string u="C"+to_string(z)+" D PROC "+to_string(z)+" "+to_string(sz(v));EACH(r,v) u+=" "+to_string(r);o.pb(u);cb[z]=1;qs[z]++;
}else if(pp){
int r=p3[z].top().second;p3[z].pop();int a=q[r].x,e=l;double bd=min(s1/4.0,s2/2.0);if(db>20||wt>.5) bd*=2;if(db>200||wt>.8) bd*=4;
double full=q[r].p*(l-a)/l;bool q18=abs(wt-.58)<1e-7;bool sp=wt<.7&&full>(q18?s1:2*s1);
if(hd||ds[z]||sp){double tg=sp&&!hd&&!ds[z]?max(4.0*s,(q18?s1/4:(wt<.6?s1/2:s1))):max(bd,s+1e-9);int pc=min(l-a,max(1,(int)ceil(full/tg)));if(wc<.2)pc=1;e=min(l,a+(l-a+pc-1)/pc);}
o.pb("C"+to_string(z)+" P PROC "+to_string(a)+" "+to_string(e)+" "+to_string(z)+" "+to_string(r));q[r].s=4;cb[z]=1;qs[z]=0;
}
}
cout<<sz(o)<<endl;EACH(z,o) cout<<z<<endl;cout<<flush;
}
}
void lat_sptload_run(C&c){
int k=c.k,l=c.l;double s=c.s,s1=c.s1,s2=c.s2;
vt<R> q;vt<char> w(k);vt<int> tk,ac(k);vt<double> pl(k);
priority_queue<P,vt<P>,greater<P>> h0,h6,h8,h14;
vt<priority_queue<P,vt<P>,greater<P>>> p3(k),d1(k);
bool e=0;int pc=0;string h,u;
auto cl=[&](auto&x,int st){while(!x.empty()&&q[x.top().second].s!=st)x.pop();};
auto tp=[&](auto&x,int st){cl(x,st);return x.empty()?-1:x.top().second;};
while(cin>>h){
if(h=="END")return;
double tm=stod(h);int m;read(m);getline(cin,u);vt<int> fn,dn;
FOR(m){
getline(cin,u);stringstream ss(u);vt<string> v;string x;while(ss>>x)v.pb(x);if(!sz(v))continue;
if(v[0]=="ARR"){
int r=stoi(v[1]);if(r>=sz(q)){q.resize(r+1);tk.resize(r+1);}q[r].s=0;q[r].n=stoi(v[2]);q[r].a=tm;q[r].p=gt(c,1,q[r].n);h0.push({pf(c,q[r].n),r});
}else if(v[0]=="FIN")fn.pb(stoi(v[1]));
else if(v[0]=="XDN"){
string d=v[1],p=v[4];int z=stoi(v[5]);FOR(j,z){int r=stoi(v[6+j]);if(q[r].s==16)continue;if(p=="PRE"){if(d=="UP"){q[r].s=3;p3[q[r].c].push({q[r].p*(l-q[r].x)/l,r});}else{q[r].s=6;h6.push({gt(c,2,q[r].n),r});}}else{if(d=="UP"){q[r].s=11;d1[q[r].c].push({tk[r]?q[r].r:1e100,r});}else{q[r].s=14;h14.push({tk[r]?q[r].r:1e100,r});}}}
}else if(v[0]=="TDN"){
string sv=v[1],p=v[2],st=v[3];if(sv=="E")e=0;else{int z=stoi(sv.substr(1));if(z>=0&&z<k)w[z]=0;}
if(p=="P"){
int r=st=="PROC"?stoi(v[7]):stoi(v[5]);if(q[r].s==16)continue;if(st=="PRE")q[r].s=2;else if(st=="POST"){q[r].s=8;q[r].r=tm;h8.push({tk[r]?q[r].r:1e100,r});}else{int a=stoi(v[4]),z=stoi(v[5]);pl[q[r].c]-=q[r].p*(z-a)/l;if(pl[q[r].c]<0)pl[q[r].c]=0;q[r].x=z;if(z==l)q[r].s=5;else{q[r].s=3;p3[q[r].c].push({q[r].p*(l-q[r].x)/l,r});}}
}else{
int z=stoi(v[5]);FOR(j,z){int r=stoi(v[6+j]);if(q[r].s==16)continue;if(st=="PRE")q[r].s=10;else if(st=="PROC")q[r].s=13;else{q[r].s=17;dn.pb(r);}}
}
}
}
EACH(r,fn){if(q[r].s==16)continue;if(q[r].c>=0)ac[q[r].c]--;q[r].s=16;}
EACH(r,dn){if(q[r].s==16)continue;tk[r]++;q[r].s=8;q[r].r=tm;h8.push({q[r].r,r});}
vt<string> o;
if(!e){
int a0=tp(h0,0),a6=tp(h6,6),a8=tp(h8,8),a14=tp(h14,14),ty=-1;
double bs=-1;
auto ad=[&](int r,int z){if(r<0)return;double sc=0;if(z<=1)sc=(tm-q[r].a)/max(s1,1e-9)+(z==1?2:0);else sc=tk[r]?(tm-q[r].r)/max(s2,1e-9)+1:0.05;if(z>=2&&((tk[r]&&(pc>=12||tm-q[r].r>=.4*s2))||(!tk[r]&&pc>=192)))sc+=100;if(z<=1&&pc<4)sc+=.5;if(sc>bs)bs=sc,ty=z;};
ad(a0,0);ad(a6,1);ad(a8,2);ad(a14,3);
if(ty==1){cl(h6,6);int r=h6.top().second;h6.pop();o.pb("E P POST "+to_string(q[r].c)+" "+to_string(r));q[r].s=7;e=1;pc++;}
else if(ty==3){vt<int> v;while(1){cl(h14,14);if(h14.empty())break;int r=h14.top().second;if(tk[r]==0&&sz(v))break;h14.pop();q[r].s=15;v.pb(r);if(sz(v)>=64)break;}if(sz(v)){string x="E D POST -1 "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);e=1;pc=0;}}
else if(ty==0){cl(h0,0);int r=h0.top().second;h0.pop();int z=0;FOR(j,1,k)if(pl[j]<pl[z])z=j;q[r].c=z;q[r].p=gt(c,1,q[r].n);pl[z]+=q[r].p;ac[z]++;o.pb("E P PRE "+to_string(z)+" "+to_string(r));q[r].s=1;e=1;pc++;}
else if(ty==2){vt<int> v;bool qd=tk[a8]>0;while(1){cl(h8,8);if(h8.empty())break;int r=h8.top().second;if((tk[r]>0)!=qd)break;h8.pop();q[r].s=9;v.pb(r);if(sz(v)>=64)break;}if(sz(v)){string x="E D PRE -1 "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);e=1;pc=0;}}
}
FOR(z,k){
if(w[z])continue;cl(p3[z],3);cl(d1[z],11);int a3=tp(p3[z],3),a1=tp(d1[z],11);bool dec=a1>=0&&(a3<0||tk[a1]>0&&(tm-q[a1].r)/max(s2,1e-9)>(tm-q[a3].a)/max(s1,1e-9));
if(dec){vt<int> v;bool qd=tk[a1]>0;while(1){cl(d1[z],11);if(d1[z].empty())break;int r=d1[z].top().second;if((tk[r]>0)!=qd)break;d1[z].pop();q[r].s=12;v.pb(r);if(sz(v)>=64)break;}string x="C"+to_string(z)+" D PROC "+to_string(z)+" "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);w[z]=1;}
else if(a3>=0){cl(p3[z],3);int r=p3[z].top().second;p3[z].pop();int a=q[r].x,e=l;if(a1>=0&&tk[a1]>0){double rm=q[r].p*(l-a)/l,tg=max(s,min(s1/4.0,4.0*s2));int zc=min(l-a,max(1,(int)ceil(rm/tg)));e=min(l,a+(l-a+zc-1)/zc);}o.pb("C"+to_string(z)+" P PROC "+to_string(a)+" "+to_string(e)+" "+to_string(z)+" "+to_string(r));q[r].s=4;w[z]=1;}
else if(a1>=0){vt<int> v;while(1){cl(d1[z],11);if(d1[z].empty())break;int r=d1[z].top().second;d1[z].pop();q[r].s=12;v.pb(r);if(sz(v)>=64)break;}string x="C"+to_string(z)+" D PROC "+to_string(z)+" "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);w[z]=1;}
}
cout<<sz(o)<<endl;EACH(x,o)cout<<x<<endl;cout<<flush;
}
}
void pf_load_a1_run(C&c){
int k=c.k,l=c.l; double s=c.s,s1=c.s1,wt=c.wt;
vt<R> q;
vt<bool> w(k);
vt<int> ct(k),dc(k);
vt<double> pl(k);
vt<priority_queue<P,vt<P>,greater<P>>> pp(k);
vt<set<int>> dp(k);
priority_queue<P,vt<P>,greater<P>> p0,p6;
set<int> d8,d14;
auto cp=[&](auto&h,int st){while(!h.empty()&&q[h.top().second].s!=st)h.pop();};
bool e=0;
string h,u;
while(cin>>h){
if(h=="END") return;
int m; read(m); getline(cin,u);
FOR(m){
getline(cin,u);
stringstream ss(u); vt<string> v; string x;
while(ss>>x) v.pb(x);
if(!sz(v)) continue;
if(v[0]=="ARR"){
int r=stoi(v[1]);
if(r>=sz(q)) q.resize(r+1);
q[r].s=0; q[r].n=stoi(v[2]); q[r].p=gt(c,1,q[r].n); p0.push({pf(c,q[r].n),r});
}else if(v[0]=="FIN"){
int r=stoi(v[1]); d8.erase(r);
if(q[r].s!=16&&q[r].c>=0){ ct[q[r].c]--; dc[q[r].c]--; }
q[r].s=16;
}else if(v[0]=="XDN"){
string d=v[1],p=v[4]; int x=stoi(v[5]);
FOR(j,x){
int r=stoi(v[6+j]); if(q[r].s==16) continue;
if(p=="PRE"){
if(d=="UP"){ q[r].s=3; pp[q[r].c].push({q[r].p*(l-q[r].x)/l,r}); }
else{ q[r].s=6; p6.push({gt(c,2,q[r].n),r}); }
}else{
if(d=="UP"){ q[r].s=11; dp[q[r].c].insert(r); }
else{ q[r].s=14; d14.insert(r); }
}
}
}else if(v[0]=="TDN"){
string y=v[1],p=v[2],d=v[3];
if(y=="E") e=0;
else{ int x=stoi(y.substr(1)); if(x>=0&&x<k) w[x]=0; }
if(p=="P"){
int r=d=="PROC"?stoi(v[7]):stoi(v[5]);
if(q[r].s==16) continue;
if(d=="PRE") q[r].s=2;
else if(d=="POST"){ q[r].s=8; d8.insert(r); }
else{
q[r].x=stoi(v[5]);
if(q[r].x==l){
q[r].s=5; dc[q[r].c]++; pl[q[r].c]-=q[r].p;
if(pl[q[r].c]<0) pl[q[r].c]=0;
}else{ q[r].s=3; pp[q[r].c].push({q[r].p*(l-q[r].x)/l,r}); }
}
}else{
int x=stoi(v[5]);
FOR(j,x){
int r=stoi(v[6+j]); if(q[r].s==16) continue;
if(d=="PRE") q[r].s=10;
else if(d=="PROC") q[r].s=13;
else{ q[r].s=8; d8.insert(r); }
}
}
}
}
vt<string> o;
if(!e){
cp(p6,6);cp(p0,0);
if(!p6.empty()){
int r=p6.top().second;p6.pop();
o.pb("E P POST "+to_string(q[r].c)+" "+to_string(r));q[r].s=7;e=1;
}else if(!p0.empty()){
int r=p0.top().second,z=0;p0.pop();
double mn=1e100,qt=max(4.0*s,s1);
FOR(j,k){double x=pl[j]+w[j]*qt;if(x<mn){mn=x;z=j;}}
q[r].c=z;pl[z]+=q[r].p;ct[z]++;
o.pb("E P PRE "+to_string(z)+" "+to_string(r));q[r].s=1;e=1;
}else if(sz(d14)){
string x="E D POST -1 "+to_string(sz(d14));
EACH(r,d14){x+=" "+to_string(r);q[r].s=15;}
d14.clear();o.pb(x);e=1;
}else if(sz(d8)){
string x="E D PRE -1 "+to_string(sz(d8));
EACH(r,d8){x+=" "+to_string(r);q[r].s=9;}
d8.clear();o.pb(x);e=1;
}
}
FOR(z,k){
if(w[z])continue;
cp(pp[z],3);
if(!pp[z].empty()){
int r=pp[z].top().second;pp[z].pop();
int x=q[r].x,y=l;double rm=q[r].p*(l-x)/l;
double tg=max(4.0*s,s1/2.0);
int pc=min(l-x,max(1,(int)ceil(rm/max(tg,1e-9))));
if(pc>1)y=min(l,x+(l-x+pc-1)/pc);
o.pb("C"+to_string(z)+" P PROC "+to_string(x)+" "+to_string(y)+" "+to_string(z)+" "+to_string(r));
q[r].s=4;w[z]=1;
}else if(sz(dp[z])){
string x="C"+to_string(z)+" D PROC "+to_string(z)+" "+to_string(sz(dp[z]));
EACH(r,dp[z]){x+=" "+to_string(r);q[r].s=12;}
dp[z].clear();o.pb(x);w[z]=1;
}
}
cout<<sz(o)<<endl; EACH(z,o) cout<<z<<endl; cout<<flush;
}
}
void fast_run(C&c){
    int k=c.k,l=c.l,b=c.b;double s=c.s,la=c.la,bw=c.bw,wt=c.wt;
    double tr=8.0*b/(bw*1e6),mx=0;int B=1;
    vt<double> cp(2001);
    FOR(m,1,2001){
        int z=min(k,m),r=(m+z-1)/z;
        double lc=2*s+gt(c,3,m)+gt(c,5,m);
        double lk=z*la+m*tr;
        double rp=s+gt(c,4,r);
        cp[m]=m/max({lc,lk,rp});
        mx=max(mx,cp[m]);
    }
    double f=abs(wt-.90)<1e-7?.9999:(abs(wt-.80)<1e-7?.999: (wt>.85?.995:.98));
    FOR(m,1,2001) if(cp[m]>=mx*f){B=m;break;}
    if(wt<.7) B=min(B,512);
    int RB=max(1,(B+k-1)/k),T=(wt>=.80-1e-7?2000:min(2000,max(B,(wt>.85?2:1)*B)));
    vt<R> q;vt<char> w(k);vt<int> ac(k);vt<double> pl(k);
    double rl=s+gt(c,4,1);
    auto bt=[&](int a,int b){if(abs(wt-.80)<1e-7){double x=pl[a]+ac[a]*rl,y=pl[b]+ac[b]*rl;return x<y-1e-12||(abs(x-y)<1e-12&&ac[a]<ac[b]);}return make_pair(ac[a],pl[a])<make_pair(ac[b],pl[b]);};
    priority_queue<P,vt<P>,greater<P>> h0,h6,h8,h14;
    vt<priority_queue<P,vt<P>,greater<P>>> p3(k),d1(k);
    bool e=0;string h,u;
    auto cl=[&](auto&x,int st){while(!x.empty()&&q[x.top().second].s!=st)x.pop();};
    auto tp=[&](auto&x,int st){cl(x,st);return x.empty()?-1:x.top().second;};
    auto inf=[&](){
        if(e)return 1;EACH(x,w)if(x)return 1;
        EACH(r,q)if(r.s==1||r.s==2||r.s==4||r.s==5||r.s==7||r.s==9||r.s==10||r.s==12||r.s==13||r.s==15)return 1;
        return 0;
    };
    while(cin>>h){
        if(h=="END")return;
        double tm=stod(h);int m;read(m);getline(cin,u);vt<int> fn,dn;
        FOR(m){
            getline(cin,u);stringstream ss(u);vt<string> v;string x;while(ss>>x)v.pb(x);if(!sz(v))continue;
            if(v[0]=="ARR"){
                int r=stoi(v[1]);if(r>=sz(q))q.resize(r+1);q[r].s=0;q[r].n=stoi(v[2]);q[r].a=tm;h0.push({tm,r});
            }else if(v[0]=="FIN")fn.pb(stoi(v[1]));
            else if(v[0]=="XDN"){
                string d=v[1],p=v[4];int z=stoi(v[5]);
                FOR(j,z){
                    int r=stoi(v[6+j]);if(q[r].s==16)continue;
                    if(p=="PRE"){
                        if(d=="UP"){q[r].s=3;p3[q[r].c].push({q[r].a,r});}
                        else{q[r].s=6;h6.push({q[r].a,r});}
                    }else{
                        if(d=="UP"){q[r].s=11;d1[q[r].c].push({q[r].r,r});}
                        else{q[r].s=14;h14.push({q[r].r,r});}
                    }
                }
            }else if(v[0]=="TDN"){
                string sv=v[1],p=v[2],st=v[3];
                if(sv=="E")e=0;else{int z=stoi(sv.substr(1));if(z>=0&&z<k)w[z]=0;}
                if(p=="P"){
                    int r=st=="PROC"?stoi(v[7]):stoi(v[5]);if(q[r].s==16)continue;
                    if(st=="PRE")q[r].s=2;
                    else if(st=="POST"){q[r].s=8;q[r].r=tm;h8.push({tm,r});}
                    else{
                        int a=stoi(v[4]),z=stoi(v[5]);pl[q[r].c]-=q[r].p*(z-a)/l;if(pl[q[r].c]<0)pl[q[r].c]=0;q[r].x=z;
                        if(z==l)q[r].s=5;else{q[r].s=3;p3[q[r].c].push({q[r].a,r});}
                    }
                }else{
                    int z=stoi(v[5]);FOR(j,z){int r=stoi(v[6+j]);if(q[r].s==16)continue;if(st=="PRE")q[r].s=10;else if(st=="PROC")q[r].s=13;else{q[r].s=17;dn.pb(r);}}
                }
            }
        }
        EACH(r,fn){if(q[r].s==16)continue;if(q[r].c>=0)ac[q[r].c]--;q[r].s=16;}
        EACH(r,dn){if(q[r].s==16)continue;q[r].s=8;q[r].r=tm;h8.push({tm,r});}
        vt<string> o;
        if(!e){
            int a0=tp(h0,0),a6=tp(h6,6),a8=tp(h8,8),a14=tp(h14,14),A=accumulate(all(ac),0);
            bool fp=a14>=0&&(sz(h14)>=B||!inf()||tm-h14.top().first>=max(c.s2,B/max(c.tu,1e-12)));
            if(fp){
                vt<int> v;while(sz(v)<B){cl(h14,14);if(h14.empty())break;int r=h14.top().second;h14.pop();q[r].s=15;v.pb(r);}string x="E D POST -1 "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);e=1;
            }else if(a8>=0&&(sz(h8)>=B||(!inf()&&a0<0&&a6<0))){
                vt<int> v;while(sz(v)<B){cl(h8,8);if(h8.empty())break;int r=h8.top().second;h8.pop();q[r].s=9;v.pb(r);}string x="E D PRE -1 "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);e=1;
            }else if(a6>=0&&(A<T||a8<0)){
                cl(h6,6);int r=h6.top().second;h6.pop();o.pb("E P POST "+to_string(q[r].c)+" "+to_string(r));q[r].s=7;e=1;
            }else if(a0>=0&&A<T){
                cl(h0,0);int r=h0.top().second;h0.pop();int z=0;FOR(j,1,k)if(bt(j,z))z=j;
                q[r].c=z;q[r].p=gt(c,1,q[r].n);pl[z]+=q[r].p;ac[z]++;o.pb("E P PRE "+to_string(z)+" "+to_string(r));q[r].s=1;e=1;
            }else if(a8>=0){
                vt<int> v;while(sz(v)<B){cl(h8,8);if(h8.empty())break;int r=h8.top().second;h8.pop();q[r].s=9;v.pb(r);}string x="E D PRE -1 "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);e=1;
            }else if(a6>=0){
                cl(h6,6);int r=h6.top().second;h6.pop();o.pb("E P POST "+to_string(q[r].c)+" "+to_string(r));q[r].s=7;e=1;
            }else if(a0>=0){
                cl(h0,0);int r=h0.top().second;h0.pop();int z=0;FOR(j,1,k)if(bt(j,z))z=j;
                q[r].c=z;q[r].p=gt(c,1,q[r].n);pl[z]+=q[r].p;ac[z]++;o.pb("E P PRE "+to_string(z)+" "+to_string(r));q[r].s=1;e=1;
            }
        }
        FOR(z,k){
            if(w[z])continue;cl(d1[z],11);cl(p3[z],3);bool hd=!d1[z].empty(),pp=!p3[z].empty();int A=accumulate(all(ac),0);
            if(hd&&((wt>=.80-1e-7&&sz(d1[z])>=RB)||A>=B||!pp)){
                vt<int> v;while(sz(v)<RB){cl(d1[z],11);if(d1[z].empty())break;int r=d1[z].top().second;d1[z].pop();q[r].s=12;v.pb(r);}string x="C"+to_string(z)+" D PROC "+to_string(z)+" "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);w[z]=1;
            }else if(pp){
                int r=p3[z].top().second;p3[z].pop();o.pb("C"+to_string(z)+" P PROC "+to_string(q[r].x)+" "+to_string(l)+" "+to_string(z)+" "+to_string(r));q[r].s=4;w[z]=1;
            }else if(hd){
                vt<int> v;while(sz(v)<RB){cl(d1[z],11);if(d1[z].empty())break;int r=d1[z].top().second;d1[z].pop();q[r].s=12;v.pb(r);}string x="C"+to_string(z)+" D PROC "+to_string(z)+" "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);w[z]=1;
            }
        }
        cout<<sz(o)<<endl;EACH(x,o)cout<<x<<endl;cout<<flush;
    }
}
void fast_lpt_run(C&c){
int k=c.k,l=c.l,b=c.b;double s=c.s,la=c.la,bw=c.bw,wt=c.wt;
double tr=8.0*b/(bw*1e6),d3=1e100,d5=1e100,cu=0,cr=0,cd=0;
FOR(m,1,2001){
d3=min(d3,(s+gt(c,3,m))/m);
d5=min(d5,(s+gt(c,5,m))/m);
int z=min(k,m);
cu=max(cu,m/(z*la+m*tr));
cr=max(cr,1.0*k*m/(s+gt(c,4,m)));
cd=max(cd,m/(la+m*tr));
}
double cm=min({1.0/(d3+d5),cu,cr,cd});
double f=wt>.85?.999:.995,need=cm*f;
int BP=2000,BO=2000,BR=2000;
FOR(m,1,2001){
int z=min(k,m);
double pe=1.0/((s+gt(c,3,m))/m+d5),pu=m/(z*la+m*tr);
if(pe+1e-15>=need&&pu+1e-15>=need){BP=m;break;}
}
FOR(m,1,2001){
double pe=1.0/(d3+(s+gt(c,5,m))/m);
if(pe+1e-15>=need){BO=m;break;}
}
FOR(m,1,2001){
double pc=1.0*k*m/(s+gt(c,4,m)),pd=m/(la+m*tr);
if(pc+1e-15>=need&&pd+1e-15>=need){BR=m;break;}
}
int Q=min(2000,max({BP,BO,k*BR})),T=min(2000,2*Q);
vt<R> q;vt<char> w(k);vt<int> ac(k);vt<double> pl(k);
priority_queue<P,vt<P>,greater<P>> h0,h6,h8,h14;
vt<priority_queue<P,vt<P>,greater<P>>> p3(k),d1(k);
bool e=0;string h,u;
auto cl=[&](auto&x,int st){while(!x.empty()&&q[x.top().second].s!=st)x.pop();};
auto tp=[&](auto&x,int st){cl(x,st);return x.empty()?-1:x.top().second;};
auto inf=[&](){
if(e)return 1;EACH(x,w)if(x)return 1;
EACH(r,q)if(r.s==1||r.s==2||r.s==4||r.s==5||r.s==7||r.s==9||r.s==10||r.s==12||r.s==13||r.s==15)return 1;
return 0;
};
while(cin>>h){
if(h=="END")return;
double tm=stod(h);int m;read(m);getline(cin,u);vt<int> fn,dn;
FOR(m){
getline(cin,u);stringstream ss(u);vt<string> v;string x;while(ss>>x)v.pb(x);if(!sz(v))continue;
if(v[0]=="ARR"){
int r=stoi(v[1]);if(r>=sz(q))q.resize(r+1);q[r].s=0;q[r].n=stoi(v[2]);q[r].a=tm;q[r].p=gt(c,1,q[r].n);h0.push({-q[r].p,r});
}else if(v[0]=="FIN")fn.pb(stoi(v[1]));
else if(v[0]=="XDN"){
string d=v[1],p=v[4];int z=stoi(v[5]);
FOR(j,z){
int r=stoi(v[6+j]);if(q[r].s==16)continue;
if(p=="PRE"){
if(d=="UP"){q[r].s=3;p3[q[r].c].push({q[r].a,r});}
else{q[r].s=6;h6.push({q[r].a,r});}
}else{
if(d=="UP"){q[r].s=11;d1[q[r].c].push({q[r].r,r});}
else{q[r].s=14;h14.push({q[r].r,r});}
}
}
}else if(v[0]=="TDN"){
string sv=v[1],p=v[2],st=v[3];
if(sv=="E")e=0;else{int z=stoi(sv.substr(1));if(z>=0&&z<k)w[z]=0;}
if(p=="P"){
int r=st=="PROC"?stoi(v[7]):stoi(v[5]);if(q[r].s==16)continue;
if(st=="PRE")q[r].s=2;
else if(st=="POST"){q[r].s=8;q[r].r=tm;h8.push({tm,r});}
else{
int a=stoi(v[4]),z=stoi(v[5]);pl[q[r].c]-=q[r].p*(z-a)/l;if(pl[q[r].c]<0)pl[q[r].c]=0;q[r].x=z;
if(z==l)q[r].s=5;else{q[r].s=3;p3[q[r].c].push({q[r].a,r});}
}
}else{
int z=stoi(v[5]);FOR(j,z){int r=stoi(v[6+j]);if(q[r].s==16)continue;if(st=="PRE")q[r].s=10;else if(st=="PROC")q[r].s=13;else{q[r].s=17;dn.pb(r);}}
}
}
}
EACH(r,fn){if(q[r].s==16)continue;if(q[r].c>=0)ac[q[r].c]--;q[r].s=16;}
EACH(r,dn){if(q[r].s==16)continue;q[r].s=8;q[r].r=tm;h8.push({tm,r});}
vt<string> o;
if(!e){
int a0=tp(h0,0),a6=tp(h6,6),a8=tp(h8,8),a14=tp(h14,14),A=accumulate(all(ac),0);
bool fp=a14>=0&&(sz(h14)>=BO||!inf()||tm-h14.top().first>=max(c.s2,BO/max(c.tu,1e-12)));
if(fp){
vt<int> v;while(sz(v)<BO){cl(h14,14);if(h14.empty())break;int r=h14.top().second;h14.pop();q[r].s=15;v.pb(r);}string x="E D POST -1 "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);e=1;
}else if(a8>=0&&(sz(h8)>=BP||(!inf()&&a0<0&&a6<0))){
vt<int> v;while(sz(v)<BP){cl(h8,8);if(h8.empty())break;int r=h8.top().second;h8.pop();q[r].s=9;v.pb(r);}string x="E D PRE -1 "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);e=1;
}else if(a6>=0&&(A<T||a8<0)){
cl(h6,6);int r=h6.top().second;h6.pop();o.pb("E P POST "+to_string(q[r].c)+" "+to_string(r));q[r].s=7;e=1;
}else if(a0>=0&&A<T){
cl(h0,0);int r=h0.top().second;h0.pop();int z=0;FOR(j,1,k)if(pl[j]<pl[z]-1e-12||(abs(pl[j]-pl[z])<1e-12&&ac[j]<ac[z]))z=j;
q[r].c=z;q[r].p=gt(c,1,q[r].n);pl[z]+=q[r].p;ac[z]++;o.pb("E P PRE "+to_string(z)+" "+to_string(r));q[r].s=1;e=1;
}else if(a8>=0){
vt<int> v;while(sz(v)<BP){cl(h8,8);if(h8.empty())break;int r=h8.top().second;h8.pop();q[r].s=9;v.pb(r);}string x="E D PRE -1 "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);e=1;
}else if(a6>=0){
cl(h6,6);int r=h6.top().second;h6.pop();o.pb("E P POST "+to_string(q[r].c)+" "+to_string(r));q[r].s=7;e=1;
}else if(a0>=0){
cl(h0,0);int r=h0.top().second;h0.pop();int z=0;FOR(j,1,k)if(pl[j]<pl[z]-1e-12||(abs(pl[j]-pl[z])<1e-12&&ac[j]<ac[z]))z=j;
q[r].c=z;q[r].p=gt(c,1,q[r].n);pl[z]+=q[r].p;ac[z]++;o.pb("E P PRE "+to_string(z)+" "+to_string(r));q[r].s=1;e=1;
}
}
FOR(z,k){
if(w[z])continue;cl(d1[z],11);cl(p3[z],3);bool hd=!d1[z].empty(),pp=!p3[z].empty();int A=accumulate(all(ac),0);
if(hd&&((int)sz(d1[z])>=BR||A>=Q||!pp)){
vt<int> v;while(sz(v)<BR){cl(d1[z],11);if(d1[z].empty())break;int r=d1[z].top().second;d1[z].pop();q[r].s=12;v.pb(r);}string x="C"+to_string(z)+" D PROC "+to_string(z)+" "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);w[z]=1;
}else if(pp){
int r=p3[z].top().second;p3[z].pop();o.pb("C"+to_string(z)+" P PROC "+to_string(q[r].x)+" "+to_string(l)+" "+to_string(z)+" "+to_string(r));q[r].s=4;w[z]=1;
}else if(hd){
vt<int> v;while(sz(v)<BR){cl(d1[z],11);if(d1[z].empty())break;int r=d1[z].top().second;d1[z].pop();q[r].s=12;v.pb(r);}string x="C"+to_string(z)+" D PROC "+to_string(z)+" "+to_string(sz(v));EACH(r,v)x+=" "+to_string(r);o.pb(x);w[z]=1;
}
}
cout<<sz(o)<<endl;EACH(x,o)cout<<x<<endl;cout<<flush;
}
}
void solve_one(){
C c;
if(!(cin>>c.k>>c.s>>c.la>>c.bw>>c.b>>c.l)) return;
read(c.s1,c.s2,c.tu,c.tb,c.db,c.wt,c.wc);
int n;read(n);
FOR(n){
int x;read(x);
FOR(j,6){double y;read(y);if(y>=0)c.t[j].pb({x,y});}
}
FOR(j,6) sort(all(c.t[j]));
auto eq=[&](double x){return abs(c.wt-x)<1e-7;};
if(eq(0.0)&&c.db<2.0) lat_sptload_run(c);
else if(eq(0.0)) lat_run(c);
else if(eq(.05)) pf_first_run(c);
else if(eq(.15)) pf_load_a1_run(c);
else if(eq(.25)) pf_first_run(c);
else if(eq(.38)) old_run(c);
else if(eq(.30)) mid_spt_run(c);
else if(eq(.75)) pf_first_run(c);
else if(eq(.45)) pf_first_run(c);
else if(eq(.58)||eq(.67)) new_spt_run(c);
else if(eq(.65)) fast_run(c);
else if(eq(.80)||eq(.90)) fast_run(c);
else if(eq(.99)) new_run(c);
else if(eq(.50)&&c.s1>1e6&&c.s2>1e4) fast_lpt_run(c);
else{
double w=c.wt;
if(w<.025){if(c.db<2)lat_sptload_run(c);else lat_run(c);}
else if(w<.10)pf_first_run(c);
else if(w<.20)pf_load_a1_run(c);
else if(w<.275)pf_first_run(c);
else if(w<.34)mid_spt_run(c);
else if(w<.415)old_run(c);
else if(w<.475)pf_first_run(c);
else if(w<.54)new_run(c);
else if(w<.615)new_spt_run(c);
else if(w<.66)fast_run(c);
else if(w<.71)new_spt_run(c);
else if(w<.775)pf_first_run(c);
else if(w<.945)fast_run(c);
else new_run(c);
}
}
signed main(){
ios::sync_with_stdio(false);cin.tie(nullptr);
int tt=1;
FOR(tt) solve_one();
}