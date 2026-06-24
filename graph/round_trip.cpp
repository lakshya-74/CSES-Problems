#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
int st = -1 , ed = -1;
bool dfs(int curr ,int par, vector<int>& visited , vector<vector<int>>& graph,vector<int>& parent){
    visited[curr] = 1;
        for(auto x:graph[curr]){
            if(x== par) continue;
            if(visited[x]){
                st = curr;
                ed = x;
                return true;
            }
            parent[x] = curr;
            if(dfs(x,curr,visited,graph,parent)) return true;
        }
    return false;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> parent(n,-1);
    bool iscycle = false;
    vector<int> visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfs(i,-1,visited,graph,parent)){
                iscycle = true;
                break;
            }
        }
    }
    if(!iscycle){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    vector<int> ans;
    ans.push_back(ed);
    int curr= st;
    while(curr!=ed){
        ans.push_back(curr);
        curr = parent[curr]; 
    }
    ans.push_back(ed);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]+1<<" ";
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