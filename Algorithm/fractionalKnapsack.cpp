#include<bits/stdc++.h>
using namespace std;
#define finish first
#define start second

int main(){

	 #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int s,n; 
	cin >> s >> n;
	double w[n],p[n];

	vector<pair<double,pair<int,int>>>v;

	for(int i=0;i<n;i++){
		cin >> w[i] >> p[i];
		double ppw = p[i]/w[i];
		v.push_back({ppw,{p[i],w[i]}});
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	// for(int i=0;i<n;i++){
	// 	cout << v[i].second.second << " " << v[i].second.first << " " << v[i].first << endl;
	// }
	double totalProfit = 0;
	for(int i=0;i<n;i++){
		double iw = v[i].second.second;
		double ip = v[i].second.first;
		double ippw = v[i].first;
		if(s>=iw){
			s-=iw;
			totalProfit+=ip;
		}
		else{
			totalProfit+=s*ippw;
			s = 0;
			break;
		}
	}
	cout << totalProfit << endl;

}