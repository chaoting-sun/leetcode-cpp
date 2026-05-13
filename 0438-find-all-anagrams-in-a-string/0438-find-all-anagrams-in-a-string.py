# sliding window

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s) < len(p):
            return []

        chars = [0] * 26
        distinct_chars_to_match = 0
        for ch in p:
            char_index = ord(ch) - ord('a')
            if chars[char_index] == 0:
                distinct_chars_to_match += 1
            chars[char_index] += 1

        ans = []
        left = 0

        for right in range(len(s)):
            ch = s[right]
            char_index = ord(ch) - ord('a')
            
            chars[char_index] -= 1
            if chars[char_index] == 0:
                distinct_chars_to_match -= 1

            while chars[char_index] < 0:
                left_char_index = ord(s[left]) - ord('a')
                if chars[left_char_index] == 0:
                    distinct_chars_to_match += 1
                chars[left_char_index] += 1
                left += 1
            
            if distinct_chars_to_match == 0:
                ans.append(left)
                
        return ans


'''
case: s = 'abacd', p = 'ab'
trace:
chars = [1, 1, 0, 0]
distinct_chars_to_match = 2

l = 0

r = 0
    chars = [0, 1, 0, 0]
    distinct_chars_to_match = 1
r = 1
    chars = [0, 0, 0, 0]
    distinct_chars_to_match = 0
    ans = [0]
r = 2
    chars = [-1, 0, 0, 0]
    chars = [0, 0, 0, 0]
    l = 1
'''