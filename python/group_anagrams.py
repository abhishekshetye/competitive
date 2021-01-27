class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = {}
        for each in strs:
            val = ''.join(sorted(each))
            if val in mp:
                mp[val].append(each)
            else:
                valList = [each]
                mp[val] = valList
        ans = []
        for k , v in mp.items():
            ans.append(v)
        return ans