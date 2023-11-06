#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl "\n"
#define ll long long

vector<int>g[100];
int vis[100];
void dfs(int u){
  vis[u] = 1;
  cout << u << endl;
  for(int i=0;i<g[u].size();i++){
    if(!vis[g[u][i]]){
      dfs(g[u][i]);
    }
  }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int node, edges;
    cin >> node >> edges;

    for(int i=0;i<edges;i++){
      int u,v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

   for(int i=0;i<=node;i++){
    if(!vis[i])dfs(i);
   }

}
/*
8 8
0 1
0 3
2 4
1 2
0 2
5 7
5 6
7 8
*/