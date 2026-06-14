class Solution {
public:

    string encode(vector<string>& strs) {
        string code = "";
        for(string s:strs){
            int n = s.size();
            code += ("%("+ to_string(n)+")"+s);
        }
        return code;
    }

    vector<string> decode(string s) {
        vector<string> my_str;
        int i=0;
        int len;
        while(i<s.size()){
            if(s[i] == '%' && s[i+1] == '('){
                i+=2;
                string slen = "";
                while(s[i]!=')'){
                    slen += s[i];
                    i++;
                }
                len = stoi(slen);
                i++;
                string word = s.substr(i, len);
                my_str.push_back(word);
                i+=len;
            } else i++;
        }
        return my_str;
    }
};
