#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<ll,ll>

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<pp>> graph(n+1);
    while(m--){
        ll a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }    
    vector<vector<ll>> dist(n+1,vector<ll>(k,1e18));
    dist[1][0] = 0;
    priority_queue<pp,vector<pp> , greater<pp>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        ll cnode = curr.second;
        ll cdist = curr.first;
        if(cdist>dist[cnode][k-1]) continue;
        for(auto adj:graph[cnode]){
            ll nnode = adj.first;
            ll ndist = adj.second;
            ll len = cdist + ndist;
            if(len<dist[nnode][k-1]){
                dist[nnode][k-1] = len;
                sort(dist[nnode].begin(),dist[nnode].end());
                pq.push({len,nnode});
            }
        }
    }
    for(int i=0;i<k;i++){
        cout<<dist[n][i]<<" ";
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