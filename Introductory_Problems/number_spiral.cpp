#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> mat = {{1,2,9,10,25},{4,3,8,11,24},{5,6,7,12,23},{16,15,14,13,22},{17,18,19,20,21}};
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;

        a--;
        b--;
        cout<<mat[a][b]<<endl;
    }
    return 0;
}