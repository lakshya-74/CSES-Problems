#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
void dfs(int i , vector<vector<ll>>& adj , vector<ll>& vis , stack<ll>& st){
    vis[i] = 1;
    for(auto x:adj[i]){
        if(!vis[x]) dfs(x,adj,vis,st);
    }
    st.push(i);
}
void dfs1(int i , vector<vector<ll>>& adj , vector<ll>& vis , vector<ll>& ans){
    vis[i] = 1;
    ans.push_back(i);
    for(auto x:adj[i]){
        if(!vis[x]) dfs1(x,adj,vis,ans);
    }
}
vector<vector<ll>> scc(vector<vector<ll>>& adj){
    int n = adj.size();
    stack<ll> st;
    vector<ll> vis(n,0); 
    for(int i=1;i<n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }  
    vector<vector<ll>> rev(n);
    for(int i=1;i<n;i++){
        vis[i] =0;
        for(auto x:adj[i]){
            rev[x].push_back(i);
        }
    } 
    vector<vector<ll>> ans;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        if(!vis[curr]){
            vector<ll> temp;
            dfs1(curr,rev,vis,temp);
            ans.push_back(temp);
        }
    }
    return ans;
}
ll dfs2(int i , vector<vector<ll>>& dag , vector<ll>& scc_coins , vector<ll>& dp){
    if(dp[i] != -1) return dp[i];
    ll ans = scc_coins[i];
    for(auto x:dag[i]){
        ans = max(ans,scc_coins[i]+dfs2(x,dag,scc_coins,dp));
    }
    return dp[i] = ans;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll> coins(n+1);
    for(int i=1;i<=n;i++){
        cin>>coins[i];
    }
    vector<vector<ll>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<vector<ll>> comp = scc(adj);
    int sz = comp.size();
    vector<ll> scc_coins(sz,0);
    vector<ll> belongs(n+1,0);
    for(int i=0;i<sz;i++){
        for(auto x:comp[i]){
            scc_coins[i] += coins[x];
            belongs[x] = i;
        }
    }
    vector<vector<ll>> dag(sz);
    for(int i=1;i<=n;i++){
        for(auto x:adj[i]){
            if(belongs[i] != belongs[x]){
                dag[belongs[i]].push_back(belongs[x]);
            }
        }
    }
    vector<ll> dp(sz,-1);
    ll ans =0;
    for(int i=0;i<sz;i++){
        ans = max(ans,dfs2(i,dag,scc_coins,dp));
    }
    cout<<ans<<"\n";
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