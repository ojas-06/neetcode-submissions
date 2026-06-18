class Solution {
public:
int left,right;
    void center(string &s, int i, int j){
        while( i>=0 && j<s.size() ){
            if(s[i] == s[j]) {i--;j++;}
            else break;
        }
        if(j-i-1 > right-left+1){
            right = j-1;
            left = i+1;
        }
    }
    string longestPalindrome(string s) {
        left = 0;
        right = 0;
        for(int i=0;i<s.size();i++) {
            center(s,i,i);
            center(s,i,i+1);
        }
        return s.substr(left, right-left+1);
    }
};
