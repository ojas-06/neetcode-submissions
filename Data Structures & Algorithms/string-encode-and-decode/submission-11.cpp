class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for(auto& s:strs){
            res += ("%" + to_string(s.size()) + "%" + s);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i<s.size()){
            if(s[i] == '%') {
                int j = i+1;
                while(j<s.size() && s[j] != '%') j++;
                if(j == s.size()) return {};
                int sz = stoi(s.substr(i+1, j-i-1));
                res.push_back(s.substr(j+1, sz));
                i = j+sz+1;;
            }
            else {res.back() += s[i];
            i++;}

        }
        return res;
    }
};
