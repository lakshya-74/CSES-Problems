#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
int mod = 1e9 + 7;
int rec(int n,vector<int>& dp){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int total = 0;
    for(int i=1;i<=6;i++){
        total = (total + rec(n-i,dp))%mod;
    }
    return dp[n] = total;
}
void solve(){
    ll n;
    cin>>n;
    // vector<int> dp(n+1,-1);
    // cout<<rec(n,dp);

    // tabulation --->
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(j<=i) dp[i] = (dp[i] + dp[i-j])%mod;
        }
    }
    cout<<dp[n];
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