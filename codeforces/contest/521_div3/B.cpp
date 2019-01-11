#include<bits/stdc++.h>

using namespace std;

int main()  {
  int n;
  cin>>n;
  int arr[n], ans = 0;
  for(int i=0;i<n;i++)  cin>>arr[i];
  for(int i=1;i<n;i++)  {
    if(arr[i]==0 && arr[i-1]==1 &&arr[i+1]==1)  {
        arr[i+1] = 0;
        ans++;
    }
  }
  cout<<ans;
  return 0;
}
