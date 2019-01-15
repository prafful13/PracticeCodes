class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s = prices.size();
        if(s == 0)  return 0;
        int max = 0, min = prices[0];
        for(int i=1;i<s;i++)    {
            if(prices[i]-min > max) max = prices[i] - min;
            if(min > prices[i]) min = prices[i];
        }
        return max;
    }
};
