#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    vector<int> indegree(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    vector<int> ans;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) q.push(i);
    }
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(auto x:graph[curr]){
            indegree[x]--;
            if(indegree[x]==0) q.push(x);
        }
    }
    if(ans.size()!=n){
        cout<<"IMPOSSIBLE";
    }
    else{
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
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