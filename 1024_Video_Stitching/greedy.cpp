class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(1)
     */
    int videoStitching(vector<vector<int>>& clips, int T) {
        //vector<int>dp(T+1, INT_MAX); // min number of segments to cover [0, i].
        sort(clips.begin(), clips.end(), [](const auto clip1, const auto clip2){
            return clip1[0] < clip2[0];
        });
        if(clips[0][0] != 0){
            return -1;
        }
        
        int start = 0, end = 0, ans = 0, idx = 0;
        // starting from the previous max reachable end
        while(start < T){
            // clips[idx][0] has to be smaller or equal to start so that the interval would have the oppotunity to overlap
            while(idx < clips.size() && clips[idx][0] <= start) end = max(end, clips[idx++][1]);
            // idx == clips.size() or the start of the following element are all bigger than start, no more overlaps
            if(start == end) return -1;
            ++ans;
            start = end;
        }
        return ans;
    }
};
