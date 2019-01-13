class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = nums.size();
        for(int i=0; i<s-1; i++)
            for(int j=i+1; j<s; j++)
                if(nums[i] + nums[j] == target) {
                    vector<int> res;
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
    }
};
