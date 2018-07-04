class Solution {
/*
 * Space: O(1), like linkd cycle, use two ptrs.
 */
public:
    int calDigitSquare(int n){
        int sum = 0;
        while(n >= 1){
            sum += (n % 10)*(n % 10);
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = calDigitSquare(slow);
            fast = calDigitSquare(fast);
            fast = calDigitSquare(fast);
        }while(slow != fast && slow != 1);
        if(slow == 1) return true;
        else return false;
    }
};
