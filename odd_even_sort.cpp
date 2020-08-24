class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even, odd;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] & 1)
                odd.push_back(A[i]);
            else
                even.push_back(A[i]);
        }
        for (int i = 0; i < odd.size(); ++i)
            even.push_back(odd[i]);
        return even;
    }
};