class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> f(26,0);
        for(char &c: s) f[c-'a']++;
        for(char &c: t) f[c-'a']--;
        for(int i=0;i<26;i++) if(f[i] != 0) return false;
        return true;
    }
};
