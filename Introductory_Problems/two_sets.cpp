#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    ll sum = (n*(n+1))/2;
    if(sum&1) cout<<"NO";
    else{
        sum /= 2;
        cout<<"YES\n";
        vector<bool> check(n+1,false);
        vector<ll> first;
        ll i = n;
        while(sum>0){
            if(sum-i<0){
                i--;
                continue;
            }
            first.push_back(i);
            check[i] = true;
            sum -= i;
            i--;
        }
        vector<ll> second;
        for(ll i=1;i<n+1;i++){
            if(!check[i]){
                second.push_back(i);
            }
        }
        cout<<first.size()<<endl;
        for(ll i=0;i<first.size();i++){
            cout<<first[i]<<" ";
        }
        cout<<endl;
        cout<<second.size()<<endl;
        for(ll i=0;i<second.size();i++){
            cout<<second[i]<<" ";
        }

    }
    return 0;
}