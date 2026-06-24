#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
vector<int> dx = {2,1,-1,-2,-2,-1,1,2};
vector<int> dy = {1,2,2,1,-1,-2,-2,-1};
int cmoves(int i, int j , vector<vector<int>>& board){
    int count = 0;
    for(int k=0;k<8;k++){
        int ni = i + dx[k];
        int nj = j + dy[k];
        if(ni>=0 && ni<8 && nj>=0 && nj<8 && board[ni][nj]==0) count++;
    }
    return count;
}
bool dfs(int i,int j, int steps ,vector<vector<int>>& board){
    board[i][j] = steps;
    if(steps==64) return true;
    vector<pair<int,pair<int,int>>> v;
    for(int k=0;k<8;k++){
        int ni = i + dx[k];
        int nj = j + dy[k];
        if(ni>=0 && ni<8 && nj>=0 && nj<8 && board[ni][nj]==0){
            int deg = cmoves(ni,nj,board);
            v.push_back({deg,{ni,nj}});
        }
    }
    sort(v.begin(),v.end());
    for(auto x:v){
        int nx = x.second.first;
        int ny = x.second.second;
        if(dfs(nx,ny,steps+1,board)) return true;
    }
    board[i][j] = 0;
    return false;
}
void solve(){
    int x,y;
    cin>>x>>y;
    x--,y--;
    vector<vector<int>> board(8,vector<int>(8,0));
    dfs(y,x,1,board);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
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