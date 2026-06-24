#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<ll,ll>
vector<vector<pp>> graph;
void solve(){
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    vector<ll> dist(n+1,1e18);
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    dist[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        ll dis = curr.first;
        int node = curr.second;
        if(dis>dist[node]) continue;
        for(auto adj:graph[node]){
            int nexdist = adj.second;
            int nexnode = adj.first;
            if(dis + nexdist< dist[nexnode]){
                dist[nexnode] = dis + nexdist;
                pq.push({dis+nexdist,nexnode});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   int t=1;
//  cin>>t;
while(t--){
solve();
}

    return 0;
}