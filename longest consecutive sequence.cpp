class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int unique = 100000;
        
        for (int i = 0; i < nums.size(); ++i) {
            
            if (nums[i] > 0 && nums[i] < unique && nums[i] <= nums.size()) {
                nums[nums[i] - 1] = unique + nums[nums[i] - 1];
            } 
            else if (nums[i] > unique) {
                int val = nums[i] - unique;
                if (val <= nums.size())
                    nums[val - 1] = unique + nums[val - 1];
            }
        }
        
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > unique)
                ans++;
        else
            break;
        
        return ans;
        
    }
};