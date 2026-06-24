#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1,0) , outdegree(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        outdegree[u]++;
        indegree[v]++;
    }
    if((indegree[1]+1 != outdegree[1]) || (indegree[n] != outdegree[n]+1)){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    for(int i=2;i<n;i++){
        if(indegree[i] != outdegree[i]){
            cout<<"IMPOSSIBLE\n";
            return;
        }
    }
    stack<int> st;
    vector<int> ans;
    st.push(1);
    while(!st.empty()){
        int v = st.top();
        if(adj[v].size() == 0){
            ans.push_back(v);
            st.pop();
        }
        else{
            int u = adj[v].back();
            adj[v].pop_back();
            st.push(u);
        }
    }
    reverse(ans.begin(),ans.end());
    if(ans.size() != m+1 || ans[0] != 1 || ans.back() != n){
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