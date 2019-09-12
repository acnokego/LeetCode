class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(n)
     */
    void recursive(vector<int>& ans, int curr, int n){

        // if it's 1 we only have to add to 9
        for(int i = 0; i <= ((curr == 1) ? 8 : 9); ++i){
            int num = curr + i;
            if(num > n) return;
            ans.push_back(num);
            // start from 10 before go to 11
            recursive(ans, num * 10, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        recursive(ans, 1, n);
        return ans;
        
    }
       
};
