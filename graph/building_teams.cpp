#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
vector<vector<int>> edge;
bool bfs(int i,vector<int>& color){
    color[i] = 1;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int curr= q.front();
        q.pop();
        for(auto x:edge[curr]){
            if(color[x]==0){
                color[x] = 3- color[curr];
                q.push(x); 
            }
            else if(color[x]!=3-color[curr]) return false;
        }
    }
    return true;
}
void solve(){
    int n ,m;
    cin>>n>>m;
    edge.resize(n+1);
    while(m--){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> color(n+1,0);
    for(int i=1;i<=n;i++){
        if(color[i]==0){
            if(!bfs(i,color)){
                cout<<"IMPOSSIBLE";
                return;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<color[i]<<" ";
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