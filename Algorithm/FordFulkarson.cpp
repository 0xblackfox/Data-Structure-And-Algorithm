// C++ program for implementation of Ford Fulkerson
// algorithm
#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

// Number of vertices in given graph
int const N = 100;
int graph[N][N];
int rGraph[N][N];

bool bfs(int n, int s, int t, int parent[])
{
  bool visited[n];
  memset(visited, 0, sizeof(visited));
  queue<int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;

  // Standard BFS Loop
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v = 0; v <n; v++) {
      if (visited[v] == false && rGraph[u][v] > 0) {
        if (v == t) {
          parent[v] = u;
          return true;
        }
        q.push(v);
        parent[v] = u;
        visited[v] = true;
      }
    }
  }

  return false;
}

int fordFulkerson(int n, int s, int t)
{
  int u, v;
  for (u = 0; u <n; u++)
    for (v = 0; v < n; v++)
      rGraph[u][v] = graph[u][v];

  int parent[n];

  int max_flow = 0;
  while (bfs(n,s, t, parent)) {

    int path_flow = INT_MAX;
    for (v = t; v != s; v = parent[v]) {
      u = parent[v];
      path_flow = min(path_flow, rGraph[u][v]);
    }

    for (v = t; v != s; v = parent[v]) {
      u = parent[v];
      rGraph[u][v] -= path_flow;
      rGraph[v][u] += path_flow;
    }

    max_flow += path_flow;
  }


  return max_flow;
}

int main()
{


  int n,m;
  cin>>n>>m;
  for(int i =0;i<m;i++)
  {
    int x,y,wt;
    cin>>x>>y>>wt;
    graph[x][y]=wt;
  }

  cout << "The maximum possible flow is "
    << fordFulkerson(n,0,n-1);

  return 0;
}

/*6(node) 10(Vertex/edge)
 0 1 15( 0 ar 1 er moddhe capacity 15)
 0 2 11
 1 2 8
 1 3 9
 2 1 10
 2 4 9
 3 5 10
 4 1 15
 4 3 8
 4 5 11
 The maximum possible flow is 18*/
