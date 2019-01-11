#include <bits/stdc++.h>

using namespace std;

int main()  {
  int n;
  cin>>n;
  int arr[1000005];
  map<int, vector<int>> hash;
  set<int> nice_ind;

  long long int sum = 0;
  map<int,vector<int>>::iterator it;

  for(int i=1;i<=n;i++)  {
    cin>>arr[i];
    sum+=arr[i];
    hash[arr[i]].push_back(i);
  }

  for(int i=1;i<=n;i++) {
    sum -= arr[i];
    if(sum%2==0 && hash.find(sum/2)!=hash.end())  {
      
      nice_ind.insert(i);
    }
    sum += arr[i];
  }

  cout<<nice_ind.size()<<endl;
  for(auto &i:nice_ind) cout<<i<<" ";

  return 0;
}
