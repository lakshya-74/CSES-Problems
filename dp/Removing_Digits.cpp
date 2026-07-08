#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
int rec(int i , vector<int>& dp){
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    int x = i;
    int ans = 1e8;
    while(x>0){
        int d = x%10;
        x /= 10;
        if(d==0) continue;
        ans = min(ans,1+rec(i-d,dp));
    }
    return dp[i] = ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<rec(n,dp);
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