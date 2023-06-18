#include<bits/stdc++.h>
using namespace std;

//217A
/*the number of required coordinates to make the whole graph connected is the number
of distinct connected coordinates reduced by one
*/

struct point{
    int x,y;
};
point a[105];
bool used[105];
int n;
//checking connected coordinates
void checkin(int idx){
    used[idx]=true;
    for(int i=0; i<n; ++i){
        if((a[idx].x==a[i].x || a[idx].y==a[i].y) && !used[i]){
            checkin(i);
        }
    }
}
int main(){
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>a[i].x>>a[i].y;
    }
    memset(used,false,sizeof(used));
    int connect = -1;
    for(int i=0; i<n; ++i){
        if(!used[i]){
            connect++;
            checkin(i);
        }
    }
    cout<<connect<<'\n';
}