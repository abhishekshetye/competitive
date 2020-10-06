class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int indexB = 0;
        
        for (int i = 0; i < A.size(); ++i) {
            
            while (indexB < B.size() && B[indexB][1] < A[i][0])
                indexB++;
            
            while (indexB < B.size() && B[indexB][0] <= A[i][1]) {
                vector<int> temp {max(A[i][0], B[indexB][0]), min(A[i][1], B[indexB][1])};
                ans.push_back(temp);
                if (B[indexB][1] >= A[i][1])
                    break;
                indexB++;
            }
        
        }
        
        return ans;
        
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);