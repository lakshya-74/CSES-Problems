#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
void topo(int i , vector<vector<int>>& graph, stack<int>& st , vector<int>& vis){
    vis[i] = 1;
    for(auto x:graph[i]){
        if(!vis[x]) topo(x,graph,st,vis);
    }
    st.push(i);
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
    stack<int> st;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            topo(i,graph,st,vis);
        }
    }
    vector<int> dist(n+1,INT_MIN);
    vector<int> parent(n+1,-1);
    dist[1] = 0;
    while(!st.empty()){
        int curr= st.top();
        st.pop();
        if(dist[curr]==INT_MIN) continue;
        for(auto x:graph[curr]){
            if(dist[x]<dist[curr] +1){
                dist[x] = dist[curr] + 1;
                parent[x] = curr;
            }
        }
    }
    if(dist[n]==INT_MIN) cout<<"IMPOSSIBLE";
    else{
        vector<int> ans;
        ans.push_back(n);
        int curr = parent[n];
        while(curr!=1){
            ans.push_back(curr);
            curr = parent[curr];
        }
        ans.push_back(1);
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }

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