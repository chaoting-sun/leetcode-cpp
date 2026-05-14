class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        char_count = [0] * 26
        for ch in s:
            char_count[ord(ch) - ord('a')] += 1

        for ch in t:
            char_count[ord(ch) - ord('a')] -= 1

        for i in range(26):
            if char_count[i] != 0:
                return False
        return True