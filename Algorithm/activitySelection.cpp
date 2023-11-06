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

	int n; cin >> n;
	int start[n],finish[n];
	for(int i=0;i<n;i++)cin >> start[i];
	for(int i=0;i<n;i++)cin >> finish[i];
	vector<pair<int,int>>time;
	map<pair<int,int>,int>mp;
	for(int i=0;i<n;i++){
		time.push_back({finish[i],start[i]});
		mp[{finish[i],start[i]}] = i+1;
	}
	sort(time.begin(),time.end());
	vector<int>task;
	task.push_back(mp[{time[0].finish,time[0].start}]);
	int ptft = time[0].finish;
	for(int i=1;i<n;i++){
		if(time[i].start>=ptft){
			task.push_back(mp[{time[i].finish,time[i].start}]);
			ptft = time[i].finish;
		}
	}
	for(int i=0;i<task.size();i++){
		cout << task[i] << " ";
	}
	cout << endl;
}