class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expand(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return left + 1, right

        best_left = -1
        best_right = -1

        for i in range(len(s)):
            str_left, str_right = expand(i, i)
            if str_right - str_left > best_right - best_left:
                best_left, best_right = str_left, str_right
        
        for i in range(len(s) - 1):
            str_left, str_right = expand(i, i + 1)
            if str_right - str_left > best_right - best_left:
                best_left, best_right = str_left, str_right
        
        return s[best_left:best_right]