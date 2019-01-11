#include<bits/stdc++.h>

using namespace std;

int main()  {
  int n,k;
  cin>>n>>k;
  int types[101] = {0}, max = 0;

  for(int i=0;i<n;i++)  {
    int temp;
    cin>>temp;
    types[temp]++;
    if(types[temp] > max) max = types[temp];
  }

  int sets = ceil(1.0*max / k), ans = 0;

  for(int i=1; i<=100; i++) {
    if(types[i]!=0) ans += k*sets - types[i];
  }

  cout<<ans;
}
