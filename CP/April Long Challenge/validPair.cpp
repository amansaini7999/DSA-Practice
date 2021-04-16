#include<bits/stdc++.h>
using namespace std;

bool check(int a, int b, int c){
  if(a==b || a==c || b==c)
    return 1;

  return 0;
}

int main()
{
  int a, b, c;
  cin>>a>>b>>c;

  if(check(a, b, c))
    cout<<"Yes";
  else
    cout<<"No";

  return 0;
}
