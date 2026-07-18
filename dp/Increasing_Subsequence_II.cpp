#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
int mod = 1e9 +7;
int maxN = 2e5+5;
ll dp[200005];
ll query(int idx){
    ll sum = 0;
    for(int i=idx;i>0;i-= i& -i)
        sum = (sum + dp[i]) % mod;
    return sum;
}
void update(int idx, ll val){
    for(int i=idx;i<maxN;i+= i& -i)
        dp[i] = (dp[i] + val) % mod;
}
void solve(){
    int n;
    cin>>n;
    vector<pp> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second=i+1;
    }
    sort(arr.begin(),arr.end(),[](pp a,pp b){
        return a.first == b.first? b.second<a.second : a.first<b.first;
    });
    ll ans = 0;
    for(int i=0;i<n;i++){
        int idx = arr[i].second;
        ll amt = query(idx)+1;
        ans = (ans + amt) % mod;
        update(idx, amt);
    }
    cout<<ans<<"\n";
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

