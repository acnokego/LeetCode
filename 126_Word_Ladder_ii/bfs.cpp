class Solution {
public:
    /*
     * Complexity: O(len(wordList)*len(wordLength)*26)
     * Space: 
     */
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(), wordList.end());
        vector<vector<string>>ans;
        queue<vector<string>>q;
        q.push(vector<string>{beginWord});
        
        bool end = false;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; ++i){
                vector<string>curr_trans = q.front();
                q.pop();
                dict.erase(curr_trans.back());
                string currWord = curr_trans.back();
                for(int j = 0; j < currWord.length(); ++j){
                    char origin = currWord[j];
                    for(int k = 0; k < 26; ++k){
                        currWord[j] = 'a' + k;
                        if(dict.count(currWord)){
                            curr_trans.push_back(currWord);
                            if(currWord == endWord){
                                ans.push_back(curr_trans);
                                end = true;
                            } else {
                                q.push(curr_trans);
                            }
                            curr_trans.pop_back();
                        }
                    }
                    currWord[j] = origin;
                }
            }
            if(end) break;
            
        }
        return ans;
    }
};
