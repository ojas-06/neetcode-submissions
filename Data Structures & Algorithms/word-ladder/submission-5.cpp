class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Dump all words into an unordered_set for O(1) lookups
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        // If the target word isn't even in the list, bail out early
        if (dict.find(endWord) == dict.end()) return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth = 1;
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            // Process all words at the current depth level
            for (int i = 0; i < levelSize; i++) {
                string curr = q.front();
                q.pop();
                
                // If we found the end word, return the current depth
                if (curr == endWord) return depth;
                
                // Generate all possible 1-letter mutations of the current word
                for (int j = 0; j < curr.size(); j++) {
                    char originalChar = curr[j];
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue; // Skip the exact same letter
                        
                        curr[j] = c;
                        
                        // If this valid mutation exists in our dictionary
                        if (dict.find(curr) != dict.end()) {
                            q.push(curr);
                            dict.erase(curr); // Erasing acts as our "visited" check
                        }
                    }
                    // Restore the word back to normal before changing the next letter
                    curr[j] = originalChar;
                }
            }
            // Move to the next breadth level
            depth++;
        }
        
        // If the queue empties and we never reached endWord
        return 0;
    }
};