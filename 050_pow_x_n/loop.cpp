class Solution {
  /*
   * Complexity: O(lgn)
   * Space: O(1)
   */
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if (n < 0){
            n = -n;
            x = 1/x;
        }
        double ans = 1;
        // for INT_MIN
        if(n < 0){
            n = INT_MAX ;
            ans *= x;
        }

        while(n > 0){
            if(n % 2 != 0) ans *= x;
            x *= x;
            n /= 2;
            
        }
        return ans;
    }
};
