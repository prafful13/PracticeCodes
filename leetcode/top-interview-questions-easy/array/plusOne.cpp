class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res = digits;
        int s = digits.size();
        s--;
        int carry = 0;
        res[s] = digits[s] + 1;
        int temp = res[s];
        res[s] = res[s] % 10;
        carry = temp / 10;
        s--;
        while(s>=0)  {
            res[s] = digits[s] + carry;
            if(res[s] >= 10)    {
                int temp = res[s];
                res[s] = res[s] % 10;
                carry = temp / 10;
            }
            else    carry = 0;
            s--;
        }
        if(carry > 0)   {
            vector<int>::iterator it = res.begin();
            res.insert(it, carry);
        }
        return res;
    }
};
