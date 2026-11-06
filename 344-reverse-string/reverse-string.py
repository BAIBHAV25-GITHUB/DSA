class Solution:
    def reverseString(self, s: list[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        i = 0
        for j in range(len(s)-1, -1, -1):
            if i < j:
                s[i], s[j] = s[j], s[i]
            else:
                break
            i += 1
        
        