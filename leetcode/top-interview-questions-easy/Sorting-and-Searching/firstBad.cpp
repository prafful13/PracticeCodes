// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int64_t i=0, j=n;
        while(j>i+1)  {
            int64_t mid = (i+j)/2;
            if(isBadVersion(mid)) {
                j = mid;
            }
            else    {
                i = mid;
            }
        }
        return j;
    }
};
