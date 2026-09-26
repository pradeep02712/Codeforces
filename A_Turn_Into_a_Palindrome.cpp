#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F(i, a, b) for(int i = (a); i < (b); i++)

void solve(){
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    int x = 0;
    F(i, 0, n / 2){
        int j = n-1-i;
        if (s[i] != s[j]){
            x += (s[i] == c || s[j] == c) ? 1 : 2;
        }
    }
    cout << x << endl;
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