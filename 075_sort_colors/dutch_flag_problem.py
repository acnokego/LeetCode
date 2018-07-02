class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        """
        Complexity: O(n)
        Space: O(1)
        """
        # red is the last non red idx
        # blue is the first non blue idx
        red, white, blue = 0, 0, len(nums)-1
    
        while white <= blue:
            # swap with red
            # after swap the red become next pos.
            if nums[white] == 0:
                nums[red], nums[white] = nums[white], nums[red]
                white += 1
                red += 1
            # already in correct place
            elif nums[white] == 1:
                white += 1
            # swap with blue
            # and blue idx -= 1, since the origin pos has become blue
            # but we are not sure about the element at white idx.
            else:
                nums[white], nums[blue] = nums[blue], nums[white]
                blue -= 1
