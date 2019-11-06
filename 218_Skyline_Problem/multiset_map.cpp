class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multimap<int, int>coords;
        for(auto building : buildings){
            coords.insert(make_pair(building[0], building[2]));
            coords.insert(make_pair(building[1], -building[2]));
        }
        
        multiset<int>heights{0}; // init 0 for critical point when there is no building(y == 0)
        vector<vector<int>>corners;
        int x = -1, y = 0;
        // iterate from left to right
        for(auto p : coords){
            if(x >= 0 && p.first != x && (corners.empty()|| (corners.back()[1]!= y))){
                // initial corner
                // p.first != x -> previos building ending point overlap with
                // next one's starting point, push it to corner after all p with
                // the same x has been handled.
                // or **height change**
                corners.push_back(vector<int>{x, y});
            }
            
            if(p.second >= 0){
                heights.insert(p.second);
            } else {
                // reach the end of the building, pop its height
                heights.erase(heights.find(-p.second));
            }
            
            x = p.first;
            y = *(heights.rbegin()); // update current max height when the previous building get removed.
        }
        
        if(!corners.empty()){
            // the last point
            corners.push_back(vector<int>{x, 0});
        }
        return corners;
            
    }
};
