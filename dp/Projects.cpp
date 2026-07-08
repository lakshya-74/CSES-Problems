#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    sort(arr.begin(),arr.end());
    vector<ll> dp(n+1,0);
    for(int i=n-1;i>=0;i--){
        dp[i] = dp[i+1];
        int lo = i+1 , hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(arr[mid][0]>arr[i][1]){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        int next = lo;
        dp[i] = max(dp[i],arr[i][2] + dp[next]);
    }
    cout<<dp[0]<<endl;
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