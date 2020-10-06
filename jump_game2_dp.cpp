class Solution {
public:
    int arr[200000];
    int jump(vector<int>& nums) {
        
        if (nums.size() == 0 || nums.size() == 1)
            return 0;
        
        int max_reach_index = 1;
        
        arr[0] = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            
            int reach = i + nums[i];
            
            while (max_reach_index <= reach) {
                arr[max_reach_index] = arr[i] + 1;
                max_reach_index++;
            }
        }
        
        return arr[nums.size() - 1];
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);