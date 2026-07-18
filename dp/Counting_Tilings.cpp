#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
int mod = 1e9 + 7;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(m+1,vector<ll>(1<<(n+1),0)));
    dp[n][0][0] = 1;
    for(int i = 1; i <= m; i++){
            for(int j = 0; j < (1<<n); j++)
                dp[0][i][j<<1] = dp[n][i-1][j];

            for(int j = 1; j <= n; j++){
                int x = 1<<(j-1);
                int y = 1<<j;
                for(int mask = 0; mask < (1<<(n+1)); mask++){
                    dp[j-1][i][mask] %= mod;
                    if((mask&x) && (mask&y)) continue;
                    if(mask&x) dp[j][i][mask^x] += dp[j-1][i][mask];
                    else if(mask&y) dp[j][i][mask^y] += dp[j-1][i][mask];
                    else {
                        dp[j][i][mask^x] += dp[j-1][i][mask];
                        dp[j][i][mask^y] += dp[j-1][i][mask];
                    }
                }
            }
    }
    cout<<dp[n][m][0]%mod;
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