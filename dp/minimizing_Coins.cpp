#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
int rec(int idx,int sum , vector<int>& arr,vector<vector<int>>& dp){
    if(sum==0) return 0;
    if(idx==0){
        if(sum%arr[0]==0) return sum/arr[0];
        return 1e9;
    }
    if(dp[idx][sum]!=-1) return dp[idx][sum];
    int a = 1e9;
    if(arr[idx]<=sum) a = 1 + rec(idx,sum-arr[idx],arr,dp);
    int b = rec(idx-1,sum,arr,dp);
    return dp[idx][sum] = min(a,b);
}
void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // vector<vector<int>> dp(n,vector<int>(x+1,-1));
    // int ans= rec(n-1,x,arr,dp);
    // if(ans>=1e9) cout<<-1;
    // else cout<<ans;
    vector<vector<int>> dp(n,vector<int>(x+1,1e9));
    for(int i=0;i<n;i++) dp[i][0]=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){
            int a = 1e9;
            if(arr[i]<=j) a = 1 + dp[i][j-arr[i]];
            int b = 1e9;
            if(i>0) b = dp[i-1][j];
            dp[i][j] = min(a,b);
        }
    }
    int ans = dp[n-1][x];
    if(ans>=1e9) cout<<-1;
    else cout<<ans;
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