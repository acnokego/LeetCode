class Solution:
    """
    Complexity: O(n)
    Space: O(n)
    """
    def licenseKeyFormatting(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        group_list = S.upper().split('-')
        total_count = sum([len(g) for g in group_list])


        strings = ''.join(group_list)
        #move the number equal to the remainder to the first group
        new_string = strings[:total_count % K]
        if(len(new_string)):
            new_string += '-'
        # get each groups of string     
        for i in range(total_count % K, len(strings), K):        
            new_string += strings[i:i+K]
            new_string += '-'
        new_string = new_string[:-1]
            
        return new_string
