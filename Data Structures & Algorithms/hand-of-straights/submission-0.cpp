class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize) return false;
        vector<vector<int>> hs(hand.size()/groupSize);
        sort(hand.begin(), hand.end());

        for(int &x:hand){
            for(int i=0;i<hs.size();i++){
                if(!hs[i].size() || (hs[i].back()+1 == x && hs[i].size() < groupSize)){
                    hs[i].push_back(x);
                    break;
                }
            }
        }
        for(int i=0;i<hs.size();i++){
            if(hs[i].size() != groupSize) return false;
        }
        return true;
    }
};
