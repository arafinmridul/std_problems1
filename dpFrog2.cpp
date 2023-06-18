#include<iostream>
using namespace std;
#include<cstring>
#include<climits>
#include<algorithm>
#include<cmath>

//AtCoder DP tasks Frog 2

const int N = 1e5+9;
int a[N];

int dp[N];
int n,k;

int frog(int x){
    //0 based indexing
    if(!x) return 0;
    if(dp[x] != -1) return dp[x];

    int cost = INT_MAX;
    for(int i=1; i<=k; ++i){
        if(x-i>=0)
            cost = min(cost, frog(x-i)+abs(a[x-i]-a[x]));
    }
    
    return dp[x] = cost;
}

int main(){
    memset(dp, -1, sizeof(dp));

    cin >> n >> k;
    for(int i=0; i<n; ++i)
        cin >> a[i];

    //0 based indexing
    cout << frog(n-1) << '\n';
}