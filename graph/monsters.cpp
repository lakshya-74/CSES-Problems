#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<char>> arr(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>> monst_dist(n,vector<int>(m,1e8));
    queue<pp> q;
    int posx=-1, posy =-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='M'){
                monst_dist[i][j] = 0;
                q.push({i,j});
            }
            else if(arr[i][j]=='A'){
                posx = i;
                posy = j; 
            }
        }
    }
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        int i = curr.first;
        int j = curr.second;
        for(int k=0;k<4;k++){
            int nr = i + dx[k];
            int nc = j + dy[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && arr[nr][nc]!='#' && monst_dist[nr][nc]>monst_dist[i][j] + 1){
                monst_dist[nr][nc] = monst_dist[i][j] + 1;
                q.push({nr,nc});
            }
        }
    }

    vector<vector<int>> path_dist(n,vector<int>(m,1e8));
    path_dist[posx][posy] = 0;
    q.push({posx,posy});
    int end_i = -1, end_j = -1;
    vector<vector<int>> path(n,vector<int>(m,-1));
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        int i = curr.first;
        int j = curr.second;
        if(i==0 || i==n-1 || j==0 || j==m-1){
            end_i = i;
            end_j = j;
            break;
        }
        for(int k=0;k<4;k++){
            int nr = i + dx[k];
            int nc = j + dy[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && arr[nr][nc]!='#' && path_dist[nr][nc]>path_dist[i][j] + 1){
                if(path_dist[i][j] + 1 < monst_dist[nr][nc]){
                    path_dist[nr][nc] = path_dist[i][j] + 1;
                    q.push({nr,nc});
                    path[nr][nc] = k;
                }
            }
        }
    }
    if(end_i==-1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES\n";
    vector<char> ans;
    vector<char> dir = {'R','L','D','U'};
    while(end_i!=posx || end_j!= posy){
        int curr = path[end_i][end_j];
        ans.push_back(dir[curr]);
        end_i -= dx[curr];
        end_j -= dy[curr];
    }
    cout<<ans.size()<<endl;
    for(int i=(int)ans.size()-1;i>=0;i--){
        cout<<ans[i];
    }
    cout<<endl;

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