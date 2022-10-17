class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.upper()
        self.map = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000,
        }
        res = 0
        flag = False
        for i in range(len(s)) :
            if flag :
                flag = False
                continue
            
            if s[i] == 'I' :
                if i + 1 < len(s) and (s[i + 1] == 'V' or s[i + 1] == 'X') :
                    res += (self.map.get(s[i + 1]) - self.map.get(s[i]))
                    flag = True
            elif s[i] == 'X' :
                if i + 1 < len(s) and (s[i + 1] == 'L' or s[i + 1] == 'C') :
                    res += (self.map.get(s[i + 1]) - self.map.get(s[i]))
                    flag = True
            elif s[i] == 'C' :
                if i + 1 < len(s) and (s[i + 1] == 'D' or s[i + 1] == 'M') :
                    res += (self.map.get(s[i + 1]) - self.map.get(s[i]))
                    flag = True
                
            if not flag :
                res += self.map.get(s[i])
                
        return res
    

obj = Solution()
print(obj.romanToInt('VII'))
                    