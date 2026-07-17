#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
void funct1(int l,int r , vector<int>& arr , vector<int>&v){
    stack<int> st;
    for(int i=l;i<=r;i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            st.pop();
        }
        if(st.empty()){
            v[i] = -1;
        } else {
            v[i] = st.top();
        }
        st.push(i);
    }
}
void funct2(int l,int r , vector<int>& arr , vector<int>&v){
    stack<int> st;
    for(int i=l;i>=r;i--){
        while(!st.empty() && arr[st.top()] < arr[i]){
            st.pop();
        }
        if(st.empty()){
            v[i] = arr.size();
        } else {
            v[i] = st.top();
        }
        st.push(i);
    }
}
void update(int i , int val, vector<int>& seg){
    i += seg.size()/2;
    seg[i] = val;
    while(i>1){
        i/=2;
        seg[i] = max(seg[2*i],seg[2*i+1]);
    }
}
int query(int l , int r , vector<int>& seg){
    l += seg.size()/2;
    r += seg.size()/2;
    int ans = 0;
    while(l<=r){
        if(l%2==1) ans = max(ans,seg[l++]);
        if(r%2==0) ans = max(ans,seg[r--]);
        l/=2;
        r/=2;
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> l(n) , r(n);
    funct1(0,n-1,arr,l);
    funct2(n-1,0,arr,r);
    vector<pp> v(n);
    for(int i=0;i<n;i++){
        v[i] = {arr[i],i };
    }
    sort(v.begin(),v.end());
    vector<int> dp(n,1);
    vector<int> seg(2*n,0);

    for(int i=0;i<n;i++){
        int h = v[i].first;
        int idx = v[i].second;
        int left = query(l[idx]+1,idx-1,seg);
        int right = query(idx+1,r[idx]-1,seg);
        dp[idx] = 1 + max(left,right);
        update(idx,dp[idx],seg);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,dp[i]);
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