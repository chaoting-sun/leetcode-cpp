class Solution:
    def longestPalindrome(self, s: str) -> str:
        max_length_idx = -1
        max_length = 0
        
        def expand(left, right):
            nonlocal max_length_idx, max_length
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            curr_length = right - left - 1
            
            if curr_length > max_length:
                max_length = curr_length
                max_length_idx = left + 1

        for i in range(len(s)):
            expand(i, i)
        
        for i in range(len(s) - 1):
            expand(i, i + 1)
        
        return s[max_length_idx: max_length_idx + max_length]