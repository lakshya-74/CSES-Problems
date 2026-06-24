#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int a_i= -1, a_j = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                a_i = i;
                a_j = j;
                break;
            }
        }
        if(a_i!=-1) break;
    }
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    vector<vector<pp>> parent(n,vector<pp>(m,{-1,-1}));
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    queue<pp> q;
    q.push({a_i,a_j});  
    visited[a_i][a_j] = true;
    bool found = false;
    pp end = {-1,-1};   
    while(!q.empty()){
        auto curr = q.front();
        int x = curr.first;
        int y = curr.second;
        q.pop();
        if(grid[x][y]=='B'){
            found = true;
            end = {x,y};
            break;
        }
        for(int k=0;k<4;k++){
            int newX = x + dx[k];
            int newY = y + dy[k];
            if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]!='#' && !visited[newX][newY]){
                visited[newX][newY] = true;
                parent[newX][newY] = {x,y};
                q.push({newX,newY});
            }
        }
    }
    if(found){
        cout<<"YES\n";
        vector<pp> path;
        pp curr = end;
        while(curr.first!=-1 && curr.second!=-1){
            path.push_back(curr);
            curr = parent[curr.first][curr.second];
        }
        reverse(path.begin(), path.end());
        cout<<path.size()-1<<"\n";
        for(int i=1;i<path.size();i++){
            pp& p = path[i];
            pp& prev = path[i-1];
            if(p.first>prev.first) cout<<"D";
            else if(p.first<prev.first) cout<<"U";
            else if(p.second>prev.second) cout<<"R";
            else cout<<"L";
        }
        cout<<"\n";
    }
    else{
        cout<<"NO\n";
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