class Solution {
public:
    /*
     * Complexity: O(nlgk)
     * Space: O(n)
     */
    struct myCmp {
        bool operator()(pair<string, int>& a, pair<string, int>& b){
            if(a.second == b.second) return a.first < b.first;
            // the top would has the smallest count and the higher alphabetical order 
            return a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        priority_queue<pair<string, int>, vector<pair<string,int>>, myCmp> heap;     
        for(string& s : words){
            count[s] += 1;
        }
        
        for(auto it = count.begin(); it != count.end(); ++it){
            heap.push(*it);
            if(heap.size() > k) heap.pop();
        }
        
        vector<string>ans(k);
        for(int i = k - 1; i >= 0; --i){
            ans[i] = heap.top().first;
            heap.pop();
        }
        return ans;
        
    }
};
