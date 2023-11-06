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
    for(int i=0;i<edges;i++){
      int u,v,c; cin >> u >> v >> c;
      q.push({{u,v},c});
    }

    int source = 0, dest = nodes;
    for(int i=0;i<=nodes;i++)dis[i] = inf;
    dis[source] = 0;
    for(int i=0;i<nodes;i++){
      for(int j=0;j<edges;j++){
        int u = q.front().first.first;
        int v = q.front().first.second;
        int c = q.front().second;
        q.pop();
        q.push({{u,v},c});
        if(dis[u]!=inf && dis[u]+c<dis[v]){
          dis[v] = dis[u] + c;
        }
      }

    }

    cout << "N-1 th relaxation:\n";
    for(int i=0;i<=nodes;i++)cout << dis[i] << " ";
    cout << endl;

    for(int j=0;j<edges;j++){
      int u = q.front().first.first;
      int v = q.front().first.second;
      int c = q.front().second;
      q.pop();
      q.push({{u,v},c});
      if(dis[u]!=inf && dis[u]+c<dis[v]){
        dis[v] = dis[u] + c;
      }

    }

    cout << "N th relaxation:\n";
    for(int i=0;i<=nodes;i++)cout << dis[i] << " ";
    cout << endl;
}

/*
4 8
0 1 -1
0 2 5
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
2 0 -2
*/