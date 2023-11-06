#include <bits/stdc++.h>
using namespace std;
vector<string> v1;
void path(vector<vector<int> >maze,int n,int m,int cr,int cc,string ans){
if(cr<0 || cc<0 || cr==n || cc==m || maze[cr][cc]==0)return;
if(cr==n-1 && cc==m-1){
      v1.push_back(ans);
    return;

}
maze[cr][cc]=0;
path(maze,n,m,cr-1,cc,ans+'t');//top
path(maze,n,m,cr+1,cc,ans+'b');//bottom
path(maze,n,m,cr,cc-1,ans+'l');//left
path(maze,n,m,cr,cc+1,ans+'r');//right
maze[cr][cc]=1;
}

int main()
{

   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   vector<vector<int> >maze = {
                       { 1, 0, 1, 1 },
                       { 1, 1, 1, 1 },
                       { 0, 0, 0, 1 },
                       { 1, 1, 0, 1 } 
                    };

   path(maze,maze.size(),maze[0].size(),0,0,"");
   sort(v1.begin(),v1.end());
   cout<<v1[0]<<endl;
    return 0;
}
