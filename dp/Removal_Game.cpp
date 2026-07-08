#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
void rec(int i,int j,vector<int>& arr,vector<vector<ll>>& dp){
    if(i>j){
        return;
    }
    if(dp[i][j]!=LLONG_MIN){
        return;
    }
    if(i==j){
        dp[i][j] = arr[i];
        return;
    }
    rec(i+1,j,arr,dp);
    rec(i,j-1,arr,dp);
    dp[i][j] = max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
}
void solve(){
    ll n;
    cin>>n;
    vector<int> arr(n);
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    vector<vector<ll>> dp(n,vector<ll>(n,LLONG_MIN));
    rec(0,n-1,arr,dp);
    // total sum = F + S; means first player score + second player score
    // dp[0][n-1] = F - S; means first player score - second player score (our dp is storing the difference between first and second player score)
    // F = (total sum + difference)/2
    ll ans = (sum+(ll)dp[0][n-1])/2;
    cout<<ans<<endl;

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