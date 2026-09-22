#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F(i, a, b) for(int i = (a); i < (b); i++)

void solve(){
    int n;
    cin >> n;
    
    vector<int> v(n);
    F(i, 0, n) {
        int a;
        cin >> a;
        v[i] = a - (i + 1);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int m = 1;
    int c = 1;
    F(i, 1, v.size()){
        if (v[i] == v[i - 1] + 1) {
            c++;
            m = max(m, c);
        } else {
            c = 1;
        }
    }
    cout << m << endl;
}
signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t= 1;
    cin >> t;
    while(t--){
        solve();
    }
}