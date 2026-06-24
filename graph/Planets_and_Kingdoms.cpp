#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
void dfs(int i , vector<vector<int>>& adj , vector<int>& vis , stack<int>& st){
    vis[i] = 1;
    for(auto x:adj[i]){
        if(!vis[x]) dfs(x,adj,vis,st);
    }
    st.push(i);
}
void dfs1(int i , vector<vector<int>>& adj , vector<int>& vis , vector<int>& ans , int& count){
    vis[i] = 1;
    ans[i] = count;
    for(auto x:adj[i]){
        if(!vis[x]) dfs1(x,adj,vis,ans,count);
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    stack<int> st;
    vector<int> vis(n+1,0); 
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }  
    vector<vector<int>> rev(n+1);
    for(int i=1;i<=n;i++){
        vis[i] =0;
        for(auto x:adj[i]){
            rev[x].push_back(i);
        }
    } 
    int count = 0;
    vector<int> ans(n+1,0);
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        if(!vis[curr]){
            count++;
            dfs1(curr,rev,vis,ans,count);
        }
    }
    cout<<count<<"\n";
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
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