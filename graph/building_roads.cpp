#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
vector<int> parent;
int find(int x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}
void Union(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        parent[b] = a;
    }
}
void solve(){
    int n ,m;
    cin>>n>>m;
    parent.assign(n,0);
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        Union(a,b);
    }
    vector<int> v;
    for(int i=0;i<n;i++){
        if(parent[i]==i){
            v.push_back(i);
        }
    }
    cout<<v.size()-1<<"\n";
    for(int i=1;i<v.size();i++){
        cout<<v[0]+1<<" "<<v[i]+1<<"\n";
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