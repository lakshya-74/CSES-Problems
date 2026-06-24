#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int,int>
struct Edge {
  int to, rev;
  long long cap;
};
struct Dinic {
  int n;
  vector<vector<Edge>> g;
  vector<int> level, it;

  Dinic(int n) : n(n), g(n), level(n), it(n) {}

  void add_edge(int u, int v, long long cap) {
    g[u].push_back({v, (int)g[v].size(), cap});
    g[v].push_back({u, (int)g[u].size()-1, 0}); // reverse edge (capacity 0)
  }

  bool bfs(int s, int t) {
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    q.push(s);
    level[s] = 0;

    while(!q.empty()) {
      int u = q.front(); q.pop();
      for(auto &e : g[u]) {
        if(e.cap > 0 && level[e.to] == -1) {
          level[e.to] = level[u] + 1;
          q.push(e.to);
        }
      }
    }

    return level[t] != -1;
  }

  long long dfs(int u, int t, long long f) {
    if(u == t) return f;

    for(int &i = it[u]; i < (int)g[u].size(); ++i) {
      Edge &e = g[u][i];
      if(e.cap > 0 && level[e.to] == level[u] + 1) {
        long long pushed = dfs(e.to, t, min(f, e.cap));
        if(pushed > 0) {
          e.cap -= pushed;
          g[e.to][e.rev].cap += pushed;
          return pushed;
        }
      }
    }

    return 0;
  }

  long long max_flow(int s, int t) {
    long long flow = 0;
    while(bfs(s, t)) {
      fill(it.begin(), it.end(), 0);
      while(long long pushed = dfs(s, t, LLONG_MAX))
        flow += pushed;
    }

    return flow;
  }

  vector<bool> reachable(int s) {
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while(!q.empty()) {
      int u = q.front(); q.pop();
      for(auto &e : g[u]) {
        if(e.cap > 0 && !vis[e.to]) {
          vis[e.to] = true;
          q.push(e.to);
        }
      }
    }

    return vis;
  }
};
void solve(){
int n, m;
  cin >> n >> m;
  Dinic dinic(n);
  vector<pair<int, int>> edges;

  for(int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    dinic.add_edge(a, b, 1);
    dinic.add_edge(b, a, 1);
    edges.push_back({a, b});
  }
  long long flow = dinic.max_flow(0, n - 1);

  vector<bool> reachable = dinic.reachable(0);

  vector<pair<int, int>> cut;
  for(auto x : edges) {
    if(reachable[x.first] && !reachable[x.second]) 
      cut.push_back({x.first, x.second});
    else if(reachable[x.second] && !reachable[x.first]) 
      cut.push_back({x.second, x.first});
  }

  cout << cut.size() << "\n";
  for(auto x:cut) 
    cout << x.first + 1 << " " << x.second + 1 << "\n";

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