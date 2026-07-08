#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
// int c = 0;
// void rec(int i,int sum,vector<int>& arr,vector<vector<ll>>& dp){
//     if(i<0){
//         if(sum>0){
//             c++;
//         }
//         return;
//     }
//     if(dp[i][sum]){
//         c++;
//         return;
//     }
//     rec(i-1,sum+arr[i],arr,dp);
//     rec(i-1,sum,arr,dp);
//     dp[i][sum] = 1;
// }
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,0));
    // rec(n-1,0,arr,dp); 
    // cout<<c<<endl;
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=arr[i-1]){
                dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=sum;i++){
        if(dp[n][i]){
            ans++;
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=sum;i++){
        if(dp[n][i]){
            cout<<i<<" ";
        }
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