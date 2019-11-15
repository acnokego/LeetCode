class Solution {
public:
    // recursive find its parent
    string find(string s, unordered_map<string, string>& p) {
        return p[s] == s ? s : find(p[s], p);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string>owners;
        unordered_map<string, string>parents;
        unordered_map<string, set<string>>unions;
        
        for(int i = 0; i < accounts.size(); ++i){
            for(int j = 1; j < accounts[i].size(); ++j){
                parents[accounts[i][j]] = accounts[i][j];
                owners[accounts[i][j]] = accounts[i][0];
            }
        }
        
        // for each group, assign the parent to the first email's parent.
        for(int i = 0; i < accounts.size(); ++i){
            string p = find(accounts[i][1], parents);
            for(int j = 2; j < accounts[i].size(); ++j){
                // assign its previous parent to the group of the first email
                parents[find(accounts[i][j], parents)] = p;
            }
        }
        
        // for email that has the same parent, assign it to the same group
        for(int i = 0; i < accounts.size(); ++i){
            for(int j = 1; j < accounts[i].size(); ++j){
                unions[find(accounts[i][j], parents)].insert(accounts[i][j]);
            }
        }
        
        vector<vector<string>>ans;
        for(auto emails : unions){
            vector<string>acc{owners[emails.first]};
            acc.insert(acc.end(), emails.second.begin(), emails.second.end());
            ans.push_back(acc);
        }
        return ans;
    }
};
