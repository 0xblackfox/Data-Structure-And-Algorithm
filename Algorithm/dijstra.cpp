#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl "\n"
#define ll long long
#define inf 1000000009
ll mod = INT_MAX;

vector<pair<int,int>>g[1001];
int dis[1001];

int dij(int st, int ed){
  for(int i=0;i<1001;i++)dis[i] = inf;
  priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
  pq.push({0,st});
  dis[st] = 0;
  while(!pq.empty()){
    int Pnode = pq.top().second;
    int Pcost = pq.top().first;
    pq.pop();
    for(int i=0;i<g[Pnode].size();i++){
      int Cnode = g[Pnode][i].second;
      int edgeCost = g[Pnode][i].first;
      if(Pcost+edgeCost<dis[Cnode]){
        dis[Cnode] = Pcost+edgeCost;
        pq.push({dis[Cnode], Cnode});
      }
    }
  }
  return dis[ed];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
 
    int nodes,edges; cin >> nodes >> edges;
    for(int i=0;i<edges;i++){
      int u,v,c; cin >> u >> v >> c;
      g[u].push_back({c,v});
      g[v].push_back({c,u});
    }

    cout << dij(1,3) << endl;
    
}