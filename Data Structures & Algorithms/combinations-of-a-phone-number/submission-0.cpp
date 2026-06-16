class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,vector<char>> mp = {
            {2, {'a','b','c'}},
            {3, {'d','e','f'}},
            {4, {'g','h','i'}},
            {5, {'j','k','l'}},
            {6, {'m','n','o'}},
            {7, {'p','q','r', 's'}},
            {8, {'t','u','v'}},
            {9, {'w','x','y', 'z'}}
        };
        queue<string> res;
        for(auto &c:mp[digits[0]-'0']){
            res.push(string(1,c));
        }
        for(int i = 1;i<digits.size();i++){
            int S = res.size();
            while(S--){
                string s = res.front();
                res.pop();

                for(char c:mp[digits[i]-'0']){
                    string t = s+c;
                    res.push(t);
                }
            }
        }
        std::vector<std::string> v;
    
        v.reserve(res.size());

        while (!res.empty()) {
            v.push_back(std::move(res.front())); 
            res.pop();
        }

        return v;
    }
};
