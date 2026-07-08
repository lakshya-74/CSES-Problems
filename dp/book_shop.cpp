#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
// int rec(int i,int x , vector<int>& p,vector<int>& page,vector<vector<int>>& dp){
//     if(i<0) return 0;
//     if(dp[i][x]!=-1) return dp[i][x];
//     int a = rec(i-1,x,p,page,dp);
//     int b = 0;
//     if(x>=p[i]) b = page[i] + rec(i-1,x-p[i],p,page,dp);
//     return dp[i][x] = max(a,b);
// }
void solve(){
    int n , x;
    cin>>n>>x;
    vector<int> p(n) , page(n) ;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        cin>>page[i];
    }
    vector<vector<int>> dp(n,vector<int>(x+1,0));
    for(int j=p[0];j<=x;j++) dp[0][j] = page[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=x;j++){
            int a = dp[i-1][j];
            int b = 0;
            if(j>=p[i]) b = page[i] + dp[i-1][j-p[i]];
            dp[i][j] = max(a,b);
        }
    }
    cout<<dp[n-1][x];
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