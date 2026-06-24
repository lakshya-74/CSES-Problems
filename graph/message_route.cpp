#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    vector<int> parent(n,-1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> q;
    q.push(0);
    parent[0] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int x:graph[curr]){
            if(parent[x]==-1){
                parent[x] = curr;
                q.push(x);
            }
        }
    }
    if(parent[n-1]==-1){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    vector<int> path;
    int curr = n-1;
    while(curr!=0){ 
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(0);
    reverse(path.begin(),path.end());   
    cout<<path.size()<<"\n";
    for(int x:path){
        cout<<x+1<<" ";
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