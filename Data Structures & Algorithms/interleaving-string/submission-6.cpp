class Solution {
public:

    bool isi(string&s1,string&s2,string&s3,int i,int j,int k,vector<vector<int>>& done){
        if(k >= s3.size()) return true;
        if(i == s1.size()) {
            if(s2[j] != s3[k]) return false;
            return isi(s1,s2,s3,i,j+1,k+1,done);
        }
        if(j == s2.size()){
            if(s1[i] != s3[k]) return false;
            return isi(s1,s2,s3,i+1,j,k+1,done);
        }
        if(done[i][j] != -1) return done[i][j];
        if(s1[i] != s3[k] && s2[j] != s3[k]) {done[i][j] = 0; return false;}
        if(s1[i] == s3[k] && s2[j] != s3[k]) {done[i][j] = isi(s1,s2,s3,i+1,j,k+1,done); return done[i][j];}
        if(s1[i] != s3[k] && s2[j] == s3[k]) {done[i][j] = isi(s1,s2,s3,i,j+1,k+1,done);return done[i][j];}
        {done[i][j] = isi(s1,s2,s3,i+1,j,k+1,done) || isi(s1,s2,s3,i,j+1,k+1,done); return done[i][j];}
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size()) return false;
        vector<vector<int>> done(s1.size()+1,
                                        vector<int>(s2.size()+1,-1));
        return isi(s1,s2,s3,0,0,0,done);
    }
};
