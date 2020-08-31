class Solution {
public:
    int candy(vector<int>& ratings) {
        
        if (ratings.size() == 0)
            return 0;
        
        vector<pair<int,int>> ans (ratings.size() + 2, make_pair(0,0));
        vector<pair<int, int>> input;
    
        
        for (int i = 0; i < ratings.size(); ++i)
            input.push_back(make_pair(ratings[i], i));
        
        sort(input.begin(), input.end());
        
        ans[input[0].second + 1] = make_pair(input[0].first, 1); //1 candy to the lowest person
        
        for (int i = 1; i < input.size(); ++i) {
            
            int pos = input[i].second + 1;
            int curr = input[i].first;

            if (ans[pos-1].first < curr && ans[pos+1].first < curr) 
                ans[pos] = make_pair(input[i].first, max(ans[pos-1].second, ans[pos+1].second) + 1);
            else if (ans[pos-1].first < curr) 
                ans[pos] = make_pair(input[i].first, ans[pos-1].second + 1);
            else if (ans[pos+1].first < curr)
                ans[pos] = make_pair(input[i].first, ans[pos+1].second + 1);
            else
                ans[pos] = make_pair(input[i].first, 1);
        }
        
        int sum = 0;
        for (int i = 0; i < ans.size(); ++i)
            sum += ans[i].second;
        
        return sum;
    }
};