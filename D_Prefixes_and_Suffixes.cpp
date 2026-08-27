#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve(){
    int d;
    cin >> d;

    double num = 3.141592653589793;
    double ans = num * ((1.0 * d * d) / 4.0);

    cout << fixed << setprecision(15) << ans << endl;

}