class Solution {
public:
    void parse(string& preorder, vector<string>& token){
        
        int pos1 = 0;
        int pos2;
        
        pos1 = preorder.find(",", pos1);
        if(pos1 != string::npos){
            token.push_back(preorder.substr(0, pos1));
        }
        else{
            token.push_back(preorder);
            return;
        }
        
        while((pos2 = preorder.find(",", pos1+1)) != string::npos){
            token.push_back(preorder.substr(pos1+1, pos2-pos1-1));
            pos1 = pos2;
        }
        
        token.push_back(preorder.substr(pos1+1));
    }
    
    bool isValidSerialization(string preorder) {
        
        int left = 1, idx = 0;
        vector<string>parse_string;
        
        // parse the comma
        parse(preorder, parse_string);
        
        
        for(;left > 0 && idx < parse_string.size(); ++idx){
           
            // there should be two children for each root
            if(parse_string[idx] != "#"){
                left += 2;
            }
            left -= 1;
        }
        if(idx == parse_string.size() && left == 0) return true;
        return false;
    }
};
