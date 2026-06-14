class Node{
public:
    Node* next[26];
    bool flag;

    Node() : flag(false) {
        for(int i=0;i<26;i++) next[i] = nullptr;
    }
};

class Trie{
Node* root;
public: 
    Trie(): root(new Node()) {}
    void insert(string &s){
        Node *ptr = root;
        for(int i = 0;i<s.size();i++){
            if(!ptr -> next[s[i]-'a']) ptr -> next[s[i]-'a'] = new Node();
            ptr = ptr -> next[s[i]-'a'];
            if(i == s.size()-1) ptr->flag = true;
        }
    }
    bool checkWord(string &s){
        return search(s, 0, root);
    }
private:
    bool search(string s, int index, Node* ptr){
        if(index == s.size()) return ptr->flag;
        if(s[index] == '.'){
            for(char c = 'a'; c<='z'; c++){
                if(!ptr->next[c-'a']) continue;
                s[index] = c;
                if(search(s, index+1, ptr->next[c-'a'])) return true;
            }
            return false;
        }
        if(!ptr->next[s[index] - 'a']) return false;
        return search(s,index+1, ptr->next[s[index]-'a']);
    }
};

class WordDictionary {
public:
Trie T;
    WordDictionary() {
    }
    
    void addWord(string word) {
        T.insert(word);
    }
    
    bool search(string word) {
        return T.checkWord(word);
    }
};
