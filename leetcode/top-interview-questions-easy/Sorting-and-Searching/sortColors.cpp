class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = 0, j, k;
        j = k = nums.size()-1;
        for(; a <= j;)   {
            if(nums[a] == 2)    {
                swap(nums[a], nums[k]);
                if(j == k)  j--;
                k--;
            }
            else if(nums[a] == 1)   {
                swap(nums[a], nums[j]);
                j--;
            }
            else if(nums[a] == 0)   {
                a++;
            }
        }
    }
};
