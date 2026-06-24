#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    int count = 0;      
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.' && !visited[i][j]){
                count++;
                queue<pp> q;
                q.push({i,j});
                visited[i][j] = true;
                while(!q.empty()){
                    auto curr = q.front();
                    int x = curr.first;
                    int y = curr.second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int newX = x + dx[k];
                        int newY = y + dy[k];
                        if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]=='.' && !visited[newX][newY]){
                            visited[newX][newY] = true;
                            q.push({newX,newY});
                        }
                    }
                }
            }
        }
    }
    cout<<count<<"\n";
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