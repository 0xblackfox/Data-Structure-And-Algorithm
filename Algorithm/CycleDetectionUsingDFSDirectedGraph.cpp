#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl "\n"
#define ll long long

vector<int>g[100];
int parOf[100];   
int vis[100];
bool flag = false;

bool dfs(int u){
  vis[u] = true;
  for(int i=0;i<g[u].size();i++){
    int v = g[u][i];
    if(!vis[v])dfs(v);
    else return flag|=true;
  }
  vis[u] = 0;
  return flag;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int node,edge; 
    cin >> node >> edge;
    for(int i=0;i<edge;i++){
      int u,v; cin >> u >> v;
      g[u].push_back(v);
    }
    bool isCycleDetected = false;
    for(int i=1;i<=node;i++){
      if(!vis[i]){
        if(dfs(i)){
          isCycleDetected = true ; break;
        }
      }
    }
    if(isCycleDetected)cout << "Cycle Detected" << endl;
    else cout << "No cycles" << endl;
}
/*
5 6
1 2
2 3
3 5
1 4
5 4
3 1
*/