#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>ans.back()){
            ans.push_back(arr[i]);
        }
        else{
            int lo = 0 , hi = ans.size()-1;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(ans[mid]>=arr[i]){
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            ans[lo] = arr[i];
        }
    }
    cout<<ans.size()<<endl;
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