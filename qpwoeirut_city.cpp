#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1706C qpwoeirut_city

const int N = 2e5+7;
int n;
int a[N];
int to_build(int idx){
    return max(0LL, max(a[idx-1],a[idx+1]) - a[idx] + 1LL);
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }
    int count = 0;
    for(int i=2; i<n; i+=2){
        count += to_build(i);
    }
    int ans = count;
    if(n&1){
        cout << ans << nl;
        return;
    }
    for(int i=n-1; i>1; i-=2){
        count -= to_build(i-1);
        count += to_build(i);
        ans = min(ans,count);
    }
    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}