class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<bool> in_cur(candidates.size(), false);
        dfs(0,{},0,candidates,target, in_cur);
        return res;
    }
    void dfs(int i, vector<int> cur, int sum,  vector<int>& candidates, int target, vector<bool>& in_cur){
        if(sum == target){
            res.push_back(cur);
            return;
        }
        if(i == candidates.size()) return;
        if( sum + candidates[i] > target ) return;

        for(int j = i;j<candidates.size(); j++){
            if(j>0 && candidates[j] == candidates[j-1] && !in_cur[j-1]) continue;
            cur.push_back(candidates[j]);
            in_cur[j] = true;
            dfs(j+1, cur, sum + candidates[j], candidates, target, in_cur);
            in_cur[j] = false;
            cur.pop_back();
        }
    }
};
