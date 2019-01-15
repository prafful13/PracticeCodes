class Solution {
public:
    int *arr;
    int climbStairs(int n) {
        arr = new int[n+1];
        for(int i=0;i<=n;i++)   arr[i]=-1;
        arr[1] = 1;
        arr[0] = 1;
        climbStairsHelper(n);
        return arr[n];
    }

    int climbStairsHelper(int a)   {
        if(a<0) return 0;
        if(arr[a] == -1)    {
            arr[a] = climbStairsHelper(a-1) + climbStairsHelper(a-2);
        }
        return arr[a];
    }
};
