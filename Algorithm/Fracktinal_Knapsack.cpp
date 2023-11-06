#include<bits/stdc++.h>
using namespace std;

int knapsack(int sizeItem[], int value[], int s, int n) {
    // create a dp array
    // dp[i][j] will store the maximum value of artifacts considering i items and j capacity
    int dp[n + 1][s + 1];

    // fill the dp table in bottom up manner
    for (int i = 0 ; i < n + 1 ; i++) {
        for (int j = 0 ; j < s + 1 ; j++) {
            // if i = 0 or j = 0 i.e. if number of items = 0 or capacity = 0 , maximum value will be 0
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            // if size of item is less than or equal to capacity
            else if (sizeItem[i - 1] <= j) {
                // dp[i][j] = maximum of profit including i-1 th element or profit without including i-1 th element
                dp[i][j] = max(dp[i - 1][j], value[i - 1] + dp[i - 1][j - sizeItem[i - 1]]);
            }
            // if size of item is greater than capacity
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // return the maximum value of stolen artifacts
    return dp[n][s];
}

int main() {
    // s will store the capacity of knapsack
    // n will store the number of atifacts
    int s, n;

    // take s and n as input
    cin >> s >> n;

    // create two arrays of size n
    // array for storing size of atifacts
    int sizeItem[n];
    // array for storing value of artifacts
    int value[n];

    // run a for loop for taking input
    for (int i = 0 ; i < n ; i++) {
        // store input in arrays
        cin >> sizeItem[i] >> value[i];
    }
    // call the function and print the result
    cout << knapsack(sizeItem, value, s, n) << endl;
}


/** input :
4 5      --> 4 => Maximum Weight , 5 => Array Input
1 8
2 4
3 0
2 5
2 3

**/