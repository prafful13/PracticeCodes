#include <bits/stdc++.h>

using namespace std;

int main()  {
  long int t;
  cin>>t;
  while(t--)  {
    int a,b,k;
    int ans;
    cin>>a>>b>>k;

    cout<<(a-b)*1ll*(k/2) + a*(k&1)<<endl;
    // if(k%2!=0)  ans+=a;

    // cout<<ans<<endl;

    // cout << (a - b) * 1ll * (k / 2) + a * (k & 1) << endl;
  }
  return 0;
}
