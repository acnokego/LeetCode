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
 * I could have just reversed the first half of list...
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        if(head->next == NULL) return true;
        int length = 1;
        ListNode *count = head;
        while(count->next != NULL){
            count = count->next;
            ++length;
        }
        int  mid = length / 2; //the half 
        ListNode* first = head;
        for(int i = 0; i < mid - 1; ++i){
            first = first -> next;
        }
        
        // break from the first half
        ListNode* second;
        if(length % 2 == 0){
            second = first -> next;
        }
        else{
            second = first -> next -> next;
        }
        first -> next = NULL;
        
        //reverse the second half
        ListNode* prev = NULL;
        while(second != NULL){
            ListNode* next = second -> next;
            second -> next = prev;
            prev = second;
            second = next;
        }
        // assign first to head of ptr
        first = head;
        // assign second to the end of ptr.
        second = prev;
        for(int i = 0; i < mid; ++i){
            if(first -> val != second -> val) return false;
            first = first -> next;
            second = second -> next;
        }
        return true;
    }
};
