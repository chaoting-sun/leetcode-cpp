class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = {} # sorted str: ids

        for i in range(len(strs)):
            sorted_str = "".join(sorted(strs[i]))

            if sorted_str not in groups:
                groups[sorted_str] = []
            groups[sorted_str].append(i)

        ans = []

        for group in groups.values():
            ans.append([])
            for idx in group:
                ans[-1].append(strs[idx])
        
        return ans