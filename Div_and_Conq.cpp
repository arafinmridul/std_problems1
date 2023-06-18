#include<bits/stdc++.h>
using namespace std;

//1741D CF
//Almost same concept for Merge Sort

const int N = 3e5+7;
int a[N];
int n;

int solve(int l,int r){
    if(r-l == 1){
        return 0;
    }
    int mid = (l+r) >> 1;
    int mxl = *max_element(a+l,a+mid);
    int mxr = *max_element(a+mid,a+r);
    int ans = 0;
    if(mxl > mxr){
        ans++;
        for(int i=0; i<mid-l; ++i){
            swap(a[l+i],a[mid+i]);
        }
    }
    return ans + solve(l,mid) + solve(mid,r);
}

int solve(){
    int changes = solve(0,n);    
    if(is_sorted(a,a+n)){
        return changes;
    }
    return -1;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){   
        cin >> n;
        for(int i=0; i<n; ++i)
            cin >> a[i];
        cout << solve() << '\n';
    }
}