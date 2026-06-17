class Solution {
public:
    bool isAlphanumeric(char c){
        return (c >= 'A' && c <= 'Z') || 
               (c >= 'a' && c <= 'z') || 
               (c >= '0' && c <= '9');
    }
    
    // Helper to convert uppercase to lowercase manually
    char toLower(char c) {
        if (c >= 'A' && c <= 'Z') return c + 32;
        return c;
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while(i < j){
            // Add i < j condition to prevent out-of-bounds crashes
            while(i < j && !isAlphanumeric(s[i])) i++;
            while(i < j && !isAlphanumeric(s[j])) j--;
            
            if(i >= j) break;
            
            // Convert both to lowercase before comparing to avoid math bugs
            if(toLower(s[i]) != toLower(s[j])) {
                return false;
            }
            
            i++;
            j--;
        }
        return true;
    }
};