#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

// pairs
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdb;

// vectors
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<double> vdb;

// vectors of vectors
typedef vector<vint> vvint;
typedef vector<vll> vvll;
typedef vector<vdb> vvdb;

#define frlp(v) for (auto ele : v) 
#define frlpr(v) for (auto& ele : v) 

#define rep(i, n) for (int i = 0; i < (int)(n); i++) 
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; i--) 
#define reprng(i, s, e) for (int i = (int)(s); i < (int)(e); i++) 
#define rreprng(i, e, s) for (int i = (int)(e); i >= (int)(s); i--) 

#define pb push_back 
#define qb pop_back 
#define pf push_front 
#define qf pop_front 

#define maxe max_element 
#define mine min_element 

#define lmnt(x) x[(x).size() - 1] 

#define yn(ans) printf("%s\n", (ans) ? "yes" : "no"); 
#define YN(ans) printf("%s\n", (ans) ? "YES" : "NO"); 

const ll INF = 1e18;

template<typename T>
bool chmax(T &a, const T b) { 
    if (a >= b) return false;
    a = b;
    return true;
}

template<typename T>
bool chmin(T &a, const T b) { 
    if (a <= b) return false;
    a = b;
    return true;
}

template<typename T>
void print(vector<T>& v, bool withSize = false) { 
    if (withSize) cout << v.size() << endl;
    rep(i, v.size()) cout << v[i] << " ";
    cout << endl;
}
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vint a(n+1, 0);

    a[0] = 1;
    set<int> p[3];
    p[1].insert(0);
    int l = 0;
    for (auto c : s){
        if (c == '+'){
            l++;
            if (a[l - 1] == 2)
                a[l] = 2;
            else if (l == 1)
                a[l] = 1;
            else
                a[l] = 0;
            p[a[l]].insert(l);
        }
        else if (c == '-'){
            p[a[l]].erase(l);
            l--;
        }
        else if (c == '1'){
            if (p[2].empty()){
                for (auto x : p[0]){
                    p[1].insert(x);
                    a[x] = 1;
                }
                p[0].clear();
            }
            else{
                cout << "NO" << endl;
                return;
            }
        }
        else{
            if (a[l] == 1){
                cout << "NO" << endl;
                return;
            }
            p[a[l]].erase(l);
            a[l] = 2;
            p[a[l]].insert(l);
        }
    }
    cout << "YES" << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test1=1;
    cin >> test1;

    while (test1--) {
        solve();
    }

    return 0;
}