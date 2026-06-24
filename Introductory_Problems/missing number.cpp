#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    vector<int> arr(t-1);
    // 
    int ans = t;
    for(int i=0;i<t-1;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<t-1;i++){
        if(arr[i]!=i+1){
            ans = i+1;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}