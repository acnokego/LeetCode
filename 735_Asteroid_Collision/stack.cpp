class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(n)
     */
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        vector<int>right; // the asteroids go right 
        
        for(int i = 0; i < asteroids.size(); ++i){
            if(asteroids[i] > 0){
                // right
                right.push_back(asteroids[i]);
            } else {
                // left
                // the right asteroid get destroyed by the left asteroid
                while(right.size() && right.back() < -1*asteroids[i]){
                    right.pop_back();
                }
                // no right asteroid in the stack, push the current asteroid to the ans since it would nevet collide with anyone.
                if(!right.size()){
                    ans.push_back(asteroids[i]);
                } // else get destoryed by the right
                else if(right.back() == -1*asteroids[i]){
                    right.pop_back(); // disappear
                }
            }
        }
        // push back the asteriods that go right
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
};
