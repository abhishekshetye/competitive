class Solution {
public:
    
    map<char, int> store;
    int minChar = -1;
    
    int lengthOfLongestSubstring(string s) {
    
        int ans = 0, len = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            
            if (store.find(s[i]) != store.end()) {
                
                minChar = max(minChar, store[s[i]]);
                
                while(minChar < i && store.find(s[minChar + 1]) == store.end())
                    minChar++;
                                    
            }
            
            store[s[i]] = i;
            
            len = i - minChar;
                
            ans = max(ans, len);
            
        }
        
        return ans;
    }
};
// Fast I/O; 4 ms
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);