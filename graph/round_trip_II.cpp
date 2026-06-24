#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
int st  = -1, ed = -1;
void dfs(int  src , vector<vector<int>>& graph , vector<int>& parent, vector<int>& path_visited,vector<int>& visited){
    visited[src] = 1;
    path_visited[src] = 1;
    for(auto x:graph[src]){
        if(!visited[x]){
            parent[x] = src;
            dfs(x,graph,parent,path_visited,visited);
        }
        else{
            if(path_visited[x]){
                st = src;
                ed = x;
            }
        }
    }
    path_visited[src] = 0;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    vector<int> visited(n+1,0), parent(n+1,-1) , path_visited(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
                dfs(i,graph,parent,path_visited,visited);
                if(st!=-1) break;    
        }
    }
    if(st==-1){
        cout<<"IMPOSSIBLE";
        return;
    }
    vector<int> ans;
    ans.push_back(st);
    int curr = st;
    while(curr!=ed){
        ans.push_back(parent[curr]);
        curr = parent[curr];
    }
    ans.push_back(st);
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
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