class Solution {
public:
    /*
     * Complexity: O(n^2)
     * Space: O(n)
     */

    // Euclidean algorithm (x, y should be positive if we truly want to find GCD)
    // for slope (1,1), (-1,-1), we can have gcd 1, -1, so the key after
    // dividing gcd would be the same
    int getGCD(int x, int y){
        if(y == 0) return x;
        return getGCD(y, x % y);
    }
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        if(!len) return 0;
        
        int max_ans = 0;
        for(int i = 0; i < len; ++i){
            unordered_map<string, int>slope;
            int overlap = 0;
            int tmp_max = 0;
            for(int j = i + 1; j < len; ++j){
                int diff_x = points[j][0] - points[i][0];
                int diff_y = points[j][1] - points[i][1];
                if(diff_x == 0 && diff_y == 0){
                    ++overlap;
                    continue;
                }            
                int gcd = getGCD(diff_x, diff_y);
                if(gcd != 0){
                    diff_x /= gcd;
                    diff_y /= gcd;
                }
                string key = to_string(diff_x) + "," + to_string(diff_y);
                if(slope.count(key)){
                    slope[key] += 1;
                } else {
                    slope[key] = 1;
                }
                tmp_max = max(slope[key], tmp_max);
            }
            max_ans = max(max_ans, tmp_max + overlap + 1);
        }
        return max_ans;
    }
};
