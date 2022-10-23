class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if p[-1] == '*' :
            if p[-2] == '.' :
                return True
            else :
                if p[-2] in s:
                    return True
        return False
    

obj = Solution()
print(obj.isMatch('aa', 'a*'))