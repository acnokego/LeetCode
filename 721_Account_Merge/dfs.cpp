class Solution {
public:
    void recursive(int acc_idx, vector<vector<string>>& accounts, set<string>& curr_list, vector<bool>& added_account, unordered_map<string, vector<int>>& email_occur){
        added_account[acc_idx] = true;
        for(int i = 1; i < accounts[acc_idx].size(); ++i){
            string email = accounts[acc_idx][i];
            curr_list.insert(email);
            for(int next_idx : email_occur[email]){
                if(!added_account[next_idx]){
                    recursive(next_idx, accounts, curr_list, added_account, email_occur);
                }
            }
        }
        
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        unordered_map<string, vector<int>>email_occur;
        for(int i = 0; i < accounts.size(); ++i){
            for(int j = 1; j < accounts[i].size(); ++j){
                email_occur[accounts[i][j]].push_back(i);
            }
        }
        vector<bool>added_account(accounts.size(), false);
        vector<vector<string>>ans;
        for(int i = 0; i < accounts.size(); ++i){
            if(!added_account[i]){
                set<string>curr_list;
                recursive(i, accounts, curr_list, added_account, email_occur);
                vector<string>merge_account{accounts[i][0]};
                merge_account.insert(merge_account.end(), curr_list.begin(), curr_list.end());
                ans.push_back(merge_account);
            }
        }
        return ans;
    }
};
