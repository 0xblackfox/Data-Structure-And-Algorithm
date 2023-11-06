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

    int nodes, edges; cin >> nodes >> edges;
    vector<pair<int,pair<int,int>>>g;
    for(int i=0;i<edges;i++){
      int u,v,c; cin >> u >> v >> c;
      g.push_back({c,{u,v}});
    }

    sort(g.begin(),g.end());
    reverse(g.begin(),g.end());

    int parOf[nodes+1];
    for(int i=0;i<=nodes;i++)parOf[i] = i;

    int totalCost = 0;

    for(int i=edges-1;i>=0;i--){

      int c = g[i].first;
      int u = g[i].second.first;
      int v = g[i].second.second;

      int mn =min(parOf[u],parOf[v]);
      int mx = max(parOf[u],parOf[v]);

      if(mx!=mn){
        totalCost+=c;
        cout << u << " " << v << " : " << c << endl;
      }

      for(int ii=0;ii<=nodes;ii++){
        if(mn == parOf[ii])parOf[ii] = mx;
      }
      
      g.pop_back();
    }
    cout << "Total Cost = "<< totalCost << endl;
}
