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

queue<pair<pair<int,int>,int>>q;
int dis[1001];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int nodes,edges; cin >> nodes >> edges;
    int mat[nodes+1][nodes+1];
    for(int i=0;i<=nodes;i++){
      for(int j=0;j<=nodes;j++){
        if(i!=j)mat[i][j] = inf;
        else mat[i][j] = 0;
      }
    }
    for(int i=0;i<edges;i++){
      int u,v,c; cin >> u >> v >> c;
      mat[u][v] = c;
      //mat[v][u] = c //for undirected graph
    }

    for(int k=1;k<=nodes;k++){
      for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){
          mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
        }
      }
    }
    
    for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){
          cout << mat[i][j] << " ";
        }
        cout << endl;
      }

}
/*
4 6
1 4 5
1 2 3
2 1 2
2 4 4
3 2 1
4 3 2
*/