#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl "\n"
#define ll long long
ll mod = INT_MAX;
int profit[2001],cap[2001];
int dp[2001][2001];
int item, size;
int f(int in, int rem){
    if(dp[in][rem]!=-1)return dp[in][rem];
    if(in==size || rem==0)return 0;
    int a=0,b=0;
    if(cap[in]<=rem)a = profit[in]+f(in+1,rem-cap[in]);
    b = f(in+1,rem);
    return dp[in][rem] = max(a,b);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
 
    int t=1; //cin >> t;
 
    while(t--){
        
        cin >> item >> size;
        memset(dp, -1, sizeof(dp));

        for(int i=0;i<item;i++)cin >> cap[i] >> profit[i];
 
        cout << f(0,size) << endl;
         
   }
    
}