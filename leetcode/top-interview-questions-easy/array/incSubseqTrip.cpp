class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f = INT_MAX, m = INT_MAX;
        for(int i=0;i<nums.size();i++)  {
            if(nums[i] <= f)  f = nums[i];
            else if(nums[i] <= m) m = nums[i];
            else    return true;
        }
        return false;
    }
};
