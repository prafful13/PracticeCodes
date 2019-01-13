class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, j;
        int s = nums.size();
        while(nums[i]!=0 && i<s)   i++;
        j=0;
        while(j<s)  {
            if(i<j) {
                if(nums[j]!=0)  {
                    nums[i] = nums[j];
                    nums[j] = 0;
                    while(nums[i]!=0 && i<s)   i++;
                }
            }
            j++;
        }
    }
};
