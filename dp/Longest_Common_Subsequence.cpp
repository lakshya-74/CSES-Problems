#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>

// int rec(int i, int j, vector<int> &a, vector<int> &b, vector<vector<int>> &dp){
//     if(i>=a.size() || j>=b.size()) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(a[i]==b[j]){
//         return dp[i][j]=1+rec(i+1,j+1,a,b,dp);
//     }
//     return dp[i][j]=max(rec(i+1,j,a,b,dp),rec(i,j+1,a,b,dp));
// }

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n) , b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    vector<int> ans;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // cout<<rec(0,0,a,b,dp)<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    int i = n, j = m;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            ans.push_back(a[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>=dp[i][j-1]){
            i--;
        }
        else j--;
    }
    for(int i=(int)ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
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