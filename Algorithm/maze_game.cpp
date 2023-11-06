#include<bits/stdc++.h>
using namespace std;

int maze(int n, int m, int** ans, int i, int j)
{
   int l = INT_MAX, r = INT_MAX, u = INT_MAX, d = INT_MAX;

   if (i - 1 >= 0) l = ans[i - 1][j];
   if (i + 1 < n) r = ans[i + 1][j];
   if (j - 1 >= 0) u = ans[i][j - 1];
   if (j + 1 < m) d = ans[i][j + 1];

   int c = min(l, min(r, min(u, d)));
   return c;
}
int main() {
   int t;
   cin >> t;
   while (t--)
   {
      int n, m;
      cin >> n >> m;

      int** arr = new int*[n];
      int** ans = new int*[n];
      for (int i = 0; i < n; i++)
      {
         arr[i] = new int[m];
         ans[i] = new int[m];
         for (int j = 0; j < m; j++)
         {
            cin >> arr[i][j];
            ans[i][j] = INT_MAX;
         }
      }


      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
         {
            if (i == 0 && j == 0)
            {
               ans[i][j] = arr[i][j];
            }
            else
            {
               ans[i][j] = arr[i][j] + maze(n, m, ans, i, j);
            }
         }
      }

      cout << ans[n - 1][m - 1] << endl;
   }
   return 0;
}



/**
3

4 5
0 3 11 2 9
7 3 4 9 9
1 7 5 13 3
2 3 4 2 5

1 6
0 1 2 3 4 5

2 3
0 5 9
7 3 2
**/
