#include <iostream>
#include <climits>
using namespace std;
int knapSack(int v[], int w[], int n, int W) {
   if (W < 0)
      return INT_MIN;
   if (n < 0 || W == 0)
      return 0;
   int in = v[n] + knapSack(v, w, n - 1, W - w[n]);
   int ex = knapSack(v, w, n - 1, W);
   return max (in, ex);
}
int main() {
   int W, n, v, w;

   cin >> W >> n;

   int sizeItem[n];
   int value[n];


   for (int i = 0 ; i < n ; i++) {
      cin >> sizeItem[i] >> value[i];
   }


   /*   int v[] = { 10, 20, 30, 40, 60, 70 };
      int w[] = { 1, 2, 3, 6, 7, 4 };
      int W = 7;
      int n = sizeof(v) / sizeof(v[0]);*/
   cout << "Knapsack value is " << knapSack(sizeItem, value, n - 1, W);
   return 0;
}




/** input :
4 3      --> 4 => Maximum Weight , 3 => Array Input
1 4
2 5
3 1
**/