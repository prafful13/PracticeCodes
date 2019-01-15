class Solution {
public:
    int binarySearch(vector<int> arr, int l, int r, int x) {
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);
            return binarySearch(arr, mid + 1, r, x);
        }
        return -1;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int s = nums.size();
        set<vector<int>> res;
        sort(nums.begin(),nums.end());
        int flag = 0;
        for(int i=0; i<s; i++)  {
            if(nums[i]==0)  {
                flag++;
            }
        }
        if(flag == s && s>=3)   {
            vector<int> temp;
            temp.push_back(0);
            temp.push_back(0);
            temp.push_back(0);
            vector<vector<int>> ans;
            ans.push_back(temp);
            return ans;
        }


        map<int, vector<pair<int,int>>> sums;
        for(int i=0;i<s-1;i++)
            for(int j=i+1; j<s; j++)
                sums[nums[i]+nums[j]].push_back(make_pair(i,j));

        for(int i=0;i<s;i++)    {
            int to_search = 0 - nums[i];
            if(sums.find(to_search) != sums.end())   {
                int si = sums[to_search].size();
                for(int j=0; j<si; j++) {
                    int f = sums[to_search][j].first;
                    int s = sums[to_search][j].second;
                    if(i != s && i != f && s!=f)    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[s]);
                        temp.push_back(nums[f]);
                        sort(temp.begin(), temp.end());
                        res.insert(temp);
                    }
                }
            }

        }
        vector<vector<int>> ans(res.size());
        copy(res.begin(),res.end(),ans.begin());
        return ans;

    }
};
