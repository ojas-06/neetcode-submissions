class Solution {
public:
    bool dist(string& a,string& b){
        int diff = 0;
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]) diff++;
            if(diff > 1) return false;
        }
        if(diff != 1) return false;
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<vector<int>> graph(n+1);
        int ewIndex = -1;
        for(int i=0;i<n ; i++){
            if(endWord == wordList[i]) ewIndex = i;
            if(dist(beginWord, wordList[i])) {
                graph[n].push_back(i);
                graph[i].push_back(n);
            }
            for(int j = i+1;j<n;j++){
                if(dist(wordList[i], wordList[j])) {
                    graph[j].push_back(i);
                    graph[i].push_back(j);
                }
            }
        }
        cout<<"ewIndex = "<<ewIndex<<endl;
        for(int i=0;i<=n;i++){
            for(int &j:graph[i]) cout<<j<<" ";
            cout<<endl;
        }
        if(ewIndex == -1) return 0;
        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(n);
        visited[n] = true;
        int d = 1;
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                int x = q.front();
                q.pop();
                for(int y:graph[x]){
                    if(y == ewIndex) {return d+1;}
                    if(!visited[y]){
                        visited[y] = true;
                        q.push(y);
                    }
                }
            }
            d++;
        }
        return 0;
    }
};
