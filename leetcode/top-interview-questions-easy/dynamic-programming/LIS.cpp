class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        if(nums.size()==0)  return 0;
        dp[0] = 1;
        int ans = 1;
        for(int pos = 1; pos < nums.size(); pos++)  {
            int max = 0;
            for(int i=0;i<pos;i++)  {
                if(nums[pos] > nums[i] && max < dp[i])  max = dp[i];
            }
            dp[pos] = max + 1;
            ans = ans < dp[pos] ? dp[pos] : ans;
        }
        return ans;
    }
};
