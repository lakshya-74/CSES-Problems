#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<ll,ll>
void djikstra(int src , vector<vector<pp>>& graph , vector<ll>& dist){
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        ll dis = curr.first;
        int node = curr.second;
        if(dis>dist[node]) continue;
        for(auto adj:graph[node]){
            ll nexdist = adj.second;
            int nexnode = adj.first;
            if(dis + nexdist< dist[nexnode]){
                dist[nexnode] = dis + nexdist;
                pq.push({dis+nexdist,nexnode});
            }
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pp>> graph(n+1) , rever(n+1);
    vector<tuple<ll,ll,ll>> edges;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        rever[b].push_back({a,c});
        edges.push_back({a,b,c});
    }
    vector<ll> dist1(n+1,1e18),dist2(n+1,1e18);
    djikstra(1,graph,dist1);
    djikstra(n,rever,dist2);
    
    ll ans = 1e18;
    for(auto [u,v,w] : edges){
        ans = min(ans,dist1[u]+w/2+dist2[v]);
    }
    cout<<ans;

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