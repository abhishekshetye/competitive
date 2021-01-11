#include<algorithm>

class Solution {
public:
    stack<int> list;
    set<string> dict;
    set<int> alreadyProcessed; 
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int maxLen = INT_MIN;
        for (int i = 0; i < wordDict.size(); ++i) {
            dict.insert(wordDict[i]);
            maxLen = max(maxLen, (int) wordDict[i].size());
        }
        
        list.push(0);
        
        while(!list.empty()) {
            int pos = list.top();
            list.pop();
            bool isDone = calculate(pos, s, maxLen);
            if (isDone)
                return true;
        }
        
        return false;
        
    }
    
    bool calculate(int pos, string s, int maxLen) {
        
        if (alreadyProcessed.find(pos) != alreadyProcessed.end())
            return false;
        
        int newLimit = pos + maxLen > s.size() ? s.size() : pos + maxLen;
        
        for (int i = pos + 1; i <= newLimit; ++i) {
            string subWord = s.substr(pos, i - pos);
            
            if (dict.find(subWord) != dict.end()) {
                list.push(i);
                 
                if (i == s.size())
                    return true;
            }
        }
        
        alreadyProcessed.insert(pos);
        
        return false;
    }
    
};