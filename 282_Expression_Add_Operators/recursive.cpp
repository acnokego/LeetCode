class Solution {
public:
    /*
     * Complexity: O(3^n)
     * Space: O(n)
     */
    void recursive(string& num, int pos, int target, long sum, int prev, string tmp, vector<string>& ans){
        if(pos == num.length() && sum == target){
            ans.push_back(tmp);
            return;
        }
        for(int i = pos; i < num.length(); ++i){
            string curr_num = num.substr(pos, i - pos + 1);
            if(curr_num[0] == '0' && i > pos) break; // no number start with 0 except 0 itself.
            long val = stol(curr_num);
            if(pos == 0){
                recursive(num, i + 1, target, val, val, curr_num, ans);
            } else {
                recursive(num, i + 1, target, sum + val, val, tmp + "+" + curr_num, ans);
                recursive(num, i + 1, target, sum - val, -val, tmp + "-" + curr_num, ans);
                recursive(num, i + 1, target, sum - prev + prev * val, prev * val, tmp + "*" + curr_num, ans);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        string tmp = "";
        recursive(num, 0, target, 0, 0, tmp, ans);
        return ans;
    }
};
