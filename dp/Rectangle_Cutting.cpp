#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
ll rec(int a, int b, vector<vector<ll>>& dp) {
    if(a==b) return 0;
    if(dp[a][b]!=1e18) return dp[a][b];
    for(int i=1;i<=a/2;i++){
        dp[a][b] = min(dp[a][b],1+rec(i,b,dp)+rec(a-i,b,dp));
    }
    for(int i=1;i<=b/2;i++){
        dp[a][b] = min(dp[a][b],1+rec(a,i,dp)+rec(a,b-i,dp));
    }
    return dp[a][b];
}    
void solve(){
    int a,b;
    cin>>a>>b;
    vector<vector<ll>> dp(a+1,vector<ll>(b+1,1e18));
    cout<<rec(a,b,dp);
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