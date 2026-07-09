class Solution {
public:
    int climbStairs(int n) {
        if( n == 1) return 1;
        if (n == 2) return 2;
        n = n - 2;
        int prevprev = 1;
        int prev = 2;
        int res = 2;
        while(n--){
            res = prev + prevprev;
            prevprev = prev;
            prev = res;
        }
        return res;
    }
};