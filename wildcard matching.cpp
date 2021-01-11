class Solution {
public:
    bool arr[2005][2005];
    
    bool isMatch(string leftWord, string rightWord) {
        
        if (leftWord.size() == 0 && rightWord.size() == 0)
            return true;

        bool pr[rightWord.length() + 5];
        for (int i = 0; i < rightWord.size(); ++i) {
            bool val = rightWord[i] == '*';
            if (i != 0)
                val &= pr[i-1];
            pr[i] = val;
        }
    
        if (leftWord.size() == 0) 
            return pr[rightWord.size() - 1];
        
        arr[0][0] = rightWord[0] == '*' || rightWord[0] == '?' || leftWord[0] == rightWord[0];
        
        if (!arr[0][0])
            return false;
        
        for (int i = 0; i < leftWord.size(); ++i) 
            for (int j = 0; j < rightWord.size(); ++j) {
                
                if (i == 0 && j == 0)
                    continue;

                char leftChar = leftWord[i], rightChar = rightWord[j];
                
                if (rightChar == '*') {
                    bool prev = false;
                    if (i == 0) 
                        prev = arr[i][j-1];
                    else if (j == 0)
                        prev = arr[i-1][j];
                    else
                        prev = arr[i][j-1] || arr[i-1][j];
                    arr[i][j] = prev;
                }
                else {
                    bool matching = rightChar == '?' ? true : (leftChar == rightChar);
                    if (i == 0) 
                        arr[i][j] = matching & pr[j - 1];
                    else if (j == 0) 
                        arr[i][j] = false;
                    else
                        arr[i][j] = arr[i-1][j-1] && matching;
                }   
            }
        
        return arr[leftWord.size() - 1][rightWord.size() - 1];
    }
};

// Fast I/O; 4 ms
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);