class Node{
public:
    Node* next[26];
    bool flag;
    Node(){
        for(int i=0;i<26;i++) next[i] = nullptr;
        flag = false;
    }
};

class Trie{
public: 
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string& s){
        Node* ptr = root;
        for(int i=0;i<s.size();i++){
            if(!ptr->next[s[i]-'a']) ptr->next[s[i]-'a'] = new Node();
            ptr = ptr->next[s[i]-'a'];
            if(i == s.size()-1) ptr->flag = true;
        }
    }
};

class Solution {
public:
vector<string> v;
vector<pair<int,int>> dirs = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};
    bool check(vector<vector<char>>& board, Node* ptr, int i, int j, string& s){
        if(ptr->flag){
            v.push_back(s);
            ptr->flag = false;
            bool chk = true;
            for(int i=0;i<26;i++){
                if(ptr->next[i]) {
                    chk = false;
                    break;
                }
            }
            if(chk) return true;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
            return false;

        for(auto&[u,v]:dirs){
            if((i+u < 0 || i+u>=board.size() || j+v<0 || j+v >= board[0].size()) || board[i+u][j+v] == '*' || !ptr->next[board[i+u][j+v]-'a']) continue;
            char temp = board[i+u][j+v];
            board[i+u][j+v] = '*';
            s.push_back(temp);
            if(check(board, ptr->next[temp-'a'], i+u, j+v, s)){
                delete ptr->next[temp-'a'];
                ptr->next[temp-'a'] = nullptr;
            }
            s.pop_back();
            board[i+u][j+v] = temp;
        }
        if(ptr->flag) return false;
        for(int i=0;i<26;i++){
            if(ptr->next[i]) {
                return false;
            }
        }
        return true;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie T;
        for(auto& w:words){
            T.insert(w);
        }

        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(T.root->next[board[i][j]-'a']){
                    char temp = board[i][j];
                    board[i][j] = '*';
                    string s(1,temp);
                    if(check(board, T.root->next[temp-'a'], i, j, s)){
                        delete T.root->next[temp-'a'];
                        T.root->next[temp-'a'] = nullptr;
                    }
                    board[i][j] = temp;
                }
            }
        }

        return v;
    }
};