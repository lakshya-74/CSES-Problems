#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
vector<int> parent;
vector<int> sz;
int find(int x){
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void Union(int x , int y,int& mx){
    x = find(x);
    y = find(y);
    if(x!=y){
        if(sz[x]<sz[y]){
            swap(x,y);
        }
        parent[y] = x;
        sz[x]+=sz[y];
    }
    if(sz[x]>mx){
        mx = sz[x];
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    parent.resize(n+1);
    sz.resize(n+1,1);
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    int mx = 1;
    int comp = n;
    while(m--){
        int u,v;
        cin>>u>>v;
        if(find(u)!=find(v)){
            Union(u,v,mx);
            comp--;
        }
        cout<<comp<<" "<<mx<<"\n";
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