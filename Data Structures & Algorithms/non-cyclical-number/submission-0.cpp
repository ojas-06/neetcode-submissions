class Solution {
public:
unordered_map<int, bool> visited;
    bool check(int n){
        if(n == 1) return true;
        visited[n] = true;
        int sos = 0;
        while(n){
            int d = n%10;
            n/=10;
            sos+=d*d;
        }
        if(visited.count(sos)) return false;
        return check(sos);
    }
    bool isHappy(int n) {
        return check(n);
    }
};
