class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row_num = image.size();
        int col_num = image[0].size();
        int origin_color = image[sr][sc];
        queue<pair<int, int>>q;
        q.push(make_pair(sr, sc));
        vector<vector<int>>directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        while(!q.empty()){
            auto pos = q.front();
            q.pop();
            if(image[pos.first][pos.second] != newColor){
                image[pos.first][pos.second] = newColor;
                for(auto dir : directions){
                    int n_r = pos.first + dir[0];
                    int n_c = pos.second + dir[1];
                    if(n_r >= 0 && n_r < row_num && n_c >=0 && n_c < col_num && image[n_r][n_c] == origin_color){
                        q.push(make_pair(n_r, n_c));
                    }
                }
            }
        }
        return image;
    }
};
