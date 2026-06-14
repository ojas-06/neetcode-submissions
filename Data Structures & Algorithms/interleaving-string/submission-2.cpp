class Solution {
public:
    bool isi(string&s1,string&s2,string&s3,int i,int j,int k){
        if(k == s3.size()) return true;
        if(s1[i] != s3[k] && s2[j] != s3[k]) return false;
        if(s1[i] == s3[k] && s2[j] != s3[k]) return isi(s1,s2,s3,i+1,j,k+1);
        if(s1[i] != s3[k] && s2[j] == s3[k]) return isi(s1,s2,s3,i,j+1,k+1);
        return isi(s1,s2,s3,i+1,j,k+1) || isi(s1,s2,s3,i,j+1,k+1);
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size()) return false;
        return isi(s1,s2,s3,0,0,0);
    }
};
