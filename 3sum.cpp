class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        map<int, int> store;
        vector<vector<int>> ans;
        set<vector<int>> dup;
        
        for (int i = 0; i < nums.size(); ++i)
            store[nums[i]] = (store.find(nums[i]) != store.end()) ? store[nums[i]] + 1 : 1;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); ++i) {
            
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            
            for (int j = i + 1; j < nums.size(); ++j) {
                int a = nums[i], b = nums[j];
                
                if (store.find((a + b) * -1) != store.end()) {            
                    int sizeToLookFor = store[(a + b) * -1];
                    if (a == (a + b) * -1)
                        sizeToLookFor--;
                    if (b == (a + b) * -1)
                        sizeToLookFor--;
                    if (sizeToLookFor > 0) {
                        vector<int> temp {a, b, (a + b) * -1 };
                        sort(temp.begin(), temp.end());
                        if (dup.find(temp) == dup.end()) {
                            dup.insert(temp);
                            ans.push_back(temp);
                        }
                    }
                }
            }
        }
        
        return ans;
        
    }
};