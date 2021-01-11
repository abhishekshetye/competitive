class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if (nums.size() == 0)
            return -1;
        
        int pivot = findPivot(0, nums.size() - 1, nums);
        
        int leftTryIndex = binarySearch(0, pivot - 1, target, nums);
        
        return leftTryIndex != -1 ? leftTryIndex : binarySearch(pivot, nums.size() - 1, target, nums);
    }
    
    
    int findPivot(int left, int right, vector<int>& nums) {
        
        int mid = (left + right) / 2;
        
        int val = nums[mid];
        
        if (mid != 0 && nums[mid] < nums[mid - 1])
            return mid;
        
        if (left >= right)
            return left;
        
        if (val > nums[right])
            return findPivot(mid + 1, right, nums);
        
        return findPivot(left, mid - 1, nums);   
    }
    
    int binarySearch(int left, int right, int target, vector<int>& nums) {
        
        int mid = (left + right) / 2;
        
        int val = nums[mid];
        
        if (val == target)
            return mid;
        
        if (left >= right)
            return -1;
        
        if (val > target) 
            return binarySearch(left, mid - 1, target, nums);
        else 
            return binarySearch(mid + 1, right, target, nums);
    }
};