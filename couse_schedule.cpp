class Solution {
public:
    map<int, vector<int>> graph;
    bool ans = true;
        
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> visited(numCourses + 5, 0);
        
        for (int i = 0; i < prerequisites.size(); ++i) {
            if (graph.find(prerequisites[i][0]) == graph.end())
                graph[prerequisites[i][0]] = vector<int>{};
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for (int course = 0; course < numCourses && ans; ++course)
            if (visited[course] == 0 )
                canFinishWith(course, visited);
        
        
        return ans;
    }
    
    void canFinishWith(int course, vector<int> &visited) {
        
        visited[course] = 1;
        
        vector<int> pre = graph[course];
        
        for (int i = 0; i < pre.size() && ans; ++i) {
            
            if (visited[pre[i]] == 1) { //already visited 
                ans = false;
                return;
            }
            
            canFinishWith(pre[i], visited);
        }
        
        visited[course] = 2; //some other value
    }
};