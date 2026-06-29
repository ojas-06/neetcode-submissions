class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0); 
        int left = 0;
        int max_freq = 0;
        int max_len = 0;
        
        for (int right = 0; right < s.size(); right++) {
            counts[s[right] - 'A']++;
            max_freq = max(max_freq, counts[s[right] - 'A']);
            
            int window_len = right - left + 1;
            if (window_len - max_freq > k) {
                counts[s[left] - 'A']--;
                left++;
            }
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};