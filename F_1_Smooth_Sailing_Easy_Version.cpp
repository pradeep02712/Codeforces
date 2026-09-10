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
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> s(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    int dx[9] = {0,1,0,-1,0,1,1,-1,-1};
    int dy[9] = {0,0,1,0,-1,-1,1,-1,1};
    vvint d(n + 1, vint(m + 1, -1));
    vvint v(n + 1, vint(m + 1, 0));
    vector<pint> a, c;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'v')
                a.pb({i, j});
            else if (s[i][j] == '#') {
                c.pb({i, j});
                v[i][j] = 1;
            }
        }
    }
    queue<pint> qu;
    for (auto [x, y] : a){
        d[x][y] = 0;
        qu.push({x, y});
    }
    while (!qu.empty()){
        auto [x, y] = qu.front();
        qu.pop();
        for (int k = 1; k <= 4; k++) {
            int a = x + dx[k];
            int b = y + dy[k];
            if (a >= 1 && a <= n &&
                b >= 1 && b <= m &&
                d[a][b] == -1) {
                d[a][b] = d[x][y] + 1;
                qu.push({a, b});
            }
        }
    }
    auto bfs = [&](vector<pint> a, int o){
        vvint z(n + 1, vint(m + 1, -1));
        queue<pint> q;
        for (auto [x, y] : a){
            if (!v[x][y]) {
                z[x][y] = 0;
                q.push({x, y});
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 1; k <= (o ? 4 : 8); k++){
                int a = x + dx[k];
                int b = y + dy[k];
                if (a >= 1 && a <= n &&
                    b >= 1 && b <= m &&
                    !v[a][b] &&
                    z[a][b] == -1) {
                    z[a][b] = z[x][y] + 1;
                    q.push({a, b});
                }
            }
        }
        return z;
    };

    auto sol = [&](int x, int y, int k){
        reprng(i, 1, n + 1)
            reprng(j, 1, m + 1)
                v[i][j] = 0;

        for (auto [i, j] : c)
            v[i][j] = 1;

        reprng(i, 1, n + 1)
            reprng(j, 1, m + 1)
                if (d[i][j] < k)
                    v[i][j] = 1;

        vvint z = bfs({{x, y}}, 1);
        reprng(i, 1, n + 1)
            reprng(j, 1, m + 1)
                v[i][j] = (z[i][j] != -1);
        z = bfs(c,0);
        reprng(i, 1, n + 1) {
            reprng(j, 1, m + 1) {
                if ((i == 1 || i == n || j == 1 || j == m) &&
                    z[i][j] != -1)
                    return false;
            }
        }
        return true;
    };
    while (q--){
        int x,y;
        cin >>x>>y;
        int l=0, r = n+m;
        while (l <= r){
            int k = (l+r)/2;
            if (sol(x, y,k))
                l = k+1;
            else
                r=k-1;
        }
        cout << l-1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test1=1;
    //cin >> test1;

    while (test1--) {
        solve();
    }

    return 0;
}