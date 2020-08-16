class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() <= 1)
            return 0;
		
        vector<int> up(prices.size(), 0), down(prices.size(), 0);
        
        int min_val = prices[0];
        up[0] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            up[i] = max(up[i-1], prices[i] - min_val);
            min_val = min(min_val, prices[i]);
        }
        
        int len = prices.size() - 1, max_val = prices[len];
        down[len] = 0;
        for (int i = len - 1; i >= 0; --i) {
            down[i] = max(down[i+1], max_val - prices[i]);
            max_val = max(max_val, prices[i]);
        }
        
        
        int ans = 0;
        for (int i = 1; i < up.size(); ++i)
            ans = max(ans, up[i-1] + down[i]);
        
        return max(ans, prices[len] - prices[0]);
        
    }
};