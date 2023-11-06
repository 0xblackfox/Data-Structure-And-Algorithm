#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define ll long long
#define inf 1000000009
ll mod = LLONG_MAX;
int cse = 1;

int lcs[100][100];



int main(){

    int t; cin >> t;
    for(int T=0;T<t;T++){
        string s1,s2; cin >> s1 >> s2;
    int row = s2.size();
    int col = s1.size();
    for(int i=1;i<=row;i++){
      for(int j=1;j<=col;j++){
        if(s1[j-1]==s2[i-1]){
          lcs[i][j] = lcs[i-1][j-1]+1;
        }
        else{
          lcs[i][j] = max(lcs[i][j-1],lcs[i-1][j]);
        }
      }
    }

    // for(int i=0;i<=row;i++){
    //   for(int j=0;j<=col;j++){
    //     cout << lcs[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    string sub = "";
    int i = s2.size(), j = s1.size();
    while(lcs[i][j]!=0){
      if(s2[i-1]==s1[j-1]){
        sub+=s2[i-1];
        i--; j--;
      }
      else{
        if(lcs[i-1][j]>lcs[i][j-1])i--;
        else j--;
      }
    }
    reverse(sub.begin(),sub.end());
    cout << sub.size() << " " << sub << endl;
    }

}
