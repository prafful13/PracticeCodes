class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int s = nums.size();
        int res = nums[0];
        for(int i=1; i<s;i++)   res ^= nums[i];
        return res;
    }
};
