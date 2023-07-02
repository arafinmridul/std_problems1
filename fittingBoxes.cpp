#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl '\n'

//CF 1498B
//calculating maximum height for fitting all boxes
//boxes are of different widths
//fitting as many boxes as possible in one level of certain width
//then leveling up

void solve(){
    int n,w; cin>>n>>w;
    multiset<int> st;
    for(int i=0; i<n; ++i){
        int x; cin>>x;
        st.insert(x);
    }
    int ht = 0;
    int temp = -1;
    while(st.empty() == 0){
        auto it = st.upper_bound(temp);
        if(it != st.begin()){
            it--;
            int val = *it;
            temp -= val;
            st.erase(it);
        }
        else{
            ++ht;
            temp = w;
        }
    }
    cout << ht << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}