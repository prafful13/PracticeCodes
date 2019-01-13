class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator it = nums.begin();
        if(it == nums.end())    return 0;
        int temp = *it;
        it++;
        while(it!=nums.end())    {
            if(*it == temp) *it = INT_MAX;
            else    temp = *it;
            it++;
        }
        it = nums.begin();
        vector<int>::iterator i = nums.begin();
        while(*i!=INT_MAX && i != nums.end())  i++;
        while(it!=nums.end())  {
            if(*it == INT_MAX && i == nums.begin()) i = it;
            else if(*it != INT_MAX && it > i) {
                *i = *it;
                *it = INT_MAX;
                while(*i!=INT_MAX)  i++;
            }
            it++;
        }
        int ans = 0;
        it = nums.begin();
        while(it!=nums.end())   {
            if(*it == INT_MAX)  break;
            cout<<*it<<" ";
            ans++;
            it++;
        }

        return ans;
    }
};
