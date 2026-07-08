#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
int rec(int i, int j,string& s1 , string&s2 , vector<vector<int>>& dp){
    if(i==0 && j==0) return !(s1[i]==s2[j]);
    else if(i<0 && j<0) return 1e8;
    else if(i<0 && j>=0) return j+1;
    else if(i>=0 && j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]){
        return rec(i-1,j-1,s1,s2,dp);
    }
    // add character
    int a = 1 + rec(i,j-1,s1,s2,dp);
    // remove
    int b = 1 + rec(i-1,j,s1,s2,dp);
    int c = 1 + rec(i-1,j-1,s1,s2,dp);
    return dp[i][j] = min({a,b,c});
}
void solve(){
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // cout<<rec(n-1,m-1,s1,s2,dp);

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++) dp[i][0] = i;
    for(int j=0;j<=m;j++) dp[0][j] = j;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                int a = 1 + dp[i][j-1];
                int b = 1 + dp[i-1][j];
                int c = 1 + dp[i-1][j-1];
                dp[i][j] = min({a,b,c});
            }
        }
    }
    cout<<dp[n][m];
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