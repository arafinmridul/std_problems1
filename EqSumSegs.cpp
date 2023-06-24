#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1741C
//minimize the maximum length of segments of equal sum

const int N = 2010;
int n,a[N];

int segs(int i,int sum){
    if(i == n)
        return 0;
    for(int j=i+1,cur=0; j<=n; ++j){
        cur += a[j-1];
        if(cur > sum)
            return n;
        if(cur == sum)
            return max(j-i,segs(j,sum));
    }
    return n;
}

void solve(){
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    int ans = n;
    for(int len=1,sum=0; len<=n; ++len){
        sum += a[len-1];
        ans = min(ans,segs(0,sum));
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