#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1836B
//Closest multiple of a number to an integer

void solve(){
    int n,k,g; cin>>n>>k>>g;
    int save = min((n-1)*((g-1)/2),k*g);
    int x = (k*g)-save;
    int r = (x%g);
    int c = ceil((double)g/2);
    (r>=c) ? save-=(g-r) : save+=r;
    cout << save << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}