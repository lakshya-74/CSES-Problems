#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>

void solve(){
    ll n;
    cin>>n;
    ll sum = n*(n+1)/2;
    int mod = 1e9 + 7;
    if(sum%2!=0){
        cout<<0<<endl;
        return;
    }
    sum /= 2;
    vector<vector<int>> dp(n,vector<int>(sum+1,0));
    // why we dont include n number??
    // because we are trying to find the number of ways to partition the set {1,2,3,...,n} into two subsets with equal sum.
    // in this every time 2*ans will come eg. if we want sum = 3 , sets will be {1,2} and {3} or {3} and {1,2} 
    // will be treated as different sets but they are same so we will divide by 2 in the end.
    // but we are using module so if we divide by 2 then we will get wrong answer so we will not divide by 2
    // instead we will force n to be included in second set so in first set we will only have numbers from 1 to n-1
    // in this way every set counted once only
    dp[0][0] = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=i){
                dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % mod;
            }
        }
    }
    cout<<dp[n-1][sum]%mod<<endl;
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