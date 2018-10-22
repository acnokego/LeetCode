class Solution {
  /*
   * Complexity: O(nlgn) + O(n^2)
   * Space: O(n)
   *
   * Sort the higest people first, for the people with the smae height sort 
   * according to how many people in front of them. After sorting, insert
   * people to the result array according to how many people in front of them.
   */
public:
    struct cmp {
      bool operator()(pair<int,int> a, pair<int,int>b){
          return (a.first > b.first) || (a.first == b.first && a.second < b.second);
      }  
    };
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>>ans;
        if(people.size()){
            sort(people.begin(), people.end(), cmp());
            for(int i = 0; i < people.size(); ++i){
                ans.insert(ans.begin() + people[i].second, people[i]);
            }
        }
        return ans;
    }
};
