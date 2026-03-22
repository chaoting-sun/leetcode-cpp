class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expand(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return left + 1, right

        max_str_left = -1
        max_str_right = -1

        for i in range(len(s)):
            str_left, str_right = expand(i, i)
            if str_right - str_left > max_str_right - max_str_left:
                max_str_right = str_right
                max_str_left = str_left
        
        for i in range(len(s) - 1):
            str_left, str_right = expand(i, i + 1)
            if str_right - str_left > max_str_right - max_str_left:
                max_str_right = str_right
                max_str_left = str_left
        
        return s[max_str_left:max_str_right]