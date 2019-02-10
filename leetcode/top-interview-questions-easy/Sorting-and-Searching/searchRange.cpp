class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int l = -1, r = -1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(nums[mid] == target) {
                l = r = mid;
                while(l>=0 && nums[l] == target)    l--;
                while(r<=nums.size()-1 && nums[r] == target)    r++;
                break;
            }
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }
        if(l == -1 && r == -1)  return {-1,-1};
        l++;
        r--;
        return {l,r};
    }
};
