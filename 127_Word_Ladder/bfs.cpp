class Solution {
public:
    /*
     * Complexity: O(list_len * word_len)
     * Space: O(list_len)
     */
    int dist(const string& s1, const string& s2){
        int ans = 0;
        for(int i = 0; i < s1.length(); ++i){
            if(s1[i] != s2[i]){
                ++ans;
            }
        }
        return ans;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // construct edge list
        unordered_set<string>dict(wordList.begin(), wordList.end());
        
        queue<string>q1, q2;
        q1.push(beginWord);
        
        int length = 0;
        while(!q1.empty()){
            ++length;
            while(!q1.empty()){
                string curr = q1.front();
                q1.pop();              
                for(auto it = dict.begin(); it != dict.end(); ){
                    if(dist(curr, *it) == 1){
                        if(*it == endWord){
                            return length + 1;
                        }
                        q2.push(*it);
                        it = dict.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
            swap(q1, q2);
        }
        return 0;   
    }
};
