class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0, j=0; j<n; i++) {
            if(i>=m)    {
                int temp = nums1[i];
                nums1[i] = nums2[j];
                nums2[j] = temp;
                j++;
            }
            else if(i<m && (nums1[i]>nums2[j])){
                int temp = nums1[i];
                nums1[i] = nums2[j];
                nums2[j] = temp;
                int k;
                for(k = j + 1; k < n; k++)  {
                    if(nums2[k-1] > nums2[k]) {
                        temp = nums2[k];
                        nums2[k] = nums2[k-1];
                        nums2[k-1] = temp;
                    }
                    else    break;
                }

            }
        }
    }
};
