class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if (nums.size() == 0)
            return false;
    
        int reach = 0;
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            reach = max(reach, i + nums[i]);
            if (reach <= i)
                return false;
        }
        
        return true;
    }
};