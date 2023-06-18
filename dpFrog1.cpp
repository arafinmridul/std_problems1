#include<iostream>
using namespace std;
#include<climits>
#include<algorithm>
#include<cmath>
#include<cstring>

//AtCoder DP tasks Frog 1

const int N = 1e5+7;
int a[N];

int dp[N];

//first brute force recursion
//then implementing memoization
int frog(int i){
    //0 based indexing
    if(!i) return 0;
    if(dp[i] != -1) return dp[i];

    int cost = INT_MAX;
    cost = min(cost, frog(i-1)+abs(a[i-1]-a[i]));
    if(i>1) cost = min(cost, frog(i-2)+abs(a[i-2]-a[i]));

    return dp[i] = cost;
}

int main(){
    memset(dp, -1, sizeof(dp));

    int n; cin>>n;
    for(int i=0; i<n; ++i)
        cin>>a[i];
        
    //0 based indexing
    cout << frog(n-1) << endl;
}