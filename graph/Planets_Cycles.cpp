#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
void dfs(int i ,int steps, int& c_len , int& c_start , vector<int>& arr , vector<int>& dp , vector<int>& visited , vector<int>& dist){
    if(visited[i]) return;
    visited[i] = 1;
    dist[i] = steps;
    int v = arr[i];
    if(!visited[v]){
        dfs(v,steps+1,c_len,c_start,arr,dp,visited,dist);
    }
    else{
        if(dp[v]==0){
            c_len = dist[i] - dist[v] + 1;
            c_start = v;
        }
        else{
            c_len = dp[v];
        }
    }
    if(c_start==-1){
        dp[i] = dp[v] + 1;
    }
    else{
        dp[i] = c_len;
        if(c_start==i) c_start = -1;
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    vector<int> dp(n+1,0) , visited(n+1,0) , dist(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            int c_len = -1;
            int c_start = -1;
            dfs(i,1,c_len,c_start,arr,dp,visited,dist);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   int t=1;
 // cin>>t;
while(t--){
solve();
}

    return 0;
}