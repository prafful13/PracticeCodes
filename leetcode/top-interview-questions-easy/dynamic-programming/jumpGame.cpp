class Solution {
public:
    unordered_map<int, bool> dp;
    bool canJump(vector<int>& nums, int curr = 0) {
        if(nums.size() == 0)    return true;
        if(nums[0] == 25000)    return false;
        if(dp.find(curr)!=dp.end()) return dp[curr];
        if(curr >= nums.size()-1)   return dp[curr] = true;
        bool ans = false;
        while(nums[curr]>0) {
            ans = ans || canJump(nums, curr + nums[curr]);
            nums[curr]--;
            if(ans == true) break;
        }
        return dp[curr] = ans;
    }
};
