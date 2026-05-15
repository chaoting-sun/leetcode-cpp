class Solution:
    # sliding window
    def maxLengthGivenK(self, s: str, k: int, ch: str) -> int:
        max_length = 1
        left = 0
        char_count = 0
        for right in range(len(s)):
            if s[right] == ch:
                char_count += 1
            while (right - left + 1) - char_count > k:
                if s[left] == ch:
                    char_count -= 1
                left += 1
            max_length = max(max_length, right - left + 1)
        
        return max_length


    def characterReplacement(self, s: str, k: int) -> int:
        if len(s) == 0:
            return 0
        
        existing_chars = set()
        for ch in s:
            existing_chars.add(ch)

        max_length = 1
        for ch in existing_chars:
            curr_max_length = self.maxLengthGivenK(s, k, ch)
            max_length = max(max_length, curr_max_length)
        
        return max_length
        