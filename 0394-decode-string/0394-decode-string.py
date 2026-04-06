class Solution:
    def decode(self, s, i):
        parts = []
        n = 0
        while i < len(s):
            if s[i].islower():
                parts.append(s[i])
                i += 1
            elif s[i].isdigit():
                n = n * 10 + int(s[i])
                i += 1
            elif s[i] == '[':
                i, inner = self.decode(s, i + 1)
                parts.append(inner * n)
                n = 0
            else:
                return i + 1, "".join(parts)

        return i, "".join(parts)
    
    def decodeString(self, s: str) -> str:
        _, decoded = self.decode(s, 0)
        return decoded
 
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