class Solution {
public:
	int arr[110][110];

    bool isInterleave(string s1, string s2, string s3) {
    
        if (s1.size() + s2.size() != s3.size())
            return false;
        
        if (s3.size() == 0)
            return true;
        
    	for (int i = 0; i <= s1.size() + 2; ++i)
    		for (int j = 0; j <= s2.size() + 2; ++j)
    			arr[i][j] = -1;

    	arr[0][0] = 0;

    	for (int i = 0; i <= s1.size(); ++i) 
    		for (int j = 0; j <= s2.size(); ++j) {
                
                if (arr[i][j] == s3.size())
                    return true;
                
                if (arr[i][j] == -1) //it never reaches here
                    continue;
                
    			if (i < s1.size() && s3[arr[i][j]] == s1[i]) 
    				arr[i+1][j] = arr[i][j] + 1;
    			
				if (j < s2.size() && s3[arr[i][j]] == s2[j]) 
    				arr[i][j+1] = arr[i][j] + 1;
    		
    		}
        
    	return false;

    }
};