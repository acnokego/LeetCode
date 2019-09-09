class Solution {
public:
    /*
     * Complexity: O(nlgn)
     * Space: O(n)
     */
    bool isNStraightHand(vector<int>& hand, int W) {
        int size = hand.size();
        if(size % W != 0) return false;
        
        // O(nlgn)
        map<int, int>sorted_hand;
        for(int &card : hand) {
            sorted_hand[card] += 1;
        }
        
        int group_count = 0;
        int remain_size = size;
        while(remain_size) {
            int group_size = 0;
            int prev = -1;
            vector<int>to_delete;
            for(auto it = sorted_hand.begin(); it != sorted_hand.end() && group_size < W;){   
                if (prev > 0) {
                    // consecutive
                    if(it -> first == prev + 1) {
                        group_size += 1;
                        it -> second -= 1;
                    }else return false;      
                } else{
                    // init prev
                    group_size += 1;
                    it -> second -= 1;
                }
                prev = it ->first;
                // erase while iterate
                if(!it->second){
                    sorted_hand.erase(it++);
                } else ++it;
            }
            
            if(group_size != W) return false;
            // increase num of group
            remain_size -= W;
        }
        return true;
    }
};
