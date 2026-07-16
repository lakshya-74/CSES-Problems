#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<pp> dp(1<<n,{n+1,0});
    dp[0] = {1,0};
    for(int m=1;m<(1<<n);m++){
        for(int i=0;i<n;i++){
            if(m&(1<<i)){
                int pre = m^(1<<i);
                pp curr = dp[pre];
                if(curr.second+arr[i]<=x){
                    curr.second+=arr[i];
                }
                else{
                    curr.first++;
                    curr.second=arr[i];
                }
                dp[m] = min(dp[m],curr);
            }
        }
    }
    cout<<dp[(1<<n)-1].first<<"\n";
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