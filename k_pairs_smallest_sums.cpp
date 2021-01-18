class Solution {
public:
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<pair<int, pair<int,int>>> q;
        
        for (int i = 0; i < nums1.size(); ++i)
            for (int j = 0; j < nums2.size(); ++j) {
                
                int sum = nums1[i] + nums2[j];
                
                if (q.empty() || q.size() < k) {
                    q.push(make_pair(sum, make_pair(nums1[i], nums2[j])));
                } else {
                    
                    pair<int, pair<int, int>> topEle = q.top();
                    
                    if (topEle.first > sum) {
                        q.pop();
                        q.push(make_pair(sum, make_pair(nums1[i], nums2[j])));
                    }   
                }
            }
        
        vector<vector<int>> ans;
        
        while(!q.empty()) {
            pair<int, pair<int, int>> topEle = q.top();
            vector<int> temp;
            temp.push_back(topEle.second.first);
            temp.push_back(topEle.second.second);
            ans.push_back(temp);
            q.pop();
        }
        
        return ans;
        
    }
};