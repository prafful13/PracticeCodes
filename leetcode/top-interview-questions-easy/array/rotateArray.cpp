class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res = nums;
        int s = nums.size();
        for(int i=0;i<s; i++) {
            int temp = i + k;
            temp = temp % s;
            res[temp] = nums[i];
        }
        nums = res;
    }

    void reverseArr(vector<int>& nums, int a, int b)    {
        while(a<=b) {
            int temp = nums[a];
            nums[a] = nums[b];
            nums[b] = temp;
            a++;
            b--;
        }
    }

    //Better Solution
    void rotateInPlace(vector<int>& nums, int k)    {
        int n = nums.size();
        k = k % n;
        reverseArr(nums, n-k, n-1);
        reverseArr(nums, 0, n-k-1);
        reverseArr(nums, 0, n-1);
    }
};
