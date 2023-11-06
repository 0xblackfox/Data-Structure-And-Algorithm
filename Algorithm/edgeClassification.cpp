#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl "\n"
#define ll long long
bool flag = false;
int parentOf[100];
vector<int>g[100];
int timeC = 0;
int vis[100];
int inTime[100], outTime[100];
int edgeVisited[100][100];

void dfsToCalculateInTimeOutTime(int u){
  vis[u] = 1;
  inTime[u] = timeC++;
  for(int i=0;i<g[u].size();i++){
    if(!vis[g[u][i]]){
      
      cout << "Tree edge: "<< u << " " << g[u][i] << endl; 
      edgeVisited[u][g[u][i]] = 1;

      dfsToCalculateInTimeOutTime(g[u][i]);

    }
  }
  outTime[u] = timeC++;
}

bool dfsChildToParent(int u,int v){
  vis[u] = 1;
  // cout << u << endl;
  for(int i=0;i<g[u].size();i++){
    if(!vis[g[u][i]]){
      if(v == g[u][i])return (flag|=true);
      dfsChildToParent(g[u][i],v);
    }
  }
  return flag;
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
    }

   for(int i=1;i<=node;i++){
    if(!vis[i])dfsToCalculateInTimeOutTime(i);
   }

   // for(int i=1;i<=node;i++){
   //  cout << inTime[i]<<"/"<<outTime[i]<<" ";
   // }

   for(int u=1; u<=node; u++){
    for(int i=0;i<g[u].size();i++){
      int child = g[u][i];
      if(!edgeVisited[u][child]){//u-3; child-1;

        for(int i=1;i<=node;i++)vis[i] = 0;

        if(!dfsChildToParent(child,u)){
          cout << "Cross edge: "<< u << " " << child << endl;;
        }
        else if(inTime[u]>inTime[child]){
          cout << "Back edge: "<< u << " " << child << endl;
        }
        else {
          cout << "forward edge: "<< u << " " << child << endl;
        }

      }

    }
   }
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