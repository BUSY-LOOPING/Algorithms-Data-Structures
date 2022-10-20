class Solution(object):
    def __init__(self) :
        self.map = {
            0 : '',
            1 : 'one',
            2: 'two',
            3 : 'three',
            4 : 'four',
            5 : 'five',
            6 : 'six',
            7 : 'seven',
            8 : 'eight',
            9 : 'nine',            
            
            10: 'ten',
            11: 'eleven',
            12 : 'twelve',
            13 : 'thirteen',
            14 : 'fourteen',
            15 : 'fifteen',
            16 : 'sixteen',
            17 : 'seventeen',
            18 : 'eighteen',
            19 : 'nineteen',
            20 : 'twenty',
            
            30 : 'thirty',
            40 : 'forty',
            50 : 'fifty',
            60 : 'sixty',
            70 : 'seventy',
            80 : 'eighty',
            90 : 'ninety',
            
            100 : 'hundred',
            1000 : 'thousand',
            1000000: 'million',
            1000000000: 'billion'
        }
        
    
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        
        num_str = str(num)
        res = ''
        for i in range(0, len(num_str), 3):
            max = i + 3 if i + 3 < len(num_str) else len(num_str)
            power_10 = [j-1 for j in range(max, i, -1)]
            print(power_10)
            res += self.eval_3digit(num_str[i:max])
            # if power_10[-1] % 3 == 0:
            #     res += self.format(pow(10, power_10[-1]))
    
            
        return res
    
    def eval_3digit(self, num_str):
        res = ''
        max = len(num_str)
        if int(num_str[0 : max]) >= 100 :
            res += self.format(int(num_str[0]))
            res += self.format(100)
            
        res += self.eval_2digit(num_str[1:max])
            
        return res
    
    def eval_2digit(self, num_str):
        res = ''
        max = len(num_str)
        if int(num_str[0 : max]) <= 20 :
            res += self.format(int(num_str[0 : max]))
        elif int(num_str[0 : max]) < 100 :
            res += self.format(int(num_str[0] + '0'))
            res += self.format(int(num_str[1]))
        return res
    
    def format(self, input) :
        #input type :int
        res= self.map[input]
        if res == '' :
            return res;
        res = res.capitalize() + ' '
        return res

obj = Solution()
s = 1942
print(obj.numberToWords(s))
i = 50

