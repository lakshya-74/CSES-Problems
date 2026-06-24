#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
struct Edge{
    int to;
    ll cap;
    int rev;
    Edge(int to_ , ll cap_ , int rev_){
        to = to_;
        cap = cap_;
        rev = rev_;
    }
};
struct Dinic
{
    int n;
    vector<vector<Edge>> g;
    vector<int> level;
    vector<int> it;
    Dinic(int n_){
        n = n_;
        g.resize(n_);
        level.resize(n_);
        it.resize(n_);
    }
    void add_edge(int u , int v , ll cap){
        g[u].emplace_back(v,cap,g[v].size());
        g[v].emplace_back(u,0LL,g[u].size() -1);
    }
    bool bfs(int s , int t){
        fill(level.begin(),level.end(),-1);
        queue<int> q;
        q.push(s);
        level[s] = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto &x:g[u]){
                if(x.cap>0 && level[x.to]<0){
                    level[x.to] = level[u] + 1;
                    q.push(x.to);
                }
            }
        }
        return level[t] != -1;
    }

    ll dfs(int u , int t , ll f){
        if(u==t) return f;
        for(int &i=it[u] ;i<g[u].size();i++){
            auto &e = g[u][i];
            if(e.cap<=0) continue;
            if(level[e.to]!=level[u]+1) continue;
            ll pushed = dfs(e.to,t,min(f,e.cap));
            if(pushed>0){
                e.cap -= pushed;
                g[e.to][e.rev].cap += pushed;
                return pushed;
            }
        }
        return 0;
    }
    ll max_flow(int s ,int t){
        ll flow = 0;
        while(bfs(s,t)){
            fill(it.begin(),it.end(),0);
            while(true){
                ll pushed = dfs(s,t,1e18);
                if(pushed==0) break;
                flow += pushed;
            }
        }
        return flow;
    }
};


void solve(){
    int n,m;
    cin>>n>>m;
    Dinic dinic(n);
    for(int i=0;i<m;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        a-- , b--;
        dinic.add_edge(a,b,c);
    }
    ll ans = dinic.max_flow(0,n-1);
    cout<<ans;
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