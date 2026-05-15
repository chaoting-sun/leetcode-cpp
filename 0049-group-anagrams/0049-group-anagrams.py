from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)
        for s in strs:
            sorted_s = ''.join(sorted(s))
            groups[sorted_s].append(s)
        
        ans = []
        for v in groups.values():
            ans.append(v)
        return ans