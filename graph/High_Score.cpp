#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<ll,ll>

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> graph;
    vector<vector<int>> rev(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph.push_back({a,b,c});
        rev[b].push_back(a);
    }
    vector<ll> dist(n+1,-1e18);
    dist[1] = 0;
    for(int i=0;i<n-1;i++){
        for(auto x:graph){
            int u = x[0];
            int v = x[1];
            int w = x[2];
            if(dist[u]!=-1e18 && dist[u] + w > dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    vector<int> canreach(n+1,0);
    canreach[n] = 1;
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto x:rev[curr]){
            if(!canreach[x]){
                canreach[x] = 1;
                q.push(x);
            }
        }
    }
    for(auto x:graph){
        int u = x[0];
        int v = x[1];
        int w = x[2];
        if(dist[u]!=-1e18 && dist[u] + w > dist[v] && canreach[v]){
            cout<<-1;
            return;
        }
    }
    cout<<dist[n];
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