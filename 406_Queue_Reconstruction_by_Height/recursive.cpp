class Solution {
  /*
   * Complexity: O(n^2)
   * Space: O(n)
   */
public:
    struct cmp {
      bool operator()(pair<int,int> a, pair<int,int>b){
          return (a.first < b.first) || (a.first == b.first && a.second > b.second);
      }  
    };
    void recursive(vector<pair<int, int>>& ans, int start, int end) {
        if(start >= end){
            return;
        }
        // find the shortest one and with the most people in front of it
        // since it is the first one whose positions needed to be set
        auto shortest = min_element(ans.begin() + start, ans.begin() + end + 1, cmp());
        // make the shortest as the pivot swap it to the last
        iter_swap(shortest, ans.begin() + end);
        // get the order of the rest pairs
        recursive(ans, start, end - 1);
        // move the pivot to the correct position without change the order
        int order = ans[end].second;
        for(int i = end; i > order; --i){
            swap(ans[i], ans[i - 1]);
        }
        return;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>>ans = people;
        if(people.size()){
            recursive(ans, 0, people.size()-1);
        }
        return ans;
    }
};
