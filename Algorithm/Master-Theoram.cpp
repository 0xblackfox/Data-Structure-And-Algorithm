/// BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
long long int lcm(long long int a, long long b)
{
  return a * (b / __gcd(a, b));
}
const long long int mx = 1e7 + 123;
long long int a[mx];
int getA(string s)
{
  int i = 0;
  while (s[i] != '=')
  {
    i++;
  }
  i++;
  string num = "";
  while (s[i] != 'T')
  {
    num = num + s[i];
    i++;
  }
  return stoi(num);
}
int getB(string s)
{
  int i = 0;
  while (s[i] != '/')
  {
    i++;
  }
  i++;
  string num = "";
  while (s[i] != ')')
  {
    num = num + s[i];
    i++;
  }
  return stoi(num);
}
int getK(string s)
{
  int i = 0;
  string num = "";
  while (s[i] != '+')
  {
    i++;
  }
  i++;
  if (s[i + 1] == 'l')
  {
    return 1;
  }
  else
  {
    for (i = i + 1; s[i] != 'l'; i++)
    {
      num = num + s[i];
    }
  }
  return stoi(num);
}
int getP(string s)
{
  int i = 0;
  string num = "";
  bool f = false;
  for (int i = 0; i < s.size() - 4; i++)
  {
    if (s[i] == 'l' && s[i + 1] == 'o' && s[i + 2] == 'g')
    {
      f = true;
      break;
    }
  }
  if (!f) {
    return 0;
  }
  for (i = s.size() - 2; i >= 0; i++) {
    if (s[i] == ')') {
      break;
    }
    else {
      num = num + s[i];
    }
  }
  reverse(num.begin(), num.end());
  return stoi(num);
}
bool negative(string s)
{
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '-')
    {
      return 1;
    }
  }
  return 0;
}
int main()
{
  optimize();
  // freopen("a.txt","r",stdin);freopen("b.txt","w",stdout);
  long long int t, i, n;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    int a = getA(s);
    int b = getB(s);
    int k = getK(s);
    int p = getP(s);
    cout << a << " " << b << " " << p << " " << k << endl;
    if (a >= 1 || b > 1 || (!negative(s)))
    {
      double logV = log10(a) / log10(b);
      if (logV > k)
      {
        cout << "O(n^log" << a << b << ")\n";
      }
      else if (logV == k)
      {
        if (p > -1)
        {
          cout << "O(n^" << k << " logn" << p + 1 << ")\n";
        }
        else if (p == -1)
        {
          cout << "O(n^" << k << " loglogn<<)\n";
        }
        else
        {
          cout << "O(n^" << k << ")\n";
        }
      }
      else
      {
        if (p < 0)
        {
          cout << "O(n^" << k << ")\n";
        }
        else
        {
          cout << "O(n^" << k << " lognp)\n";
        }
      }
    }
    else
    {
      cout << "Doesn't apply master's theorem\n";
    }
  }
//std::cout << std::fixed << std::setprecision(2);
}
/// ALHAMDULILLAH