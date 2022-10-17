class Solution(object):
    def checkIfPangram(self, sentence):
        """
        :type sentence: str
        :rtype: bool
        """
        lower_case = [chr(i) for i in range(97, 123)]
        for i in lower_case :
            if i not in sentence :
                return False
        
        return True
    
