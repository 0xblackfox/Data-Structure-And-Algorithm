#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl "\n"
#define ll long long
int mat[100][100];

string s[501];


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nodes,edges;
    cin >> nodes >> edges;
    int g[nodes+1][nodes+1];
    memset(g,0,sizeof g);
    
    for(int i=0;i<edges;i++){
      int u,v,c; cin >> u >> v >> c;
      g[u][v] = g[v][u] = c;
    }

    int selected[nodes+1]={0};
    selected[1] = 1;

    int mn = INT_MAX;
    int dest,source,totalCost=0;
    for(int cntOfEdges=1;cntOfEdges<=nodes-1;cntOfEdges++){
      mn = INT_MAX;
      for(int i=1;i<=nodes;i++){
        if(selected[i]){
          for(int j=1;j<=nodes;j++){
            if(!selected[j] && g[i][j]){
              if(mn>g[i][j]){
                source= i;
                dest = j; mn = g[i][j];
              }
            }
          }
          
        }
      }
      cout << source << " -> " << dest << " : " << mn << endl;
      totalCost+=mn;
      selected[dest]=1;
    }
    cout << "totalCost = " << totalCost << endl;

}

/*
6 10
1 4 5
1 2 6
2 3 5
2 5 3
4 3 5
1 3 1
4 6 2
3 5 6
3 6 4
5 6 6
*/      