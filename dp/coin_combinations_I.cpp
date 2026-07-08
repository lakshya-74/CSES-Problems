#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
ll mod = 1e9+7;
// int rec(int idx, int sum , vector<int>& arr,vector<vector<int>>& dp){
//     if(sum==0) return 1;
//     if(idx==0){
//         if(sum%arr[0]==0) return 1;
//         return 0;
//     }
//     if(dp[idx][sum]!=-1) return dp[idx][sum];
//     ll a = 0;
//     if(arr[idx]<=sum) a = rec(idx,sum-arr[idx],arr,dp);
//     ll b = rec(idx-1,sum,arr,dp);
//     ll ans = 0;
//     ans = (ans+a)%mod;
//     ans = (ans+b)%mod;
//     return dp[idx][sum] = ans%mod;
// }


// this calculate the combinataions of coins to make the sum x,
// if we want to calculate the permutations then we have to change the order of loops in tabulation method
void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // vector<vector<int>> dp(n,vector<int>(x+1,-1));
    // cout<<rec(n-1,x,arr,dp);

    // try all the coins for all the sums from 1 to x
    vector<int> dp(x+1,0);
    dp[0]=1;
    for(int sum = 1;sum<=x;sum++){
        for(int i=0;i<n;i++){
            if(arr[i]<=sum){
                dp[sum] = (dp[sum]+dp[sum-arr[i]]);
                if(dp[sum]>=mod) dp[sum] -= mod;
                // here we are adding the number of ways 
                // to make the sum by including the current coin arr[i]
            }
        }
    }
    cout<<dp[x];     
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