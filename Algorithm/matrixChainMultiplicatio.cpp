#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl "\n"
#define ll long long
int mat[100][100];

int f(int i, int j,int d[]){
  int mn = INT_MAX;
  for(int k = i;k<j;k++){
    mn = min(mn,mat[i][k]+mat[k+1][j]+d[i-1]*d[j]*d[k]);
  }
  return mn;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n; int d[n];
    for(int i=0;i<n;i++){
      cin >>d[i];
    }
    
    for(int i=1, df=1;i<n-1;i++,df++){
      for(int j=1+i;j<n;j++){
        mat[j-df][j] = f(j-df,j,d);
      }
    }

    // for(int i=0;i<n;i++){
    //   for(int j=0;j<n;j++){
    //     cout << mat[i][j] << "\t\t\t";
    //   }
    //   cout << endl;
    // }
    cout << "Ans: "<<mat[1][n-1] << endl;
}