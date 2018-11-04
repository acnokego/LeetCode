class Solution {
  /*
   * Complexity: O(l1*l2*lg(k))
   * Space: O(k)
   */
public:
    static bool compare(pair<int,int> p1, pair<int,int> p2){
        return (p1.first + p1.second) < (p2.first + p2.second);
    }
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&compare)> tmp_ans(compare);
        int i = 0, j = 0;
        
        // store k element in the max_heap first
        for(; i < nums1.size() && tmp_ans.size() < k; ++i){
            for(j = 0; j < nums2.size() && tmp_ans.size() < k; ++j){
                tmp_ans.push(make_pair(nums1[i], nums2[j]));
            }
        }
        // if there are still number in the the prvious i
        if(j < nums2.size()) i -= 1;
        // start from the next i
        else j = 0;
        // then check the rest of pairs, if one of the pairs sum is smaller than
        // the max sum, replace it.
        for(; i < nums1.size(); ++i){
            for(; j < nums2.size(); ++j){
                pair<int,int> max = tmp_ans.top();
                if(nums1[i] + nums2[j] < (max.first + max.second)){
                    tmp_ans.pop();
                    tmp_ans.push(make_pair(nums1[i], nums2[j]));
                }
                else break;
            }
            j = 0;
        }
        vector<pair<int,int>>ans(tmp_ans.size());
        if(tmp_ans.size()) copy(&(tmp_ans.top()), &(tmp_ans.top()) + tmp_ans.size(), &ans[0]);
        return ans;
    }
};
