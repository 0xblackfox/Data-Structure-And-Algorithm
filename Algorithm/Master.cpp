#include<bits/stdc++.h>
using namespace std;
int cse = 1;
int a,b,p,k;

bool checkNegative(string s){
  for(int i=0;i<s.size();i++){
    if(s[i]=='-')return true;
  }
  return false;
}
void f(string s){
	string A="",B="",K="",P="";
	int i=0;
	while(s[i]!='=')i++;
	i++;
	while(s[i]!='T'){
		A+=s[i++];
	}

	while(s[i]!='/')i++;
	i++;
	while(s[i]!=')'){
		B+=s[i++];
	}

	while(s[i]!='^')i++;
	i++;
	while(s[i]!=')'){
		K+=s[i++];
	}

	while(s[i]!='^')i++;
	i++;
	while(i<s.size()){
		P+=s[i++];
	}
	a = stoi(A);
	b = stoi(B);
	k = stoi(K);
	p = stoi(P);
}
int main(){


    int t;  cin >> t;
    while(t--){
      string s; cin >> s;
      f(s);
      if(a<1 || b<=1 || checkNegative(s)){
        cout << s << "\tInvalid\t\tDoes not apply\n";
      }
      else{
        double valueOfLog = log10(a)/log10(b);
        if(valueOfLog>k){
          cout <<s << "\t\tO(n^"<<valueOfLog<<")\t\tcase " << cse++ << "\n";
        }
        else if(valueOfLog==k){
          if(p>-1)cout <<s << "\t\tO(n^"<<k<<" (log^"<<p+1<<")n\t\tcase " << cse++ << "\n";
          else if(p==-1)cout <<s << "\t\tO(n^" <<k <<" loglogn)\t\tcase " << cse++ << "\n";
          else cout <<s << "\t\tO(n^" <<k <<")\t\tcase " << cse++ << "\n";
        }
        else{
          if(p>=0){
            cout <<s << "\t\tO(n^"<<k<<" (logn)^"<<p<<")\t\tcase " << cse++ << "\n";
          }
          else{
            cout <<s << "\t\tO(n^" <<k <<")\t\tcase " << cse++ << "\n";
          }
        }
      }

    }

}
/*
Input Set
4
T(n)=3T(n/2)+(n^2)*(logn)^0
T(n)=4T(n/2)+(n^2)*(logn)^0
T(n)=3T(n/2)+(n^1)*(logn)^0
T(n)=64T(n/8)-(n^2)*(logn)^1

*/
