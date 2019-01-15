class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        map<int, int> profit;
        profit[nums.size()-1] = nums[nums.size()-1];
        int ans = robHelper(nums, 0, profit);
        // cout<<endl;
        // for(int i=0;i<nums.size();i++)  cout<<profit[i]<<" ";
        return profit[0];
    }

    int robHelper(vector<int>& nums, int pos, map<int, int>& profit) {
        if(pos+1 > nums.size()) return 0;
        if(profit.find(pos) != profit.end())   return profit[pos];
        profit[pos] = max(robHelper(nums, pos+2, profit) + nums[pos], robHelper(nums, pos+1, profit));
        return profit[pos];
    }
};
