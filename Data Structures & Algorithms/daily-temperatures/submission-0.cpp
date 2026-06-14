class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer;
        for(int i=0;i<temperatures.size();i++) answer.push_back(0);
        stack<int> util;
        int curr;
        for(int i=0;i<temperatures.size();i++){
            while(1){
                if(util.empty() || temperatures[util.top()]>=temperatures[i]){
                    util.push({i});
                    break;
                }
                else{
                    curr = util.top();
                    answer[curr] = i-curr;
                    util.pop();
                }
            }
        }
        return answer;
    }
};
