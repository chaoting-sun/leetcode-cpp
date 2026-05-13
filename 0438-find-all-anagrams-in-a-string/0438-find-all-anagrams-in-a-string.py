# sliding window

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s) < len(p):
            return []

        p_count = [0] * 26
        window_count = [0] * 26
        
        for ch in p:
            p_count[ord(ch) - ord('a')] += 1
        
        ans = []
        left = 0

        for right in range(len(s)):
            window_count[ord(s[right]) - ord('a')] += 1

            if right - left + 1 > len(p):
                window_count[ord(s[left]) - ord('a')] -= 1
                left += 1
            
            if right - left + 1 == len(p) and window_count == p_count:
                ans.append(left)
            
        return ans


'''
s = 'abc', p = 'ab'
p_count = [1 1 0]
l = 0
r = 0
    window_count = [1 0 0]
r = 1
    window_count = [1 1 0]
    ans = [0]
r = 2
    window_count = [1 1 1]
    window_count = [0 1 1]
    l = 1
'''


# class Solution:
#     def findAnagrams(self, s: str, p: str) -> List[int]:
#         if len(s) < len(p):
#             return []

#         chars = [0] * 26
#         distinct_chars_to_match = 0
#         for ch in p:
#             char_index = ord(ch) - ord('a')
#             if chars[char_index] == 0:
#                 distinct_chars_to_match += 1
#             chars[char_index] += 1

#         ans = []
#         left = 0

#         for right in range(len(s)):
#             ch = s[right]
#             char_index = ord(ch) - ord('a')
            
#             chars[char_index] -= 1
#             if chars[char_index] == 0:
#                 distinct_chars_to_match -= 1

#             while chars[char_index] < 0:
#                 left_char_index = ord(s[left]) - ord('a')
#                 if chars[left_char_index] == 0:
#                     distinct_chars_to_match += 1
#                 chars[left_char_index] += 1
#                 left += 1
            
#             if distinct_chars_to_match == 0:
#                 ans.append(left)
                
#         return ans