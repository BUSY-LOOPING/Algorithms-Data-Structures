from re import S


class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        dct = {}
        for i in range(len(strs)):
            l = strs[i].split()
            l = l.sort()
            key = ''.join(sorted(strs[i]))
            if key in dct:
                dct[key].append(strs[i])
            else :
                dct[key] = [strs[i]]   
        
        return dct.values()         
        

s = Solution()
strs = ["cba"]
print(s.groupAnagrams(strs))
l = 'cba'.split()
print(l)