#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl "\n"
#define ll long long

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int node, edges;
    cin >> node >> edges;
    vector<int>g[node+1];
    for(int i=0;i<edges;i++){
      int u,v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    int vis[node+1]={0};

    for(int i=0;i<=node;i++){

      queue<int>q;

      if(vis[i])continue;
      else{
        vis[i] = 1;
        q.push(i);
      }
      
      while(!q.empty()){
        int u = q.front();
        cout << u << endl;

        q.pop();
        for(int j=0;j<g[u].size();j++){
          int v= g[u][j];

          if(!vis[v]){
            vis[v] = 1;
            q.push(v);
          }
        }
      }
    }

}
/*8 8
0 1
0 3
2 4
1 2
0 2
5 7
5 6
7 8
8?