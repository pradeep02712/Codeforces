#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F(i, a, b) for(int i = (a); i < (b); i++)

void solve(){
    int n;
    cin >> n;
    map<int,int> f;
    F(i, 0, n){
        int x;
        cin >> x;
        f[x]++;
    }
    int c = 0;
    while (c < n){
        for (auto it = f.rbegin(); it != f.rend(); ++it){
            if (it->second > 0){
                cout << it->first << (c == n - 1 ? "" : " ");
                it->second--;       
                c++;     
            }
        }
    }
    cout << endl;
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