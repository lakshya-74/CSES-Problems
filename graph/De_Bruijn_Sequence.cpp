#include <bits/stdc++.h>
using namespace std;
// for more understang see yash poonia videoo...
#define ll long long
#define pp pair<int,int>
string de_bruijn(int n,int k){
    string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(k<=0 || n<=0 || k>alphabet.size()) return "";
    if(n==1){
        string s;
        for(int i=0;i<k;i++) s+=alphabet[i];
        return s;
    }
    //number of nodes 
    ll nodes = pow(k,n-1);
    vector<int> nextEdge(nodes,0);
    stack<pp> st;
    vector<int> ans;
    st.push({0,-1});
    while(!st.empty()){
        int v = st.top().first;
        int edge = st.top().second;
        if(nextEdge[v]<k){
            int d = nextEdge[v]++;
            ll u = (v*k+d)%nodes;
            st.push({u,d});
        }
        else{
            st.pop();
            if(edge!=-1){
                ans.push_back(edge);
            }
        }
    }
    reverse(ans.begin(),ans.end());
    string s = "";
    for(int i=0;i<n-1;i++) s += alphabet[0];
    for(int d:ans){
        s += alphabet[d];
    } 
    return s;
}
void solve(){
    int n,k;
    cin>>n;
    k = 2;
    cout<<de_bruijn(n,k)<<"\n";
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