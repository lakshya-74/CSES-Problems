#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    int maxlen = 1;
    for(int i=0;i<s.size();){
        char c = s[i];
        int len = 1;
        int j = i+1;
        while(j<s.size() && s[j]==c){
            len++;
            j++;
        }
        maxlen = max(maxlen,len);
        i = j;
    }
    cout<<maxlen;
    return 0;
}