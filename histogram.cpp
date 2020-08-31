class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
	
        if (heights.size() == 0)
            return 0;
        
		int ans = 0;

		stack<pair<int,int>> st;

		st.push(make_pair(-1,-1)); 

		for (int i = 0; i < heights.size(); ++i) {

			if (heights[i] < st.top().first) {

				while (!st.empty() && heights[i] <= st.top().first) {
					
					int height = st.top().first;
	
					st.pop();
                    
					if (!st.empty())
						ans = max(ans, height * (i - st.top().second - 1));
				}

			}

			st.push(make_pair(heights[i], i));

		}

		while (!st.empty()) {
            
			int height = st.top().first;
            
			st.pop();
            
			if (!st.empty()) {
                int val = height * (heights.size() - st.top().second - 1);
                ans = max(val, ans);
			}
		}

		return ans;
    }

};