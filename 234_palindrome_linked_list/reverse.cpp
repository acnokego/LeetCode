/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
 * Complexity: O(n)
 * Space: O(1)
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        
        ListNode* mid1 = dummy;
        ListNode* mid2 = dummy;
        ListNode* prev = NULL;
        ListNode* mid1_next = head;
        
        while(mid2 -> next != NULL && mid2 -> next -> next != NULL){
            
            mid2 = mid2 -> next -> next;
            
            // reverse the first half
            mid1 = mid1_next;
            mid1_next = mid1 -> next;
            mid1 -> next = prev;
            prev = mid1;
      
        }
        
        // odd
        if(mid2 -> next != NULL) mid2 = mid1_next -> next;
        // even 
        else mid2 = mid1_next;
        
        while(mid1 != NULL && mid2 != NULL){
            if(mid1 -> val != mid2 -> val) return false;
            mid1 = mid1 -> next;
            mid2 = mid2 -> next;
        }
        return true;
        
       
        
    }
};
