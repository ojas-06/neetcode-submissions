class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0;
        int cm = 101;

        for(int i=0;i<prices.size();i++){
            mp = max(mp, prices[i] - cm);
            cm = min(cm, prices[i]);
        }
        return mp;
    }
};
