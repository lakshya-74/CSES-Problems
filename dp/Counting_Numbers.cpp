#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
vector<int> v;
ll dp[20][11][2][2]; 
ll dfs(int pos, int prev, int t, int s){
    if(pos == v.size()) return 1;

    ll &ans = dp[pos][prev+1][t][s];
    if(ans != -1 && !t) return ans;

    ll res = 0;
    int lim = t ? v[pos] : 9;

    for(int d = 0; d <= lim; d++){
        int ntight = t && (d == lim);

        if(!s && d == 0){
            res += dfs(pos+1, -1, ntight, 0);
        }
        else{
            if(prev != -1 && prev == d) continue;
            res += dfs(pos+1, d, ntight, 1);
        }
    }

    if(!t) ans = res;
    return res;
}

ll func(ll x){
    if(x < 0) return 0;

    v.clear();

    if(x == 0){
        v.push_back(0);
    }
    else{
        while(x){
            v.push_back(x%10);
            x/=10;
        }
        reverse(v.begin(),v.end());
    }

    memset(dp,-1,sizeof(dp));

    return dfs(0,-1,1,0);
}
void solve(){
    ll n,m;
    cin>>n>>m;
    cout<<func(m) - func(n-1);
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