#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> adj(n+1,vector<ll>(n+1,1e18));
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a][b] = min(c,adj[a][b]);
        adj[b][a] = min(c,adj[b][a]);
    }
    for(int i=1;i<=n;i++){
        adj[i][i] = 0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(adj[i][k]<1e18 && adj[k][j]<1e18){
                    adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<(adj[a][b]==1e18?-1:adj[a][b])<<endl;
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