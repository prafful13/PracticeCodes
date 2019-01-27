class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size()-1);
    }

    int search(vector<int>& nums, int target, int low, int high)    {
        if(low > high)  return -1;
        int mid = (high + low) / 2;
        if(nums[mid] == target) return mid;

        if(nums[low] <= nums[mid])   {
            if(nums[low] <= target && nums[mid] >= target)  return search(nums, target, low, mid-1);
            return search(nums, target, mid+1, high);
        }

        if(target <= nums[high] && nums[mid] <= target)  return search(nums, target, mid+1, high);
        return search(nums, target, low, mid-1);
    }
};
