#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<ll,ll>
ll mod = 1e9 + 7;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pp>> graph(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    priority_queue<pp,vector<pp> , greater<pp>> q;
    q.push({0,1});
    vector<ll> dist(n+1,1e18);
    dist[1] = 0;
    vector<ll> mn(n+1,1e18),mx(n+1,0);
    vector<ll> ways(n+1,0);
    mn[1] = 0 , mx[1] = 0;
    ways[1] = 1;
    while(!q.empty()){
        auto curr = q.top();
        q.pop();
        ll node = curr.second;
        ll d = curr.first;
        if(d>dist[node]) continue;
        for(auto x:graph[node]){
            ll adj = x.first;
            ll dis = x.second;
            if(dis + d == dist[adj]){
                ways[adj] = (ways[adj] + ways[node])%mod;
                mn[adj] = min(mn[adj],mn[node]+1);
                mx[adj] = max(mx[adj],mx[node]+1);
            }    
            else if(dis + d <dist[adj]){
                ways[adj] = ways[node];
                mn[adj] = mn[node] +1;
                mx[adj] = mx[node] +1;
                dist[adj] = dis + d;
                q.push({dist[adj],adj});
            }
        }
    }
    cout<<dist[n]<<" "<<ways[n]<<" "<<mn[n]<<" "<<mx[n];
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