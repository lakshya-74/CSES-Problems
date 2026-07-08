#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
int mod = 1e9 + 7;
int rec(int i,int j , vector<vector<char>>& v,vector<vector<int>>& dp){
    if(i<0 || j<0 || v[i][j]=='*') return 0;
    if(i==0 && j==0) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int a = rec(i-1,j,v,dp);
    int b = rec(i,j-1,v,dp);
    return dp[i][j] = (a+b)%mod;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<char>> v(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<rec(n-1,n-1,v,dp);
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