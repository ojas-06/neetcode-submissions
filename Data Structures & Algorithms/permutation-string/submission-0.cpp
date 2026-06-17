class Solution {
public:
    bool check(vector<int>& v){
        for(int i=0;i<v.size();i++){
            if(v[i] != 0) return false;
        }
        return true;
    }
    void print(vector<int>& v){
        for(int &i:v) cout<<i<<" ";
        cout<<endl;
    }
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        vector<int> f(26,0);
        for(char &c:s1) f[c-'a']++;
        print(f);

        for(int i=0;i<s1.size();i++){
            f[s2[i] - 'a']--;
        }
        print(f);
        if(check(f)) return true;

        for(int i=1; i <= s2.size() - s1.size(); i++){
            f[s2[i-1]-'a']++;
            f[s2[s1.size()-1+i] - 'a']--;
            print(f);
            if(check(f)) return true;
        }
        return false;
    }
};
