#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
int mod = 1e9 +7;
vector<vector<ll>> dp(1e6+1,vector<ll>(2));
void pre(){
    dp[1][0]   = 1;
    dp[1][1]   = 1;
    for(int i=2;i<=1e6;i++){
        dp[i][0] = (4*dp[i-1][0] + dp[i-1][1])%mod;
        dp[i][1] = (dp[i-1][0] + 2*dp[i-1][1])%mod;
    }
}
void solve(){
    int n;
    cin>>n;
    
    cout<<(dp[n][0]+dp[n][1])%mod<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre();
   int t;
 cin>>t;
while(t--){
solve();
}

    return 0;
}