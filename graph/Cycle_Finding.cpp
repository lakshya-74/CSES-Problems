#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<ll,ll>

void solve(){
    ll n , m ; 
    cin>>n>>m;
    vector<vector<ll>> edges;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }
    vector<ll> dist(n+1,0);
    vector<ll> parent(n+1,-1);
    for(int i=0;i<=n;i++){
        parent[i] = i;
    }
    for(int i=0;i<n-1;i++){
        for(auto x:edges){
            ll u = x[0];
            ll v = x[1];
            ll w = x[2];
            if(dist[u]+w<dist[v]){
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
    ll node = -1;
    for(auto x:edges){
        ll u = x[0];
        ll v = x[1];
        ll w = x[2];
        if(dist[u]+w<dist[v]){
            parent[v] = u;
            node = v;
            break;
        }
    }
    if(node==-1){
        cout<<"NO";
    }
    else{
        cout<<"YES\n";
        for(int i=0;i<n;i++){
            node = parent[node];
        }
        vector<ll> v;
        v.push_back(node);
        ll x = parent[node];
        while(x!=node){
            v.push_back(x);
            x = parent[x];
        }
        v.push_back(node);
        for(int i=v.size()-1;i>=0;i--){
            cout<<v[i]<<" ";
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