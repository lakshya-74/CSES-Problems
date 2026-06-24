#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
int mod = 1e9 + 7;
ll dfs(int i, vector<vector<int>>& graph, vector<ll>& dp){
    if(i==dp.size()-1) return 1;
    if(dp[i]!=-1) return dp[i];
    int ans =0;
    for(auto x:graph[i]){
        ans = (ans + dfs(x,graph,dp))%mod;
    }
    return dp[i] = ans%mod;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    vector<ll> dp(n+1,-1);
    cout<<dfs(1,graph,dp);
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