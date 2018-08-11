class Solution {
  /*
   * Complexity: O(nlgn)
   * Space: O(n)
   */
public:
    static bool comp(string a, string b){
        return (a+b) < (b+a);
    }
    string largestNumber(vector<int>& nums) {
        priority_queue<string, vector<string>, decltype(&comp)> max_heap(&comp);
        for(auto& n : nums)max_heap.push(to_string(n));
        string ans;
        while(!max_heap.empty()){
            string tmp = max_heap.top();
            ans += tmp;
            max_heap.pop();
        }
        if(ans[0] == '0') return "0";
        return ans;
    }
};
