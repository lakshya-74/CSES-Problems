#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>

void solve(){
    int n;
    cin>>n;
    vector<string> grid(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    vector<vector<int>> visited(n,vector<int>(n,0));
    string ans = "";
    ans += grid[0][0];
    visited[0][0]= 1;
    vector<pp> v;
    v.push_back({0,0});

    // total we have n-1 + n-1 == 2n-2 steps to traverse from 0,0 to n-1,n-1

    for(int steps=1;steps<=2*n-2;steps++){
        vector<pp> temp;
        char best = 'Z';
        for(int i=0;i<v.size();i++){
            int x = v[i].first;
            int y = v[i].second;
            if(x+1<n){
                temp.push_back({x+1,y});
                best = min(best,grid[x+1][y]);
            }
            if(y+1<n){
                best = min(best,grid[x][y+1]);
                temp.push_back({x,y+1});
            }
        }
        v.clear();
        for(int i=0;i<temp.size();i++){
            int x = temp[i].first;
            int y = temp[i].second;
            if(grid[x][y]==best && !visited[x][y]){
                v.push_back({x,y});
                visited[x][y] = 1;
            }    
        }
        for(int i=0;i<v.size();i++){
            int x = v[i].first;
            int y = v[i].second;
            visited[x][y ] = 0;
        }
        ans += best;
    }
    cout<<ans;
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