'''

https://leetcode.com/problems/maximal-network-rank/

Store graph in map of set to optimzie the finding. Iterate through vertices and get the maximum rank.

'''

class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        
        if len(roads) == 0:
            return 0
        
        graph = {}
        for each in roads:
            f, s = each[0], each[1]
            if f in graph:
                graph[f].add(s)
            else:
                graph[f] = {s}
            
            if s in graph:
                graph[s].add(f)
            else:
                graph[s] = {f}
        
        ans = 0
        for i in range(0, n):
            for j in range(i + 1, n):
                if i in graph and j in graph:
                    ans = max(ans, len(graph[i]) + len(graph[j]) - 1) if i in graph[j] else max(ans, len(graph[i]) + len(graph[j]))
        return ans