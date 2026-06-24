#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
void dfs(int v,vector<vector<pp>>& adj,vector<int>& idx,vector<int>& ans){
    while(!adj[v].empty()){
        auto x = adj[v].back();
        adj[v].pop_back();
        if(idx[x.second]) continue;
        idx[x.second] = 1;
        dfs(x.first,adj,idx,ans);
    }
    ans.push_back(v);
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pp>> adj(n+1);
    vector<int> deg(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
        deg[u]++;
        deg[v]++;
    }
    for(int i=1;i<=n;i++){
        if(deg[i]%2 != 0){
            cout<<"IMPOSSIBLE\n";
            return;
        }
    }
    vector<int> ans;
    vector<int> idx(m,0);
    dfs(1,adj,idx,ans);
    reverse(ans.begin(),ans.end());
    if(ans.size() != m+1){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    for(auto x:ans){
        cout<<x<<" ";
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