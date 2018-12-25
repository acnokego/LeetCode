/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  /*
   * Complexity: O(1) // getRandom
   * Space: O(n)
   */
private:
    vector<int>list;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head){
        while(head != NULL){
            list.push_back(head -> val);
            head = head -> next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int rand_idx = rand() % list.size();
        return list[rand_idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
