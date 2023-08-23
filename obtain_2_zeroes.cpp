#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1260B

void solve(){
    int a,b; cin>>a>>b;
    //diff times diff numbers
    //initially both are 0 0
    //over time, x and 2x are added to them
    //0 + 0 + 3x + 3y + 3z + ... = 3(x + y + z + ...)
    //therefore, the addition of the final a and b are divisible by 3
    //and obviously the max diff between the numbers is the smaller number
    if((a+b)%3 == 0 and 2*min(a,b) >= max(a,b))
        cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}