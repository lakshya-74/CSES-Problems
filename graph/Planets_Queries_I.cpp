#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++){
        cin>>parent[i];
    }
    ll size = log2(1e9);
    vector<vector<int>> dp(n+1,vector<int>(size+1,-1));
    for(int i=1;i<=n;i++){
        dp[i][0] = parent[i];
    }
    for(int j=1;j<=size;j++){
        for(int i=1;i<=n;i++){
            if(dp[i][j-1]!=-1) dp[i][j] = dp[ dp[i][j-1] ][j-1];
        }
    }
    while(q--){
        int x,k;
        cin>>x>>k;
        for(int j=0;j<=size;j++){
            if((k>>j)&1){
                x = dp[x][j];
                if(x==-1) break;
            }
        }
        cout<<x<<"\n";
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