#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'
using lll = __int128;

//CF 1850E cardboard

const int N = 2e5+7;
int a[N];
int n,c;

__int128 check(int w){
    __int128 sum = 0;
    for(int i=0; i<n; ++i){
        sum += (a[i]+w)*(a[i]+w);
    }
    return sum;
}

void solve(){
    cin >> n >> c;
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    int l=1,r=1e9;
    while(l <= r){
        int mid = l+(r-l)/2;
        if(check(mid) == (lll)c){
            cout << mid/2 << nl;
            return;
        }
        else if(check(mid) > (lll)c){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}