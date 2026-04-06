class Solution:
    def decode(self, s, start_idx):
        decoded_s = ""
        n = 0
        idx = start_idx
        while idx < len(s):
            if s[idx].islower():
                decoded_s += s[idx]
                idx += 1
            elif s[idx].isdigit():
                n = n * 10 + int(s[idx])
                idx += 1
            elif s[idx] == '[':
                new_start_idx, current_decoded_s = self.decode(s, idx + 1)
                decoded_s += n * current_decoded_s
                idx = new_start_idx
                n = 0
            else:
                idx += 1
                break

        return idx, decoded_s
    
    def decodeString(self, s: str) -> str:
        _, decoded_s = self.decode(s, 0)
        return decoded_s
 
'''
test case:
s = "3[a2[c]]"
trace:
     01234567
s = "3[a2[c]]"
             i

decoded_s = ""
i = 0
    n = 3
i = 1
    8, acc = self.decode(s, 2)
        decoded_s = "a"
        n = 2
        7, c = self.decode(s, 5)
            decoded_s = "c"
        decoded_s = "acc"
        i = 7
        n = 0
        i = 8
decoded_s = accaccacc
i = 8
n = 0
'''