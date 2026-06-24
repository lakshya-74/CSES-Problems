#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
void dfs(int i,vector<vector<int>> &adj,vector<int> &vis,stack<int> &st){
    vis[i] = 1;
    for(auto &e:adj[i]){
        if(!vis[e]){
            dfs(e,adj,vis,st);
        }
    }
    st.push(i);
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
    vector<int> vis(n+1,0);
    stack<int> st;
    dfs(1,adj,vis,st);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<"NO\n";
            cout<<"1 "<<i<<"\n";
            return;
        }
    }
    vector<vector<int>> rev(n+1);
    for(int i=1;i<=n;i++){
        vis[i] = 0;
        for(auto &e:adj[i]){
            rev[e].push_back(i);
        }
    }
    int count =0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            count++;
            if(count>1){
                cout<<"NO\n";
                cout<<node<<" "<<rev[node][0]<<"\n";
                return;
            }
            dfs(node,rev,vis,st);
        }
    }
    cout<<"YES\n"; 
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