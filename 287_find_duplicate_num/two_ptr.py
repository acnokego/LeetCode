class Solution:
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        """
        Complexity: O(n)
        Space: O(1)
        
        Think of a linked list with a cycle in it somewhere. 
        (142. Linked List Cycle II)

        Say fast pointer goes twice as fast as the slow pointer, and when they 
        meet at point A, they both must be within the cycle.

        Now consider this, how much further has the fast pointer gone than the 
        slow pointer has? Some multiplier of the loop length, which is exactly 
        how much the slow pointer has gone before fast ans slow meet. 
        (Proof: Time of travel "t" for both fast and slow are the same, 
        Dist(fast) = v(fast) * t = 2 * v(slow) * t, so Dist(fast) - Dist(slow) 
        = 2 * v(slow) * t - v(slow) * t = v(slow) * t = Dist(slow)). 
        This means, the distant from starting point to point A must be the n 
        length of the loop length. 

        So when we set another point starting from the start point and its speed
        is same as the slow pointer, if they walk a distance of n length of the 
        loop, **they will be at point A at the same time**, so they must enter the 
        loop at the same time. That's why the point where they first meet is the
        entry point of the loop.
        """
        if nums == []:
            return -1 
        slow = nums[0]
        fast = nums[nums[0]]
        # find the point A they meet within the cycle
        while slow != fast:
            slow = nums[slow]
            fast = nums[nums[fast]]
        fast = 0
        # find the entry point
        while fast != slow:
            fast = nums[fast]
            slow = nums[slow]
        return slow
