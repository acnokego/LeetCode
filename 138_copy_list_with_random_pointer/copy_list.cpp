/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
/*
 * Complexity: O(n)
 * Space: O(1)
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *l1, *l2, *newhead;
        if(!head) return NULL;
        // make the l1 -> next point to the corresponding node in l2;
        // and l2 -> next store the original l1 -> next
        // in this case, we could easily access the node pointed by random
        // pointer in the new list.
        for(l1 = head; l1 != NULL; l1 = l1 -> next -> next){
            l2 = new RandomListNode(l1 -> label);
            l2 -> next = l1 -> next;
            l1 -> next = l2;
        }
        newhead = head -> next;
        // assign random pointer
        for(l1 = head; l1 != NULL; l1 = l1 -> next -> next){
            if(l1->random){
                l1 -> next -> random = l1 -> random -> next;
            }
        }
        // restore the original list
        for(l1 = head; l1 != NULL; l1 = l1 -> next){
            l2 = l1 -> next;
            l1 -> next = l2 -> next;
            if(l2 -> next) l2 -> next = l2 -> next -> next;
        }
        return newhead;
    }
};
