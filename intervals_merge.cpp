class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ans;


        int mStart = getStart(newInterval), mEnd = getEnd(newInterval), merge = 0;
        
        if (intervals.size() == 0 || getEnd(newInterval) < getStart(intervals[0])) {
            ans.push_back(newInterval);
            merge = 2;
        }
        
        for (int i = 0; i < intervals.size(); ++i) {
            
            vector<int> curr = intervals[i];
            
            if (merge == 2) {
                //already merged so just put as is
                ans.push_back(curr);
            } 
            else if (merge == 1) {
                //merging as started but not finished
                if (curr[0] > mEnd) {
                    vector<int> temp {mStart, mEnd};
                    ans.push_back(temp);
                    ans.push_back(curr);
                    merge = 2;
                } else {
                    mEnd = max(curr[1], newInterval[1]);
                }
            }
            else if (i != 0 && getEnd(intervals[i-1]) < getStart(newInterval) && getStart(curr) > getEnd(newInterval)) {
                //if there is no overlap
                merge = 2;
                ans.push_back(newInterval);
                ans.push_back(curr);
            }
            else if (getStart(newInterval) <= getEnd(curr)) {
                //need to merge
                merge = 1, mStart = min(getStart(curr), getStart(newInterval)), mEnd = max(newInterval[1], curr[1]);
            }
            else {
                //put it as is
                ans.push_back(intervals[i]);
            }
        }
        
        if (merge != 2) {
            //merge started but not finished
            vector<int> temp {mStart, mEnd};
            ans.push_back(temp);
        }
        
        return ans;
    }
    
    int getStart(vector<int> interval) {
        return interval[0];
    }
    
    int getEnd(vector<int> interval) {
        return interval[1];
    }
};