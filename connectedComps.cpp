#include<bits/stdc++.h>
using namespace std;
#define int long long

//1829E CF
//maximum value of connected components

const int N = 1005;
int a[N][N];
bool used[N][N];
int n,m;

int dfs(int i,int j){
    used[i][j] = true;
    int ans = a[i][j];
    if(i and a[i-1][j] and !used[i-1][j]){
        ans += dfs(i-1,j);
    }
    if(j and a[i][j-1] and !used[i][j-1]){
        ans += dfs(i,j-1);
    }
    if(i!=n-1 and a[i+1][j] and !used[i+1][j]){
        ans += dfs(i+1,j);
    }
    if(j!=m-1 and a[i][j+1] and !used[i][j+1]){
        ans += dfs(i,j+1);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cin >> a[i][j];
                used[i][j] = false;
            }
        }
        int mx = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(!used[i][j] and a[i][j]){
                    mx = max(mx,dfs(i,j));
                }
            }
        }
        cout << mx << '\n';
    }
}