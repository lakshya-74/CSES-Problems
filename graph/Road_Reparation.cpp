#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
vector<int> parent;
int find(int x){
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void Union(int x , int y){
    x = find(x);
    y = find(y);
    if(x!=y){
        parent[y] = x;
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    parent.resize(n+1);
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    vector<vector<int>> adj;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj.push_back({u,v,w});
    }
    sort(adj.begin(),adj.end(),[](const vector<int> &a,const vector<int> &b){
        return a[2] < b[2];
    });
    ll ans =0;
    for(auto &e:adj){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        if(find(u)!=find(v)){
            Union(u,v);
            ans+=w;
        }
    }
    int count =0;
    for(int i=1;i<=n;i++){
        if(find(i)==i){
            count++;
        }
        if(count>1){
            cout<<"IMPOSSIBLE\n";
            return;
        }

    }
    cout<<ans<<"\n";
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