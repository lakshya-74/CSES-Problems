#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
    }
    int mx = 1<<n;
    vector<vector<int>> dp(mx,vector<int>(n,0));
    dp[1][0] = 1;
    for(int mask =0;mask<mx;mask++){
        for(int u=0;u<n;u++){
            if(!((1<<u)&mask)) continue;
            if(dp[mask][u] == 0) continue;
                for(int v:adj[u]){
                    if((1<<v)&mask) continue;
                    int newmask = mask|(1<<v);
                    dp[newmask][v] = (dp[newmask][v]+dp[mask][u])%1000000007;
                }
        }
    }
    cout<<dp[mx-1][n-1]<<"\n";
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