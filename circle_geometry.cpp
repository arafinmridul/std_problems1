#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1100C NN and the Optical Illusion

const double pi = acos(-1);

void solve(){
    double n,r; cin>>n>>r;
    double sine  = sin(pi/n);
    double R = (r*sine)/(1-sine);
    cout << fixed << setprecision(12) << R << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}