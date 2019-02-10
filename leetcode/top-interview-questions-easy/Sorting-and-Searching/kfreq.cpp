class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(auto it: nums)  {
            m[it] = 0;
        }
        for(auto it: nums)  {
            m[it]++;
        }
        map<int, vector<int>, std::greater<int>> m2;
        for(auto it: m) {
            m2[it.second].push_back(it.first);
        }
        int i = 0;
        vector<int> ans;
        for(auto it: m2)    {
            for(auto ite: it.second)   {
                if(i>=k)    break;
                i++;
                ans.push_back(ite);
            }
            if(i>=k)    break;
        }
        return ans;
    }
};
