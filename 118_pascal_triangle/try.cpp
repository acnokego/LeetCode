class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector< vector<int> > ans;
        for(int i = 0; i < numRows; ++i){
            vector<int>row;
            if(i == 0) row.push_back(1);
            else{
                for(int j = 0; j < i+1; ++j){
                    int element = (j == 0 || j == i ? 1: ans[i-1][j-1]+ans[i-1][j]);
                    row.push_back(element);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};
