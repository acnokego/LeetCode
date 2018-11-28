// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

/*
 * Complexity: O(lgn)
 * Space: O(1)
 */
class Solution {
public:
    int guessNumber(int n) {
        int start = 1, end = n;
        while(start < end){
            // prevent overflow...
            int mid = (end - start) / 2 + start;
            int higher = guess(mid);
            if(higher == 1) start = mid + 1;
            else if (higher == -1) end = mid - 1;
            else return mid;
        }
        
        // start == end
        return end;
    }
};
