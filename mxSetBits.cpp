#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1615B
//calculating the setbits in each bit position as prefix sum fashion
//keeping the maximum on bits and deleting remaining off bits

const int N = 2e5+12;
int a[N][20];
void go(){
    for(int i=1; i<N; ++i){
        for(int j=0; j<20; ++j){
            a[i][j] = a[i-1][j];
            if(i & (1<<j)) a[i][j]++;
        }
    }
}
void solve(){
    int l,r; cin>>l>>r;
    int mx = 0;
    for(int i=0; i<20; ++i){
        mx = max(mx,a[r][i]-a[l-1][i]);
    }
    cout << r-l+1-mx << nl;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    go();
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}