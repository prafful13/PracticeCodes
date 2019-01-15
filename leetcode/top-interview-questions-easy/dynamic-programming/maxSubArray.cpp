class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int sum = nums[0];
        int s = nums.size();
        for(int i=1;i<s;i++)    {
            if(sum < 0) sum = 0;
            sum += nums[i];
            if(sum > max)   max = sum;
        }
        return max;
    }
};
