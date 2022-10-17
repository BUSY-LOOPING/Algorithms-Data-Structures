#Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
import numpy as np
import math 

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        dct = {}
        for i in nums:
            if i in dct:
                dct[i] += 1
            else :
                dct[i] = 1
        res = np.array(list(dct.keys()))[np.array(list(dct.values())) > int(math.floor(len(nums) / 3))]
        return res
    