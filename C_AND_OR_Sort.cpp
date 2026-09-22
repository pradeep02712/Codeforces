#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F(i, a, b) for(int i = (a); i < (b); i++)

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = (s[0] == '0' ? 0 : 1e9); 
    int b = (s[0] == '1' ? 0 : 1e9);
    F(i,1,n){
        int x = a + (s[i] == '1' ? 1 : 0);
        int y = min(a, b) + (s[i] == '0' ? 1 : 0);
        a = x;
        b = y;
    }
    cout << min(a, b) << endl;
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