class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(1)
     */
    bool isOneBitCharacter(vector<int>& bits) {
        int one = 0;
        for(int i = bits.size() - 2; i >= 0; --i){
            if(bits[i] == 1){
                ++one;
            } else {
                break;
            }
        }
        return (one % 2 == 0) ? true : false;
        
    }
};
